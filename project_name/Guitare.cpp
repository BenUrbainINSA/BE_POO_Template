#include "Guitare.h"

Guitare::Guitare():Instrument(660,1000, "Guitare"){}

void Guitare::emettreSon() const{
  tone(14,note,duree);
}
