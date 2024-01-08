
#ifndef _DNP3_MODBUS_RELAY_CONFIG_MANAGER_HPP_
#define _DNP3_MODBUS_RELAY_CONFIG_MANAGER_HPP_

#include "INIReader.h"
#include "dnp3_modbus_types.hpp"
//#include "dnp3_object_manager.hpp"
//#include "dnp3_comm_session.hpp"
//#include "broker.hpp"
#include "mqtt_connection.hpp"

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
     * Carrega os mapas Dnp3 x Modbus a partir do arquivo de configuração
     * previamente carregado
     * @param index_to_modbus_addr_map mapa para registradores Modbus
     * @param index_to_dnp3_data_map mapa para pontos DNP3
     *
     * @retval true Mapas carregados com sucesso
     * @retval false Falha no carregamento dos mapas
     */
    bool load_maps_from_file();
//    bool load_maps_from_file(std::map<unsigned int, TModbusData>& index_to_modbus_data_map,
//                             std::map<unsigned int, TDnp3Data>& index_to_dnp3_data_map);

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
};

#endif
