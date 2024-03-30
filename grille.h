#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define T_MAP 9

struct Grille{
  char etat_case[T_MAP][T_MAP];
  int type_case[T_MAP][T_MAP];
  int case_perso[2];
};


struct Grille create_map();

void affiche_map(struct Grille map);

struct Grille move_perso(struct Grille *map);
