#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <Arduino.h>
#include <Wire.h>
#include "rgb_lcd.h"

class Menu{

private:
  //Pin 
  int potentiometerPin;
  int buttonPin;
  
  //LCD 
  rgb_lcd& lcd;
  const int colorR = 255;
  const int colorG = 255;
  const int colorB = 255;

  //Instrument 
  std::vector<std::string> instruments;

  // Etat menu
  int currentSelection;
  int lastPotValue;

  // methode utilisée en interne : 
  void displayMenu();
  void handleSelection();

public:
  Menu(int potPin, int button, rgb_lcd& lcd);
  void init();
  void update();
  const std::string& getInstrument();
  void addIntrument(const std::string& instrument);

};


#endif