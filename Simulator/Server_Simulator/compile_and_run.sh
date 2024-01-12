#!/bin/sh
make clean
make all
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 1 Mapas_Francisco_Sa/inverterUG1A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 2 Mapas_Francisco_Sa/inverterUG2A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 3 Mapas_Francisco_Sa/inverterUG3A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 4 Mapas_Francisco_Sa/inverterUG4A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 5 Mapas_Francisco_Sa/inverterUG5A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 6 Mapas_Francisco_Sa/meterNUCD_EC1.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 7 Mapas_Francisco_Sa/meterNUCD_EC2.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 8 Mapas_Francisco_Sa/meterNUCD_EC3.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 9 Mapas_Francisco_Sa/meterNUCD_EC4.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 10 Mapas_Francisco_Sa/meterNUCD_EC5.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 11 Mapas_Francisco_Sa/station_1.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 12 Mapas_Francisco_Sa/stringboxUG1A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 13 Mapas_Francisco_Sa/stringboxUG2A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 14 Mapas_Francisco_Sa/stringboxUG3A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 15 Mapas_Francisco_Sa/stringboxUG4A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 16 Mapas_Francisco_Sa/stringboxUG5A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 17 Mapas_Francisco_Sa/transformerUG1_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 18 Mapas_Francisco_Sa/transformerUG2_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 19 Mapas_Francisco_Sa/transformerUG3_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 20 Mapas_Francisco_Sa/transformerUG4_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 21 Mapas_Francisco_Sa/transformerUG5_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 22 Mapas_Francisco_Sa/utr3288io.cfg



