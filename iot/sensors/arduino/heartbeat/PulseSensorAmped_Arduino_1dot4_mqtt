
/* 
Codigo para leitura de batimentos cardiacos e envio para servidor MQTT
*/

#include <SPI.h>
#include <Ethernet.h>
#include <PubSubClient.h>

// Update these with values suitable for your network.
byte mac[]    = {  0x0E, 0xED, 0xBA, 0xFE, 0x02, 0x1D };
IPAddress ip(192, 168, 10, 100);
IPAddress dnServer(8, 8, 4, 4);
IPAddress gateway(192, 168, 10, 1);
IPAddress subnet(255, 255, 255, 0);

char message_buff[400];

EthernetClient ethClient;
PubSubClient client(ethClient);

//  Sensor Variables
int pulsePin = 0;                 // Pulse Sensor purple wire connected to analog pin 0
int blinkPin = 13;                // pin to blink led at each beat
int fadePin = 5;                  // pin to do fancy classy fading blink at each beat
int fadeRate = 0;                 // used to fade LED on with PWM on fadePin

// Volatile Variables, used in the interrupt service routine!
volatile int BPM;                   // int that holds raw Analog in 0. updated every 2mS
volatile int Signal;                // holds the incoming raw data
volatile int IBI = 600;             // int that holds the time interval between beats! Must be seeded! 
volatile boolean Pulse = false;     // "True" when User's live heartbeat is detected. "False" when not a "live beat". 
volatile boolean QS = false;        // becomes true when Arduoino finds a beat.

// Regards Serial OutPut  -- Set This Up to your needs
static boolean serialVisual = false;   // Set to 'false' by Default.  Re-set to 'true' to see Arduino Serial Monitor ASCII Visual Pulse 

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

void setup(){
  pinMode(blinkPin,OUTPUT);         // pin that will blink to your heartbeat!
  pinMode(fadePin,OUTPUT);          // pin that will fade to your heartbeat!
  Serial.begin(115200);             // we agree to talk fast!
  interruptSetup();                 // sets up to read Pulse Sensor signal every 2mS 
   // IF YOU ARE POWERING The Pulse Sensor AT VOLTAGE LESS THAN THE BOARD VOLTAGE, 
   // UN-COMMENT THE NEXT LINE AND APPLY THAT VOLTAGE TO THE A-REF PIN
//   analogReference(EXTERNAL);   

  //Serial.begin(57600);
  client.setServer("sigtrac-1316363234.sa-east-1.elb.amazonaws.com", 1883);
  Ethernet.begin(mac, ip, dnServer, gateway, subnet);
  // Allow the hardware to sort itself out
  delay(1500);
}


//  Where the Magic Happens
void loop(){
  
    serialOutput() ;       
    
  if (QS == true){     // A Heartbeat Was Found
                       // BPM and IBI have been Determined
                       // Quantified Self "QS" true when arduino finds a heartbeat
        fadeRate = 255;         // Makes the LED Fade Effect Happen
                                // Set 'fadeRate' Variable to 255 to fade LED with pulse
        serialOutputWhenBeatHappens();   // A Beat Happened, Output that to serial.     
        QS = false;                      // reset the Quantified Self flag for next time 

        // If heartbeat is found, send the value to MQTT
        if (!client.connected()) {
            reconnect();
        }
        client.loop();
 
        String pubString = "{\"name\": \"Sensor de Frequencia Cardiaca\", "
                           " \"alias\": messageName, "
                           " \"type\": \"HeartBeat\", "
                           " \"timestamp\": \"timestamp\", "
                           " \"patientName\": \"patientName\", "
                           " \"BPM\": " + String(BPM) + "}";
 
        pubString.toCharArray(message_buff, pubString.length()+1);
        //Serial.println(pubString);
        client.publish("outTopic", message_buff);
        delay(2000);
        client.loop();   
  }
     
  ledFadeToBeat();                      // Makes the LED Fade Effect Happen 
  delay(20);                             //  take a break
}

void ledFadeToBeat(){
    fadeRate -= 15;                         //  set LED fade value
    fadeRate = constrain(fadeRate,0,255);   //  keep LED fade value from going into negative numbers!
    analogWrite(fadePin,fadeRate);          //  fade LED
  }
