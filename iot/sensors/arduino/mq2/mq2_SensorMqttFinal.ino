#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

#define MQTT_MAX_PACKET_SIZE 2048

int pin_led_verm = 8;
int pin_led_verde = 9;
byte mac[]    = {  0x90, 0xA2, 0xDA, 0x0D, 0x80, 0x68 };
IPAddress ip(192, 168, 76, 47);
IPAddress myDns(8,8,4, 4);
IPAddress gateway(192, 168, 0, 1);
IPAddress subnet(255, 255, 255, 0);
IPAddress server(85, 119, 83, 194);
//85.119.83.194 = test.org
//char server[] = "test.mosquitto.org";
//char server[] = "sigtrac-1316363234.sa-east-1.elb.amazonaws.com";

EthernetClient ethClient;
PubSubClient client(ethClient);

int pin_buzzer = 10;
int pin_d0 = 7;
int pin_a0 = A2;
int nivel_sensor = 100;
bool firstMsg;


// Entra em loop e so termina se conseguir se conectar ao servidor
void reconnect() {
  while (!client.connected()) {
    Serial.print("Tentando se conectar ao servidor...");

    if (client.connect("arduinoClient")) {
      Serial.println("conectado");

//    Serial.print("Se cadastrando no servidor...");
      String valor = "StringGas";
      String json = "{\"alias\": \"0x90,0xA2,0xDA,0x0D,0x80,0x68\", \"name\": \"Smoke\", \"value\": { \"nivelGas\": \"" + valor + "\"}, \"type\": \"MQ-2\"}";
      int str_len = json.length() + 1;
      char charBuf[str_len];
      json.toCharArray(charBuf, str_len); 
      client.publish("new-sensor",charBuf);
//    Serial.println("cadastrado");

    } else {
      Serial.print("falhou, codigo de erro=");
      Serial.print(client.state());
      Serial.println(" tentando novamente em 5s");
      delay(5000);
    }
  }
}

void setup()
{
  // Iniciando leds e sirene do sensor
  pinMode(pin_d0, INPUT);
  pinMode(pin_a0, INPUT);
  pinMode(pin_led_verde, OUTPUT);
  pinMode(pin_buzzer, OUTPUT);
  pinMode(pin_led_verm, OUTPUT);

  Serial.begin(57600);

  // Iniciando conexao de rede
  Ethernet.begin(mac);  
  client.setServer(server, 1883);
  Serial.print("IP = ");
  Serial.println(Ethernet.localIP());

  firstMsg = false;

  delay(1500);
}

// Envia dados do sensor para servidor
void sendInf(int valor_analogico)
{
  Serial.print("Enviando mensagem para servidor...");

  String json = "{\"alias\": \"0x90,0xA2,0xDA,0x0D,0x80,0x68\", \"value\": { \"nivelGas\": \"" + String(valor_analogico) + "\"}}";
  int str_len = json.length() + 1;
  char charBuf[str_len];
  json.toCharArray(charBuf, str_len); 
  client.publish("MQ2",charBuf);

  Serial.println("Mensagem enviada");
}

void loop()
{
  // Lendo entradas
  int valor_digital = digitalRead(pin_d0);
  int valor_analogico = analogRead(pin_a0);
  Serial.print("Pino D0 : ");
  Serial.print(valor_digital);
  Serial.print(" Pino A0 : ");
  Serial.println(valor_analogico);

  // Testa se valor lido eh acima do critico 
  if (valor_analogico > nivel_sensor)
  {  
    digitalWrite(pin_buzzer, HIGH);          // Aciona a sirene
    
    digitalWrite(pin_led_verm, HIGH);
    digitalWrite(pin_led_verde, LOW);
    if (firstMsg) {
      while (!client.connected()) reconnect(); // Garante a conexao com o servidor
      sendInf(valor_analogico);                // Envia dados ao servidor
    }
    firstMsg = false;
  }
  else
  {
    firstMsg = true;
    digitalWrite(pin_buzzer, LOW);           // Desativa a sirene
    
    digitalWrite(pin_led_verm, LOW);
    digitalWrite(pin_led_verde, HIGH);
  }
  delay(100);
}
