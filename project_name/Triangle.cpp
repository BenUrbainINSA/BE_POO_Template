#include "Triangle.h"

Triangle::Triangle():Instrument(800,1000){}

void Triangle::emettreSon() const{
  tone(14,note,duree);
}
