module.exports = {
    mqtt: {
        production: `mqtt://${process.env.MQTT_ADDRESS}:1883`,
        development: `mqtt://${process.env.MQTT_ADDRESS}:1883`,
        channels: ["update-sensor", "new-sensor", "test"]
    },

    api: {
      production: `http://${process.env.API_ADDRESS}:8080/api/`,
      development: `http://${process.env.API_ADDRESS}:8080/api/`,
    }
};
