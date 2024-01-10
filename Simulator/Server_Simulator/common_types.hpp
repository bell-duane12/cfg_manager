
#ifndef _COMMON_TYPES_HPP_
#define _COMMON_TYPES_HPP_


#include <vector>
#include <string>

// Common definitions .

typedef struct {
  std::string ip;
  unsigned int port;      
  std::string  user;  
  std::string  password; 
  unsigned int gateway_id;
  unsigned int keepalive; 
  unsigned int pubInterval;
} TBrokerConfig;

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
} TDnp3Configr;

typedef enum {
  RTU = 1,
  TCP = 2,
  RTU_TCP = 3,
} TModbusTypeConn;

typedef struct {
  unsigned int modbus_seq;
  TModbusTypeConn mode;
  unsigned int port;
  unsigned int baud_rate;
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
} TModbusConfig;

typedef struct {
  unsigned int map_seq;
  unsigned int mapId;
  std::string map_description; 
  std::string map_path; 
} TEtsClassMap;

typedef struct {
  unsigned int class_seq;
  unsigned int classId;
  unsigned int typeId;
  std::string name;
  std::string version;
  unsigned int mapId;
  std::string map_description; 
  std::string map_path; 
} TEtsClass;

typedef struct {
  unsigned int seq;
  unsigned int equipId;
  std::string name;
  std::string manufacturer;
  std::string model;
  unsigned int class_id;
  unsigned int ug;
  TModbusConfig modbus_cfg;
  TDnp3Configr dnp3_cfg;
  TEtsClass classmap;
} TEtsConfig;

typedef enum {
  ONN = 1,      // Thread on e equipamento respondendo
  OFFF = 2,     // Thread on, mas equipamento não responde
  STOPPED = 3,  // Thread parada 
} TEtsThreadStatus;

#endif
