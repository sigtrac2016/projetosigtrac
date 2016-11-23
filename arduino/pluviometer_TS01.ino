/*
SIG-TRAC 2016
 TS #01 - Civil Defense
 A simple mocked embedded system to simulate a real crisis.
 
 Circuit:
 * Ethernet shield attached arduino UNO
 * Connect a 1K Ohm potentiometer in +5V, GND and A0
 
 Based upon Web Server by Tom Igoe and David Mellis
 
 Edit history: 
 created 18 Dec 2009
 by David A. Mellis
 modified 22 Nov 2016
 by TS #01 - Civil Defense
 */


#include <Ethernet.h>
#include <SPI.h>
#include "RestClient.h"

RestClient client = RestClient("192.168.0.10",8080); //need to be the IP of your computer

int value =0;
int pluviometer = A0;

//Setup
void setup() {
  Serial.begin(9600);
  // Connect through DHCP
  Serial.println("connect to network");
  client.dhcp();
/*
  // Can still fall back to manual config:
  byte mac[] = { 0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  //the IP address for the shield:
  byte ip[] = { 192, 168, 2, 11 };
  Ethernet.begin(mac,ip);
*/
  Serial.println("Setup!");
}

String response;
void loop(){
  //read sensor
  value = analogRead(pluviometer);
  value = value*0.15;

  if(value > 70){
  //POST
  String aux("lat=21&long=30%2e123&segmento=c&titulo=Alerta do Pluviometro 37215&descricao=Valor de chuva acumulada :" + (String)value + " mm");
  char *data = malloc((aux.length()+2) *sizeof(char));
  strcpy(data, aux.c_str());
  response = "";
  int statusCode = client.post("/api/chamados", data, &response);
  Serial.print("Status code from server: ");
  Serial.println(statusCode); // 200 OK
  Serial.print("Response body from server: ");
  Serial.println(response);
  //END POST
  
  while(statusCode != 200){
    statusCode = client.post("/api/chamados", data, &response);
    Serial.print("Status code from server: ");
    Serial.println(statusCode); // 200 OK
    Serial.print("Response body from server: ");
    Serial.println(response);
  }
  delay(120*60000); //to the arduino doesn't flood the database
  }
}

