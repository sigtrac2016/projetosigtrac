FROM node:4
MAINTAINER Luiz Coura <luizcoura@gmail.com>

ENV DEBIAN_FRONTEND noninteractive

# Requirements
RUN apt-get update && apt-get install -y \
  cron \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir /lm35
WORKDIR /lm35

ADD . /lm35
RUN npm install

ADD crontab /etc/cron.d/ts07-mock

RUN touch /var/log/cron.log

CMD cron && tail -f /var/log/cron.log
