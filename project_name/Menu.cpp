#include "Menu.h"

Menu::Menu(int potPin, int button, rgb_lcd lcd) 
    : potentiometerPin(potPin), buttonPin(button), lcd(lcd), 
      currentSelection(0), lastPotValue(-1), state(-1), stateChanged(true), 
      lastButtonState(LOW), lastPotValue3(-1), lastPotValue2(-1) {}

Menu::~Menu() {}

void Menu::init() {
    Serial.println("buttonPin");
    Serial.println(buttonPin);

    pinMode(buttonPin, INPUT);
    pinMode(potentiometerPin, INPUT);
    lcd.begin(16, 2);
    lcd.setRGB(colorR, colorG, colorB);

    // Création des instruments si la liste est vide
    if (instruments.empty()) {
        instruments.push_back(new Guitare());
        instruments.push_back(new Triangle());
    }

    // Affiche le Main Menu à l'initialisation
    displayMainMenu();
}

void Menu::update() {
    int potValue = analogRead(potentiometerPin);
    int buttonValue = digitalRead(buttonPin);

    if (stateChanged) {
        // Reset des variables ou affichage lié au nouvel état
        switch (this->state) {
            case -1: // Main Menu
                displayMainMenu();
                break;
            case 0: // Sélection d'instruments
                displayMenuInstrument();
                break;
            case 1: // Instrument sélectionné
                handleSelection();
                break;
            case 2: // Placement d'instrument
                displayPlacementMenu(1); // Position initiale à afficher
                break;
            default:
                break;
        }
        stateChanged = false; // Transition terminée
    }

    // Gestion des états
    switch (this->state) {
        case -1: // Main Menu
            potValue = map(potValue, 0, 1023, 0, 1); // Mappe sur les options du Main Menu
            if (potValue != lastPotValue) {
                displayMainMenu(); // Rafraîchit l'affichage si changement
                lastPotValue = potValue;
            }
            if (buttonValue == HIGH && lastButtonState == LOW) { // Transition Main Menu -> sélection
                delay(50); // Anti-rebond
                this->state = potValue == 0 ? 3 : 0; // 3 = Jouer musique, 0 = Sélection instrument
                stateChanged = true; // Détecte le nouvel état
            }
            break;

        case 0: // Sélection d'instruments
            potValue = map(potValue, 0, 1023, 0, instruments.size() - 1);
            if (potValue != lastPotValue) {
                currentSelection = potValue;
                displayMenuInstrument();
                lastPotValue = potValue;
            }
            if (buttonValue == HIGH && lastButtonState == LOW) { // Transition sélection -> confirmation
                delay(50); // Anti-rebond
                this->state = 1; // Passe à handleSelection
                stateChanged = true;
            }
            break;

        case 1: // Sélection confirmée
            handleSelection();
            this->state = 2; // Passe à placement
            stateChanged = true;
            break;

        case 2: // Placement d'instruments
            handlePlacement();
            break;
        case 3:
            jouerMelodie(100);
            this->state = -1;
        default:
            break;
    }

    lastButtonState = buttonValue; // Met à jour l’état précédent du bouton
}

void Menu::displayMainMenu() {
    int potValue = analogRead(potentiometerPin);
    int mappedValue3 = map(potValue, 0, 1023, 0, 1); // Mappe sur "Jouer" ou "Ajouter"
    int buttonValue = digitalRead(buttonPin);

    if (mappedValue3 != lastPotValue3) {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Main Menu:");
        lcd.setCursor(0, 1);

        switch (mappedValue3) {
            case 0:
                lcd.print("> Jouer Musique");
                break;
            case 1:
                lcd.print("> Ajouter Instru");
                break;
            default:
                break;
        }

        lastPotValue3 = mappedValue3;
    }

    if (buttonValue == HIGH && lastButtonState == LOW) {
        delay(50); // Anti-rebond
        this->state = (mappedValue3 == 0) ? 3 : 0; // Passe à l’état correspondant
        stateChanged = true;
    }

    lastButtonState = buttonValue; // Met à jour l’état précédent
}

void Menu::displayMenuInstrument() {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Select Instrument:");
    lcd.setCursor(0, 1);
    lcd.print("> ");
    lcd.print(instruments[currentSelection]->getNom().c_str());
    delay(100);
}

void Menu::handleSelection() {
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

    if (position != lastPotValue2) {
        displayPlacementMenu(position);
        lastPotValue2 = position;
    }

    if (buttonValue == HIGH) {
        delay(50); // Anti-rebond
        placeInstrument(position - 1); // Placer l'instrument à l'indice correspondant
        this->state = -1; // Retourner au menu principal
        stateChanged = true;
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

void Menu::jouerMelodie(int tempo) {
    for (int i = 0; i < 16; i++) {
        if (Lecture[i] != nullptr) {
            Lecture[i]->emettreSon();
        }
        delay(tempo);
    }
}
