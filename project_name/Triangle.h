#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Instrument.h"
#include <string>
using namespace std;

class Triangle : public Instrument{
  public : 
    Triangle();
    void emettreSon() const;
};


#endif