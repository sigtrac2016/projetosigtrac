var mqtt = require('mqtt');
var MQTT_URL = require("../config").mqtt.getUrl();

var pub  = mqtt.connect(MQTT_URL);

channel = process.argv[2];

messageName = process.argv[3];
message = JSON.stringify({
  "name": "Sensor de Test",
  "alias": messageName,
  "location": {
  	"latitude": 230.12,
  	"longitude": 85
  }
});

// Publisher setup
pub.on('connect', function () {
  pub.publish(channel, message);
  console.log("Published '" + message + "' to " + channel);
  process.exit();
});
