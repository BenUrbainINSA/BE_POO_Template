#include "Triangle.h"

Triangle::Triangle():Instrument(800,1000, "Triangle"){}

void Triangle::emettreSon() const{
  tone(14,note,duree);
}
