/*
 Envia dados de temperatura usando MQTT 
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>
//#include <aJSON.h>

// Update these with values suitable for your network.
byte mac[]    = {  0x0E, 0xED, 0xBA, 0xFE, 0x02, 0x1D };
IPAddress ip(192, 168, 10, 100);
IPAddress dnServer(8, 8, 4, 4);
IPAddress gateway(192, 168, 10, 1);
IPAddress subnet(255, 255, 255, 0);

//Sensor de temperatura usando o LM35
const int LM35 = A0; // Define o pino que lera a saída do LM35
float temperatura; // Variável que armazenará a temperatura medida
char message_buff[400];

EthernetClient ethClient;
PubSubClient client(ethClient);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("arduinoClient")) {
      Serial.println("connected");
      // Once connected, publish an announcement...
      //client.publish("outTopic","hello world");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup()
{
  Serial.begin(57600);
  client.setServer("sigtrac-1316363234.sa-east-1.elb.amazonaws.com", 1883);
  Ethernet.begin(mac, ip, dnServer, gateway, subnet);
  // Allow the hardware to sort itself out
  delay(1500);
}

void loop()
{
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  temperatura = (float(analogRead(LM35))*5/(1023))/0.01;
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  String pubString = "{\"name\": \"Sensor de Temperatura\", \"alias\": messageName, \"type\": \"Temp\", \"value\": {\"temperature\": \"" + String(temperatura) + "\", \"humi}}";
  //String pubString = "{\"name\": \"Sensor de Temperatura\", \"alias\": messageName, \"type\": \"Temp\", \"value\": {\"temperature\": \"" + String(temperatura) + "\", \"humidity\": 00}, \"location\": {\"latitude\": 10, \"longitude\": 060, \"altitude\": 3000}}";
  pubString.toCharArray(message_buff, pubString.length()+1);
  //Serial.println(pubString);
  client.publish("outTopic", message_buff);
  delay(2000);
  client.loop();
}
