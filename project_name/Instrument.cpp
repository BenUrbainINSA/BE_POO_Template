#include "Instrument.h"
#include <string>

using namespace std;



Instrument::Instrument(const int note, const int duree, const string nom){
  this->note = note;
  this->duree = duree;
  this->nom = nom;
}



int Instrument::getNote(){
  return this->note;
}


int Instrument::getDuree(){
  return this->duree;
}

string Instrument::getNom() {
  return this->nom;
}

Instrument::~Instrument(){}
