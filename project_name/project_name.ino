#include "Application.h"

Application myApplication;

void setup() 
{
  // put your setup code here, to run once:
  //myApplication.init();
  pinMode(16,OUTPUT);
  pinMode(13,INPUT);
}

void loop() 
{
  // put your main code here, to run repeatedly:
  //myApplication.run();
  digitalWrite(16,LOW);
  delay(1000);
  digitalWrite(16,HIGH);
  
}
