/*************************************************************
  Download latest Blynk library here:
    https://github.com/blynkkk/blynk-library/releases/latest

  Blynk is a platform with iOS and Android apps to control
  Arduino, Raspberry Pi and the likes over the Internet.
  You can easily build graphic interfaces for all your
  projects by simply dragging and dropping widgets.

    Downloads, docs, tutorials: http://www.blynk.cc
    Sketch generator:           http://examples.blynk.cc
    Blynk community:            http://community.blynk.cc
    Follow us:                  http://www.fb.com/blynkapp
                                http://twitter.com/blynk_app

  Blynk library is licensed under MIT license
  This example code is in public domain.

 *************************************************************
  This example runs directly on ESP8266 chip.

  Note: This requires ESP8266 support package:
    https://github.com/esp8266/Arduino

  Please be sure to select the right ESP8266 module
  in the Tools -> Board menu!

  Change WiFi ssid, pass, and Blynk auth token to run :)
  Feel free to apply it to any other example. It's simple!
 *************************************************************/

/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial


#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "JQ97bn1je7kORnFW664NwIRK7usgYyIy";

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "sakib";
char pass[] = "22222222";

int sensorPin = A0; 
int sensorValue;  
int limit = 25; 
int state =0;
void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass);
  //Blynk.notify("Hey, Blynkers! My hardware can push now!");

   Serial.begin(9600);
 pinMode(D1, OUTPUT);
 pinMode(D0, OUTPUT);
}

void loop()
{
 sensorValue = analogRead(sensorPin); 
 sensorValue=map(sensorValue, 0, 1023, 0, 100);
 Serial.println("Analog Value : ");
 Serial.println(sensorValue);
 Serial.println(state);
 if (sensorValue>limit) {
 digitalWrite(D1, HIGH); 
 digitalWrite(D0, HIGH);

 if(state==1){
 Blynk.notify("The moisture value is low. So the Pump is turned on.");
 state=0;
 }
 }
 else {
 digitalWrite(D1, LOW); 
 digitalWrite(D0,LOW);
 
 if(state==0){
 Blynk.notify("The moisture value is normal. So the Pump is turned off.");
 state=1;
 }
 }
 
 delay(1000);
  
  Blynk.run();
}
