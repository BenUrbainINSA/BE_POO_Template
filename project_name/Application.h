/*********************************************************************
 * @file  Apllication.h
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier header de l'application
 *********************************************************************/
#ifndef APPLICATION_H_
#define APPLICATION_H_

#include "Menu.h"
/**
  * @class Application
  * @brief Classe Application 
*/    
class Application
{
  private : 
    rgb_lcd lcd;            // Instance de l'écran LCD
    int potentiometerPin;   // Broche du potentiomètre
    int selectButtonPin;    // Broche du bouton de sélection
    Menu menu;              // Menu gérant les interactions
    
  public :
    /**
     * @fn Application();
     * @brief Constructeur par defaut
    */    
    Application();
    /**
     * @fn Application();
     * @brief Destructeur
    */    
    ~Application();    
    /**
     * @fn void init(void)
     * @brief Fonction d'initialisation de l'application
    */
    void init(void);
    /**
     * @fn void run(void)
     * @brief Fonction de lancement de l'application
    */
    void run(void);
};
#endif