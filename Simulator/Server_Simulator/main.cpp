#include <iostream>
#include <utility>
#include <thread> 

#include "srv.h"
#include "dnp3_modbus_relay_config_manager.hpp"

int main(int argc, char* argv[]) {

  if(argc != 6) {

    std::cout << "[ERROR] Argument read error (./exec host port user password gateway_id)\n";
    return 1;

  }

  MqttServerWrapper c(argv[1], atoi(argv[2]), argv[3], argv[4], atoi(argv[5])); 

  Dnp3_Modbus_Relay_Config_Manager cfg("utr3288io.cfg"); // Arquivo de teste

  std::vector<TEtsListConfig> etsConfigList(1); 
  
  etsConfigList[0] = cfg.get_config();
                         
                         
  //if(c.is_connected()) {

    c.configEts(11, etsConfigList);

  //}


  while(1) {
    //c.configEts(11, etsConfigList);
    //std::this_thread::sleep_for(std::chrono::seconds(15));
  };

  return 0;
}
