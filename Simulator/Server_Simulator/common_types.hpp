
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


#endif
