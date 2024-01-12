#include <iostream>
#include <utility>
#include <thread> 
#include <atomic>

#include "srv.h"
#include "dnp3_modbus_relay_config_manager.hpp"


std::atomic<bool> running(true);


int main(int argc, char* argv[]) {

  if(argc != 8) {

    std::cout << "[ERROR] Argument read error (./exec host port user password gateway_id ticket cfg_filename)\n";
    return 1;

  }

  MqttServerWrapper mqtt_server(argv[1], atoi(argv[2]), argv[3], argv[4], atoi(argv[5])); 

  Dnp3_Modbus_Relay_Config_Manager cfg(argv[7]); 

  std::vector<TEtsListConfig> etsConfigList(1); 
  etsConfigList[0] = cfg.get_config();
                                                 
  if(mqtt_server.is_connected()) {
    mqtt_server.configEts(atoi(argv[6]), etsConfigList);
  }

  while(running.load(std::memory_order_relaxed)) {  
  };
  
  std::cout << ">> MqttServerWrapper - Message (" << argv[6] << ") successfully published!" << std::endl;
  
  return 0;
  
}
