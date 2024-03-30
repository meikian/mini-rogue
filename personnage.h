#ifndef PERSONNAGE_H
#define PERSONNAGE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "potion.h"


struct Personnage{
  char *nom;
  int pv;
  int pt_armure;
  int xp;
  int niveau;
  int ration;
  int piece;
  struct Potion listepotion[2];
  char etat[50];
};

struct Personnage init_perso(char nom[], int pv, int pt_armure, int xp, int niveau, int or, char etat[]);

void affiche_perso(struct Personnage);



#endif
