var request = require("request");
var mqtt = require("mqtt");
var _ = require("lodash");

var config = require("../config");

var MQTT_URL = config.mqtt.getUrl();
var API_URL = config.api.getUrl();

var sub  = mqtt.connect(MQTT_URL);

var channels = {
  "new-sensor": function(message) {
    request.post({
      url: API_URL + "sensores",
      json: JSON.parse(message.toString()),
    }, function(error, response, body){
        if(error) {
            console.log(error);
        } else {
            console.log(response.statusCode, body);
        }
      }
    );
  },
  "update-sensor": function(message) {
    message = JSON.parse(message.toString());
    console.log("Patching value from " + API_URL + "sensores/" + message.alias + " to " + message.value);
    request.patch({
      url: API_URL + "sensores/" + message.alias,
      json: {value: message.value},
    }, function(error, response, body){
        if(error) {
            console.log(error);
        } else {
            console.log(response.statusCode, body);
        }
      }
    );
  },
  "test": function(message) {
    console.log("Getting message from swapi.co/api/" + message.toString());
    var apiResult = request.get("http://swapi.co/api/" + message.toString(), function(error, response, body) {
      console.log(body);
    });
  }
};

// Subscriber setup
sub.on("connect", function () {
  console.log("Subscribing");
  _.forEach(_.keys(channels), (c) => {
    sub.subscribe(c);
    console.log("> " + c);
  });
});

sub.on("message", function (topic, message) {
  console.log("Received Message on " + topic);
  channels[topic](message);
});
