var config = {};
function buildUrl(obj) {
  return obj.protocol + "://" + obj.ip + ":" + obj.port + "/" + obj.postfix;
}

config.mqtt = {
  port: 1883,
  ip: "192.168.99.100",
  protocol: "mqtt",
  postfix: "",
  getUrl: function() { return buildUrl(this); },
  channels: ["update-sensor", "new-sensor", "test"]
};

module.exports = config;
