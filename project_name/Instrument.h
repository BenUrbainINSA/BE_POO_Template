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
  
  public :
    Instrument(const int note, const int duree);

    virtual void emettreSon() const = 0;

    int getNote();

    string getNom();

    int getDuree();

    virtual ~Instrument();

};



#endif