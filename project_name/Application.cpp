/*********************************************************************
 * @file  Apllication.cpp
 * @author <mettre l'adresse mail ou nom prenom>
 * @brief Fichier source de l'application
 *********************************************************************/
#include "Application.h"
#include "Guitare.h"
#include "Piano.h"
#include "Trompette.h"
#include "Triangle.h"


Application::Application()
{
  // Code
  ; 
}
  
Application::~Application()
{
  // Code
  ;
}  

void Application::init(void)
{
  pinMode(14,OUTPUT);
  Guitare Francois ;
  Piano Eric ;
  Trompette Antoine ;
  Triangle Denis ;

  Francois.emettreSon();
  delay(1000);
  Eric.emettreSon();
  delay(1000);
  Antoine.emettreSon();
  delay(1000);
  Denis.emettreSon();
  delay(1000);
}


void Application::run(void)
{

}
