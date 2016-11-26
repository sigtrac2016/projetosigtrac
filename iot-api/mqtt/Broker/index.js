var mosca = require("mosca");
var config = require("../config");

console.log(config.mongo.getUrl());

var ascoltatore = {
  //using ascoltatore
  type: "mongo",
  url: config.mongo.getUrl() + "mqtt",
  pubsubCollection: "ascoltatori",
  mongo: {}
};

var settings = {
  port: config.mqtt.port,
  backend: ascoltatore
};

var server = new mosca.Server(settings);

server.on("clientConnected", function(client) {
    console.log("client connected", client.id);
});

// fired when a message is received
server.on("published", function(packet, client) {
  console.log("Published", packet.payload);
});

server.on("ready", setup);

// fired when the mqtt server is ready
function setup() {
  console.log("Mosca server is up and running");
}
