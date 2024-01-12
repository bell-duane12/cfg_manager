#ifndef TESTE_COMUNICACAO_H
#define TESTE_COMUNICACAO_H

#include <mosquittopp.h>

#include "../protobuf_api/out/command.pb.h"
#include "../protobuf_api/out/config.pb.h"
#include "../protobuf_api/out/header.pb.h"
#include "../protobuf_api/out/messages.pb.h"
#include "../protobuf_api/out/objects.pb.h"

#include <string>

#define ENABLE_DEBUG_CONSOLE 1
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"

typedef enum {
  OBJ_BINARY = 1,
  OBJ_COUNTER = 2,
  OBJ_ANALOG = 3,
  OBJ_COMMAND = 4,
  OBJ_REGULATION = 5,
  OBJ_NONE = 6,
} TDnp3ObjectType;

typedef struct {
  unsigned int dnp3_seq;
  unsigned int outstation_id;
  std::string ip1;
  std::string ip2;
  std::string ip3;
  unsigned int port1;
  unsigned int port2;
  unsigned int port3;
  unsigned int uns_conn_token;
  unsigned int uns_addr;
  unsigned int master_id1;
  unsigned int master_id2;
  unsigned int master_id3;
  unsigned int analog_out_point_offset;
  unsigned int binary_in_confirm_cmd;
  unsigned int failure_point;
  int dnp3_failure_point_val;
  bool check_failure;
  TDnp3ObjectType dnp3_failure_point_type;
  unsigned int equip_id;
} TDnp3Parms;

// Tambem pode pegar do banco, pra ficar mais generico
typedef enum {
  TCP = 1,
  RTU = 2,
  RTU_TCP = 3,
} TModbusTypeConn;

typedef struct {
  unsigned int modbus_seq;
  TModbusTypeConn mode;
  unsigned int port;
  /*unsigned int*/ std::string baud_rate;
  unsigned int num_devs;
  unsigned int addr;
  unsigned int timeout;
  unsigned int inter_polling;
  unsigned int intra_polling;
  unsigned int retry_timeout;
  unsigned int retries;
  unsigned int poll_trigger;
  std::string ip;
  std::string device;
  std::string address_list;
  std::string trigger_path;
  unsigned int equip_id;
} TModbusParms;

typedef struct {

  std::string version;
  unsigned int classId;
  unsigned int typeId;
  unsigned int mapId;
  std::string name;
  std::string map_path;
  std::string map_description;
  
} TEtsClass;

typedef struct {

  std::string name;
  std::string manufacturer;
  std::string model;
  unsigned int class_id;
  unsigned int ug;
  TModbusParms modbus_cfg;
  TDnp3Parms dnp3_cfg;
  TEtsClass classmap;   
                
/*
    uint64_t id;
    uint32_t dnp3Addr;
    uint32_t integrityInterval;
    bool class1;
    bool class2;
    bool class3;
    uint32_t classInterval;
    uint32_t timeout;
    uint32_t offLineTimeout;
*/
} TEtsListConfig;

typedef struct {
  std::string ip;
  unsigned int port;      
  std::string  user;  
  std::string  password; 
  unsigned int gateway_id;
  unsigned int keepalive; 
  unsigned int pubInterval;
} TBrokerConfig;

typedef struct
{

    uint32_t point;
    float value;
    uint64_t timestamp;
    bool online;

} TEtsListObjectsValues;

typedef struct
{

    ObjType objType;
    std::vector<TEtsListObjectsValues> alarmObjects;
    std::vector<TEtsListObjectsValues> staticObjects;

} TEtsListObjects;

class MqttServerWrapper : public mosqpp::mosquittopp
{

    /*********************************
        BASIC INFO FROM CONNECTION
    *********************************/

public:
    typedef enum : int
    {
        
        NOT_CONNECTED = 0,
        CONNECTED,
        COULD_NOT_CONNECT

    } CONNECTION;

private:
    const char *id;     // Subscriber ID
    const char *host;   // Host
    int port;           // Port
    int keepalive;      // The number of seconds after which the broker should send a PING message
                        // to the client if no other messages have been exchanged in that time.
    const char *user;   // User
    const char *passw;  // Password
    uint64_t gatewayID; // Gateway ID

    int connected; // Connected to server. 0 not connected
    int subscriptions;  // Number of subscriptions


    /*********************************
        USER COMMANDS
    *********************************/
   
public:
    bool is_connected();

    /*********************************
        BROKER EVENTS
    *********************************/

private:
    // Executes on connection
    void on_connect(int rc);

    // Executes on disconnection
    void on_disconnect(int rc);

    // Executes on a publication
    void on_publish(int mid);

    // Execute on a subscribe
    void on_subscribe(int mid, int qos_count, const int *granted_qos);

    // Executes on a new message
    void on_message(const struct mosquitto_message *message);

    /*********************************
        PROTOBUF PREPARE DATA
    *********************************/
    // Mounts header
    void mountHeader(HeaderMessage &h, MessageType, uint64_t serial, uint64_t reqId);

    // Dispachs Upload
    bool dispachUpload(UploadToGateway &upload);

public:
    // Class Constructor
    MqttServerWrapper(const char *_host, const int &_port,
                                     const char *_user, const char *_passw,
                                     const uint64_t &_gatewayID);

    // Class Destructor
    ~MqttServerWrapper();

    /*********************************
        MESSAGE SEND COMMANDS
    *********************************/

public:
    bool configEts(uint64_t reqId, std::vector<TEtsListConfig> &etsConfigList);
    bool sendTC(uint64_t reqId, uint64_t serial, uint16_t point, DOType operation, uint32_t cmd_timeout, uint32_t t = 0);
    bool sendAC(uint64_t reqId, uint64_t serial, uint16_t point, AOType operation, uint32_t cmd_timeout, uint32_t t = 0);
    bool getETSTime(uint64_t reqId, uint64_t serial);
    bool configETSTime(uint64_t reqId, uint64_t serial, uint64_t rtcdata = 0);
    bool enableETS(uint64_t reqId, uint64_t serial);
    bool disableETS(uint64_t reqId, uint64_t serial);
    bool getTOChanges(uint64_t reqId, uint64_t serial);
    bool getETSState(uint64_t reqId, uint64_t serial);
    
    bool sendLoggerCommand(uint64_t reqId, uint64_t serial, bool operation);
    bool sendEtsStatusRequest(uint64_t reqId, uint64_t serial);
    bool sendThreadCommand(uint64_t reqId, uint64_t serial, ThrCmdType operation);
    /*********************************
        MESSAGE RESPONSE COMMANDS
    *********************************/

    /* ---------- */
private:
    void configEtsResponse(const HeaderMessage &h, const ConfigGatewayResponse &gwr);

protected:
    void ackConfigEts(uint64_t reqId, uint32_t numdevices);
    void nackConfigEts(uint64_t reqId, uint32_t numdevices);

    /* ---------- */
private:
    void sendTCResponse(const HeaderMessage &h, const DigitalCommand &c);
    void sendACResponse(const HeaderMessage &h, const AnalogCommand &c);

protected:
    void ackTelecommand(uint64_t reqId, uint64_t serial, uint16_t point);
    void nackTelecommand(uint64_t reqId, uint64_t serial, uint16_t point);
    void ackAnalogCommand(uint64_t reqId, uint64_t serial, uint16_t point);
    void nackAnalogCommand(uint64_t reqId, uint64_t serial, uint16_t point);

    /* ---------- */
private:
    void mountCmdEtsState(const HeaderMessage &h, const ReadCommandClass &c);
    void MountEtsNotification(const HeaderMessage &h, const NotificationValues &v);

protected:
    void reportETSState(uint64_t reqId, uint64_t serial, bool etsConf, bool etsUp,
                               bool etsAlarmed, bool etsEnabled, std::vector<TEtsListObjects> values);

    /* ---------- */
private:
    void getETSTimeCommand(const HeaderMessage &h, const RTCCommands &c);

protected:
    void ackConfigETSTime(uint64_t reqId, uint64_t serial);
    void nackConfigETSTime(uint64_t reqId, uint64_t serial);
    void ackRtcAnswer(uint64_t reqId, uint64_t serial, uint64_t timeStamp);
    void nackRtcAnswer(uint64_t reqId, uint64_t serial);

    /* ---------- */
private:
    void enableDisableETS(const HeaderMessage &h, bool op);

protected:
    void ackEnableETS(uint64_t reqId, uint64_t serial);
    void ackDisableETS(uint64_t reqId, uint64_t serial);

    /* ---------- */
public:
    void etsUp(uint64_t serial);

    /* ---------- */
public:
    void etsDown(uint64_t serial);

    /* ---------- */
public:
    void setASRId(uint64_t gwid, bool configured);

    /* ---------- */
public:
    void sssFailure();
    bool keepAlive();
};

#endif // TESTE_COMUNICACAO_H
