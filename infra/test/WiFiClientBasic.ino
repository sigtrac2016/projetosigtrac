/*
 *  This sketch sends a message to a TCP server
 *
 */

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

ESP8266WiFiMulti WiFiMulti;

const char* ssid = "MOTOROLA-7CAE8";
const char* password = "a0ca6d5c8e11141d085d";
const char* host = "192.168.0.3";
const uint16_t port = 25135;

const int buttonPin = 5;     // the number of the GPIO pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
      // initialize the pushbutton pin as an input:
    pinMode(buttonPin, INPUT);
  
    Serial.begin(115200);
    delay(10);

    // We start by connecting to a WiFi network
    WiFiMulti.addAP(ssid, password);

    Serial.println();
    Serial.println();
    Serial.print("Wait for WiFi... ");

    while(WiFiMulti.run() != WL_CONNECTED) {
        Serial.print(".");
        delay(500);
    }

    Serial.println("");
    Serial.println("WiFi connected");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    delay(500);

    connect();
}

// Use WiFiClient class to create TCP connections
WiFiClient client;
    
void connect(){
  
    Serial.print("connecting to ");
    Serial.println(host);
    
    client.stop();
}

void loop() {
    

    if (!client.connect(host, port)) {
        Serial.println("connection failed");
        Serial.println("wait 5 sec...");
        delay(5000);
        
        connect();
        //return;
    }

    buttonState = digitalRead(buttonPin);

    if(buttonState == LOW)
    {
      // This will send the request to the server
      client.print("Sinal de alerta !!!");
    }
    
    //read back one line from server
    //String line = client.readStringUntil('\r');
    //client.println(line);

    //Serial.println("closing connection");
    //client.stop();
    
    //Serial.println("wait 5 sec...");
    delay(50);
}

