var mqtt = require('mqtt')
var moment = require('moment')

require('events').EventEmitter.prototype._maxListeners = 100;

var client  = mqtt.connect('mqtt://sigtrac-1316363234.sa-east-1.elb.amazonaws.com')

var sensors = [
  ['3713c444-98d6-11e6-ae22-56b6b6499611',-23.216235398215513,-45.89347949637158,605.178],
  ['3713c37c-98d6-11e6-ae22-56b6b6499611',-23.216570639642338,-45.89349022520764,606.023],
  ['3713c2a0-98d6-11e6-ae22-56b6b6499611',-23.216590359700067,-45.89380136145337,605.799],
  ['3713bfb2-98d6-11e6-ae22-56b6b6499611',-23.21680235013679,-45.893447309863404,606.666],
  ['3713beea-98d6-11e6-ae22-56b6b6499611',-23.217034060229295,-45.8935009540437,606.305],
  ['3713be2c-98d6-11e6-ae22-56b6b6499611',-23.216417809096228,-45.89287868155225,605.489],
  ['3713bd64-98d6-11e6-ae22-56b6b6499611',-23.217048850221552,-45.89289477480634,606.441],
  ['3713bc9c-98d6-11e6-ae22-56b6b6499611',-23.216674169912938,-45.89288404597028,605.981],
  ['3713bbca-98d6-11e6-ae22-56b6b6499611',-23.217093220188502,-45.892460256945924,606.077],
  ['3713bad0-98d6-11e6-ae22-56b6b6499611',-23.217122800158272,-45.89203646792157,605.509],
  ['3713b6e8-98d6-11e6-ae22-56b6b6499611',-23.216753050065254,-45.890904575717286,599.544],
  ['3713b620-98d6-11e6-ae22-56b6b6499611',-23.217073500205004,-45.89131227148755,602.213],
  ['3713b544-98d6-11e6-ae22-56b6b6499611',-23.21709815018392,-45.89057198179944,598.322],
  ['3713b30a-98d6-11e6-ae22-56b6b6499611',-23.217275629897756,-45.890915304553346,600.295],
  ['3713b22e-98d6-11e6-ae22-56b6b6499611',-23.217517199129325,-45.89136055124982,602.543],
  ['3713ae00-98d6-11e6-ae22-56b6b6499611',-23.217260839930614,-45.8918433488725,604.998],
  ['3713ad24-98d6-11e6-ae22-56b6b6499611',-23.21749747920843,-45.891950637233094,605.921]
]

var DHT11 = function(uuid, timestamp, value, location) {
  this.uuid = uuid
  this.timestamp = timestamp
  this.value = value
  this.location = location
}

var Value = function(temperature, humidity) {
  this.temperature = temperature
  this.humidity = humidity
}

var Location = function(latitude, longitude, altidude) {
  this.latitude = latitude
  this.longitude = longitude
  this.altidude = altidude
}

var random = function(min, max) {
  return Math.random() * (max - min) + min;
}

var timestamp = moment().valueOf()

sensors.forEach(function(entry) {
  var value = new Value(random(20, 21), random(10, 11))
  var location = new Location(entry[1], entry[2], entry[3])
  var sensor = new DHT11(entry[0], timestamp, value, location)

  client.publish(sensor.uuid, JSON.stringify(sensor))
})

client.end()