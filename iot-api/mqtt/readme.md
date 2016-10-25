# Dummy Clients

node ./Client/dummies/update.js [channel] [alias] [new-value]
node ./Client/dummies/create.js [channel] [alias]

# Current Channels:

new-sensor: redirects the message as a POST call to api/sensores

update-sensor: redirects the message as a PATCH call to api/sensores/:alias

### see [Schema](../server/src/models/sensor) of api/sensores
