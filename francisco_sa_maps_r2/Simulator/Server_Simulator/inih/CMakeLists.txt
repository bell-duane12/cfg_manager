# Menor versão com suporte a cross-compiling
cmake_minimum_required(VERSION 2.6)

project(libinih CXX C)

# Fontes da biblioteca teleobjects
set(SOURCES
  INIReader.cpp
  ini.c
  )

# Flag para ligar mensagens de debug dos métodos sendo executados
option (DEBUG_COMMDEV_FLOW "Show method names being called during execution" OFF)
if (DEBUG_COMMDEV_FLOW)
  # Define propriedades para compilação dos fontes
  set_source_files_properties (${SOURCES}
  PROPERTIES COMPILE_FLAGS "-DDEBUG_COMMDEV")
endif(DEBUG_COMMDEV_FLOW)

# Prepara bibliotecas estática e compartilhada
add_library(libinih_static STATIC ${SOURCES})
add_library(libinih_shared SHARED ${SOURCES})

# Especifica os nomes dos arquivos que as bibliotecas devem ter de forma que os
# mesmos não assumam os mesmos nomes dos targets, que é o comportamento default.
set_target_properties(libinih_static PROPERTIES OUTPUT_NAME cppinih)
set_target_properties(libinih_shared PROPERTIES OUTPUT_NAME cppinih)

# Define caminho de instalação dos targets de bibliotecas
install(TARGETS libinih_static libinih_shared
        DESTINATION ${CMAKE_FIND_ROOT_PATH}/usr/lib)

