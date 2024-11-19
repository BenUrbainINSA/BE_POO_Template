#ifndef INSTRUMENT_H
#define INSTRUMENT_H

#include <Arduino.h>
#include <iostream>
#include <string>
using namespace std;

int buzzerPin = 9;

class Instrument{
  protected :
    int note;
    string nom;
    int duree;
  
  public :
    Instrument(const int note, const string nom);

    void emettreSon(int note, int duree);

    int getNote();

    string getNom();

    int getDuree();

    virtual ~Instrument();

};



#endif