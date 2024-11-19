#ifndef PIANO_H
#define PIANO_H

#include "Instrument.h"
#include <string>
using namespace std;

class Piano : public Instrument{
  public : 
    Piano();
    void emettreSon() const;
};


#endif