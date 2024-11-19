#include "Menu.h"

Menu::Menu(int potPin, int button, rgb_lcd& lcd) :  potentiometerPin(potPin), buttonPin(buttonPin), lcd(lcd), currentSelection(0), lastPotValue(-1){}

void Menu::init(){
  pinMode(buttonPin,INPUT);
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

  if (instruments.empty()) {
    instruments.push_back("Clarinette");
  }
}

void Menu::update(){}
void Menu::displayMenu();
void Menu::handleSelection();


void Menu::addIntrument(const std::string &instrument){
  Menu::instruments.push_back(instrument);
}

const std::string& getInstrument(){
  return instruments[currentSelection];
}