#!/bin/bash

_SERVER_PROPERTIES=/usr/local/kafka/config/server.properties

[ "${ADVERTISED_HOSTNAME}" ] && _HOSTNAME=${ADVERTISED_HOSTNAME} || _HOSTNAME=${HOSTNAME}

sed -i 's!^advertised.host.name=.*!advertised.host.name=${_HOSTNAME}!' ${_SERVER_PROPERTIES}

exec /usr/local/kafka/bin/kafka-server-start.sh ${_SERVER_PROPERTIES} 