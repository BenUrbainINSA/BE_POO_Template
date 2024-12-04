#include "Application.h"
#include "Menu.h"
#include <Wire.h>
#include "rgb_lcd.h"


Application myApplication;

void setup() 
{
  // Initialiser l'application
  myApplication.init();
}

void loop() 
{
  // Lancer l'application (mettre à jour le menu)
  myApplication.run();
}
