#include "Application.h"
#include "Menu.h"
#include <Wire.h>
#include "rgb_lcd.h"


Application myApplication;

void setup() 
{
    Serial.begin(9600);

  // Initialiser l'application
  myApplication.init();
}

void loop() 
{
  // Lancer l'application (mettre à jour le menu)
  myApplication.run();
}
