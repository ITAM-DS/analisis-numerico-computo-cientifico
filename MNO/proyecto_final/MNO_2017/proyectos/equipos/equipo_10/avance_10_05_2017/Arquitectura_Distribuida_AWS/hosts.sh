#!/bin/bash

echo "127.0.0.1 localhost
54.183.187.216 master
54.241.142.234 nodo1
54.219.172.190 nodo2


# The following lines are desirable for IPv6 capable hosts
::1 ip6-localhost ip6-loopback
fe00::0 ip6-localnet
ff00::0 ip6-mcastprefix
ff02::1 ip6-allnodes
ff02::2 ip6-allrouters
ff02::3 ip6-allhosts">hosts

sudo mv hosts /etc/

