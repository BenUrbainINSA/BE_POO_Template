#include "Instrument.h"
#include <string>

using namespace std;



Instrument::Instrument(const int note, const int duree){
  this->note = note;
  this->duree = duree;
}

int Instrument::getNote(){
  return this->note;
}


int Instrument::getDuree(){
  return this->duree;
}

Instrument::~Instrument(){}
