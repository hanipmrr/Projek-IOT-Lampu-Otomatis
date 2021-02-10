#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#define LED1  D1
#define LED2  D2
#define LED3  D3
#define LED4  D4
#define sensor A0

char auth[] = "TjyMx9cxTg-XnQ0PFASO9z7mBVLsAh_J";
char ssid[] = "hnp";
char pass[] = "11111111";
//int IntensitasLDR;
unsigned long start, finished, elapsed;

BlynkTimer timer;


void sendSensor()
{
  int LDR = analogRead(sensor);

  
    if(LDR <15)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    finished=millis();
  Serial.println("LIGHT ON");
  elapsed=finished-start;
  Serial.print(elapsed);
  Serial.println(" milliseconds elapsed");
  Serial.println();
  }
  else
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
     Serial.println("LIGHT OFF");
  start=millis();
   }
}

void setup()
{
  // Debug console
  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  timer.setInterval(500L, sendSensor);

}

void loop()
{
  Blynk.run();
  timer.run();
  //IntensitasLDR = analogRead (sensor);               
  //Serial.print ("Intensitas: ");                                 
  //Serial.println (IntensitasLDR);  
  delay (100);
}

BLYNK_WRITE (V1){
int pinValue=param.asInt();
if (pinValue==0) {
    digitalWrite(LED1, HIGH);
    delay(2000);
    finished=millis();
  Serial.println("LIGHT ON");
  elapsed=finished-start;
  Serial.print(elapsed);
  Serial.println(" milliseconds elapsed");
  Serial.println();
    
}else {
    digitalWrite(LED1, LOW);
    Serial.println("LIGHT OFF");
  start=millis();
}
}

BLYNK_WRITE (V2){
int pinValue=param.asInt();
if (pinValue==0) {
    digitalWrite(LED2, HIGH);
    delay(2000);
    finished=millis();
  Serial.println("LIGHT ON");
  elapsed=finished-start;
  Serial.print(elapsed);
  Serial.println(" milliseconds elapsed");
  Serial.println();
    
}else {
    digitalWrite(LED2, LOW);
    Serial.println("LIGHT OFF");
  start=millis();
}
}

BLYNK_WRITE (V3){
int pinValue=param.asInt();
if (pinValue==0) {
    digitalWrite(LED3, HIGH);
    delay(2000);
    finished=millis();
  Serial.println("LIGHT ON");
  elapsed=finished-start;
  Serial.print(elapsed);
  Serial.println(" milliseconds elapsed");
  Serial.println();
    
}else {
    digitalWrite(LED3, LOW);
    Serial.println("LIGHT OFF");
  start=millis();
}
}

BLYNK_WRITE (V4){
int pinValue=param.asInt();
if (pinValue==0) {
    digitalWrite(LED4, HIGH);
    delay(2000);
    finished=millis();
  Serial.println("LIGHT ON");
  elapsed=finished-start;
  Serial.print(elapsed);
  Serial.println(" milliseconds elapsed");
  Serial.println();
    
}else {
    digitalWrite(LED4, LOW);
    Serial.println("LIGHT OFF");
  start=millis();
}
}
