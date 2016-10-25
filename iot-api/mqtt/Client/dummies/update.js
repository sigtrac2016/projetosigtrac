var mqtt = require('mqtt');
var MQTT_URL = require("../../config").mqtt.getUrl();

var pub  = mqtt.connect(MQTT_URL);

channel =  "update-sensor";

messageAlias = process.argv[2];
messageValue = process.argv[3];

message = JSON.stringify({
  "alias": messageAlias,
  "value": messageValue
});

// Publisher setup
pub.on('connect', function () {
  pub.publish(channel, message);
  console.log("Published '" + message + "' to " + channel);
  process.exit();
});
