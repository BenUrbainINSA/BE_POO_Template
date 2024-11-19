#include "Trompette.h"

Trompette::Trompette():Instrument(500,1000){}

void Trompette::emettreSon() const{
  tone(14,note,duree);
}
