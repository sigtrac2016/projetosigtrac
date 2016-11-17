var mqtt = require('mqtt')
var moment = require('moment')

require('events').EventEmitter.prototype._maxListeners = 100

var client  = mqtt.connect('mqtt://52.67.204.136')

var sensors = [
  ["68a560c4-ac5b-11e6-80f5-76304dec7eb7",-23.20389472,-45.90955491,574.785,5],
  ["68a563b2-ac5b-11e6-80f5-76304dec7eb7",-23.20359643,-45.90915258,572.124,5],
  ["68a56542-ac5b-11e6-80f5-76304dec7eb7",-23.20365066,-45.90892191,571.868,5],
  ["68a56696-ac5b-11e6-80f5-76304dec7eb7",-23.20360876,-45.90864028,571.013,5],
  ["68a567d6-ac5b-11e6-80f5-76304dec7eb7",-23.20383556,-45.90891923,572.852,5],
  ["68a56c72-ac5b-11e6-80f5-76304dec7eb7",-23.2039958,-45.90918745,574.334,5],
  ["68a56dee-ac5b-11e6-80f5-76304dec7eb7",-23.20424479,-45.90894069,574.911,4],
  ["68a56f2e-ac5b-11e6-80f5-76304dec7eb7",-23.20385281,-45.90876098,572.643,4],
  ["68a5706e-ac5b-11e6-80f5-76304dec7eb7",-23.20401306,-45.90837206,572.243,4],
  ["68a571b8-ac5b-11e6-80f5-76304dec7eb7",-23.20396622,-45.90865369,572.925,3],
  ["68a57302-ac5b-11e6-80f5-76304dec7eb7",-23.20408701,-45.90859737,573.254,3],
  ["68a57442-ac5b-11e6-80f5-76304dec7eb7",-23.20417083,-45.90874489,573.961,3],
  ["68a578de-ac5b-11e6-80f5-76304dec7eb7",-23.20428916,-45.9087127,574.362,2],
  ["68a57a46-ac5b-11e6-80f5-76304dec7eb7",-23.20434093,-45.90904261,575.787,2],
  ["68a57b7c-ac5b-11e6-80f5-76304dec7eb7",-23.20425218,-45.90855177,573.668,2],
  ["68a57d20-ac5b-11e6-80f5-76304dec7eb7",-23.20418316,-45.90843375,573.063,1],
  ["68a57ea6-ac5b-11e6-80f5-76304dec7eb7",-23.20431381,-45.90851958,573.766,1],
  ["68a5800e-ac5b-11e6-80f5-76304dec7eb7",-23.20441242,-45.90855981,574.254,1],
  ["68a5814e-ac5b-11e6-80f5-76304dec7eb7",-23.20454062,-45.90846325,574.193,1],
  ["68a58694-ac5b-11e6-80f5-76304dec7eb7",-23.20446666,-45.9081843,572.801,1],
  ["68a58810-ac5b-11e6-80f5-76304dec7eb7",-23.20460471,-45.90824868,573.353,1],
  ["68a58950-ac5b-11e6-80f5-76304dec7eb7",-23.20472304,-45.90842302,574.27,1],
  ["68a58a90-ac5b-11e6-80f5-76304dec7eb7",-23.20486603,-45.9082755,573.877,1],
  ["68a58bd0-ac5b-11e6-80f5-76304dec7eb7",-23.20476495,-45.9079885,572.45,1],
  ["68a58d06-ac5b-11e6-80f5-76304dec7eb7",-23.20473537,-45.90786244,571.853,1],
  ["68a59850-ac5b-11e6-80f5-76304dec7eb7",-23.20468853,-45.90772833,571.206,1],
  ["68a58e46-ac5b-11e6-80f5-76304dec7eb7",-23.2048537,-45.90783025,571.882,1],
  ["68a59512-ac5b-11e6-80f5-76304dec7eb7",-23.20490054,-45.90774442,571.557,1],
  ["68a596c0-ac5b-11e6-80f5-76304dec7eb7",-23.20509776,-45.90773369,571.79,1],
  ["68a599c2-ac5b-11e6-80f5-76304dec7eb7",-23.20521609,-45.90796705,572.93,1]
]

var LM35 = function(uuid, timestamp, value, location) {
  this.uuid = uuid
  this.timestamp = timestamp
  this.value = value
  this.location = location
}

var Value = function(temperature) {
  this.temperature = temperature
}

var Location = function(latitude, longitude, altidude) {
  this.latitude = latitude
  this.longitude = longitude
  this.altidude = altidude
}

var random = function(min, max) {
  return Math.random() * (max - min) + min
}

var timestamp = moment().valueOf()

sensors.forEach(function(entry) {
  var value = new Value(random((20 * entry[4]), (21 * entry[4])))
  var location = new Location(entry[1], entry[2], entry[3])
  var sensor = new LM35(entry[0], timestamp, value, location)

  client.publish(sensor.uuid, JSON.stringify(sensor))
})

client.end()
