#ifndef TROMPETTE_H
#define TROMPETTE_H

#include "Instrument.h"
#include <string>
using namespace std;

class Trompette : public Instrument{
  public : 
    Trompette();
    void emettreSon() const;
};


#endif