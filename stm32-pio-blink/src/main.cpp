#include <Arduino.h>

void setup() 
{
  pinMode(PC13, OUTPUT);
  Serial.begin(115200);
}

int count = 0;

void loop() 
{
  digitalWrite(PC13, HIGH);
  delay(500);
  digitalWrite(PC13, LOW);
  delay(500);
  
  count++;
  Serial.print("Hello ");
  Serial.println(count);
}