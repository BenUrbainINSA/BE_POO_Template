#include "Instrument.h"
#include <string>

using namespace std;



Instrument::Instrument(const int note, const string nom){
  this->note = note;
  this->nom = nom;
}

void Instrument::emettreSon(int note, int duree){
  tone(buzzerPin, note, duree); //Penser à faire exception si note négative;
}

int Instrument::getNote(){
  return this->note;
}

string Instrument::getNom(){
  return this->nom;
}

int Instrument::getDuree(){
  return this->duree;
}
