FROM node:4
MAINTAINER Luiz Coura <luizcoura@gmail.com>

ENV DEBIAN_FRONTEND noninteractive

# Requirements
RUN apt-get update && apt-get install -y \
  cron \
  && rm -rf /var/lib/apt/lists/*

RUN mkdir /live
WORKDIR /live
ADD . /live

RUN npm install

EXPOSE 3888

CMD ["npm", "start"]
