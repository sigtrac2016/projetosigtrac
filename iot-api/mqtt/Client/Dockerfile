FROM node:latest

RUN mkdir -p /usr/src/mqtt-client
WORKDIR /usr/src/mqtt-client
COPY . /usr/src/mqtt-client

EXPOSE 8080
RUN npm install
CMD ["npm", "start"]
