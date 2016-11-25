#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <PubSubClient.h>

const char* SSID = "MOTOROLA-7CAE8"; //Seu SSID da Rede WIFI
const char* PASSWORD = "a0ca6d5c8e11141d085d"; // A Senha da Rede WIFI
const char* MQTT_SERVER = "iot.eclipse.org"; //Broker de teste

long lastMsg = 0;
const int buttonPin = 5;     // the number of the GPIO pin
int buttonState = 0;         // variable for reading the pushbutton status
int buttonflag = LOW;

int   id = 4;
float latitude = 0.0, longitude = 0.0;
char*  segmento = "P";
String  titulo = " ", descricao  = " ", foto = " ", status  = "reforcos", data  = "2016:10:26", hora  = "23:46:10";

String buildJson() {
  String data = "{";
  data+="id: ";
  data+=(int)id;
  data+= ",";
  
  data+="titulo :";
  data+= (String)titulo;
  data+= ",";
  
  data+="segmento: ";
  data+= (char*)segmento;
  data+= ",";
  
  data+="descricao: ";
  data+= (String)descricao;
  data+= ",";
  
  data+="lat: ";
  data+=(float)latitude;
  data+= ",";
  
  data+="long: ";
  data+=(float)longitude;
  data+= ",";
  
  data+="foto: ";
  data+= (String)foto;
  data+= ",";
  
  data+="data_hora: ";
  data+="}";
  return data;
}


WiFiClient CLIENT;
PubSubClient MQTT(CLIENT);


//CONFIGURAÇÃO DA INTERFACE DE REDE
void setupWIFI() {
  WiFi.begin(SSID, PASSWORD);
  Serial.print("Conectando na rede: ");
  Serial.println(SSID);
  while (WiFi.status() != WL_CONNECTED) {
   Serial.print(".");
   delay(500);
  }
}
void setup(void) {
  Serial.begin(115200);
  setupWIFI(); 
  MQTT.setServer(MQTT_SERVER, 1883);
}
void reconectar() {
  while (!MQTT.connected()) {
    Serial.println("Conectando ao Broker MQTT.");
    if (MQTT.connect("ESP8266")) {
      Serial.println("Conectado com Sucesso ao Broker");
    } else {
      Serial.print("Falha ao Conectador, rc=");
      Serial.print(MQTT.state());
      Serial.println(" tentando se reconectar...");
      delay(3000);
    }
  }
}
void loop(void) {
  if (!MQTT.connected()) {
    reconectar();
  }
  MQTT.loop();
  String json = buildJson();
  char jsonStr[320];
  json.toCharArray(jsonStr,320);
  
  long now = millis();
  if (now - lastMsg > 100) {
    lastMsg = now;
    
    buttonState = digitalRead(buttonPin);

    if((buttonState == LOW) && (buttonflag == LOW))
    {
      MQTT.publish("/sigtrac2016/ts04/panic/", jsonStr);
      Serial.println(jsonStr);
      buttonflag = HIGH;
    }
    else buttonflag = LOW;
  }
}


