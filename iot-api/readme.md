## Fazer os passos na seguinte ordem
##### Rodar DB
```bash
mongod
```
##### Rodar Server
```bash
node server/app.js
```
##### Rodar Broker
###### Node mosca
```bash
node mqtt/Broker
```

###### Docker sigtrac
```bash
docker run -d -h mqtt --name mqtt -p 1883:1883 projetosigtrac/mosquitto
```
##### Rodar Cliente
```bash
node mqtt/Client
```

##OR
If mongod running:
```bash
npm start
```
