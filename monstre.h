#ifndef MONSTRE_H
#define MONSTRE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>



struct Monstre{
  char *nom;
  int degats; 
  int pv;
  int xp;
  int piece;
};


struct Monstre init_monstre(char nom[], int pv, int degats, int xp, int or);

void affiche_monstre(struct Monstre);




#endif
