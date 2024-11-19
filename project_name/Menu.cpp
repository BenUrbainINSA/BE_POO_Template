#include "Menu.h"

Menu::Menu(int potPin, int button, rgb_lcd lcd) :  potentiometerPin(potPin), buttonPin(buttonPin), lcd(lcd), currentSelection(0), lastPotValue(-1){}

//fonction qui initialise le menu, donc setup du boutton, du potentiometre et de l'écran.
void Menu::init(){   
  pinMode(buttonPin,INPUT);
  pinMode(potentiometerPin,INPUT);
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);

  if (instruments.empty()) {    //Remplis la liste d'instrument. On peut ptt mettre une interuption ici 
    instruments.push_back("Clarinette");
    instruments.push_back("feur");
    instruments.push_back("Courgette");
  }
}

//Fonction qui met a jour l'affichage de l'ecran lorsque qu'il recoit une entrée. Potentiomètre fait defilier les instruments, boutton les selectionne.
void Menu::update(){
  int potValue = analogRead(potentiometerPin);
  int mappedValue = map(potValue,0,1023,0,instruments.size() -1);   //on remap la valeur analogique sur la taille de la liste d'instruments 

    if (mappedValue != lastPotValue) {  //si la valeur lu est different on update l'ecran 
      currentSelection = mappedValue;
      displayMenu();
      lastPotValue = mappedValue;
    }

    //Si on appuis sur le boutton on selection l'instrument.
}

//Affiche le menu et l'intrument selectionné pour le moment 
void Menu::displayMenu(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Instrument:");
  lcd.setCursor(0, 1);
  lcd.print("> ");
  lcd.print(instruments[currentSelection].c_str());
}

//Change l'affichage du menu lorsque l'on selection un objet pour montrer qu'on a interagis avec l'instrument 
void Menu::handleSelection(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selected:");
  lcd.setCursor(0, 1);
  lcd.print(instruments[currentSelection].c_str());
  delay(1000); // Pause pour afficher la sélection
  displayMenu(); // Retour au menu
}


//Permet d'ajouter un instrument lors du debugage ou si on crée une fonction de creation d'instruments dynamique, à voir si on a le temps 
void Menu::addIntrument(const std::string &instrument){
  Menu::instruments.push_back(instrument);
}

const std::string& Menu::getInstrument(){
  return instruments[currentSelection];
}