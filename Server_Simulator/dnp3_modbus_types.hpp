/*
 * DNP3 Modbus Types
 */

#ifndef _DNP3_MODBUS_TYPES_HPP_
#define _DNP3_MODBUS_TYPES_HPP_

#include <string>
#include <vector>

#define MAX_MODBUS_DEVICES      250

typedef enum {
  COIL,
  DISCRETE_INPUT,
  INPUT_16,
  INPUT_16LH,
  INPUT_32,
  REGISTER_16,
  REGISTER_16LH,
  REGISTER_32, // mesmo que REDISTER_32HL 
  REGISTER_32F, // mesmo que REDISTER_32HL 
  INTEGER,
  FLOAT,
  IR_FLOAT_32LH,
  IR_FLOAT_32HL,
  IR_FLOAT_LH32LH,
  HR_FLOAT_32LH,
  HR_FLOAT_32HL,
  REGISTER_32LH,  
  INPUT_32LH,
  MREGISTER,
  MREGISTER_32,
  PREGISTER,
  REGISTER_FULL_LH,
  REGISTER_FULL_HL,
  INPUT_FULL_LH,
  INPUT_FULL_HL,
  NONE
} TModbusDataType;

typedef enum {
  BIN_INPUT,
  BIN_OUTPUT,
  BIN_COUNTER,
  FRZ_COUNTER,
  ANA_INPUT,
  ANA_OUTPUT,
  _NONE
} TDnp3DataType;

typedef struct {
  unsigned int point;
//  TDnp3ObjectTypes type;
  TDnp3DataType type;
  unsigned int dnpclass;
  unsigned long value;
} TDnp3Data;

typedef enum {
  mTCP = 1,
  mRTU = 2,
  mRTU_TCP = 3,
} TModbusType;

typedef struct {
  unsigned int address;
  TModbusDataType type;
  unsigned int range;
  union {
    unsigned int uint_value;
    float flt_value;
  };
  bool config_param;
} TModbusData;

// Estrutura contendo todos os campos de dados necessários para conexão a um
// slave Modbus TCP
typedef struct
{
  TModbusType type;
  std::string ip;   ///< Endereço IP do slave Modbus
  std::string port; ///< Porta do slave Modbus
  std::string device;
  std::string baud;
  int address;      ///< Endereço slave Modbus
  int numDevs;      ///< Numero de dispositivos no barramento
  //int addressList[MAX_MODBUS_DEVICES]; ///< Lista de endereços do barramento moodbus
  std::vector<int> addressList;
  double timeout; ///< Timeout em s.us
} TModbusSlaveConfig;

// Estrutura contendo todos os campos necessários para configurar um poller Modbus
typedef struct
{
  unsigned int inter_polling; ///< Tempo entre cada sequência de polling (s)
  unsigned int intra_polling; ///< Tempo entre cada estado da sequência de polling (ms)
  unsigned int retry_timeout; ///< Tempo de timeout para repetir um estado do polling (ms)
  unsigned int retries;       ///< Número de tentativas de execução de um estado do polling
  bool poll_Semaphore;        ///< Semáforo para execução dos estados do poller
  std::string semaphore_FileName;
} TModbusPollerConfig;

// Estrutura que reune todas as informações necessárias para estabelecer uma
// conexão com um servidor master DNP3 via TCP
// NOTE: se for desejada uma conexão de entrada basta passar "ip = 0.0.0.0" na configuração
//       ao invés de se informar o IP do servidor onde se deseja conectar
typedef struct
{
  std::string ip;               /**< Endereço IP do servidor DNP3 */
  int port;                     /**< Porta TCP do servidor DNP3 */
  unsigned int master_addr;     /**< Endereço master DNP3 */
  bool unsolicited_enabled;     /**< Flag indicador de conexão com unsolicited messages */
} TDnp3MasterConnectionData;

typedef struct
{
  uint16_t Dnp3BinInputs;     /**< Número de entradas digitais */
  uint16_t Dnp3AnalogInputs;  /**< Número de entradas analógicas */
  uint16_t Dnp3Counters;      /**< Número de contadores */
  uint16_t Dnp3BinOutputs;    /**< Número de saídas digitais */
  uint16_t Dnp3AnalogOutputs; /**< Número de saídas analógicas */
  uint16_t Dnp3EventBufsize;  /**< Tamanho do buffer de eventos */
  uint16_t Class0Enable;  /**< Flags para inclusão de tipos de objetos na classe 0 */
  uint16_t Cnt2on1msTimer;
  uint16_t Cnt2InitDnp3;
  uint16_t numDevices;
  uint16_t Dnp3SlaveAddress;
  uint16_t Dnp3UnsolicitedAddress;
  uint16_t Dnp3AnalogOutputPointOffsset;
  uint16_t Dnp3BinaryInputConfirmCommand;
} TDnp3Config;

//Estrutura contendo contadores para cada tipo de objeto DNP3
typedef struct
{
  unsigned int BI;      ///< Número de objetos do tipo entrada digital (Binary Input)
  unsigned int BO;      ///< Número de objetos do tipo saída digital (Binary Output)
  unsigned int AI;      ///< Número de objetos do tipo saída analógica (Analog Input)
  unsigned int AO;      ///< Número de objetos do tipo saída digital (Analog Output)
  unsigned int CNT;     ///< Número de objetos do tipo contador (Counter)
} TDnp3ObjectsCount;


typedef struct
{
  bool State;
  uint16_t Point;
} TDnp3BIData;

typedef struct
{
  uint32_t value;
  uint16_t Point;
} TDnp3AIData;

typedef struct
{
  uint32_t value;
  uint16_t Point;
} TDnp3BCData;

typedef struct
{
  bool Enabled;
  TDnp3Data data;
} TFailureConfig;

#endif
