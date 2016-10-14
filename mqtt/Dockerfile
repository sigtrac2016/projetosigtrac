FROM ubuntu:latest
MAINTAINER Luiz Coura <luizcoura@gmail.com>

ENV DEBIAN_FRONTEND noninteractive

# Requirements
RUN apt-get update && apt-get install -y \
  curl \
&& rm -rf /var/lib/apt/lists/*
