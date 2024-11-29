#include "Menu.h"

Menu::Menu(int potPin, int button, rgb_lcd lcd) :  potentiometerPin(potPin), buttonPin(button), lcd(lcd), currentSelection(0), lastPotValue(-1){}
Menu::~Menu(){}



//fonction qui initialise le menu, donc setup du boutton, du potentiometre et de l'écran.
void Menu::init(){
  Serial.println("buttonPin");
   
  Serial.println(buttonPin);
  pinMode(buttonPin,INPUT);
  pinMode(potentiometerPin,INPUT);
  lcd.begin(16,2);
  lcd.setRGB(colorR, colorG, colorB);


  //creation des objets
  if (instruments.empty()) {    //Remplis la liste d'instrument. On peut ptt mettre une interuption ici 
    instruments.push_back(new Guitare());
    instruments.push_back(new Triangle());
  }
}

//Fonction qui met a jour l'affichage de l'ecran lorsque qu'il recoit une entrée. Potentiomètre fait defilier les instruments, boutton les selectionne.
void Menu::update(){
  int potValue = 0;
  int mappedValue1 = 0;   //on remap la valeur analogique sur la taille de la liste d'instruments 
  int buttonValue = 0;


  switch (this->state) {
    case -1:
      
    case 0 :
      potValue = analogRead(potentiometerPin);
      mappedValue1 = map(potValue,0,1023,0,instruments.size() -1);   //on remap la valeur analogique sur la taille de la liste d'instruments 
      buttonValue = digitalRead(buttonPin);

      if (mappedValue1 != lastPotValue) {  //si la valeur lu est different on update l'ecran 
      currentSelection = mappedValue1;
      displayMenuInstrument();
      lastPotValue = mappedValue1;
      }

      if (buttonValue==HIGH) {  //Si on appuis sur le boutton on selection l'objet affiché 
        this->state=1;
      }
    
    break;

    case 1 : 
      handleSelection();
      this->state=2;
    break;

    case 2: //menu de placement...
      handlePlacement();
    break;

    default:
    break;
  }
    
    

    //Si on appuis sur le boutton on selection l'instrument.
}

void Menu::displayMainMenu(){
    potValue = analogRead(potentiometerPin);
    mappedValue3 = map(potValue,0,1023,0,1);   //on remap la valeur analogique sur la taille de la liste d'instruments 
    buttonValue = digitalRead(buttonPin);

    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Main Menu:");
    lcd.setCursor(0, 1);

  if (mappedValue3 != lastPotValue) {
    case (mappedValue3){
      case 0:
        lcd.print("> Jouer Musique");
        break;

      case 1:
        lcd.print("> Jouer Musique");
        break;

    }
    lastPotValue = position;
  }

  if (buttonValue == HIGH) {
    placeInstrument(position - 1); // Placer l'instrument à l'indice correspondant
    this->state = 0; // Retourner au menu principal
  }



}

//Affiche le menu et l'intrument selectionné pour le moment 
void Menu::displayMenuInstrument(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Select Instrument:");
  lcd.setCursor(0, 1);
  lcd.print("> ");
  lcd.print(instruments[currentSelection]->getNom().c_str());
  delay(100);
}

//Change l'affichage du menu lorsque l'on selection un objet pour montrer qu'on a interagis avec l'instrument 
void Menu::handleSelection(){
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Selected:");
  lcd.setCursor(0, 1);
  lcd.print(instruments[currentSelection]->getNom().c_str());
  delay(1000); // Pause pour afficher la sélection
  
}

void Menu::handlePlacement() {
  int potValue = analogRead(potentiometerPin);
  int position = map(potValue, 0, 1023, 1, 16); // Positions de 1 à 16
  int buttonValue = digitalRead(buttonPin);

  if (position != lastPotValue) {
    displayPlacementMenu(position);
    lastPotValue = position;
  }

  if (buttonValue == HIGH) {
    placeInstrument(position - 1); // Placer l'instrument à l'indice correspondant
    this->state = 0; // Retourner au menu principal
  }
}

void Menu::displayPlacementMenu(int position) {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Place at Pos:");
  lcd.setCursor(0, 1);
  lcd.print("> ");
  lcd.print(position);
  delay(100);
}

void Menu::placeInstrument(int position) {
  // Assurez-vous que le vecteur de lecture est de la bonne taille
  if (Lecture.size() < 16) {
    Lecture.resize(16, nullptr); // Remplir avec des nullptr si nécessaire
  }

  // Ajouter l'instrument sélectionné à la position donnée
  Lecture[position] = instruments[currentSelection];
  Lecture[position]->emettreSon();
  // Confirmation visuelle
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Placed at Pos:");
  lcd.setCursor(0, 1);
  lcd.print(position + 1);
  delay(1000);
}

 void Menu::jouerMelodie(int tempo){
    for (int i=0; i<16;i++){
        Lecture[i]->emettreSon();
        delay(tempo);
    }
 }

//Permet d'ajouter un instrument lors du debugage ou si on crée une fonction de creation d'instruments dynamique, à voir si on a le temps 
/*void Menu::addIntrument(const Instrument* instrument) {
  Menu::instruments.push_back(instrument);
}

const Instrument* Menu::getInstrument() {
  return instruments[currentSelection];
}
*/