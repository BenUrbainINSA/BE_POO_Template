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

/**
 * @class Menu
 * @brief Classe Menu.
 * 
 * La classe Menu gère les interactions utilisateur à travers un écran LCD et un potentiomètre (pour la navigation) ainsi qu'un bouton (pour la sélection). 
 * Elle permet de gérer l'affichage des menus, la sélection d'instruments et leur placement dans un tableau, ainsi que la lecture d'une mélodie en fonction des instruments sélectionnés.
 */


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

  /**
 * @fn void Menu::handleSelection()
 * @brief Confirme la sélection de l'instrument actuel et affiche son nom.
 * @Exemple menu.handleSelection();
 */
    void handleSelection(); // Gérer la sélection d’un instrument
  /**
 * @fn void Menu::handlePlacement()
 * @brief Permet de placer un instrument sélectionné à une position spécifique.
 * @Exemple menu.handlePlacement();
 */
    void handlePlacement(); // Gérer le placement de l’instrument
  
  /**
 * @fn void Menu::displayMainMenu()
 * @brief Affiche le menu principal permettant de jouer une mélodie ou d'ajouter un instrument.
 * @Exemple menu.displayMainMenu();
 */
    void displayMainMenu(); // Afficher le menu principal

  /**
 * @fn void Menu::displayMenuInstrument()
 * @brief Affiche la liste des instruments disponibles pour sélection.
 * @Exemple menu.displayMenuInstrument();
 */
    void displayMenuInstrument(); // Afficher le menu de sélection d’instrument

  /**
 * @fn void Menu::displayPlacementMenu(int position)
 * @brief Affiche les options de placement pour l'instrument à la position spécifiée.
 * @Exemple menu.displayPlacementMenu(3);
 */
    void displayPlacementMenu(int position); // Afficher le menu de placement
  
/**
 * @fn void Menu::placeInstrument(int position)
 * @brief Place l'instrument sélectionné à une position donnée dans le tableau Lecture.
 * @Exemple menu.placeInstrument(5);
 */
    void placeInstrument(int position); // Placer un instrument
  /**
 * @fn void Menu::jouerMelodie(int tempo)
 * @brief Joue une mélodie en utilisant les instruments placés dans Lecture.
 * @param tempo Vitesse à laquelle la mélodie est jouée.
 * @Exemple menu.jouerMelodie(100);
 */
    void jouerMelodie(int tempo); // Jouer la mélodie avec le fichier Lecture

public:
/**
 * @fn Menu::Menu(int potPin, int button, rgb_lcd lcd)
 * @brief Constructeur de la classe Menu. Initialise les variables et configure les instruments de base.
 * @param potPin Pin du potentiomètre.
 * @param button Pin du bouton.
 * @param lcd Référence vers l'écran LCD RGB.
 * @Exemple Menu menu(A0, 2, lcd);
 */

    Menu(int potPin, int button, rgb_lcd lcd);
/**
 * @fn Menu::~Menu()
 * @brief Destructeur de la classe Menu. Libère les ressources des instruments.
 */
    ~Menu();

/**
 * @fn void Menu::init()
 * @brief Initialise les composants matériels et affiche le menu principal.
 * @Exemple Menu menu(pinPot, pinButton, lcd); menu.init();
 */
    void init(); // Initialiser le menu

/**
 * @fn void Menu::update()
 * @brief Met à jour l'état du menu en fonction des entrées utilisateur et gère les transitions d'état.
 * @Exemple menu.update();
 */
    void update(); // Mettre à jour l’état du menu en fonction des entrées utilisateur
};



#endif
