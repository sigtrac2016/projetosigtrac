var app = require('express')()
var http = require('http').Server(app)
var io = require('socket.io')(http)
var mqtt = require('mqtt')

var client  = mqtt.connect('mqtt://52.67.204.136')
 
client.on('connect', function(){
    client.subscribe('live')
})

app.get('/', function(req, res){
  res.sendFile(__dirname + '/lm35.html')
})

app.get('/static', function(req, res){
  res.sendFile(__dirname + '/static.html')
})

app.get('/data', function(req, res){
  res.sendFile(__dirname + '/data.js')
})

io.on('connection', function(socket){
  client.on('message', function (topic, message) {
    io.emit('message', message.toString())
  })
})

http.listen(80, function(){
  console.log('listening on *:80')
})
