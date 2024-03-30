#include "personnage.h"



struct Personnage init_perso(char nom[], int pv, int pt_armure, int xp, int niveau, int or, char etat[]){
  struct Personnage perso;
  perso.nom = malloc(strlen(nom));
  strcpy(perso.nom, nom);
  perso.pv = pv;
  perso.pt_armure = pt_armure;
  perso.xp = xp;
  perso.niveau = niveau;
  perso.ration = 3;
  perso.piece = or;
  strcpy(perso.etat, "normal");
  return perso;
}


void affiche_perso(struct Personnage perso){
  printf("Information sur %s : \n", perso.nom);
  printf("----------------------------------\n");
  printf("PV : %d \n" ,perso.pv );
  printf("Armure : %d \n" ,perso.pt_armure);
  printf("XP : %d \n",perso.xp );
  printf("Niveau : %d \n",perso.niveau );
  printf("Ration : %d \n", perso.ration);
  printf("Piece : %d \n",perso.piece );
  printf("Etat : %s\n", perso.etat);
}
