#include "potion.h"


struct Potion init_potion(int pv, char type[]){
  struct Potion potion;
  potion.pv = pv;
  strcpy(potion.type, type);
  return potion;
}
