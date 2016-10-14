FROM ubuntu:latest
MAINTAINER Luiz Coura <luizcoura@gmail.com>

ENV DEBIAN_FRONTEND noninteractive

# Requirements
RUN apt-get update && apt-get install -y \
  python-software-properties \
  software-properties-common \
  && rm -rf /var/lib/apt/lists/*

# Add Mosquitto PPA Repository
RUN apt-add-repository -y ppa:mosquitto-dev/mosquitto-ppa

# Install Mosquitto
RUN apt-get update && apt-get install -y \
  mosquitto \
  mosquitto-clients \
  && rm -rf /var/lib/apt/lists/*

EXPOSE 1883

CMD ["/usr/sbin/mosquitto", "-c", "/etc/mosquitto/mosquitto.conf"]