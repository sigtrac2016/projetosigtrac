// KAFKA=IP_SERVER MQTT=IP_SERVER npm start

var kafka = require('kafka-node')
var client = new kafka.Client(process.env.KAFKA)
var producer = new kafka.Producer(client)

var mqtt = require('mqtt')
var consumer = mqtt.connect('mqtt://' + process.env.MQTT)
 
consumer.on('connect', function () {
  consumer.subscribe('#')
})

consumer.on('message', function (topic, message) {
  producer.createTopics([topic.toString()], true, function (err, data) {
    if (err) {
      console.error('There was an error building the topic!', err)
      return
    }
    console.log(data)
  	producer.send([{topic: topic.toString(), messages: message.toString()}], function (err, data) {
      if (err) {
        console.error('There was an error sending the topic!', err)
        return
      }
      console.log(data)
  	})
  })
})