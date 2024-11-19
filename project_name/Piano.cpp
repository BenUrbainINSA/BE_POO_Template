#include "Piano.h"

Piano::Piano():Instrument(720,1000){}

void Piano::emettreSon() const{
  tone(14,note,duree);
}
