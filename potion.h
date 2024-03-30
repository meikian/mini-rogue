#include <stdio.h>
#include <string.h>

struct Potion{
  int pv;
  char type[15];
};

struct Potion init_potion(int pv, char type[]);
