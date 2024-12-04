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
#include "Trompette.h"
#include "Piano.h"
#include <memory> // Pour std::unique_ptr
#include "Menuexception.h"

class Menu {

private:
    // Pins
    int potentiometerPin;
    int buttonPin;

    // État du menu
    int state; // État courant du menu
    bool stateChanged; // Indique si l’état a changé pour rafraîchir l’affichage

    // LCD
    rgb_lcd& lcd;
    const int colorR = 255;
    const int colorG = 255;
    const int colorB = 255;

    // Instruments
    std::vector<Instrument*> instruments;

    // File de lecture
    std::array<Instrument*, 32> Lecture; // Tableau des instruments placés


    // Gestion des interactions
    int currentSelection; // Instrument actuellement sélectionné
    int lastPotValue; // Dernière valeur du potentiomètre (sélection instrument)
    int lastPotValue2; // Dernière valeur pour le placement
    int lastPotValue3; // Dernière valeur pour le Main Menu
    int lastButtonState; // Dernier état du bouton

    // Méthodes utilisées en interne :
    void handleSelection(); // Gérer la sélection d’un instrument
    void handlePlacement(); // Gérer le placement de l’instrument
    void displayMainMenu(); // Afficher le menu principal
    void displayMenuInstrument(); // Afficher le menu de sélection d’instrument
    void displayPlacementMenu(int position); // Afficher le menu de placement
    void placeInstrument(int position); // Placer un instrument
    void handleMusique(int CursorX, int CursorY);
    void jouerMelodie(int tempo); // Jouer la mélodie avec le fichier Lecture

public:
    Menu(int potPin, int button, rgb_lcd lcd);
    ~Menu();

    void init(); // Initialiser le menu
    void update(); // Mettre à jour l’état du menu en fonction des entrées utilisateur
};



#endif
