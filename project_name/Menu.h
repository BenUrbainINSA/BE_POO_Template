#ifndef MENU_H
#define MENU_H

#include <iostream>
#include <vector>
#include <string>
#include <Arduino.h>
#include <Wire.h>
#include "rgb_lcd.h"
#include "Instrument.h"
#include "Guitare.h"
#include "Triangle.h"
#include <memory> // pour std::unique_ptr



class Menu{

private:
  //Pin 
  int potentiometerPin;
  int buttonPin;

  //etat du menu 
  int state = -1;
  
  //LCD 
  rgb_lcd& lcd;
  const int colorR = 255;
  const int colorG = 255;
  const int colorB = 255;

  //Instrument 
  std::vector<Instrument*> instruments;

  //file de lecture 
  std::vector<Instrument*> Lecture;


  // Etat menu
  int currentSelection;
  int lastPotValue;

  // methode utilisée en interne : 
  void handleSelection();
  void handlePlacement();
  void displayMainMenu();
  void displayMenuInstrument();
  void displayPlacementMenu(int position);
  void placeInstrument(int position);
  void jouerMelodie(int tempo);

public:
  Menu(int potPin, int button, rgb_lcd lcd);
  ~Menu();
  void init();
  void update();
//  const Instrument getInstrument();
//  void addIntrument(const Instrument instrument);

};


#endif