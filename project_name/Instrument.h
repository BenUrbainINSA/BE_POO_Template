#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <Arduino.h>
#include <iostream>
#include <string>
using namespace std;

//extern const int buzzerPin = 9;

class Instrument{
  protected :
    int note;
    int duree;
    string nom;
  
  public :
    Instrument(const int note, const int duree, const string nom);

    virtual void emettreSon() const = 0;

    Instrument & operator =(const Instrument & autre){
      this->note = autre.note;
      this->duree = autre.duree;
      this->nom = autre.nom;

      return *this;
    }

    int getNote();

    string getNom() ;

    int getDuree();

    virtual ~Instrument();

};



#endif