FROM ubuntu:latest
MAINTAINER Luiz Coura <luizcoura@gmail.com>

ENV DEBIAN_FRONTEND noninteractive

# Requirements
RUN apt-get update && apt-get install -y \
  python-software-properties \
  software-properties-common \
  curl \
  git \
  build-essential \
  python2.7 \
  && rm -rf /var/lib/apt/lists/*

# Add NodeJS Repository
RUN curl -sL https://deb.nodesource.com/setup_4.x | bash -

# Install NodeJS
RUN apt-get install -y \
  nodejs \
  && rm -rf /var/lib/apt/lists/*

RUN npm config set python /usr/bin/python2.7 && npm install -g \
    npm \
    mqtt