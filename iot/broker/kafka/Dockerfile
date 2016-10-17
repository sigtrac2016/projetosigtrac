FROM java:8-jre
MAINTAINER Luiz Coura <luizcoura@gmail.com>

ENV KAFKA_VERSION 0.10.0.1
ENV SCALA_VERSION 2.11
ENV ADVERTISED_HOSTNAME kafka

# Download Kafka
ADD http://ftp.unicamp.br/pub/apache/kafka/${KAFKA_VERSION}/kafka_${SCALA_VERSION}-${KAFKA_VERSION}.tgz /tmp/

# Install Kafka
RUN mkdir -p /usr/local/kafka \
  && tar -zx -C /usr/local/kafka --strip-components=1 -f /tmp/kafka_${SCALA_VERSION}-${KAFKA_VERSION}.tgz \
  && rm -rf kafka_*

ADD config /usr/local/kafka/config

VOLUME [ "/usr/local/kafka/config" ]

EXPOSE 9092

RUN sed -i 's!^advertised.host.name=.*!advertised.host.name=${ADVERTISED_HOSTNAME}!' /usr/local/kafka/config/server.properties

CMD ["/usr/local/kafka/bin/kafka-server-start.sh", "/usr/local/kafka/config/server.properties"]