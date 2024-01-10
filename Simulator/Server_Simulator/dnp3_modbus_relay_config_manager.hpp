
#ifndef _DNP3_MODBUS_RELAY_CONFIG_MANAGER_HPP_
#define _DNP3_MODBUS_RELAY_CONFIG_MANAGER_HPP_

#include "inih/INIReader.h"

#include "dnp3_modbus_types.hpp"
#include "common_types.hpp"
#include "srv.h"

class Dnp3_Modbus_Relay_Config_Manager
{
  
  public:
    /**
     * Carrega a configuração do DNP3 Modbus relay a partir do arquivo de
     * configuração fornecido pelo usuário
     * @param cfg_filename Nome do arquivo de configuração
     */
    Dnp3_Modbus_Relay_Config_Manager(const std::string cfg_filename);

    /**
     * Atualiza os parâmetros da conexão Modbus com os presentes no arquivo de
     * configuração previamente carregado
     * @return success/failure (true/false)
     */
    bool load_modbus_cfg_from_file();
    
    /**
     * Atualiza os parâmetros do poller Modbus com os presentes no arquivo de
     * configuração previamente carregado
     * @return success/failure (true/false)
     */
    bool load_modbus_poller_cfg_from_file();
    
    /**
     * Atualiza os parâmetros de condição de falha com os presentes no arquivo de
     * configuração previamente carregado
     * @return success/failure (true/false)
     */
    bool load_failure_cfg_from_file();
    
    /**
     * Atualiza os parâmetros das conexões com os servidores DNP3 master com
     * os presentes no arquivo de configuração previamente carregado
     * @return success/failure (true/false)
     */
    bool load_dnp3_cfg_from_file();
    
    /**
     * Atualiza os parâmetros do broker com os presentes no arquivo de
     * configuração previamente carregado
     * @return success/failure (true/false)
     */
    bool load_broker_cfg_from_file();
    
    /**
     * Retorna dados de conexão ao slave Modbus
     */
    TModbusSlaveConfig get_modbus_slave_config();
    
    /**
     * Retorna o endereço slave do dispositivo DNP3 (conforme arquivo de configuração)
     */
    uint16_t get_dnp3_slave_address();
    
    /**
     * Retorna o endereço IP do slave Modbus
     */
    TModbusPollerConfig get_modbus_poller_config();

    /**
     * Retorna configuração do dispositivo DNP3
     */
    TDnp3Config get_dnp3_device_config();
    
    /**
     * Retorna configuração do broker mqtt
     */
    TBrokerConfig get_broker_config();

    /**
     * Retorna configuração de falha do enddevice
     */
    TFailureConfig get_failure_config();

    /**
     * Retorna número de conexões DNP3 especificadas no arquivo de configuração
     */
    unsigned int get_dnp3_connections_count();
    
    /**
     * Retorna o nome do arquivo de log
     */
    std::string get_config_log_file_name();
    
    /**
     * Retorna o nivel de informações para log
     */
    std::string get_config_log_level();
    
    //Definição dos mapas
    std::map<unsigned int, TModbusData> index_to_modbus_data_map;
    std::map<unsigned int, TDnp3Data> index_to_dnp3_data_map;

    /**
     * Retorna configuração do servidor DNP3 especificado pelo indice
     */
    std::vector<TDnp3MasterConnectionData> get_dnp3_connections_data();


    bool load_classmap_cfg_from_file();    
    bool load_equipment_cfg_from_file();
    
  private:
    INIReader cfg_reader;       ///< Objeto responsável pela leitura da configuração
            
    //Parâmetros do slave Modbus (inicializado com zeros)
    TModbusSlaveConfig modbus_config = {};
    
    //Parâmetros do poller Modbus (inicializado com zeros)
    TModbusPollerConfig modbus_poller_config = {};
    
    //Configuração do dispositivo DNP3 (inicializado com zeros)
    TDnp3Config dnp3_device_config = {};
    
    //Parâmetros para indicação de falha no enddevice (inicializado com zeros)
    TFailureConfig failure_config = {};
    
    //Vetor de dados para criação das conexões com os servidores DNP3 master
    std::vector<TDnp3MasterConnectionData> dnp3_connections_data;
    
    //Parâmetros do broker (inicializado com zeros)
    TBrokerConfig broker_config = {};
    
    //Contadores de tipos de objetos DNP3 (inicializado com zeros)
    TDnp3ObjectsCount dnp3_obj_count = {};
    
    // Configurações de Equipamento e de Classe
    TEtsListConfig equipment_and_class_config;
    
};

#endif
