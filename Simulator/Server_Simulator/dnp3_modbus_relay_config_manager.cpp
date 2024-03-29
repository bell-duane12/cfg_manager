
#include "dnp3_modbus_relay_config_manager.hpp"
#include "dnp3_modbus_types.hpp"

#include <iostream>
#include <string>
#include <algorithm>
#include <system_error>
#include <sstream>


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
  cout << "Modbus Poller configuration loaded..." << endl;
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
  
  // Se o modo é TCP, carrega IP e porta para conexão
  std::string type = cfg_reader.Get("modbus", "mode", "invalid");
  if (type.compare("TCP") == 0) {
    modbus_config.type = mTCP;
    modbus_config.ip = cfg_reader.Get("modbus", "ip", "error");
    if (modbus_config.ip.compare("error") == 0)
      return false;
    modbus_config.port = cfg_reader.Get("modbus", "port", "error");
    if (modbus_config.port.compare("error") == 0)
      return false;
    modbus_config.device = cfg_reader.Get("modbus", "device", "");
  }
  else if (type.compare("RTU") == 0) {
    modbus_config.type = mRTU;
    modbus_config.device = cfg_reader.Get("modbus", "device", "error");
    if (modbus_config.device.compare("error") == 0)
      return false;
    modbus_config.baud = cfg_reader.Get("modbus", "baud", "error");
    if (modbus_config.baud.compare("error") == 0)
      return false;    
    modbus_config.ip = cfg_reader.Get("modbus", "ip", "error");
    modbus_config.port = cfg_reader.Get("modbus", "port", "0");
  }
  else if (type.compare("RTU_TCP") == 0) {
    modbus_config.type = mRTU_TCP;
    modbus_config.ip = cfg_reader.Get("modbus", "ip", "error");
    if (modbus_config.ip.compare("error") == 0)
      return false;
    modbus_config.port = cfg_reader.Get("modbus", "port", "error");
    if (modbus_config.port.compare("error") == 0)
      return false;
    modbus_config.device = cfg_reader.Get("modbus", "device", "");
  }
  else
    return false;
  
  // Carrega o endereço slave modbus (não obrigatório quando o modo é TCP)
  modbus_config.address = cfg_reader.GetInteger("modbus", "address", -1);
  if (modbus_config.address < 1)
    return false;

  // Carrega o numero de dispositivos no barramento
  modbus_config.numDevs = cfg_reader.GetInteger("modbus", "numDevs", -1);
  if ((modbus_config.numDevs < 1) || (modbus_config.numDevs > MAX_MODBUS_DEVICES))
    return false;

  _addList = cfg_reader.Get("modbus", "addressList", "error");
  if (_addList.compare("error") == 0) 
    return false;
       
  modbus_config.timeout = cfg_reader.GetReal("modbus", "timeout", 1);
  if ((modbus_config.timeout == 0) || (modbus_config.timeout > 10))
    modbus_config.timeout = 0.750;


  etsConfigList.modbus_cfg.mode = (TModbusTypeConn) modbus_config.type; 
  etsConfigList.modbus_cfg.addr = modbus_config.address;
  etsConfigList.modbus_cfg.ip = modbus_config.ip;

  etsConfigList.modbus_cfg.port = std::stoi(modbus_config.port);

  etsConfigList.modbus_cfg.device = modbus_config.device;
  etsConfigList.modbus_cfg.baud_rate = modbus_config.baud;    
  etsConfigList.modbus_cfg.num_devs = modbus_config.numDevs;
  etsConfigList.modbus_cfg.address_list = _addList;
  etsConfigList.modbus_cfg.timeout = modbus_config.timeout;

  // Debug
  std::cout << " Modbus type = "        << modbus_config.type    << std::endl;
  std::cout << " Modbus ip = "          << modbus_config.ip      << std::endl;
  std::cout << " Modbus port = "        << modbus_config.port    << std::endl;
  std::cout << " Modbus device = "      << modbus_config.device  << std::endl;
  std::cout << " Modbus baud rate = "   << modbus_config.baud    << std::endl;
  std::cout << " Modbus address = "     << modbus_config.address << std::endl;
  std::cout << " Modbus numDevs = "     << modbus_config.numDevs << std::endl;
  std::cout << " Modbus addressList = " << _addList              << std::endl;  
  std::cout << " Modbus timeout = "     << modbus_config.timeout << std::endl;
      
  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_modbus_poller_cfg_from_file() {

  modbus_poller_config.inter_polling = cfg_reader.GetInteger("modbus_poller", "InterPolling", UINT32_MAX);
  if (modbus_poller_config.inter_polling == UINT32_MAX)
    return false;
  modbus_poller_config.intra_polling = cfg_reader.GetInteger("modbus_poller", "IntraPolling", UINT32_MAX);
  if (modbus_poller_config.intra_polling == UINT32_MAX)
    return false;
  modbus_poller_config.retry_timeout = cfg_reader.GetInteger("modbus_poller", "RetryTimeout", UINT32_MAX);
  if (modbus_poller_config.retry_timeout == UINT32_MAX)
    return false;
  modbus_poller_config.retries = cfg_reader.GetInteger("modbus_poller", "Retries", UINT32_MAX);
  if (modbus_poller_config.retries == UINT32_MAX)
    return false;
  modbus_poller_config.poll_Semaphore = cfg_reader.GetBoolean("modbus_poller", "PollTrigger", false);
  modbus_poller_config.semaphore_FileName = cfg_reader.Get("modbus_poller", "TriggerFileName", "error");
  if ((modbus_poller_config.semaphore_FileName.compare("error") == 0) && (modbus_poller_config.poll_Semaphore == true))
    return false;


  etsConfigList.modbus_cfg.inter_polling = modbus_poller_config.inter_polling;
  etsConfigList.modbus_cfg.intra_polling = modbus_poller_config.intra_polling;
  etsConfigList.modbus_cfg.retry_timeout = modbus_poller_config.retry_timeout;
  etsConfigList.modbus_cfg.retries = modbus_poller_config.retries;
  etsConfigList.modbus_cfg.poll_trigger = modbus_poller_config.poll_Semaphore;
  etsConfigList.modbus_cfg.trigger_path = modbus_poller_config.semaphore_FileName;


  // Debug
  std::cout << " Modbus inter polling = "   << modbus_poller_config.inter_polling                    << std::endl;
  std::cout << " Modbus intra polling = "   << modbus_poller_config.intra_polling                    << std::endl;
  std::cout << " Modbus retry timeout = "   << modbus_poller_config.retry_timeout                    << std::endl;
  std::cout << " Modbus retries = "         << modbus_poller_config.retries                          << std::endl;
  std::cout << " Modbus poll semaphore = "  << std::boolalpha << modbus_poller_config.poll_Semaphore << std::endl;
  std::cout << " Modbus semaphore file = "  << modbus_poller_config.semaphore_FileName               << std::endl;
    
  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_dnp3_cfg_from_file() {

  // OBS: GetFields retorna os campos de uma seção em ordem alfabética
  auto dnp3_fields = cfg_reader.GetFields("dnp3");
 
  dnp3_device_config.Dnp3AnalogOutputPointOffsset = cfg_reader.GetInteger("dnp3","AnalogOutputPointOffset",0);
  dnp3_device_config.Dnp3BinaryInputConfirmCommand = cfg_reader.GetInteger("dnp3","BinaryInputConfirmCommand",1);
  dnp3_device_config.Dnp3SlaveAddress = cfg_reader.GetInteger("dnp3", "slaveId", 0);
  dnp3_device_config.Dnp3UnsolicitedAddress = cfg_reader.GetInteger("dnp3", "Dnp3UnsolicitedAddress", 0);
  
  // Conferindo se há o mesmo número de IPs, portas e masterIDs
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


  etsConfigList.dnp3_cfg.analog_out_point_offset = dnp3_device_config.Dnp3AnalogOutputPointOffsset;
  etsConfigList.dnp3_cfg.binary_in_confirm_cmd = dnp3_device_config.Dnp3BinaryInputConfirmCommand;
  etsConfigList.dnp3_cfg.outstation_id = dnp3_device_config.Dnp3SlaveAddress;
  
  if (dnp3_connections_map.empty())
    throw std::system_error();
      
      
  etsConfigList.dnp3_cfg.master_id1 = dnp3_connections_map["1"].master_addr;
  etsConfigList.dnp3_cfg.ip1 = dnp3_connections_map["1"].ip;
  etsConfigList.dnp3_cfg.port1 = dnp3_connections_map["1"].port;

  if (dnp3_connections_map.size() > 1) {  
    etsConfigList.dnp3_cfg.master_id2 = dnp3_connections_map["2"].master_addr;
    etsConfigList.dnp3_cfg.ip2 = dnp3_connections_map["2"].ip;
    etsConfigList.dnp3_cfg.port2 = dnp3_connections_map["2"].port;
  } else {
    etsConfigList.dnp3_cfg.master_id2 = 0;
    etsConfigList.dnp3_cfg.ip2 = "";
    etsConfigList.dnp3_cfg.port2 = 0;  
  }
  
  if (dnp3_connections_map.size() > 2) {
    etsConfigList.dnp3_cfg.master_id3 = dnp3_connections_map["3"].master_addr;
    etsConfigList.dnp3_cfg.ip3 = dnp3_connections_map["3"].ip;
    etsConfigList.dnp3_cfg.port3 = dnp3_connections_map["3"].port;
  } else {
    etsConfigList.dnp3_cfg.master_id3 = 0;
    etsConfigList.dnp3_cfg.ip3 = "";
    etsConfigList.dnp3_cfg.port3 = 0;  
  }
  
  etsConfigList.dnp3_cfg.uns_conn_token = std::stoi(unsolicited_conn_token); 
  etsConfigList.dnp3_cfg.uns_addr = dnp3_device_config.Dnp3UnsolicitedAddress;
  

  // Debug --------------------
  std::cout << " DNP3 Analog Output Point Offset = "    << dnp3_device_config.Dnp3AnalogOutputPointOffsset  << std::endl;
  std::cout << " DNP3 Binary Input Confirm Command = "  << dnp3_device_config.Dnp3BinaryInputConfirmCommand << std::endl;
  std::cout << " DNP3 Slave Address = "                 << dnp3_device_config.Dnp3SlaveAddress              << std::endl;
  std::cout << " DNP3 Unsolicited Address = "           << dnp3_device_config.Dnp3UnsolicitedAddress        << std::endl;
  std::cout << " DNP3 Unsolicited Connection Token = "  << unsolicited_conn_token                           << std::endl;
  for (const auto& dnp3_conn : dnp3_connections_map) {
      
    const auto& key = dnp3_conn.first;
    const auto& conn = dnp3_conn.second;
    
    std::cout << " DNP3 Master ID #"   << key << ": " <<  conn.master_addr << std::endl;    
    std::cout << " DNP3 Master IP #"   << key << ": " <<  conn.ip          << std::endl;
    std::cout << " DNP3 Master Port #" << key << ": " <<  conn.port        << std::endl;
    
  }
  // --------------------------
      
  return true;
  
}

bool Dnp3_Modbus_Relay_Config_Manager::load_failure_cfg_from_file() {

  string type;
  
  failure_config.Enabled = cfg_reader.GetBoolean("Failure","CheckFailure",false);
  type = cfg_reader.Get("Failure","Dnp3FailurePointType","error");
  if (type.compare("OBJ_BINARY") == 0)
    //failure_config.data.type = BIN_INPUT;
    failure_config.data.type = OBJ_BINARY;
  else if (type.compare("OBJ_COUNTER") == 0)
    //failure_config.data.type = BIN_COUNTER;
    failure_config.data.type = OBJ_COUNTER;
  else if (type.compare("OBJ_ANALOG") == 0)
    //failure_config.data.type = ANA_INPUT;
    failure_config.data.type = OBJ_ANALOG;
  else
    //failure_config.data.type = _NONE;
    failure_config.data.type = OBJ_NONE;
  failure_config.data.point = cfg_reader.GetInteger("Failure","Dnp3FailurePoint",-1);
  failure_config.data.value = cfg_reader.GetInteger("Failure","Dnp3FailurePointValue",-1);
  
  

  etsConfigList.dnp3_cfg.check_failure = failure_config.Enabled;
  etsConfigList.dnp3_cfg.dnp3_failure_point_type = (TDnp3ObjectType) failure_config.data.type; 
  etsConfigList.dnp3_cfg.failure_point = failure_config.data.point;    
  etsConfigList.dnp3_cfg.dnp3_failure_point_val = failure_config.data.value; 
  
  
  // Debug
  std::cout << " CheckFailure = "          << std::boolalpha << failure_config.Enabled  << std::endl;
  std::cout << " Dnp3FailurePointType = "  << failure_config.data.type                  << std::endl;
  std::cout << " Dnp3FailurePoint = "      << failure_config.data.point                 << std::endl;
  std::cout << " Dnp3FailurePointValue = " << failure_config.data.value                 << std::endl;
    
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

TEtsListConfig Dnp3_Modbus_Relay_Config_Manager::get_config() {
  return etsConfigList; 
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


  etsConfigList.classmap.version = equipment_and_class_config.classmap.version;
  etsConfigList.classmap.classId = equipment_and_class_config.classmap.classId;
  etsConfigList.classmap.typeId = equipment_and_class_config.classmap.typeId;
  etsConfigList.classmap.mapId = equipment_and_class_config.classmap.mapId;
  etsConfigList.classmap.name = equipment_and_class_config.classmap.name;
  etsConfigList.classmap.map_path = equipment_and_class_config.classmap.map_path;
  etsConfigList.classmap.map_description = equipment_and_class_config.classmap.map_description;
  etsConfigList.class_id = etsConfigList.classmap.classId;
  
  // Debug 
  std::cout << " Classmap version = "       << equipment_and_class_config.classmap.version         << std::endl;
  std::cout << " Classmap class id = "      << equipment_and_class_config.classmap.classId         << std::endl;
  std::cout << " Classmap type id = "       << equipment_and_class_config.classmap.typeId          << std::endl;
  std::cout << " Classmap map id = "        << equipment_and_class_config.classmap.mapId           << std::endl;
  std::cout << " Classmap name = "          << equipment_and_class_config.classmap.name            << std::endl;
  std::cout << " Classmap map path = "      << equipment_and_class_config.classmap.map_path        << std::endl;
  std::cout << " Classmap map description " << equipment_and_class_config.classmap.map_description << std::endl;
  
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


  etsConfigList.name = equipment_and_class_config.name;
  etsConfigList.manufacturer = equipment_and_class_config.manufacturer;
  etsConfigList.model = equipment_and_class_config.model;
  etsConfigList.ug = equipment_and_class_config.ug;
  
  // Debug
  std::cout << " Equipment name = "          << equipment_and_class_config.name         << std::endl;
  std::cout << " Equipment manufacturer = "  << equipment_and_class_config.manufacturer << std::endl;
  std::cout << " Equipment model = "         << equipment_and_class_config.model        << std::endl;
  std::cout << " Equipment ug = "            << equipment_and_class_config.ug           << std::endl;
  
  return true;
  
}

