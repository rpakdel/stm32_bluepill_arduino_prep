#include <Arduino.h>

void setup() 
{
  pinMode(PC13, OUTPUT);
  Serial.begin(115200);
}

void loop() 
{
  digitalWrite(PC13, HIGH);
  delay(1000);
  digitalWrite(PC13, LOW);
  delay(1000);
  Serial.println("Hello2");
}