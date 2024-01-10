#include <iostream>
#include <utility>

#include "srv.h"
#include "dnp3_modbus_relay_config_manager.hpp"

int main(int argc, char* argv[]) {

  if(argc != 6) {

    std::cout << "[ERROR] Argument read error (./exec host port user password gateway_id)\n";
    return 1;

  }

  MqttServerWrapper c(argv[1], atoi(argv[2]), argv[3], argv[4], atoi(argv[5]));

  Dnp3_Modbus_Relay_Config_Manager("utr3288io.cfg");

/*
  std::vector<TEtsListConfig> etsConfigList(22); // 22 devices
  //std::vector<TEtsListConfig> etsConfigList(1); // 1 device

  // InverterUG1 data
  etsConfigList[0].name = "Inverter UG1";
  etsConfigList[0].manufacturer = "Sungrow";
  etsConfigList[0].model = "125KW";
  etsConfigList[0].class_id = 1;
  etsConfigList[0].ug = 1;

  // InverterUG1 dnp3 config
  etsConfigList[0].dnp3_cfg.analog_out_point_offset = 51;
  etsConfigList[0].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[0].dnp3_cfg.outstation_id = 1010;
  etsConfigList[0].dnp3_cfg.master_id1 = 0;
  etsConfigList[0].dnp3_cfg.master_id2 = 1;
  etsConfigList[0].dnp3_cfg.master_id3 = 0;  
  etsConfigList[0].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[0].dnp3_cfg.port1 = 22000;
  etsConfigList[0].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[0].dnp3_cfg.port2 = 21000;
  etsConfigList[0].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[0].dnp3_cfg.port3 = 8;
  etsConfigList[0].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[0].dnp3_cfg.uns_addr = 0;
  etsConfigList[0].dnp3_cfg.check_failure = 0;
  etsConfigList[0].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[0].dnp3_cfg.failure_point = 10;    
  etsConfigList[0].dnp3_cfg.dnp3_failure_point_val = 0;  

  // InverterUG1 modbus config
  etsConfigList[0].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[0].modbus_cfg.addr = 1;
  etsConfigList[0].modbus_cfg.ip = "172.16.6.101";
  etsConfigList[0].modbus_cfg.port = 502;
  etsConfigList[0].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[0].modbus_cfg.baud_rate = 9600;
  etsConfigList[0].modbus_cfg.num_devs = 8;
  etsConfigList[0].modbus_cfg.address_list = "1, 4, 6, 5, 7, 8, 3, 2;";
  etsConfigList[0].modbus_cfg.timeout = 1;
  etsConfigList[0].modbus_cfg.inter_polling = 5;
  etsConfigList[0].modbus_cfg.intra_polling = 2000;
  etsConfigList[0].modbus_cfg.retry_timeout = 3000;
  etsConfigList[0].modbus_cfg.retries = 2;
  etsConfigList[0].modbus_cfg.poll_trigger = 0;
  etsConfigList[0].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // InverterUG1 class config
  etsConfigList[0].classmap.classId = 1;
  etsConfigList[0].classmap.typeId = 1;
  etsConfigList[0].classmap.mapId = 1;
  etsConfigList[0].classmap.name = "inv_sung_125";
  etsConfigList[0].classmap.version = "0.0.2";
  etsConfigList[0].classmap.map_path = "inverterFSA.cfg";
  etsConfigList[0].classmap.map_description = "Mapa Inversor Sungrow 125KW";

  // ----------------------
  
  // InverterUG2 data
  etsConfigList[1].name = "Inverter UG2";
  etsConfigList[1].manufacturer = "Sungrow";
  etsConfigList[1].model = "125KW";
  etsConfigList[1].class_id = 1;
  etsConfigList[1].ug = 2;

  // InverterUG2 dnp3 config
  etsConfigList[1].dnp3_cfg.analog_out_point_offset = 51;
  etsConfigList[1].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[1].dnp3_cfg.outstation_id = 1110;
  etsConfigList[1].dnp3_cfg.master_id1 = 0;
  etsConfigList[1].dnp3_cfg.master_id2 = 1;
  etsConfigList[1].dnp3_cfg.master_id3 = 0;  
  etsConfigList[1].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[1].dnp3_cfg.port1 = 22000;
  etsConfigList[1].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[1].dnp3_cfg.port2 = 21000;
  etsConfigList[1].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[1].dnp3_cfg.port3 = 8;
  etsConfigList[1].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[1].dnp3_cfg.uns_addr = 0;
  etsConfigList[1].dnp3_cfg.check_failure = 0;
  etsConfigList[1].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[1].dnp3_cfg.failure_point = 10;    
  etsConfigList[1].dnp3_cfg.dnp3_failure_point_val = 0;  

  // InverterUG2 modbus config
  etsConfigList[1].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[1].modbus_cfg.addr = 1;
  etsConfigList[1].modbus_cfg.ip = "172.16.6.111";
  etsConfigList[1].modbus_cfg.port = 502;
  etsConfigList[1].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[1].modbus_cfg.baud_rate = 9600;
  etsConfigList[1].modbus_cfg.num_devs = 8;
  etsConfigList[1].modbus_cfg.address_list = "1, 2, 3, 4, 5, 6, 7, 8;";
  etsConfigList[1].modbus_cfg.timeout = 1;
  etsConfigList[1].modbus_cfg.inter_polling = 5;
  etsConfigList[1].modbus_cfg.intra_polling = 2000;
  etsConfigList[1].modbus_cfg.retry_timeout = 3000;
  etsConfigList[1].modbus_cfg.retries = 2;
  etsConfigList[1].modbus_cfg.poll_trigger = 0;
  etsConfigList[1].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // InverterUG2 class config
  etsConfigList[1].classmap.classId = 1;
  etsConfigList[1].classmap.typeId = 1;
  etsConfigList[1].classmap.mapId = 1;
  etsConfigList[1].classmap.name = "inv_sung_125";
  etsConfigList[1].classmap.version = "0.0.2";
  etsConfigList[1].classmap.map_path = "inverterFSA.cfg";
  etsConfigList[1].classmap.map_description = "Mapa Inversor Sungrow 125KW";
  
  // ------------------------
 
  // InverterUG3 data
  etsConfigList[2].name = "Inverter UG3";
  etsConfigList[2].manufacturer = "Sungrow";
  etsConfigList[2].model = "125KW";
  etsConfigList[2].class_id = 1;
  etsConfigList[2].ug = 3;

  // InverterUG3 dnp3 config
  etsConfigList[2].dnp3_cfg.analog_out_point_offset = 51;
  etsConfigList[2].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[2].dnp3_cfg.outstation_id = 1210;
  etsConfigList[2].dnp3_cfg.master_id1 = 0;
  etsConfigList[2].dnp3_cfg.master_id2 = 1;
  etsConfigList[2].dnp3_cfg.master_id3 = 0;
  etsConfigList[2].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[2].dnp3_cfg.port1 = 22000;
  etsConfigList[2].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[2].dnp3_cfg.port2 = 21000;
  etsConfigList[2].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[2].dnp3_cfg.port3 = 8;
  etsConfigList[2].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[2].dnp3_cfg.uns_addr = 0;
  etsConfigList[2].dnp3_cfg.check_failure = 0;
  etsConfigList[2].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[2].dnp3_cfg.failure_point = 10;
  etsConfigList[2].dnp3_cfg.dnp3_failure_point_val = 0;

  // InverterUG3 modbus config
  etsConfigList[2].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[2].modbus_cfg.addr = 1;
  etsConfigList[2].modbus_cfg.ip = "172.16.6.121";
  etsConfigList[2].modbus_cfg.port = 502;
  etsConfigList[2].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[2].modbus_cfg.baud_rate = 9600;
  etsConfigList[2].modbus_cfg.num_devs = 8;
  etsConfigList[2].modbus_cfg.address_list = "1, 2, 3, 4, 5, 6, 7, 8;";
  etsConfigList[2].modbus_cfg.timeout = 1;
  etsConfigList[2].modbus_cfg.inter_polling = 5;
  etsConfigList[2].modbus_cfg.intra_polling = 2000;
  etsConfigList[2].modbus_cfg.retry_timeout = 3000;
  etsConfigList[2].modbus_cfg.retries = 2;
  etsConfigList[2].modbus_cfg.poll_trigger = 0;
  etsConfigList[2].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // InverterUG3 class config
  etsConfigList[2].classmap.classId = 1;
  etsConfigList[2].classmap.typeId = 1;
  etsConfigList[2].classmap.mapId = 1;
  etsConfigList[2].classmap.name = "inv_sung_125";
  etsConfigList[2].classmap.version = "0.0.2";
  etsConfigList[2].classmap.map_path = "inverterFSA.cfg";
  etsConfigList[2].classmap.map_description = "Mapa Inversor Sungrow 125KW";
  
  // ------------------

  // InverterUG4 data
  etsConfigList[3].name = "Inverter UG4";
  etsConfigList[3].manufacturer = "Sungrow";
  etsConfigList[3].model = "125KW";
  etsConfigList[3].class_id = 1;
  etsConfigList[3].ug = 4;

  // InverterUG4 dnp3 config
  etsConfigList[3].dnp3_cfg.analog_out_point_offset = 51;
  etsConfigList[3].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[3].dnp3_cfg.outstation_id = 1310;
  etsConfigList[3].dnp3_cfg.master_id1 = 0;
  etsConfigList[3].dnp3_cfg.master_id2 = 1;
  etsConfigList[3].dnp3_cfg.master_id3 = 0;
  etsConfigList[3].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[3].dnp3_cfg.port1 = 22000;
  etsConfigList[3].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[3].dnp3_cfg.port2 = 21000;
  etsConfigList[3].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[3].dnp3_cfg.port3 = 8;
  etsConfigList[3].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[3].dnp3_cfg.uns_addr = 0;
  etsConfigList[3].dnp3_cfg.check_failure = 0;
  etsConfigList[3].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[3].dnp3_cfg.failure_point = 10;
  etsConfigList[3].dnp3_cfg.dnp3_failure_point_val = 0;

  // InverterUG4 modbus config
  etsConfigList[3].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[3].modbus_cfg.addr = 1;
  etsConfigList[3].modbus_cfg.ip = "172.16.6.131";
  etsConfigList[3].modbus_cfg.port = 502;
  etsConfigList[3].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[3].modbus_cfg.baud_rate = 9600;
  etsConfigList[3].modbus_cfg.num_devs = 8;
  etsConfigList[3].modbus_cfg.address_list = "1, 2, 3, 4, 5, 6, 7, 8;";
  etsConfigList[3].modbus_cfg.timeout = 1;
  etsConfigList[3].modbus_cfg.inter_polling = 5;
  etsConfigList[3].modbus_cfg.intra_polling = 2000;
  etsConfigList[3].modbus_cfg.retry_timeout = 3000;
  etsConfigList[3].modbus_cfg.retries = 2;
  etsConfigList[3].modbus_cfg.poll_trigger = 0;
  etsConfigList[3].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // InverterUG4 class config
  etsConfigList[3].classmap.classId = 1;
  etsConfigList[3].classmap.typeId = 1;
  etsConfigList[3].classmap.mapId = 1;
  etsConfigList[3].classmap.name = "inv_sung_125";
  etsConfigList[3].classmap.version = "0.0.2";
  etsConfigList[3].classmap.map_path = "inverterFSA.cfg";
  etsConfigList[3].classmap.map_description = "Mapa Inversor Sungrow 125KW";
  
  // --------------

  // InverterUG5 data
  etsConfigList[4].name = "Inverter UG5";
  etsConfigList[4].manufacturer = "Sungrow";
  etsConfigList[4].model = "125KW";
  etsConfigList[4].class_id = 1;
  etsConfigList[4].ug = 5;

  // InverterUG5 dnp3 config
  etsConfigList[4].dnp3_cfg.analog_out_point_offset = 51;
  etsConfigList[4].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[4].dnp3_cfg.outstation_id = 1410;
  etsConfigList[4].dnp3_cfg.master_id1 = 0;
  etsConfigList[4].dnp3_cfg.master_id2 = 1;
  etsConfigList[4].dnp3_cfg.master_id3 = 0;
  etsConfigList[4].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[4].dnp3_cfg.port1 = 22000;
  etsConfigList[4].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[4].dnp3_cfg.port2 = 21000;
  etsConfigList[4].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[4].dnp3_cfg.port3 = 8;
  etsConfigList[4].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[4].dnp3_cfg.uns_addr = 0;
  etsConfigList[4].dnp3_cfg.check_failure = 0;
  etsConfigList[4].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[4].dnp3_cfg.failure_point = 10;
  etsConfigList[4].dnp3_cfg.dnp3_failure_point_val = 0;

  // InverterUG5 modbus config
  etsConfigList[4].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[4].modbus_cfg.addr = 1;
  etsConfigList[4].modbus_cfg.ip = "172.16.6.141";
  etsConfigList[4].modbus_cfg.port = 502;
  etsConfigList[4].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[4].modbus_cfg.baud_rate = 9600;
  etsConfigList[4].modbus_cfg.num_devs = 8;
  etsConfigList[4].modbus_cfg.address_list = "1, 2, 3, 4, 5, 6, 7, 8;";
  etsConfigList[4].modbus_cfg.timeout = 1;
  etsConfigList[4].modbus_cfg.inter_polling = 5;
  etsConfigList[4].modbus_cfg.intra_polling = 2000;
  etsConfigList[4].modbus_cfg.retry_timeout = 3000;
  etsConfigList[4].modbus_cfg.retries = 2;
  etsConfigList[4].modbus_cfg.poll_trigger = 0;
  etsConfigList[4].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // InverterUG5 class config
  etsConfigList[4].classmap.classId = 1;
  etsConfigList[4].classmap.typeId = 1;
  etsConfigList[4].classmap.mapId = 1;
  etsConfigList[4].classmap.name = "inv_sung_125";
  etsConfigList[4].classmap.version = "0.0.2";
  etsConfigList[4].classmap.map_path = "inverterFSA.cfg";
  etsConfigList[4].classmap.map_description = "Mapa Inversor Sungrow 125KW";
  
  // --------------

  // Meter NUCD_EC1 data
  etsConfigList[5].name = "medidor EC1";
  etsConfigList[5].manufacturer = "ati";
  etsConfigList[5].model = "nUCD2387/ET-med";
  etsConfigList[5].class_id = 2;
  etsConfigList[5].ug = 1;

  // Meter NUCD_EC1 dnp3 config
  etsConfigList[5].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[5].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[5].dnp3_cfg.outstation_id = 200;
  etsConfigList[5].dnp3_cfg.master_id1 = 0;
  etsConfigList[5].dnp3_cfg.master_id2 = 1;
  etsConfigList[5].dnp3_cfg.master_id3 = 0;
  etsConfigList[5].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[5].dnp3_cfg.port1 = 22000;
  etsConfigList[5].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[5].dnp3_cfg.port2 = 21000;
  etsConfigList[5].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[5].dnp3_cfg.port3 = 8;
  etsConfigList[5].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[5].dnp3_cfg.uns_addr = 0;
  etsConfigList[5].dnp3_cfg.check_failure = 1;
  etsConfigList[5].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[5].dnp3_cfg.failure_point = 9;
  etsConfigList[5].dnp3_cfg.dnp3_failure_point_val = 0;

  // Meter NUCD_EC1 modbus config
  etsConfigList[5].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[5].modbus_cfg.addr = 1;
  etsConfigList[5].modbus_cfg.ip = "172.16.6.200";
  etsConfigList[5].modbus_cfg.port = 502;
  etsConfigList[5].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[5].modbus_cfg.baud_rate = 9600;
  etsConfigList[5].modbus_cfg.num_devs = 1;
  etsConfigList[5].modbus_cfg.address_list = "1;";
  etsConfigList[5].modbus_cfg.timeout = 1;
  etsConfigList[5].modbus_cfg.inter_polling = 5;
  etsConfigList[5].modbus_cfg.intra_polling = 2000;
  etsConfigList[5].modbus_cfg.retry_timeout = 3000;
  etsConfigList[5].modbus_cfg.retries = 2;
  etsConfigList[5].modbus_cfg.poll_trigger = 0;
  etsConfigList[5].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // Meter NUCD_EC1 class config
  etsConfigList[5].classmap.classId = 2;
  etsConfigList[5].classmap.typeId = 7;
  etsConfigList[5].classmap.mapId = 2;
  etsConfigList[5].classmap.name = "nucd";
  etsConfigList[5].classmap.version = "0.0.2";
  etsConfigList[5].classmap.map_path = "meter_nucdFSA.cfg";
  etsConfigList[5].classmap.map_description = "Mapa nUCD2387/ET-med";
  
  // --------------

  // Meter NUCD_EC2 data
  etsConfigList[6].name = "medidor EC2";
  etsConfigList[6].manufacturer = "ati";
  etsConfigList[6].model = "nUCD2387/ET-med";
  etsConfigList[6].class_id = 2;
  etsConfigList[6].ug = 2;

  // Meter NUCD_EC2 dnp3 config
  etsConfigList[6].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[6].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[6].dnp3_cfg.outstation_id = 201;
  etsConfigList[6].dnp3_cfg.master_id1 = 0;
  etsConfigList[6].dnp3_cfg.master_id2 = 1;
  etsConfigList[6].dnp3_cfg.master_id3 = 0;
  etsConfigList[6].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[6].dnp3_cfg.port1 = 22000;
  etsConfigList[6].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[6].dnp3_cfg.port2 = 21000;
  etsConfigList[6].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[6].dnp3_cfg.port3 = 8;
  etsConfigList[6].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[6].dnp3_cfg.uns_addr = 0;
  etsConfigList[6].dnp3_cfg.check_failure = 1;
  etsConfigList[6].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[6].dnp3_cfg.failure_point = 9;
  etsConfigList[6].dnp3_cfg.dnp3_failure_point_val = 0;

  // Meter NUCD_EC2 modbus config
  etsConfigList[6].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[6].modbus_cfg.addr = 1;
  etsConfigList[6].modbus_cfg.ip = "172.16.6.201";
  etsConfigList[6].modbus_cfg.port = 502;
  etsConfigList[6].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[6].modbus_cfg.baud_rate = 9600;
  etsConfigList[6].modbus_cfg.num_devs = 1;
  etsConfigList[6].modbus_cfg.address_list = "1;";
  etsConfigList[6].modbus_cfg.timeout = 1;
  etsConfigList[6].modbus_cfg.inter_polling = 5;
  etsConfigList[6].modbus_cfg.intra_polling = 2000;
  etsConfigList[6].modbus_cfg.retry_timeout = 3000;
  etsConfigList[6].modbus_cfg.retries = 2;
  etsConfigList[6].modbus_cfg.poll_trigger = 0;
  etsConfigList[6].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // Meter NUCD_EC2 class config
  etsConfigList[6].classmap.classId = 2;
  etsConfigList[6].classmap.typeId = 7;
  etsConfigList[6].classmap.mapId = 2;
  etsConfigList[6].classmap.name = "nucd";
  etsConfigList[6].classmap.version = "0.0.2";
  etsConfigList[6].classmap.map_path = "meter_nucdFSA.cfg";
  etsConfigList[6].classmap.map_description = "Mapa nUCD2387/ET-med";
  
  // --------------

  // Meter NUCD_EC3 data
  etsConfigList[7].name = "medidor EC3";
  etsConfigList[7].manufacturer = "ati";
  etsConfigList[7].model = "nUCD2387/ET-med";
  etsConfigList[7].class_id = 2;
  etsConfigList[7].ug = 3;

  // Meter NUCD_EC3 dnp3 config
  etsConfigList[7].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[7].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[7].dnp3_cfg.outstation_id = 202;
  etsConfigList[7].dnp3_cfg.master_id1 = 0;
  etsConfigList[7].dnp3_cfg.master_id2 = 1;
  etsConfigList[7].dnp3_cfg.master_id3 = 0;
  etsConfigList[7].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[7].dnp3_cfg.port1 = 22000;
  etsConfigList[7].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[7].dnp3_cfg.port2 = 21000;
  etsConfigList[7].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[7].dnp3_cfg.port3 = 8;
  etsConfigList[7].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[7].dnp3_cfg.uns_addr = 0;
  etsConfigList[7].dnp3_cfg.check_failure = 1;
  etsConfigList[7].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[7].dnp3_cfg.failure_point = 9;
  etsConfigList[7].dnp3_cfg.dnp3_failure_point_val = 0;

  // Meter NUCD_EC3 modbus config
  etsConfigList[7].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[7].modbus_cfg.addr = 1;
  etsConfigList[7].modbus_cfg.ip = "172.16.6.202";
  etsConfigList[7].modbus_cfg.port = 502;
  etsConfigList[7].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[7].modbus_cfg.baud_rate = 9600;
  etsConfigList[7].modbus_cfg.num_devs = 1;
  etsConfigList[7].modbus_cfg.address_list = "1;";
  etsConfigList[7].modbus_cfg.timeout = 1;
  etsConfigList[7].modbus_cfg.inter_polling = 5;
  etsConfigList[7].modbus_cfg.intra_polling = 2000;
  etsConfigList[7].modbus_cfg.retry_timeout = 3000;
  etsConfigList[7].modbus_cfg.retries = 2;
  etsConfigList[7].modbus_cfg.poll_trigger = 0;
  etsConfigList[7].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // Meter NUCD_EC3 class config
  etsConfigList[7].classmap.classId = 2;
  etsConfigList[7].classmap.typeId = 7;
  etsConfigList[7].classmap.mapId = 2;
  etsConfigList[7].classmap.name = "nucd";
  etsConfigList[7].classmap.version = "0.0.2";
  etsConfigList[7].classmap.map_path = "meter_nucdFSA.cfg";
  etsConfigList[7].classmap.map_description = "Mapa nUCD2387/ET-med";
  
  // --------------

  // Meter NUCD_EC4 data
  etsConfigList[8].name = "medidor EC4";
  etsConfigList[8].manufacturer = "ati";
  etsConfigList[8].model = "nUCD2387/ET-med";
  etsConfigList[8].class_id = 2;
  etsConfigList[8].ug = 4;

  // Meter NUCD_EC4 dnp3 config
  etsConfigList[8].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[8].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[8].dnp3_cfg.outstation_id = 203;
  etsConfigList[8].dnp3_cfg.master_id1 = 0;
  etsConfigList[8].dnp3_cfg.master_id2 = 1;
  etsConfigList[8].dnp3_cfg.master_id3 = 0;
  etsConfigList[8].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[8].dnp3_cfg.port1 = 22000;
  etsConfigList[8].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[8].dnp3_cfg.port2 = 21000;
  etsConfigList[8].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[8].dnp3_cfg.port3 = 8;
  etsConfigList[8].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[8].dnp3_cfg.uns_addr = 0;
  etsConfigList[8].dnp3_cfg.check_failure = 1;
  etsConfigList[8].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[8].dnp3_cfg.failure_point = 9;
  etsConfigList[8].dnp3_cfg.dnp3_failure_point_val = 0;

  // Meter NUCD_EC4 modbus config
  etsConfigList[8].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[8].modbus_cfg.addr = 1;
  etsConfigList[8].modbus_cfg.ip = "172.16.6.203";
  etsConfigList[8].modbus_cfg.port = 502;
  etsConfigList[8].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[8].modbus_cfg.baud_rate = 9600;
  etsConfigList[8].modbus_cfg.num_devs = 1;
  etsConfigList[8].modbus_cfg.address_list = "1;";
  etsConfigList[8].modbus_cfg.timeout = 1;
  etsConfigList[8].modbus_cfg.inter_polling = 5;
  etsConfigList[8].modbus_cfg.intra_polling = 2000;
  etsConfigList[8].modbus_cfg.retry_timeout = 3000;
  etsConfigList[8].modbus_cfg.retries = 2;
  etsConfigList[8].modbus_cfg.poll_trigger = 0;
  etsConfigList[8].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // Meter NUCD_EC4 class config
  etsConfigList[8].classmap.classId = 2;
  etsConfigList[8].classmap.typeId = 7;
  etsConfigList[8].classmap.mapId = 2;
  etsConfigList[8].classmap.name = "nucd";
  etsConfigList[8].classmap.version = "0.0.2";
  etsConfigList[8].classmap.map_path = "meter_nucdFSA.cfg";
  etsConfigList[8].classmap.map_description = "Mapa nUCD2387/ET-med";
  
  // --------------        
  
  // Meter NUCD_EC5 data
  etsConfigList[9].name = "medidor EC5";
  etsConfigList[9].manufacturer = "ati";
  etsConfigList[9].model = "nUCD2387/ET-med";
  etsConfigList[9].class_id = 2;
  etsConfigList[9].ug = 5;

  // Meter NUCD_EC5 dnp3 config
  etsConfigList[9].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[9].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[9].dnp3_cfg.outstation_id = 204;
  etsConfigList[9].dnp3_cfg.master_id1 = 0;
  etsConfigList[9].dnp3_cfg.master_id2 = 1;
  etsConfigList[9].dnp3_cfg.master_id3 = 0;
  etsConfigList[9].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[9].dnp3_cfg.port1 = 22000;
  etsConfigList[9].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[9].dnp3_cfg.port2 = 21000;
  etsConfigList[9].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[9].dnp3_cfg.port3 = 8;
  etsConfigList[9].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[9].dnp3_cfg.uns_addr = 0;
  etsConfigList[9].dnp3_cfg.check_failure = 1;
  etsConfigList[9].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 2;
  etsConfigList[9].dnp3_cfg.failure_point = 9;
  etsConfigList[9].dnp3_cfg.dnp3_failure_point_val = 0;

  // Meter NUCD_EC5 modbus config
  etsConfigList[9].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[9].modbus_cfg.addr = 1;
  etsConfigList[9].modbus_cfg.ip = "172.16.6.204";
  etsConfigList[9].modbus_cfg.port = 502;
  etsConfigList[9].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[9].modbus_cfg.baud_rate = 9600;
  etsConfigList[9].modbus_cfg.num_devs = 1;
  etsConfigList[9].modbus_cfg.address_list = "1;";
  etsConfigList[9].modbus_cfg.timeout = 1;
  etsConfigList[9].modbus_cfg.inter_polling = 5;
  etsConfigList[9].modbus_cfg.intra_polling = 2000;
  etsConfigList[9].modbus_cfg.retry_timeout = 3000;
  etsConfigList[9].modbus_cfg.retries = 2;
  etsConfigList[9].modbus_cfg.poll_trigger = 0;
  etsConfigList[9].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // Meter NUCD_EC5 class config
  etsConfigList[9].classmap.classId = 2;
  etsConfigList[9].classmap.typeId = 7;
  etsConfigList[9].classmap.mapId = 2;
  etsConfigList[9].classmap.name = "nucd";
  etsConfigList[9].classmap.version = "0.0.2";
  etsConfigList[9].classmap.map_path = "meter_nucdFSA.cfg";
  etsConfigList[9].classmap.map_description = "Mapa nUCD2387/ET-med";
  // -------------- 

  // station_1 data
  etsConfigList[10].name = "Estação Solarimétrica";
  etsConfigList[10].manufacturer = "Hyl";
  etsConfigList[10].model = "xxxx";
  etsConfigList[10].class_id = 3;
  etsConfigList[10].ug = 1;

  // station_1 dnp3 config
  etsConfigList[10].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[10].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[10].dnp3_cfg.outstation_id = 251;
  etsConfigList[10].dnp3_cfg.master_id1 = 0;
  etsConfigList[10].dnp3_cfg.master_id2 = 1;
  etsConfigList[10].dnp3_cfg.master_id3 = 0;
  etsConfigList[10].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[10].dnp3_cfg.port1 = 22000;
  etsConfigList[10].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[10].dnp3_cfg.port2 = 21000;
  etsConfigList[10].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[10].dnp3_cfg.port3 = 8;
  etsConfigList[10].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[10].dnp3_cfg.uns_addr = 0;
  etsConfigList[10].dnp3_cfg.check_failure = 0;
  etsConfigList[10].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 1;
  etsConfigList[10].dnp3_cfg.failure_point = 10;
  etsConfigList[10].dnp3_cfg.dnp3_failure_point_val = 0;

  // station_1 modbus config
  etsConfigList[10].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[10].modbus_cfg.addr = 1;
  etsConfigList[10].modbus_cfg.ip = "172.16.6.23";
  etsConfigList[10].modbus_cfg.port = 502;
  etsConfigList[10].modbus_cfg.device = "/dev/ttyS4";
  etsConfigList[10].modbus_cfg.baud_rate = 9600;
  etsConfigList[10].modbus_cfg.num_devs = 1;
  etsConfigList[10].modbus_cfg.address_list = "1;";
  etsConfigList[10].modbus_cfg.timeout = 1;
  etsConfigList[10].modbus_cfg.inter_polling = 10;
  etsConfigList[10].modbus_cfg.intra_polling = 2000;
  etsConfigList[10].modbus_cfg.retry_timeout = 3000;
  etsConfigList[10].modbus_cfg.retries = 2;
  etsConfigList[10].modbus_cfg.poll_trigger = 0;
  etsConfigList[10].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // station_1 class config
  etsConfigList[10].classmap.classId = 3;
  etsConfigList[10].classmap.typeId = 5;
  etsConfigList[10].classmap.mapId = 3;
  etsConfigList[10].classmap.name = "station_1";
  etsConfigList[10].classmap.version = "0.0.2";
  etsConfigList[10].classmap.map_path = "station_1FSA.cfg";
  etsConfigList[10].classmap.map_description = "Mapa Sol. Hyl";
  // -------------- 

  // stringboxUG1 data
  etsConfigList[11].name = "Stringbox UG1";
  etsConfigList[11].manufacturer = "Sungrow";
  etsConfigList[11].model = "xptz";
  etsConfigList[11].class_id = 4;
  etsConfigList[11].ug = 1;

  // stringboxUG1 dnp3 config
  etsConfigList[11].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[11].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[11].dnp3_cfg.outstation_id = 10100;
  etsConfigList[11].dnp3_cfg.master_id1 = 0;
  etsConfigList[11].dnp3_cfg.master_id2 = 1;
  etsConfigList[11].dnp3_cfg.master_id3 = 0;
  etsConfigList[11].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[11].dnp3_cfg.port1 = 22000;
  etsConfigList[11].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[11].dnp3_cfg.port2 = 21000;
  etsConfigList[11].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[11].dnp3_cfg.port3 = 8;
  etsConfigList[11].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[11].dnp3_cfg.uns_addr = 0;
  etsConfigList[11].dnp3_cfg.check_failure = 0;
  etsConfigList[11].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 3;
  etsConfigList[11].dnp3_cfg.failure_point = 10;
  etsConfigList[11].dnp3_cfg.dnp3_failure_point_val = 0;

  // stringboxUG1 modbus config
  etsConfigList[11].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[11].modbus_cfg.addr = 9;
  etsConfigList[11].modbus_cfg.ip = "172.16.6.101";
  etsConfigList[11].modbus_cfg.port = 502;
  etsConfigList[11].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[11].modbus_cfg.baud_rate = 9600;
  etsConfigList[11].modbus_cfg.num_devs = 8;
  etsConfigList[11].modbus_cfg.address_list = "9, 10, 11, 12, 13, 14, 15, 16;";
  etsConfigList[11].modbus_cfg.timeout = 1;
  etsConfigList[11].modbus_cfg.inter_polling = 5;
  etsConfigList[11].modbus_cfg.intra_polling = 2000;
  etsConfigList[11].modbus_cfg.retry_timeout = 3000;
  etsConfigList[11].modbus_cfg.retries = 2;
  etsConfigList[11].modbus_cfg.poll_trigger = 0;
  etsConfigList[11].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // stringboxUG1 class config
  etsConfigList[11].classmap.classId = 4;
  etsConfigList[11].classmap.typeId = 10;
  etsConfigList[11].classmap.mapId = 4;
  etsConfigList[11].classmap.name = "stringbox";
  etsConfigList[11].classmap.version = "v0.0.1";
  etsConfigList[11].classmap.map_path = "stringboxFSA.cfg";
  etsConfigList[11].classmap.map_description = "Mapa Stringbox Sungrow";
  // -------------- 
 
  // stringboxUG2 data
  etsConfigList[12].name = "Stringbox UG2";
  etsConfigList[12].manufacturer = "Sungrow";
  etsConfigList[12].model = "xptz";
  etsConfigList[12].class_id = 4;
  etsConfigList[12].ug = 2;

  // stringboxUG2 dnp3 config
  etsConfigList[12].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[12].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[12].dnp3_cfg.outstation_id = 11100;
  etsConfigList[12].dnp3_cfg.master_id1 = 0;
  etsConfigList[12].dnp3_cfg.master_id2 = 1;
  etsConfigList[12].dnp3_cfg.master_id3 = 0;
  etsConfigList[12].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[12].dnp3_cfg.port1 = 22000;
  etsConfigList[12].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[12].dnp3_cfg.port2 = 21000;
  etsConfigList[12].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[12].dnp3_cfg.port3 = 8;
  etsConfigList[12].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[12].dnp3_cfg.uns_addr = 0;
  etsConfigList[12].dnp3_cfg.check_failure = 0;
  etsConfigList[12].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 3;
  etsConfigList[12].dnp3_cfg.failure_point = 10;
  etsConfigList[12].dnp3_cfg.dnp3_failure_point_val = 0;

  // stringboxUG2 modbus config
  etsConfigList[12].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[12].modbus_cfg.addr = 9;
  etsConfigList[12].modbus_cfg.ip = "172.16.6.111";
  etsConfigList[12].modbus_cfg.port = 502;
  etsConfigList[12].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[12].modbus_cfg.baud_rate = 9600;
  etsConfigList[12].modbus_cfg.num_devs = 8;
  etsConfigList[12].modbus_cfg.address_list = "9, 10, 11, 12, 13, 14, 15, 16";
  etsConfigList[12].modbus_cfg.timeout = 1;
  etsConfigList[12].modbus_cfg.inter_polling = 5;
  etsConfigList[12].modbus_cfg.intra_polling = 2000;
  etsConfigList[12].modbus_cfg.retry_timeout = 3000;
  etsConfigList[12].modbus_cfg.retries = 2;
  etsConfigList[12].modbus_cfg.poll_trigger = 0;
  etsConfigList[12].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // stringboxUG2 class config
  etsConfigList[12].classmap.classId = 4;
  etsConfigList[12].classmap.typeId = 10;
  etsConfigList[12].classmap.mapId = 4;
  etsConfigList[12].classmap.name = "stringbox";
  etsConfigList[12].classmap.version = "0.0.2";
  etsConfigList[12].classmap.map_path = "stringboxFSA.cfg";
  etsConfigList[12].classmap.map_description = "Mapa Stringbox Sungrow";
  // -------------- 

  // stringboxUG3 data
  etsConfigList[13].name = "Stringbox UG3";
  etsConfigList[13].manufacturer = "Sungrow";
  etsConfigList[13].model = "xptz";
  etsConfigList[13].class_id = 4;
  etsConfigList[13].ug = 3;

  // stringboxUG3 dnp3 config
  etsConfigList[13].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[13].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[13].dnp3_cfg.outstation_id = 12100;
  etsConfigList[13].dnp3_cfg.master_id1 = 0;
  etsConfigList[13].dnp3_cfg.master_id2 = 1;
  etsConfigList[13].dnp3_cfg.master_id3 = 0;
  etsConfigList[13].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[13].dnp3_cfg.port1 = 22000;
  etsConfigList[13].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[13].dnp3_cfg.port2 = 21000;
  etsConfigList[13].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[13].dnp3_cfg.port3 = 8;
  etsConfigList[13].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[13].dnp3_cfg.uns_addr = 0;
  etsConfigList[13].dnp3_cfg.check_failure = 0;
  etsConfigList[13].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 3;
  etsConfigList[13].dnp3_cfg.failure_point = 10;
  etsConfigList[13].dnp3_cfg.dnp3_failure_point_val = 0;

  // stringboxUG3 modbus config
  etsConfigList[13].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[13].modbus_cfg.addr = 9;
  etsConfigList[13].modbus_cfg.ip = "172.16.6.121";
  etsConfigList[13].modbus_cfg.port = 502;
  etsConfigList[13].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[13].modbus_cfg.baud_rate = 9600;
  etsConfigList[13].modbus_cfg.num_devs = 8;
  etsConfigList[13].modbus_cfg.address_list = "9, 10, 11, 12, 13, 14, 15, 16";
  etsConfigList[13].modbus_cfg.timeout = 1;
  etsConfigList[13].modbus_cfg.inter_polling = 5;
  etsConfigList[13].modbus_cfg.intra_polling = 2000;
  etsConfigList[13].modbus_cfg.retry_timeout = 3000;
  etsConfigList[13].modbus_cfg.retries = 2;
  etsConfigList[13].modbus_cfg.poll_trigger = 0;
  etsConfigList[13].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // stringboxUG3 class config
  etsConfigList[13].classmap.classId = 4;
  etsConfigList[13].classmap.typeId = 10;
  etsConfigList[13].classmap.mapId = 4;
  etsConfigList[13].classmap.name = "stringbox";
  etsConfigList[13].classmap.version = "0.0.2";
  etsConfigList[13].classmap.map_path = "stringboxFSA.cfg";
  etsConfigList[13].classmap.map_description = "Mapa Stringbox Sungrow";
  // -------------- 

 // stringboxUG4 data
  etsConfigList[14].name = "Stringbox UG4";
  etsConfigList[14].manufacturer = "Sungrow";
  etsConfigList[14].model = "xptz";
  etsConfigList[14].class_id = 4;
  etsConfigList[14].ug = 4;

  // stringboxUG4 dnp3 config
  etsConfigList[14].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[14].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[14].dnp3_cfg.outstation_id = 13100;
  etsConfigList[14].dnp3_cfg.master_id1 = 0;
  etsConfigList[14].dnp3_cfg.master_id2 = 1;
  etsConfigList[14].dnp3_cfg.master_id3 = 0;
  etsConfigList[14].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[14].dnp3_cfg.port1 = 22000;
  etsConfigList[14].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[14].dnp3_cfg.port2 = 21000;
  etsConfigList[14].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[14].dnp3_cfg.port3 = 8;
  etsConfigList[14].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[14].dnp3_cfg.uns_addr = 0;
  etsConfigList[14].dnp3_cfg.check_failure = 0;
  etsConfigList[14].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 3;
  etsConfigList[14].dnp3_cfg.failure_point = 10;
  etsConfigList[14].dnp3_cfg.dnp3_failure_point_val = 0;

  // stringboxUG4 modbus config
  etsConfigList[14].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[14].modbus_cfg.addr = 9;
  etsConfigList[14].modbus_cfg.ip = "172.16.6.131";
  etsConfigList[14].modbus_cfg.port = 502;
  etsConfigList[14].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[14].modbus_cfg.baud_rate = 9600;
  etsConfigList[14].modbus_cfg.num_devs = 8;
  etsConfigList[14].modbus_cfg.address_list = "9, 10, 11, 12, 13, 14, 15, 16";
  etsConfigList[14].modbus_cfg.timeout = 1;
  etsConfigList[14].modbus_cfg.inter_polling = 5;
  etsConfigList[14].modbus_cfg.intra_polling = 2000;
  etsConfigList[14].modbus_cfg.retry_timeout = 3000;
  etsConfigList[14].modbus_cfg.retries = 2;
  etsConfigList[14].modbus_cfg.poll_trigger = 0;
  etsConfigList[14].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // stringboxUG4 class config
  etsConfigList[14].classmap.classId = 4;
  etsConfigList[14].classmap.typeId = 10;
  etsConfigList[14].classmap.mapId = 4;
  etsConfigList[14].classmap.name = "stringbox";
  etsConfigList[14].classmap.version = "0.0.2";
  etsConfigList[14].classmap.map_path = "stringboxFSA.cfg";
  etsConfigList[14].classmap.map_description = "Mapa Stringbox Sungrow";
  // -------------- 
 
 // stringboxUG5 data
  etsConfigList[15].name = "Stringbox UG5";
  etsConfigList[15].manufacturer = "Sungrow";
  etsConfigList[15].model = "xptz";
  etsConfigList[15].class_id = 4;
  etsConfigList[15].ug = 5;

  // stringboxUG5 dnp3 config
  etsConfigList[15].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[15].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[15].dnp3_cfg.outstation_id = 14100;
  etsConfigList[15].dnp3_cfg.master_id1 = 0;
  etsConfigList[15].dnp3_cfg.master_id2 = 1;
  etsConfigList[15].dnp3_cfg.master_id3 = 0;
  etsConfigList[15].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[15].dnp3_cfg.port1 = 22000;
  etsConfigList[15].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[15].dnp3_cfg.port2 = 21000;
  etsConfigList[15].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[15].dnp3_cfg.port3 = 8;
  etsConfigList[15].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[15].dnp3_cfg.uns_addr = 0;
  etsConfigList[15].dnp3_cfg.check_failure = 0;
  etsConfigList[15].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 3;
  etsConfigList[15].dnp3_cfg.failure_point = 10;
  etsConfigList[15].dnp3_cfg.dnp3_failure_point_val = 0;

  // stringboxUG5 modbus config
  etsConfigList[15].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[15].modbus_cfg.addr = 9;
  etsConfigList[15].modbus_cfg.ip = "172.16.6.141";
  etsConfigList[15].modbus_cfg.port = 502;
  etsConfigList[15].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[15].modbus_cfg.baud_rate = 9600;
  etsConfigList[15].modbus_cfg.num_devs = 8;
  etsConfigList[15].modbus_cfg.address_list = "9, 10, 11, 12, 13, 14, 15, 16;";
  etsConfigList[15].modbus_cfg.timeout = 1;
  etsConfigList[15].modbus_cfg.inter_polling = 5;
  etsConfigList[15].modbus_cfg.intra_polling = 2000;
  etsConfigList[15].modbus_cfg.retry_timeout = 3000;
  etsConfigList[15].modbus_cfg.retries = 2;
  etsConfigList[15].modbus_cfg.poll_trigger = 0;
  etsConfigList[15].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // stringboxUG5 class config
  etsConfigList[15].classmap.classId = 4;
  etsConfigList[15].classmap.typeId = 10;
  etsConfigList[15].classmap.mapId = 4;
  etsConfigList[15].classmap.name = "stringbox";
  etsConfigList[15].classmap.version = "0.0.2";
  etsConfigList[15].classmap.map_path = "stringboxFSA.cfg";
  etsConfigList[15].classmap.map_description = "Mapa Stringbox Sungrow";
  // -------------- 

  // transformerUG1 data
  etsConfigList[16].name = "Transformer UG1";
  etsConfigList[16].manufacturer = "Treetech";
  etsConfigList[16].model = "LAD";
  etsConfigList[16].class_id = 5;
  etsConfigList[16].ug = 1;

  // transformerUG1 dnp3 config
  etsConfigList[16].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[16].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[16].dnp3_cfg.outstation_id = 100;
  etsConfigList[16].dnp3_cfg.master_id1 = 0;
  etsConfigList[16].dnp3_cfg.master_id2 = 1;
  etsConfigList[16].dnp3_cfg.master_id3 = 0;
  etsConfigList[16].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[16].dnp3_cfg.port1 = 22000;
  etsConfigList[16].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[16].dnp3_cfg.port2 = 21000;
  etsConfigList[16].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[16].dnp3_cfg.port3 = 8;
  etsConfigList[16].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[16].dnp3_cfg.uns_addr = 0;
  etsConfigList[16].dnp3_cfg.check_failure = 1;
  etsConfigList[16].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 1;
  etsConfigList[16].dnp3_cfg.failure_point = 9;
  etsConfigList[16].dnp3_cfg.dnp3_failure_point_val = 0;

  // transformerUG1 modbus config
  etsConfigList[16].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[16].modbus_cfg.addr = 1;
  etsConfigList[16].modbus_cfg.ip = "172.16.6.100";
  etsConfigList[16].modbus_cfg.port = 502;
  etsConfigList[16].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[16].modbus_cfg.baud_rate = 9600;
  etsConfigList[16].modbus_cfg.num_devs = 1;
  etsConfigList[16].modbus_cfg.address_list = "1;";
  etsConfigList[16].modbus_cfg.timeout = 1;
  etsConfigList[16].modbus_cfg.inter_polling = 5;
  etsConfigList[16].modbus_cfg.intra_polling = 2000;
  etsConfigList[16].modbus_cfg.retry_timeout = 3000;
  etsConfigList[16].modbus_cfg.retries = 2;
  etsConfigList[16].modbus_cfg.poll_trigger = 0;
  etsConfigList[16].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // transformerUG1 class config
  etsConfigList[16].classmap.classId = 5;
  etsConfigList[16].classmap.typeId = 6;
  etsConfigList[16].classmap.mapId = 5;
  etsConfigList[16].classmap.name = "transformer";
  etsConfigList[16].classmap.version = "0.0.2";
  etsConfigList[16].classmap.map_path = "transformerFSA.cfg";
  etsConfigList[16].classmap.map_description = "Mapa Transformer Treetech";
  // -------------- 
 
  // transformerUG2 data
  etsConfigList[17].name = "Transformer UG2";
  etsConfigList[17].manufacturer = "Treetech";
  etsConfigList[17].model = "LAD";
  etsConfigList[17].class_id = 5;
  etsConfigList[17].ug = 2;

  // transformerUG2 dnp3 config
  etsConfigList[17].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[17].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[17].dnp3_cfg.outstation_id = 110;
  etsConfigList[17].dnp3_cfg.master_id1 = 0;
  etsConfigList[17].dnp3_cfg.master_id2 = 1;
  etsConfigList[17].dnp3_cfg.master_id3 = 0;
  etsConfigList[17].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[17].dnp3_cfg.port1 = 22000;
  etsConfigList[17].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[17].dnp3_cfg.port2 = 21000;
  etsConfigList[17].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[17].dnp3_cfg.port3 = 8;
  etsConfigList[17].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[17].dnp3_cfg.uns_addr = 0;
  etsConfigList[17].dnp3_cfg.check_failure = 1;
  etsConfigList[17].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 1;
  etsConfigList[17].dnp3_cfg.failure_point = 9;
  etsConfigList[17].dnp3_cfg.dnp3_failure_point_val = 0;

  // transformerUG2 modbus config
  etsConfigList[17].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[17].modbus_cfg.addr = 1;
  etsConfigList[17].modbus_cfg.ip = "172.16.6.110";
  etsConfigList[17].modbus_cfg.port = 502;
  etsConfigList[17].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[17].modbus_cfg.baud_rate = 9600;
  etsConfigList[17].modbus_cfg.num_devs = 1;
  etsConfigList[17].modbus_cfg.address_list = "1;";
  etsConfigList[17].modbus_cfg.timeout = 1;
  etsConfigList[17].modbus_cfg.inter_polling = 5;
  etsConfigList[17].modbus_cfg.intra_polling = 2000;
  etsConfigList[17].modbus_cfg.retry_timeout = 3000;
  etsConfigList[17].modbus_cfg.retries = 2;
  etsConfigList[17].modbus_cfg.poll_trigger = 0;
  etsConfigList[17].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // transformerUG2 class config
  etsConfigList[17].classmap.classId = 5;
  etsConfigList[17].classmap.typeId = 6;
  etsConfigList[17].classmap.mapId = 5;
  etsConfigList[17].classmap.name = "transformer";
  etsConfigList[17].classmap.version = "0.0.2";
  etsConfigList[17].classmap.map_path = "transformerFSA.cfg";
  etsConfigList[17].classmap.map_description = "Mapa Transformer Treetech";
  // -------------- 
 
  // transformerUG3 data
  etsConfigList[18].name = "Transformer UG3";
  etsConfigList[18].manufacturer = "Treetech";
  etsConfigList[18].model = "LAD";
  etsConfigList[18].class_id = 5;
  etsConfigList[18].ug = 3;

  // transformerUG3 dnp3 config
  etsConfigList[18].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[18].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[18].dnp3_cfg.outstation_id = 120;
  etsConfigList[18].dnp3_cfg.master_id1 = 0;
  etsConfigList[18].dnp3_cfg.master_id2 = 1;
  etsConfigList[18].dnp3_cfg.master_id3 = 0;
  etsConfigList[18].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[18].dnp3_cfg.port1 = 22000;
  etsConfigList[18].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[18].dnp3_cfg.port2 = 21000;
  etsConfigList[18].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[18].dnp3_cfg.port3 = 8;
  etsConfigList[18].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[18].dnp3_cfg.uns_addr = 0;
  etsConfigList[18].dnp3_cfg.check_failure = 1;
  etsConfigList[18].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 1;
  etsConfigList[18].dnp3_cfg.failure_point = 9;
  etsConfigList[18].dnp3_cfg.dnp3_failure_point_val = 0;

  // transformerUG3 modbus config
  etsConfigList[18].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[18].modbus_cfg.addr = 1;
  etsConfigList[18].modbus_cfg.ip = "172.16.6.120";
  etsConfigList[18].modbus_cfg.port = 502;
  etsConfigList[18].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[18].modbus_cfg.baud_rate = 9600;
  etsConfigList[18].modbus_cfg.num_devs = 1;
  etsConfigList[18].modbus_cfg.address_list = "1;";
  etsConfigList[18].modbus_cfg.timeout = 1;
  etsConfigList[18].modbus_cfg.inter_polling = 5;
  etsConfigList[18].modbus_cfg.intra_polling = 2000;
  etsConfigList[18].modbus_cfg.retry_timeout = 3000;
  etsConfigList[18].modbus_cfg.retries = 2;
  etsConfigList[18].modbus_cfg.poll_trigger = 0;
  etsConfigList[18].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // transformerUG3 class config
  etsConfigList[18].classmap.classId = 5;
  etsConfigList[18].classmap.typeId = 6;
  etsConfigList[18].classmap.mapId = 5;
  etsConfigList[18].classmap.name = "transformer";
  etsConfigList[18].classmap.version = "0.0.2";
  etsConfigList[18].classmap.map_path = "transformerFSA.cfg";
  etsConfigList[18].classmap.map_description = "Mapa Transformer Treetech";
  // --------------    
  
  // transformerUG4 data
  etsConfigList[19].name = "Transformer UG4";
  etsConfigList[19].manufacturer = "Treetech";
  etsConfigList[19].model = "LAD";
  etsConfigList[19].class_id = 5;
  etsConfigList[19].ug = 4;

  // transformerUG4 dnp3 config
  etsConfigList[19].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[19].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[19].dnp3_cfg.outstation_id = 130;
  etsConfigList[19].dnp3_cfg.master_id1 = 0;
  etsConfigList[19].dnp3_cfg.master_id2 = 1;
  etsConfigList[19].dnp3_cfg.master_id3 = 0;
  etsConfigList[19].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[19].dnp3_cfg.port1 = 22000;
  etsConfigList[19].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[19].dnp3_cfg.port2 = 21000;
  etsConfigList[19].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[19].dnp3_cfg.port3 = 8;
  etsConfigList[19].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[19].dnp3_cfg.uns_addr = 0;
  etsConfigList[19].dnp3_cfg.check_failure = 1;
  etsConfigList[19].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 1;
  etsConfigList[19].dnp3_cfg.failure_point = 9;
  etsConfigList[19].dnp3_cfg.dnp3_failure_point_val = 0;

  // transformerUG4 modbus config
  etsConfigList[19].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[19].modbus_cfg.addr = 1;
  etsConfigList[19].modbus_cfg.ip = "172.16.6.130";
  etsConfigList[19].modbus_cfg.port = 502;
  etsConfigList[19].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[19].modbus_cfg.baud_rate = 9600;
  etsConfigList[19].modbus_cfg.num_devs = 1;
  etsConfigList[19].modbus_cfg.address_list = "1;";
  etsConfigList[19].modbus_cfg.timeout = 1;
  etsConfigList[19].modbus_cfg.inter_polling = 5;
  etsConfigList[19].modbus_cfg.intra_polling = 2000;
  etsConfigList[19].modbus_cfg.retry_timeout = 3000;
  etsConfigList[19].modbus_cfg.retries = 2;
  etsConfigList[19].modbus_cfg.poll_trigger = 0;
  etsConfigList[19].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // transformerUG4 class config
  etsConfigList[19].classmap.classId = 5;
  etsConfigList[19].classmap.typeId = 6;
  etsConfigList[19].classmap.mapId = 5;
  etsConfigList[19].classmap.name = "transformer";
  etsConfigList[19].classmap.version = "0.0.2";
  etsConfigList[19].classmap.map_path = "transformerFSA.cfg";
  etsConfigList[19].classmap.map_description = "Mapa Transformer Treetech";
  // --------------   

  // transformerUG5 data
  etsConfigList[20].name = "Transformer UG5";
  etsConfigList[20].manufacturer = "Treetech";
  etsConfigList[20].model = "LAD";
  etsConfigList[20].class_id = 5;
  etsConfigList[20].ug = 5;

  // transformerUG5 dnp3 config
  etsConfigList[20].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[20].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[20].dnp3_cfg.outstation_id = 140;
  etsConfigList[20].dnp3_cfg.master_id1 = 0;
  etsConfigList[20].dnp3_cfg.master_id2 = 1;
  etsConfigList[20].dnp3_cfg.master_id3 = 0;
  etsConfigList[20].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[20].dnp3_cfg.port1 = 22000;
  etsConfigList[20].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[20].dnp3_cfg.port2 = 21000;
  etsConfigList[20].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[20].dnp3_cfg.port3 = 8;
  etsConfigList[20].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[20].dnp3_cfg.uns_addr = 0;
  etsConfigList[20].dnp3_cfg.check_failure = 1;
  etsConfigList[20].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 1;
  etsConfigList[20].dnp3_cfg.failure_point = 9;
  etsConfigList[20].dnp3_cfg.dnp3_failure_point_val = 0;

  // transformerUG5 modbus config
  etsConfigList[20].modbus_cfg.mode = (TModbusTypeConn) 1;
  etsConfigList[20].modbus_cfg.addr = 1;
  etsConfigList[20].modbus_cfg.ip = "172.16.6.140";
  etsConfigList[20].modbus_cfg.port = 502;
  etsConfigList[20].modbus_cfg.device = "/dev/ttyUSB0";
  etsConfigList[20].modbus_cfg.baud_rate = 9600;
  etsConfigList[20].modbus_cfg.num_devs = 1;
  etsConfigList[20].modbus_cfg.address_list = "1;";
  etsConfigList[20].modbus_cfg.timeout = 1;
  etsConfigList[20].modbus_cfg.inter_polling = 5;
  etsConfigList[20].modbus_cfg.intra_polling = 2000;
  etsConfigList[20].modbus_cfg.retry_timeout = 3000;
  etsConfigList[20].modbus_cfg.retries = 2;
  etsConfigList[20].modbus_cfg.poll_trigger = 0;
  etsConfigList[20].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // transformerUG5 class config
  etsConfigList[20].classmap.classId = 5;
  etsConfigList[20].classmap.typeId = 6;
  etsConfigList[20].classmap.mapId = 5;
  etsConfigList[20].classmap.name = "transformer";
  etsConfigList[20].classmap.version = "0.0.2";
  etsConfigList[20].classmap.map_path = "transformerFSA.cfg";
  etsConfigList[20].classmap.map_description = "Mapa Transformer Treetech";
  // -------------- 

  // UTR3288io data
  etsConfigList[21].name = "UTR3288io";
  etsConfigList[21].manufacturer = "ati";
  etsConfigList[21].model = "xptz";
  etsConfigList[21].class_id = 6;
  etsConfigList[21].ug = 1;

  // UTR3288io dnp3 config
  etsConfigList[21].dnp3_cfg.analog_out_point_offset = 0;
  etsConfigList[21].dnp3_cfg.binary_in_confirm_cmd = 1;
  etsConfigList[21].dnp3_cfg.outstation_id = 252;
  etsConfigList[21].dnp3_cfg.master_id1 = 0;
  etsConfigList[21].dnp3_cfg.master_id2 = 1;
  etsConfigList[21].dnp3_cfg.master_id3 = 0;
  etsConfigList[21].dnp3_cfg.ip1 = "172.16.6.253";
  etsConfigList[21].dnp3_cfg.port1 = 22000;
  etsConfigList[21].dnp3_cfg.ip2 = "172.16.6.253";
  etsConfigList[21].dnp3_cfg.port2 = 21000;
  etsConfigList[21].dnp3_cfg.ip3 = "8.8.8.8";
  etsConfigList[21].dnp3_cfg.port3 = 8;
  etsConfigList[21].dnp3_cfg.uns_conn_token = 2;
  etsConfigList[21].dnp3_cfg.uns_addr = 0;
  etsConfigList[21].dnp3_cfg.check_failure = 0;
  etsConfigList[21].dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) 1;
  etsConfigList[21].dnp3_cfg.failure_point = 9;
  etsConfigList[21].dnp3_cfg.dnp3_failure_point_val = 0;

  // UTR3288io modbus config
  etsConfigList[21].modbus_cfg.mode = (TModbusTypeConn) 2;
  etsConfigList[21].modbus_cfg.addr = 1;
  etsConfigList[21].modbus_cfg.ip = "192.168.20.17";
  etsConfigList[21].modbus_cfg.port = 502;
  etsConfigList[21].modbus_cfg.device = "/dev/ttyS4";
  etsConfigList[21].modbus_cfg.baud_rate = 9600;
  etsConfigList[21].modbus_cfg.num_devs = 1;
  etsConfigList[21].modbus_cfg.address_list = "1;";
  etsConfigList[21].modbus_cfg.timeout = 1;
  etsConfigList[21].modbus_cfg.inter_polling = 10;
  etsConfigList[21].modbus_cfg.intra_polling = 2000;
  etsConfigList[21].modbus_cfg.retry_timeout = 3000;
  etsConfigList[21].modbus_cfg.retries = 1;
  etsConfigList[21].modbus_cfg.poll_trigger = 0;
  etsConfigList[21].modbus_cfg.trigger_path = "/tmp/mdbProxyTrigger.cmd";

  // UTR3288io class config
  etsConfigList[21].classmap.classId = 6;
  etsConfigList[21].classmap.typeId = 11;
  etsConfigList[21].classmap.mapId = 6;
  etsConfigList[21].classmap.name = "utr3288io";
  etsConfigList[21].classmap.version = "0.0.2";
  etsConfigList[21].classmap.map_path = "utr3288io.cfg";
  etsConfigList[21].classmap.map_description = "Mapa UTR3288io";
  // -------------- 
*/                        
  if(c.is_connected()) {

    //c.configEts(11, etsConfigList);

  }

  while(1);

  return 0;
}
