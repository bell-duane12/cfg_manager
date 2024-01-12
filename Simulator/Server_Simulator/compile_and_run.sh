#!/bin/sh
make clean
make all
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 1 inverterUG1A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 2 inverterUG2A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 3 inverterUG3A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 4 inverterUG4A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 5 inverterUG5A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 6 meterNUCD_EC1.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 7 meterNUCD_EC2.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 8 meterNUCD_EC3.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 9 meterNUCD_EC4.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 10 meterNUCD_EC5.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 11 station_1.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 12 stringboxUG1A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 13 stringboxUG2A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 14 stringboxUG3A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 15 stringboxUG4A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 16 stringboxUG5A.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 17 transformerUG1_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 18 transformerUG2_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 19 transformerUG3_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 20 transformerUG4_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 21 transformerUG5_treetech.cfg
./exec 192.168.2.21 1881 ssit_mqtt_user resutiss 4 22 utr3288io.cfg



