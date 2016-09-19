var config = {};
function buildUrl(obj) {
  return obj.protocol + "://" + obj.ip + ":" + obj.port + "/" + obj.postfix;
}

config.mqtt = {
  port: 1883,
  ip: "localhost",
  protocol: "mqtt",
  postfix: "",
  getUrl: function() { return buildUrl(this); },
  channels: ["update-sensor", "new-sensor", "test"]
};

config.api = {
  port: 8080,
  ip: "192.168.0.20",
  protocol: "http",
  postfix: "api/",
  getUrl: function() { return buildUrl(this); },
};

config.mongo = {
  port: 27017,
  ip: "localhost",
  protocol: "mongodb",
  postfix: "",
  getUrl: function() { return buildUrl(this); },
};

module.exports = config;
