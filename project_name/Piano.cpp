#include "Piano.h"

Piano::Piano():Instrument(720,1000){}

void Piano::emettreSon() const{
  tone(9,note,duree);
}
