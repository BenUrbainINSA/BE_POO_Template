#ifndef GUITARE_H
#define GUITARE_H

#include "Instrument.h"
#include <string>
using namespace std;

class Guitare : public Instrument{
  public : 
    Guitare();
    void emettreSon() const;
};


#endif