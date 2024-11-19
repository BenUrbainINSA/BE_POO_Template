#include "Menu.h"

Menu::Menu(int potPin, int button, rgb_lcd lcd) :  potentiometerPin(potPin), buttonPin(buttonPin), lcd(lcd), currentSelection(0), lastPotValue(-1){}

void Menu::init(){
  pinMode(buttonPin,INPUT);
  pinMode(potentiometerPin,INPUT);
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

  if (instruments.empty()) {
    instruments.push_back("Clarinette");
    instruments.push_back("feur");
    instruments.push_back("Courgette");
  }
}

void Menu::update(){
  int potValue = analogRead(potentiometerPin);
  Serial.println(potValue);
  int mappedValue = map(potValue,0,1023,0,instruments.size() -1);

    if (mappedValue != lastPotValue) {
      currentSelection = mappedValue;
      displayMenu();
      lastPotValue = mappedValue;
  }
}

void Menu::displayMenu(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Instrument:");
  lcd.setCursor(0, 1);
  lcd.print("> ");
  lcd.print(instruments[currentSelection].c_str());
}

void Menu::handleSelection(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selected:");
  lcd.setCursor(0, 1);
  lcd.print(instruments[currentSelection].c_str());
  delay(1000); // Pause pour afficher la sélection
  displayMenu(); // Retour au menu
}


void Menu::addIntrument(const std::string &instrument){
  Menu::instruments.push_back(instrument);
}

const std::string& Menu::getInstrument(){
  return instruments[currentSelection];
}