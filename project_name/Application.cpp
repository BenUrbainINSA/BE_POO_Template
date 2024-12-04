/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include <Arduino.h>
#include "Menu.h"


// Constructeur
Application::Application()
 : lcd(),                                   // Instancie l'écran LCD
      potentiometerPin(A0),                    // Initialisation des broches
      selectButtonPin(15), //pin D8
      menu(potentiometerPin, selectButtonPin, lcd) // Initialise le menu
      
{
}

// Destructeur
Application::~Application() {
    // Rien à faire dans ce cas
}

// Initialisation de l'application
void Application::init(void)
{
  menu.init(); // Initialise le menu
}

// Exécution de l'application (mettre à jour l'affichage du menu)
void Application::run(void)
{
  try {
    menu.update();
  } catch (const MenuException& e) {
    Serial.println("Exception capturée depuis Menu :");
    Serial.println(e.what());
  }
  
}
