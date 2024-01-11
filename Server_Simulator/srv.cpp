#include <sstream>
#include <cstring>
#include <utility>
#include <iomanip>
#include <stdio.h>

#include "srv.h"

/*********************************
    CLASS CONSTRUCTION
*********************************/
MqttServerWrapper::MqttServerWrapper(const char* _host, const int& _port,
                                     const char* _user, const char* _passw,
                                     const uint64_t& _gatewayID) :

  mosquittopp("teste"),
  id("srv_tst_cfgManager"),
  host(_host),
  port(_port),
  keepalive(60),
  user(_user),
  passw(_passw),
  gatewayID(_gatewayID),
  connected(NOT_CONNECTED),
  subscriptions(0) {

  // Library Initialization
  mosqpp::lib_init();

  // Register user and password
  username_pw_set(user, passw);

  // Non-blocking connection to broker request
  connect_async(host, port, 60);

  // Start thread managing connection / publishes / subscribes
  loop_start();

}

MqttServerWrapper::~MqttServerWrapper() {

  if (is_connected())
    disconnect();         // Disconnects 

  loop_stop();            // Kill mqtt thread
  mosqpp::lib_cleanup();  // Mosquitto library cleanup
  
}

/*********************************
    SERVER CONNECTION
*********************************/

/*
    Checks if it's connected
*/
bool MqttServerWrapper::is_connected() {

  if (connected == CONNECTED)
    return true;
  return false;
  
}

/*
    Mount header
    @ Parameters
        #h: message header
        #t: type of message
        #serial: device serial number
        #reqId: requisition ID
*/
void MqttServerWrapper::mountHeader(HeaderMessage& h, MessageType t, uint64_t serial, uint64_t reqId) {

  h.set_protocol(PROT_ID_DNP3);
  h.set_msgtype(t);
  h.set_serial(serial);
  h.set_ticket(reqId);
  h.set_gwid(gatewayID);
  
}

/*
    Dispatch upload
    @ Parameters
        #upload: message to be uploaded
*/
bool MqttServerWrapper::dispachUpload(UploadToGateway& upload) {

  // Protobuff Message Serialization
  size_t size = upload.ByteSize();
  char* msg = new char[size];
  upload.SerializeToArray(msg, size);

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << "Mensagem a ser publicada na fila config/" << gatewayID << "/tx: " << std::endl;
  std::cout << upload.DebugString() << std::endl;
#endif

  // Set topic to tx
  std::ostringstream topic;
  //topic << "gateway/" << gatewayID << "/tx";
  topic << "config/" << gatewayID << "/tx";
    
  // Publish message
  int ret = publish(NULL, topic.str().c_str(), size, msg, 1, false);

  // Free created buffer
  delete[](char*) msg;

  return (ret == MOSQ_ERR_SUCCESS);
    
}

/*********************************
    MESSAGE EVENTS
*********************************/

void MqttServerWrapper::on_disconnect(int rc) {

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << ">> MqttServerWrapper - disconnection(" << rc << ")" << std::endl;
#endif
  connected = false;
    
}

void MqttServerWrapper::on_connect(int rc) {

  if (rc == 0) {
#ifdef ENABLE_DEBUG_CONSOLE
    std::cout << ">> MqttServerWrapper - connected with server" << std::endl;
#endif
    connected = true;
    std::ostringstream topic;

    topic << "config/" << gatewayID << "/rx";
    subscribe(NULL, topic.str().c_str(), 1);

    topic.str("");
    topic << "config/" << gatewayID << "/notification";
    subscribe(NULL, topic.str().c_str(), 1);
  }
  else {
#ifdef ENABLE_DEBUG_CONSOLE
    std::cout << ">> MqttServerWrapper - Impossible to connect with server(" << rc << ")" << std::endl;
#endif
  }
    
}

/*
    Executed on a new publication
    @ Parameters
        #mid: message id
*/
void MqttServerWrapper::on_publish(int mid) {

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << ">> MqttServerWrapper - Message (" << mid-2 << ") succeed to be published " << std::endl;
#endif

}

/*
    Executed on a new message
    @ Parameters
        #message: message received
*/
void MqttServerWrapper::on_message(const struct mosquitto_message* message) {

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << "Subscriber received message of topic: " << message->topic << "\n";
#endif

  // Stores message's topic
  std::string rxtopic(message->topic);

  std::ostringstream topic;

  /*********************************
        TOPIC RX
  *********************************/
  //topic << "gateway/" << gatewayID << "/rx";
  topic << "config/" << gatewayID << "/rx";
    
  // Checks if topic is rx
  if (topic.str() == rxtopic) {

    // Converts message to UploadToGateway type (Protobuf)
    UploadToServer upload;

    if (upload.ParseFromArray(message->payload, message->payloadlen)) {

#ifdef ENABLE_DEBUG_CONSOLE
      std::cout << upload.DebugString() << std::endl;
#endif

/*
      if (upload.has_header()) {

        if (upload.has_configgwresponse())
          configEtsResponse(upload.header(), upload.configgwresponse());
        else if (upload.has_cmd()) { 
                          
          if (upload.cmd().has_digcmd())
            sendTCResponse(upload.header(), upload.cmd().digcmd());
          else if (upload.cmd().has_readclass())
            mountCmdEtsState(upload.header(), upload.cmd().readclass());
          else if (upload.cmd().has_rtccmd())
            getETSTimeCommand(upload.header(), upload.cmd().rtccmd());
          else if (upload.cmd().has_enablepoll())
            enableDisableETS(upload.header(), upload.cmd().enablepoll());
          else if (upload.cmd().has_analogcmd())
            sendACResponse(upload.header(), upload.cmd().analogcmd());
            
        }
      }
*/
    }

    return;
    
  }

  /*********************************
      TOPIC NOTIFICATIOIN
  *********************************/

  topic.str("");
  //topic << "gateway/" << gatewayID << "/notification";
  topic << "config/" << gatewayID << "/notification";
    
  // Checks if topic is notification
  if (topic.str() == rxtopic) {

    // Converts message to NotificationToServer type (Protobuf)
    NotificationToServer notification;

    if (notification.ParseFromArray(message->payload, message->payloadlen)) {
	  
#ifdef ENABLE_DEBUG_CONSOLE
      std::cout << notification.DebugString() << std::endl;
#endif

/*
      if (notification.has_header()) {

        if (notification.has_eqpstatus()) {
               
          if (notification.eqpstatus().has_timestamp() &&
              notification.eqpstatus().has_online()) {    // event

                if (notification.eqpstatus().online()) {
                  etsUp(notification.header().serial());        
                }
                else {
                  etsDown(notification.header().serial());         
                }
          }
        }

        if (notification.has_gwstatus()) {
                    
          if (notification.gwstatus().has_timestamp() &&
              notification.gwstatus().has_configured()) {
              
            setASRId(gatewayID, notification.gwstatus().configured());
            
          }
        }
      }
*/
    }

    return;
  }
}

void MqttServerWrapper::on_subscribe(int mid, int qos_count, const int* granted_qos) {

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << ">> MqttServerWrapper - Subscribe" << std::endl;  
#endif

  ++subscriptions;
  
}

/*********************************
    RX COMMANDS
*********************************/

bool MqttServerWrapper::configEts(uint64_t reqId, std::vector<TEtsListConfig>& etsConfigList) {

  if ((!connected) || (etsConfigList.size() == 0))
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  ConfigGateway* c = new ConfigGateway;

  //mountHeader(*h, MSG_TYPE_GW, 0, reqId);
  h->set_ticket(reqId);
  h->set_gwid(gatewayID);
    
  upload.set_allocated_header(h);

  for (auto el = etsConfigList.begin(); el != etsConfigList.end(); el++) {
       
    auto d = c->add_devices();
       
    // equipment data
    d->set_name(el->name);
    d->set_manufacturer(el->manufacturer);
    d->set_model(el->model);
    d->set_class_id(el->class_id);
    d->set_ug(el->ug);

    // dnp3 config
    d->mutable_dnp3_cfg()->set_outstation_id(el->dnp3_cfg.outstation_id);
    d->mutable_dnp3_cfg()->set_ip1(el->dnp3_cfg.ip1);
    d->mutable_dnp3_cfg()->set_ip2(el->dnp3_cfg.ip2);       
    d->mutable_dnp3_cfg()->set_ip3(el->dnp3_cfg.ip3);       
    d->mutable_dnp3_cfg()->set_port1(el->dnp3_cfg.port1);       
    d->mutable_dnp3_cfg()->set_port2(el->dnp3_cfg.port2);
    d->mutable_dnp3_cfg()->set_port3(el->dnp3_cfg.port3);
    d->mutable_dnp3_cfg()->set_uns_conn_token(el->dnp3_cfg.uns_conn_token);
    d->mutable_dnp3_cfg()->set_uns_addr(el->dnp3_cfg.uns_addr);
    d->mutable_dnp3_cfg()->set_master_id1(el->dnp3_cfg.master_id1);
    d->mutable_dnp3_cfg()->set_master_id2(el->dnp3_cfg.master_id2);
    d->mutable_dnp3_cfg()->set_master_id3(el->dnp3_cfg.master_id3);
    d->mutable_dnp3_cfg()->set_analog_out_point_offset(el->dnp3_cfg.analog_out_point_offset);
    d->mutable_dnp3_cfg()->set_binary_in_confirm_cmd(el->dnp3_cfg.binary_in_confirm_cmd);
    d->mutable_dnp3_cfg()->set_failure_point(el->dnp3_cfg.failure_point);
    d->mutable_dnp3_cfg()->set_dnp3_failure_point_val(el->dnp3_cfg.dnp3_failure_point_val);
    d->mutable_dnp3_cfg()->set_check_failure(el->dnp3_cfg.check_failure);
    d->mutable_dnp3_cfg()->set_dnp3_failure_point_type( (TDnp3ObjectType_) el->dnp3_cfg.dnp3_failure_point_type );
       
    // modbus config       
    d->mutable_modbus_cfg()->set_mode( (TModbusTypeConn_) el->modbus_cfg.mode );
    d->mutable_modbus_cfg()->set_port(el->modbus_cfg.port);
    //d->mutable_modbus_cfg()->set_baud_rate(el->modbus_cfg.baud_rate); //TODO:
    d->mutable_modbus_cfg()->set_num_devs(el->modbus_cfg.num_devs);
    d->mutable_modbus_cfg()->set_addr(el->modbus_cfg.addr);
    d->mutable_modbus_cfg()->set_timeout(el->modbus_cfg.timeout);
    d->mutable_modbus_cfg()->set_inter_polling(el->modbus_cfg.inter_polling);
    d->mutable_modbus_cfg()->set_intra_polling(el->modbus_cfg.intra_polling);
    d->mutable_modbus_cfg()->set_retry_timeout(el->modbus_cfg.retry_timeout);
    d->mutable_modbus_cfg()->set_retries(el->modbus_cfg.retries);                     
    d->mutable_modbus_cfg()->set_poll_trigger(el->modbus_cfg.poll_trigger);
    d->mutable_modbus_cfg()->set_ip(el->modbus_cfg.ip);
    d->mutable_modbus_cfg()->set_device(el->modbus_cfg.device);
    d->mutable_modbus_cfg()->set_address_list(el->modbus_cfg.address_list);
    d->mutable_modbus_cfg()->set_trigger_path(el->modbus_cfg.trigger_path);
    
    // class config
    d->mutable_classmap()->set_classid(el->classmap.classId);
    d->mutable_classmap()->set_typeid_(el->classmap.typeId);
    d->mutable_classmap()->set_mapid(el->classmap.mapId);
    d->mutable_classmap()->set_name(el->classmap.name);
    d->mutable_classmap()->set_version(el->classmap.version);
    d->mutable_classmap()->set_classmap_path(el->classmap.map_path);
    d->mutable_classmap()->set_classmap_description(el->classmap.map_description);
            
/*
    d->set_id(el->id);
    d->set_dnp3addr(el->dnp3Addr);
    d->set_integrityinterval(el->integrityInterval);
    d->set_class1(el->class1);
    d->set_class2(el->class2);
    d->set_class3(el->class3);
    d->set_classinterval(el->classInterval);
    d->set_timeout(el->timeout);
    d->set_offlinetimeout(el->offLineTimeout);
*/

  }

  upload.set_allocated_configgw(c);

#ifdef ENABLE_DEBUG_CONSOLE
    //std::cout << "configEts:\n"
      //        << upload.DebugString();
#endif

  return (dispachUpload(upload));
  
}

bool MqttServerWrapper::sendTC(uint64_t reqId, uint64_t serial, uint16_t point, DOType operation, uint32_t cmd_timeout, uint32_t t) {

  if (!connected)
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  DigitalCommand* d = new DigitalCommand;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);

  d->set_point(point);
  d->set_operation(operation);
  d->set_time(t);

  c->set_allocated_digcmd(d);

  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
    //std::cout << "sendTC:\n"
             // << upload.DebugString();
#endif

  return (dispachUpload(upload));
  
}

bool MqttServerWrapper::sendAC(uint64_t reqId, uint64_t serial, uint16_t point, AOType operation, uint32_t cmd_timeout, uint32_t t) {

  if (!connected)
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  AnalogCommand* d = new AnalogCommand;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);

  d->set_point(point);
  d->set_operation(operation);
  d->set_time(t);

  c->set_allocated_analogcmd(d);

  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
    //std::cout << "sendTC:\n"
             // << upload.DebugString();
#endif

  return (dispachUpload(upload));
    
}

bool MqttServerWrapper::getETSTime(uint64_t reqId, uint64_t serial) {

  if (!connected)
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  RTCCommands* r = new RTCCommands;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.mutable_cmd()->set_attempts(1);

  upload.set_allocated_header(h);

  r->set_read(true);
  c->set_allocated_rtccmd(r);
  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << "getETSTime:\n"
            << upload.DebugString();
#endif

  return (dispachUpload(upload));
    
}

bool MqttServerWrapper::configETSTime(uint64_t reqId, uint64_t serial, uint64_t rtcdata) {

  if (!connected)
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  RTCCommands* r = new RTCCommands;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);

  r->set_write(true);

  if (rtcdata != 0)
    r->set_rtcdata(rtcdata);

  c->set_allocated_rtccmd(r);
  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << "configETSTime:\n"
            << upload.DebugString();
#endif

  return (dispachUpload(upload));
    
}

bool MqttServerWrapper::enableETS(uint64_t reqId, uint64_t serial) {

  if (!connected)
    return (false);

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);
  c->set_enablepoll(true);
  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << "enableETS:\n"
            << upload.DebugString();
#endif

  return (dispachUpload(upload));
    
}

bool MqttServerWrapper::disableETS(uint64_t reqId, uint64_t serial) {

  if (!connected)
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);
  c->set_enablepoll(false);
  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
  //std::cout << "disableETS:\n"
       //     << upload.DebugString();
#endif

  return (dispachUpload(upload));
    
}

bool MqttServerWrapper::getTOChanges(uint64_t reqId, uint64_t serial) {

  if (!connected)
    return (false);

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  ReadCommandClass* rc = new ReadCommandClass;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);

  rc->set_integrity(false);
  rc->set_class1(true);
  rc->set_class2(true);
  rc->set_class3(true);

  c->set_allocated_readclass(rc);

  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << "getTOChanges:\n"
            << upload.DebugString();
#endif

  return (dispachUpload(upload));
  
}

bool MqttServerWrapper::getETSState(uint64_t reqId, uint64_t serial) {

  if (!connected)
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  ReadCommandClass* rc = new ReadCommandClass;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);

  rc->set_integrity(true);
  rc->set_class1(false);
  rc->set_class2(false);
  rc->set_class3(false);

  c->set_allocated_readclass(rc);

  upload.set_allocated_cmd(c);

#ifdef ENABLE_DEBUG_CONSOLE
  std::cout << "getETSState:\n"
            << upload.DebugString();
#endif

  return (dispachUpload(upload));
    
}

/*********************************
    MESSAGE RESPONSE COMMANDS
*********************************/

void MqttServerWrapper::configEtsResponse(const HeaderMessage& h, const ConfigGatewayResponse& gwr) {

  if (gwr.success())
    ackConfigEts(h.ticket(), gwr.numdevicescfg());
  else
    nackConfigEts(h.ticket(), gwr.numdevicescfg());
        
}

void MqttServerWrapper::ackConfigEts(uint64_t reqId, uint32_t numdevices) {
  std::cout << "ackConfigEts" << std::endl;
}

void MqttServerWrapper::nackConfigEts(uint64_t reqId, uint32_t numdevices) {
  std::cout << "nackConfigEts" << std::endl;
}

void MqttServerWrapper::getETSTimeCommand(const HeaderMessage& h, const RTCCommands& c) {

  if (c.has_write()) {
    
    if (c.write())
      ackConfigETSTime(h.ticket(), h.serial());
    else
      nackConfigETSTime(h.ticket(), h.serial());
        
  }
  else if (c.has_read()) {
    
    bool success = false;
    uint64_t rtcdata = 0;

    if (c.read() && (c.rtcdata() != 0)) {
      success = true;
      rtcdata = c.rtcdata();
    }

    if (success)
      ackRtcAnswer(h.ticket(), h.serial(), rtcdata);
    else
      nackRtcAnswer(h.ticket(), h.serial());
        
  }
    
}

void MqttServerWrapper::sendTCResponse(const HeaderMessage& h, const DigitalCommand& c) {

  if (c.has_success()) {
    
    if (c.success())
      ackTelecommand(h.ticket(), h.serial(), c.point());
    else
      nackTelecommand(h.ticket(), h.serial(), c.point());
            
  }
    
}

void MqttServerWrapper::sendACResponse(const HeaderMessage& h, const AnalogCommand& c) {

  if (c.has_success()) {
  
    if (c.success())
      ackAnalogCommand(h.ticket(), h.serial(), c.point());
    else
      nackAnalogCommand(h.ticket(), h.serial(), c.point());
      
  }
  
}

void MqttServerWrapper::ackTelecommand(uint64_t reqId, uint64_t serial, uint16_t point) {
    std::cout << "ackTelecommand" << std::endl;
}

void MqttServerWrapper::nackTelecommand(uint64_t reqId, uint64_t serial, uint16_t point) {
    std::cout << "nackTelecommand" << std::endl;
}

void MqttServerWrapper::ackAnalogCommand(uint64_t reqId, uint64_t serial, uint16_t point) {

    std::cout << "ackAnalogCommand" << std::endl;
}

void MqttServerWrapper::nackAnalogCommand(uint64_t reqId, uint64_t serial, uint16_t point) {
    std::cout << "nackAnalogCommand" << std::endl;
}

void MqttServerWrapper::MountEtsNotification(const HeaderMessage& h, const NotificationValues& v) {

  bool etsConf = true, etsUp = true, etsAlarmed = false, etsEnabled = true;

  std::vector<TEtsListObjects> values;
  values.clear();

  if (v.alarmlist_size()) {
  
    etsAlarmed = true;
    for (auto rx : v.alarmlist()) {
    
      if (rx.objvalues_size()) {
      
        TEtsListObjects list;
        list.objType = rx.objtype();
        list.alarmObjects.clear();
        list.staticObjects.clear();
        for (auto rxval : rx.objvalues()) {
        
          TEtsListObjectsValues itemval;
          if (rxval.has_timestamp())
            itemval.timestamp = rxval.timestamp();
          else
            itemval.timestamp = 0;

          itemval.point = rxval.point();

          if (list.objType == OBJ_TYPE_ANALOG_INPUT)
            itemval.value = rxval.fvalue();
          else
            itemval.value = rxval.ivalue();
            
          itemval.online = false;
          if (rxval.has_online())
            itemval.online = rxval.online();

          list.alarmObjects.push_back(itemval);
          
        }
        
        values.push_back(list);
        
      }
    }
  }

  if (v.staticlist_size()) {
  
    for (auto rx : v.staticlist()) {
    
      if (rx.objvalues_size()) {
      
        TEtsListObjects list;
        list.objType = rx.objtype();
        list.alarmObjects.clear();
        list.staticObjects.clear();
        
        for (auto rxval : rx.objvalues()) {
        
          TEtsListObjectsValues itemval;
          itemval.timestamp = 0;
          itemval.online = 0;
          itemval.point = rxval.point();
          
          if ((list.objType == OBJ_TYPE_ANALOG_INPUT) || (list.objType == OBJ_TYPE_ANALOG_OUTPUT))
            itemval.value = rxval.fvalue();
          else
            itemval.value = rxval.ivalue();
            
          if (rxval.has_online())
            itemval.online = rxval.online();

          list.staticObjects.push_back(itemval);
          
        }
        
        values.push_back(list);
        
      }
    }
  }
  
  reportETSState(h.ticket(), h.serial(),
                 etsConf, etsUp, etsAlarmed, etsEnabled,
                 values);

  for (auto v : values) {
  
    v.staticObjects.clear();
    v.alarmObjects.clear();
    
  }
  values.clear();
  
}

void MqttServerWrapper::mountCmdEtsState(const HeaderMessage& h, const ReadCommandClass& c) {

  bool etsConf = true, etsUp = true, etsAlarmed = false, etsEnabled = true;

  std::vector<TEtsListObjects> values;
  values.clear();

  if (c.classvalues_size()) {

    etsAlarmed = true;

    for (auto rx : c.classvalues()) {

      if (rx.objvalues_size()) {

        TEtsListObjects list;

        list.objType = rx.objtype();
        list.alarmObjects.clear();
        list.staticObjects.clear();

        for (auto rxval : rx.objvalues()) {

          TEtsListObjectsValues itemval;

          if (rxval.has_timestamp())
            itemval.timestamp = rxval.timestamp();
          else
            itemval.timestamp = 0;

          itemval.point = rxval.point();

          if (list.objType == OBJ_TYPE_ANALOG_INPUT)
            itemval.value = rxval.fvalue();
          else
            itemval.value = rxval.ivalue();

          itemval.online = false;

          if (rxval.has_online())
            itemval.online = rxval.online();

          list.alarmObjects.push_back(itemval);
          
        }

        values.push_back(list);
        
      }
    }
  }

  if (c.integrityvalues_size()) {

    for (auto rx : c.integrityvalues()) {

      if (rx.objvalues_size()) {

        TEtsListObjects list;
        list.objType = rx.objtype();
        list.alarmObjects.clear();
        list.staticObjects.clear();

        for (auto rxval : rx.objvalues()) {

          TEtsListObjectsValues itemval;
          itemval.timestamp = 0;
          itemval.online = 0;
          itemval.point = rxval.point();

          if ((list.objType == OBJ_TYPE_ANALOG_INPUT) || (list.objType == OBJ_TYPE_ANALOG_OUTPUT))
            itemval.value = rxval.fvalue();
          else
            itemval.value = rxval.ivalue();

          if (rxval.has_online())
            itemval.online = rxval.online();

          list.staticObjects.push_back(itemval);
          
        }

        values.push_back(list);
        
      }
    }
  }

  reportETSState(h.ticket(), h.serial(),
                 etsConf, etsUp, etsAlarmed, etsEnabled,
                 values);

  for (auto v : values) {

    v.staticObjects.clear();
    v.alarmObjects.clear();
  }

  values.clear();
  
}

void MqttServerWrapper::reportETSState(uint64_t reqId, uint64_t serial, bool etsConf, bool etsUp,
                                       bool etsAlarmed, bool etsEnabled, std::vector<TEtsListObjects> values) {
  std::cout << "reportETSState" << std::endl;
}

bool MqttServerWrapper::keepAlive() {

  UploadToGateway upload;                   

  HeaderMessage* h = new HeaderMessage;     
  CheckGateway* c = new CheckGateway;       

  mountHeader(*h, MSG_TYPE_USER, 0, 12345); 

  upload.set_allocated_header(h);

  c->set_isalive(true);

  upload.set_allocated_checkgw(c);

  std::cout << "Enviando KeepAlive() para o GW" << std::endl;
  
  return(dispachUpload(upload)); 

}

void MqttServerWrapper::ackConfigETSTime(uint64_t reqId, uint64_t serial) {
  std::cout << "ackConfigETSTime" << std::endl;
}

void MqttServerWrapper::nackConfigETSTime(uint64_t reqId, uint64_t serial) {
  std::cout << "nackConfigETSTime" << std::endl;
}

void MqttServerWrapper::ackRtcAnswer(uint64_t reqId, uint64_t serial, uint64_t timeStamp) {
  std::cout << "ackRtcAnswer" << std::endl;
}

void MqttServerWrapper::nackRtcAnswer(uint64_t reqId, uint64_t serial) {
  std::cout << "nackRtcAnswer" << std::endl;
}

void MqttServerWrapper::enableDisableETS(const HeaderMessage& h, bool op) {

  if (op)
    ackEnableETS(h.ticket(), h.serial());
  else
    ackDisableETS(h.ticket(), h.serial());
        
}

void MqttServerWrapper::ackEnableETS(uint64_t reqId, uint64_t serial) {
  std::cout << "ackEnableETS" << std::endl;
}

void MqttServerWrapper::ackDisableETS(uint64_t reqId, uint64_t serial) {
  std::cout << "ackDisableETS" << std::endl;
}

void MqttServerWrapper::etsUp(uint64_t serial) {
  std::cout << "etsUp" << std::endl;
}

void MqttServerWrapper::etsDown(uint64_t serial) {
  std::cout << "etsDown" << std::endl;
}

void MqttServerWrapper::setASRId(uint64_t gwid, bool configured) {
  std::cout << "setASRId" << std::endl;
}

void MqttServerWrapper::sssFailure() {
  std::cout << "sssFailure" << std::endl;
}

bool MqttServerWrapper::sendLoggerCommand(uint64_t reqId, uint64_t serial, bool operation) {
    
  if (!connected)
    return (false);

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  LoggerCommand* d = new LoggerCommand;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);

  d->set_log_state(operation);

  c->set_allocated_logcmd(d);

  upload.set_allocated_cmd(c);

  return (dispachUpload(upload));
  
}

bool MqttServerWrapper::sendEtsStatusRequest(uint64_t reqId, uint64_t serial) {
    
  if (!connected)
    return (false);

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  EquipmentStatus* c = new EquipmentStatus;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  upload.set_allocated_eqpstatus(c);

  return (dispachUpload(upload));
  
}

bool MqttServerWrapper::sendThreadCommand(uint64_t reqId, uint64_t serial, ThrCmdType operation) {

  if (!connected)
    return false;

  UploadToGateway upload;

  HeaderMessage* h = new HeaderMessage;
  Commands* c = new Commands;
  ThreadCommand* d = new ThreadCommand;

  mountHeader(*h, MSG_TYPE_USER, serial, reqId);
  upload.set_allocated_header(h);

  c->set_attempts(1);
  d->set_operation(operation);

  c->set_allocated_threadcmd(d);

  upload.set_allocated_cmd(c);

  return (dispachUpload(upload));
  
}
