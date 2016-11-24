var app = require('express')()
var http = require('http').Server(app)
var io = require('socket.io')(http)
var mqtt = require('mqtt')

var client  = mqtt.connect('mqtt://virtual10-147.cptec.inpe.br')
 
client.on('connect', function(){
    client.subscribe('#')
})

app.get('/', function(req, res){
  res.sendFile(__dirname + '/index.html')
})

app.get('/lm35', function(req, res){
  res.sendFile(__dirname + '/map.html')
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
