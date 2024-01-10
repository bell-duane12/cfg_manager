
#include "dnp3_modbus_relay_config_manager.hpp"
#include "dnp3_modbus_types.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <system_error>


using namespace std;


Dnp3_Modbus_Relay_Config_Manager::Dnp3_Modbus_Relay_Config_Manager(const std::string cfg_filename):
  cfg_reader(cfg_filename) {
  
  cout << "Configuration loaded from '"  << cfg_filename << "': version = "
       << cfg_reader.Get("classmap","version","unknown") << endl << endl;
   
   
  if(!load_modbus_cfg_from_file())
    throw std::runtime_error("Unable to load Modbus configuration from config file");
  cout << "Modbus configuration loaded..." << endl;
  if(!load_modbus_poller_cfg_from_file())
    throw std::runtime_error("Unable to load Modbus poller configuration from config file");
  cout << "Poller configuration loaded..." << endl;
  if(!load_dnp3_cfg_from_file())
    throw std::runtime_error("Unable to load DNP3 configuration from config file");
  cout << "Dnp3 configuration loaded..." << endl;
/*
  if(!load_broker_cfg_from_file()) {
    //throw std::system_error();
    broker_config.gateway_id = 0;
  }
  cout << "Broker configuration loaded..." << endl; 
*/
  if (!load_failure_cfg_from_file()) {
    failure_config.Enabled = false;
  }
  cout << "Failure configuration loaded..." << endl;  
  if (!load_classmap_cfg_from_file()) 
    throw std::runtime_error("Unable to load Classmap configuration from config file");
  cout << "Classmap configuration loaded..." << endl;    
  if (!load_equipment_cfg_from_file()) 
    throw std::runtime_error("Unable to load Equipment configuration from config file");
  cout << "Equipment configuration loaded..." << endl;    
}

bool Dnp3_Modbus_Relay_Config_Manager::load_modbus_cfg_from_file() {

  uint8_t idx;
  string _addList;
  string token;
  string delim2 = ",";
  string delim3 = ";";
  size_t pos = 0;
  bool done = false;
  
  //Se o modo é TCP, carrega IP e porta para conexão
  std::string type = cfg_reader.Get("modbus", "mode", "invalid");
  if (type.compare("TCP") == 0) {
    modbus_config.type = mTCP;
    modbus_config.ip = cfg_reader.Get("modbus", "ip", "error");
    if (modbus_config.ip.compare("error") == 0)
      return false;
    modbus_config.port = cfg_reader.Get("modbus", "port", "error");
    if (modbus_config.port.compare("error") == 0)
      return false;
  }
  else if (type.compare("RTU") == 0) {
    modbus_config.type = mRTU;
    modbus_config.device = cfg_reader.Get("modbus", "device", "error");
    if (modbus_config.device.compare("error") == 0)
      return false;
    modbus_config.baud = cfg_reader.Get("modbus", "baud", "error");
    if (modbus_config.baud.compare("error") == 0)
      return false;
  }
  else if (type.compare("RTU_TCP") == 0) {
    modbus_config.type = mRTU_TCP;
    modbus_config.ip = cfg_reader.Get("modbus", "ip", "error");
    if (modbus_config.ip.compare("error") == 0)
      return false;
    modbus_config.port = cfg_reader.Get("modbus", "port", "error");
    if (modbus_config.port.compare("error") == 0)
      return false;
  }
  else
    return false;
  
  //Carrega o endereço slave modbus (não obrigatório quando o modo é TCP)
  modbus_config.address = cfg_reader.GetInteger("modbus", "address", -1);
  if (modbus_config.address < 1)
    return false;

  //Carrega o numero de dispositivos no barramento
  modbus_config.numDevs = cfg_reader.GetInteger("modbus", "numDevs", -1);
  if ((modbus_config.numDevs < 1) || (modbus_config.numDevs > MAX_MODBUS_DEVICES))
    return false;

  //TODO:    
/*  
  //Carrega a lista de endereeços modbus do barramento
  for (idx = 0; idx < modbus_config.numDevs; idx++)
    modbus_config.addressList[idx] = modbus_config.address + idx;
  _addList = cfg_reader.Get("modbus", "addressList", "error");
  if (_addList.compare("error") != 0) {

    cout << "Address list: " << _addList << endl;
    idx = 0;
    while ((idx < modbus_config.numDevs) && (!done)) {
      //Populando o mapa de endereços Modbus
      pos = _addList.find(delim2);
      if (pos != std::string::npos) {
        token = _addList.substr(0, pos);
        modbus_config.addressList[idx] = stoul(token);
        _addList.erase(0, pos + delim2.length());
        cout << "address[" << idx << "]: " << modbus_config.addressList[idx] << endl;
        idx++;
      }
      else {
        pos = _addList.find(delim3);
        if (pos != std::string::npos) {
          token = _addList.substr(0, pos);
          modbus_config.addressList[idx] = stoul(token);
          cout << "address[" << idx << "]: " << modbus_config.addressList[idx] << endl;
          idx++;
        }
        done = true;
      }
    }
  }
*/  
  modbus_config.timeout = cfg_reader.GetReal("modbus", "timeout", 1);
  if ((modbus_config.timeout == 0) || (modbus_config.timeout > 10))
    modbus_config.timeout = 0.750;
  
  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_modbus_poller_cfg_from_file() {

  modbus_poller_config.inter_polling = cfg_reader.GetInteger("modbus_poller", "InterPolling", -1);
  if (modbus_poller_config.inter_polling < 0)
    return false;
  modbus_poller_config.intra_polling = cfg_reader.GetInteger("modbus_poller", "IntraPolling", -1);
  if (modbus_poller_config.intra_polling < 0)
    return false;
  modbus_poller_config.retry_timeout = cfg_reader.GetInteger("modbus_poller", "RetryTimeout", -1);
  if (modbus_poller_config.retry_timeout < 0)
    return false;
  modbus_poller_config.retries = cfg_reader.GetInteger("modbus_poller", "Retries", -1);
  if (modbus_poller_config.retries < 0)
    return false;
  modbus_poller_config.poll_Semaphore = cfg_reader.GetBoolean("modbus_poller", "PollTrigger", false);
  modbus_poller_config.semaphore_FileName = cfg_reader.Get("modbus_poller", "TriggerFileName", "error");
  if ((modbus_poller_config.semaphore_FileName.compare("error") == 0) && (modbus_poller_config.poll_Semaphore == true))
    return false;

  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_dnp3_cfg_from_file() {

  //OBS: GetFields retorna os campos de uma seção em ordem alfabética
  auto dnp3_fields = cfg_reader.GetFields("dnp3");
/*
  //Carrega parte comum da configuração (igual para todas as instâncias DNP3)
  dnp3_device_config.DllTimeout = cfg_reader.GetInteger("dnp3", "DllTimeout", 3000);
  dnp3_device_config.AppTimeout = cfg_reader.GetInteger("dnp3", "AppTimeout", 10000);
  dnp3_device_config.SelectOperateTimeout = (Dnp3Uchar) cfg_reader.GetInteger("dnp3", "SelectOperateTimeout", 10);
  dnp3_device_config.Dnp3ClockAdjust = cfg_reader.GetInteger("dnp3", "Dnp3ClockAdjust", 1440);
  dnp3_device_config.Dnp3InterFrame = cfg_reader.GetInteger("dnp3", "Dnp3InterFrame", 0);
  dnp3_device_config.Dnp3EventBufsize = cfg_reader.GetInteger("dnp3", "Dnp3EventBufsize", 0);
  dnp3_device_config.UnsCtrl = (TUnsCtrl) cfg_reader.GetInteger("dnp3", "UnsCtrl", 0);
  dnp3_device_config.Class1MinimalEventsNumber = cfg_reader.GetInteger("dnp3", "Class1MinimalEventsNumber", 1);
  dnp3_device_config.Class2MinimalEventsNumber = cfg_reader.GetInteger("dnp3", "Class2MinimalEventsNumber", 10);
  dnp3_device_config.Class3MinimalEventsNumber = cfg_reader.GetInteger("dnp3", "Class3MinimalEventsNumber", 10);
  dnp3_device_config.UnsAppRetry = cfg_reader.GetInteger("dnp3", "UnsAppRetry", 20);
  dnp3_device_config.UnsAppTimeout = cfg_reader.GetInteger("dnp3", "UnsAppTimeout", 5000);
  dnp3_device_config.WDDnp3.Dnp3TX = cfg_reader.GetInteger("dnp3", "WDDnp3.Dnp3TX", 0);
  dnp3_device_config.WDDnp3.Dnp3RX = cfg_reader.GetInteger("dnp3", "WDDnp3.Dnp3RX", 0);
  dnp3_device_config.WDDnp3.PolTX = cfg_reader.GetInteger("dnp3", "WDDnp3.PolTX", 0);
  dnp3_device_config.WDDnp3.PolRX = cfg_reader.GetInteger("dnp3", "WDDnp3.PolRX", 0);
  dnp3_device_config.WDDnp3.Dnp3_Disparado_timer  = cfg_reader.GetInteger("dnp3", "WDDnp3.Dnp3_Disparado_timer ", 0);
  dnp3_device_config.WDDnp3.Dnp3_Disparado_count = cfg_reader.GetInteger("dnp3", "WDDnp3.Dnp3_Disparado_count", 0);
*/  
//  dnp3_device_config.DigitalInputClass = cfg_reader.GetInteger("dnp3", "DigitalInputClass", 0);
//  dnp3_device_config.DigitalCounterClass = cfg_reader.GetInteger("dnp3", "DigitalCounterClass", 0);
  dnp3_device_config.Dnp3AnalogOutputPointOffsset = cfg_reader.GetInteger("dnp3","AnalogOutputPointOffset",0);
  dnp3_device_config.Dnp3BinaryInputConfirmCommand = cfg_reader.GetInteger("dnp3","BinaryInputConfirmCommand",1);
  dnp3_device_config.Dnp3SlaveAddress = cfg_reader.GetInteger("dnp3", "slaveId", 0);
  dnp3_device_config.Dnp3UnsolicitedAddress = cfg_reader.GetInteger("dnp3", "Dnp3UnsolicitedAddress", 0);
  
//  dnp3_device_config.Connection1.ip = cfg_reader.Get("dnp3", "IP1", "error");
//  dnp3_device_config.Connection1.port = cfg_reader.GetInteger("dnp3", "port1", -1);
//  dnp3_device_config.Connection2.ip = cfg_reader.Get("dnp3", "IP2", "error");
//  dnp3_device_config.Connection2.port = cfg_reader.GetInteger("dnp3", "port2", -1);
  

  //conferindo se há o mesmo número de IPs, portas e masterIDs
  std::set<std::string> tokens_set; //< Tokens numéricos para contagem dos labels comuns 
  for (auto field : dnp3_fields) {
    //TDnp3MasterServer dnp3_master_server;
    if (field.compare(0, 2, "IP") == 0) {
      //armazena no set todos os tokens do campo 'IP', para verificação se há
      //correspondência com os dos campos seguintes ('masterID' e 'port')
      tokens_set.insert(field.substr(field.size()-1));
    }
    else if (field.compare(0, 8, "masterID") == 0) {
      std::string token = field.substr(field.size()-1);
      //Se o token corrente de 'masterID' não está no set inicial, gera exceção
      if (tokens_set.find(token) == tokens_set.end())
        throw std::system_error();
    }
    else if (field.compare(0, 4, "port") == 0) {
      std::string token = field.substr(field.size()-1);
      //Se o token corrente de 'port' não está no set inicial, gera exceção
      if (tokens_set.find(token) == tokens_set.end())
        throw std::system_error();
    }
  }

  //Carregamento dos dados das conexões a partir do arquivo de configuração
  std::map<std::string, TDnp3MasterConnectionData> dnp3_connections_map;
  for (auto token : tokens_set)  {

    TDnp3MasterConnectionData conn;
    conn.unsolicited_enabled = false;

    for (auto field : dnp3_fields) {
      if(field.compare(0, 3, "IP" + token) == 0)
        conn.ip = cfg_reader.Get("dnp3", field, "error");
      else if (field.compare(0, 9, "masterID" + token) == 0)
        conn.master_addr = cfg_reader.GetInteger("dnp3", field, -1);
      else if (field.compare(0, 5, "port" + token) == 0)
        conn.port = cfg_reader.GetInteger("dnp3", field, -1);
    }
    dnp3_connections_map[token] = conn;
  }
  
  //Busca no arquivo de configuração qual o token identificador da conexão
  //responsável por gerar unsolicited messages e verifica se é válido
  auto unsolicited_conn_token = cfg_reader.Get("dnp3", "UnsolicitedConnectionToken", "error");
  if (tokens_set.find(unsolicited_conn_token) == tokens_set.end())
    throw std::system_error();
  
  //Procura token de unsolicited nas conexões possíveis
  auto it = dnp3_connections_map.find(unsolicited_conn_token);
  if (it != dnp3_connections_map.end())
    it->second.unsolicited_enabled = true;
  else //Se o token informado não bater com o de nenhuma conexão, ele era inválido
    throw std::system_error();

  dnp3_connections_data.reserve(dnp3_connections_map.size());
  for (auto it=dnp3_connections_map.begin(); it != dnp3_connections_map.end(); ++it) {
    dnp3_connections_data.push_back(it->second);
  }

  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_failure_cfg_from_file() {

  string type;
  
  failure_config.Enabled = cfg_reader.GetBoolean("Failure","CheckFailure",false);
  type = cfg_reader.Get("Failure","Dnp3FailurePointType","error");
  if (type.compare("OBJ_BINARY") == 0)
    failure_config.data.type = BIN_INPUT;
  else if (type.compare("OBJ_COUNTER") == 0)
    failure_config.data.type = BIN_COUNTER;
  else if (type.compare("OBJ_ANALOG") == 0)
    failure_config.data.type = ANA_INPUT;
  else
    failure_config.data.type = _NONE;
  failure_config.data.point = cfg_reader.GetInteger("Failure","Dnp3FailurePoint",-1);
  failure_config.data.value = cfg_reader.GetInteger("Failure","Dnp3FailurePointValue",-1);
  return true;
  
}

TModbusSlaveConfig Dnp3_Modbus_Relay_Config_Manager::get_modbus_slave_config() {
  return modbus_config;
}

TModbusPollerConfig Dnp3_Modbus_Relay_Config_Manager::get_modbus_poller_config() {
  return modbus_poller_config;
}

uint16_t Dnp3_Modbus_Relay_Config_Manager::get_dnp3_slave_address() {
  return dnp3_device_config.Dnp3SlaveAddress;
}

TDnp3Config Dnp3_Modbus_Relay_Config_Manager::get_dnp3_device_config() {
  return dnp3_device_config;
}

unsigned int Dnp3_Modbus_Relay_Config_Manager::get_dnp3_connections_count() {
  return dnp3_connections_data.size();
}

std::vector<TDnp3MasterConnectionData> Dnp3_Modbus_Relay_Config_Manager::get_dnp3_connections_data() {
  return dnp3_connections_data;
}

TBrokerConfig Dnp3_Modbus_Relay_Config_Manager::get_broker_config() {
  return broker_config;
}

TFailureConfig Dnp3_Modbus_Relay_Config_Manager::get_failure_config() {
  return failure_config;
}

TEtsListConfig Dnp3_Modbus_Relay_Config_Manager::get_equipment_and_class_config() {
  return equipment_and_class_config;
}

bool Dnp3_Modbus_Relay_Config_Manager::load_broker_cfg_from_file() {

  broker_config.gateway_id = cfg_reader.GetInteger("broker", "id", -1);
  if (broker_config.gateway_id < 0)
    return false;
  broker_config.ip = cfg_reader.Get("broker", "ip", "error");
  if (broker_config.ip.compare("error") == 0)
    return false;
  broker_config.port = cfg_reader.GetInteger("broker", "port", -1);
  if (broker_config.port < 0)
    return false;
  broker_config.user = cfg_reader.Get("broker", "user", "error");
  if (broker_config.user.compare("error") == 0)
    return false;
  broker_config.password = cfg_reader.Get("broker", "passwd", "error");
  if (broker_config.password.compare("error") == 0)
    return false;
  broker_config.keepalive = cfg_reader.GetInteger("broker", "keepalive", -1);
  if (broker_config.keepalive < 0)
    return false;
  broker_config.pubInterval = cfg_reader.GetInteger("broker", "publishInterval", -1);
  if (broker_config.pubInterval < 0)
    broker_config.pubInterval = 60;

  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_classmap_cfg_from_file() {

  equipment_and_class_config.classmap.version = cfg_reader.Get("classmap", "version", "error");
  if (equipment_and_class_config.classmap.version.compare("error") == 0)
    return false;
  equipment_and_class_config.classmap.classId = cfg_reader.GetInteger("classmap", "classId", 0);
  equipment_and_class_config.class_id = equipment_and_class_config.classmap.classId;
  if (equipment_and_class_config.classmap.classId == 0)
    return false;
  equipment_and_class_config.classmap.typeId = cfg_reader.GetInteger("classmap", "typeId", 0);
  if (equipment_and_class_config.classmap.typeId == 0)
    return false;
  equipment_and_class_config.classmap.mapId = cfg_reader.GetInteger("classmap", "mapId", 0);
  if (equipment_and_class_config.classmap.mapId == 0)
    return false;
  equipment_and_class_config.classmap.name = cfg_reader.Get("classmap", "name", "error");
  if (equipment_and_class_config.classmap.name.compare("error") == 0)
    return false;
  equipment_and_class_config.classmap.map_path = cfg_reader.Get("classmap", "map_path", "error");
  if (equipment_and_class_config.classmap.map_path.compare("error") == 0)
    return false;
  equipment_and_class_config.classmap.map_description = cfg_reader.Get("classmap", "map_description", "error");
  if (equipment_and_class_config.classmap.map_description.compare("error") == 0)
    return false;

  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_equipment_cfg_from_file() {

  equipment_and_class_config.name = cfg_reader.Get("equipment", "name", "error");
  if (equipment_and_class_config.name.compare("error") == 0)
    return false;
  equipment_and_class_config.manufacturer = cfg_reader.Get("equipment", "manufacturer", "error");
  if (equipment_and_class_config.manufacturer.compare("error") == 0)
    return false;
  equipment_and_class_config.model = cfg_reader.Get("equipment", "model", "error");
  if (equipment_and_class_config.model.compare("error") == 0)
    return false;
  equipment_and_class_config.ug = cfg_reader.GetInteger("equipment", "ug", 0);
  if (equipment_and_class_config.ug == 0)
    return false;


  return true;
  
}


