var mqtt = require('mqtt');
var MQTT_URL = require("../../config").mqtt.getUrl();

var pub  = mqtt.connect(MQTT_URL);

channel = "new-sensor";

messageName = process.argv[2];
message = JSON.stringify({
  "name": "Sensor de Test",
  "alias": messageName,
  "type": "HumTemp",
  "value": {"temperature":40, "humidity": 30},
  "location": {
  	"latitude": 230.12,
  	"longitude": 85,
    "altitude": 10,
  }
});

// Publisher setup
pub.on('connect', function () {
  pub.publish(channel, message);
  console.log("Published '" + message + "' to " + channel);
  process.exit();
});
