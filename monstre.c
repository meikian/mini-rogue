#include "monstre.h"



struct Monstre init_monstre(char nom[], int pv, int degats, int xp, int or){
  struct Monstre monstre;
  monstre.nom = malloc(strlen(nom));
  strcpy(monstre.nom, nom);
  monstre.pv = pv;
  monstre.degats = degats;
  monstre.xp = xp;
  monstre.piece = or;
  return monstre;
}


void affiche_monstre(struct Monstre monstre){
  printf("Information sur le monstre %s : \n", monstre.nom);
  printf("----------------------------------\n");
  printf("PV : %d \n" ,monstre.pv );
  printf("degats : %d \n" ,monstre.degats);
  printf("XP : %d \n",monstre.xp );
  printf("Piece : %d \n",monstre.piece );
}
