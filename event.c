#include "event.h"


//lancer de des et reussite
int lancer_des_des(struct Personnage* perso){
  int i = 0;
  int lancer_de;
  int reussite;
  for(i=0;i < perso->niveau;i++){
    lancer_de = (rand()%6);
    if((lancer_de == 5) || (lancer_de == 6)){
      reussite += 1;
    }
  }
  return reussite;
}

//event generale
struct Personnage rencontre_monstre(struct Monstre *monstre, struct Personnage *perso){
  while((monstre->pv > 0) && (perso->pv > 0)){
    monstre = personnage_attaque(perso, monstre);
    perso = monstre_attaque(monstre, perso);

  }
  if(monstre->pv <= 0){
    printf("victoire! le monstre est battu \n");
    perso->piece += monstre->piece;
    perso->xp += monstre->xp;
    printf("--> voici vos nouvelles stats: \n");
    affiche_perso(*perso);

  }else{
    printf("perdu... vous etes mort \n");
    perso->pv = 0;
   }
   return *perso;
}

struct Personnage rencontre_piege(struct Personnage *perso){
  int reussite=0, type_perte=0, gain=0 ;
  printf("vous etes tombé sur un piege \n... \n");
  reussite = lancer_des_des(perso);
  if(reussite >= 1){
    gain = (rand()%6)+1;
    printf("vous avez surmonter le piege avec brillance! vous gagnez %d xp \n", gain);
    perso->xp += gain;
  }else{
    printf("oh non, le piege vous a bien eu \n");
    type_perte = (rand()%2);
    switch (type_perte) {
      case 0:
        printf("Des fleches sont sorties des mur, heureusement votre armure vous a proteger mais elle perd 1 d'efficacité \n ");
        if(perso->pt_armure < 0){
          perso->pt_armure = perso->pt_armure -1;
        }else{
          perso->pv -= 1;
        }
      break;
      case 1:
        printf("Le sol s'est ouvert sous vos pieds, remonter vous a donné tres faim, vous perdez une ration\n ");
        if(perso->pt_armure < 0){
         perso->ration = perso->ration - 1;
       }else{
         perso->pv -= 1;
       }
      break;
      case 3:
        printf("Un feu s'est declenché sous vos pied, vous perdez 1 de vie\n ");
        perso->pv = perso->pv - 1;
      break;
    }
  }
  return *perso;
}

struct Personnage rencontre_marchand(struct Personnage *perso){
  int choix=0;
  printf("Vous avez trouvé un marchand! \n \n");
  printf("Bonjour, voici ma carte: \n");
  printf("------------------------ \n");
  printf("_________acheter________\n");
  printf("1 -1PV : 3 \n");
  printf("2 -3PV : 6 \n");
  printf("3 -1 armure : 4\n");
  printf("4 -1 ration : 2 \n");
  printf("5 -1 potion : 8 \n");
  printf("________vendre_________\n");
  printf("6 -1 armure : 3\n");
  printf("7 -1 potion : 4 \n");
  printf("8 -1 ration : 1\n");
  printf("voulez-vous acheter ou vendre quelquechose? \n    <8:oui 9:non \n");
  scanf("%d",&choix);
  while(choix < 9){
    printf("quel numero voulez-vous? (9 pour quitter)\n");
    scanf("%d",&choix);
    switch (choix) {
      case 1:
        if(perso->piece < 3){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          perso->pv  += 1 ;
          perso->piece -= 3;
        }
      break;
      case 2:
        if(perso->piece < 6 ){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          perso->pv += 3;
          perso->piece -= 6;
        }
      break;
      case 3:
        if(perso->piece < 4){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          perso->pt_armure  += 1 ;
          perso->piece -= 4;
        }
      break;
      case 4:
        if(perso->piece < 2){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          perso->ration  += 1 ;
          perso->piece -= 2;
        }
      break;
      case 5:
        if(perso->piece < 8 ){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          //perso->  = ;
          perso->piece -= 8;
        }
      break;
      case 6:
        if(perso->pt_armure < 8 ){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          //perso->  -= ;
          perso->piece  += 3  ;
        }
      break;
      case 7:
        /*if(perso-> < 1){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          perso->  -= ;
          perso->piece  +=  4 ;
        }*/
      break;
      case 8:
        if(perso->ration < 1){
          printf("desolée vous n'avez pas assez d'or... ");
        }else{
          perso->ration  -= 1 ;
          perso->piece  +=  1 ;
        }
      break;
    }
  }
  return *perso;
}

struct Personnage rencontre_tresor(struct Personnage *perso){
  int reussite, niv_choix=0, choix=0;
  printf("Bravo, vous avez trouver un tresor!!! \n");
  reussite = lancer_des_des(perso);
  if(reussite == 0){
    printf("Dommage, vous n'arrivez pas a ouvrir le coffre...");
  }else{
    printf("Super, vous arrivez a ouvrir le coffre\n -->");
    niv_choix = rand()%6;
    switch (niv_choix) {
      case 0:
        printf("Vous avez le choix entre +1 armure (1) et +3xp (2), que prenez-vous?\n");
        scanf("%d",&choix);
        printf("%d",choix);
        if(choix == 1){
          perso->pt_armure += 1;
        }else if(choix ==2){
          perso->xp += 3;
        }else{
          printf("saisie non valide, vous ne gagnez donc rien\n");
        }
      break;
      case 1:
        printf("Vous avez le choix entre +2xp (1) et +1 piece (2), que prenez-vous?\n");
        scanf("%d",&choix);
        if(choix == 1){
          perso->xp += 2;
        }else if(choix ==2){
          perso->piece += 1;
        }else{
          printf("saisie non valide, vous ne gagnez donc rien\n");
        }
      break;
      case 2:
        printf("Vous avez le choix entre +1 potion Feu (1) et +2 PV (2), que prenez-vous?\n");
        scanf("%d",&choix);
        if(choix == 1){
          printf("h");
        }else if(choix ==2){
          perso->pv += 2;
        }else{
          printf("saisie non valide, vous ne gagnez donc rien\n");
        }
      break;
      case 3:
        printf("Vous avez le choix entre +2 PV (1) et +1 potion Givre (2), que prenez-vous?\n");
        scanf("%d",&choix);
        if(choix == 1){
          perso->pv += 2;
        }else if(choix ==2){
          printf("h");
        }else{
          printf("saisie non valide, vous ne gagnez donc rien\n");
        }
      break;
      case 4:
        printf("Vous avez le choix entre +3 or (1) et +5 xp (2), que prenez-vous?\n");
        scanf("%d",&choix);
        if(choix == 1){
          perso->piece += 3;
        }else if(choix ==2){
          perso->xp += 5;
        }else{
          printf("saisie non valide, vous ne gagnez donc rien\n");
        }
      break;
      case 5:
        printf("Vous avez le choix entre +1 potion Soin (1) et +1 potion Poison (2), que prenez-vous?\n");
        scanf("%d",&choix);
        if(choix == 1){
          printf("h");
        }else if(choix ==2){
          printf("h");
        }else{
          printf("saisie non valide, vous ne gagnez donc rien \n");
        }
      break;
    }
  }
  return *perso;
}


//event d'attaque
struct Monstre * personnage_attaque(struct Personnage *perso, struct Monstre *monstre){
  int lancer_de;

  printf("-->vous attaquez \n");
  lancer_de = (rand()%6);
  if(lancer_de == 6){
    lancer_de += (rand()%6);
  }
  monstre->pv = monstre->pv - lancer_de;
  printf("  il reste %d pv aux monstre \n", monstre->pv);
  return monstre;
}


struct Personnage * monstre_attaque(struct Monstre *monstre, struct Personnage *perso){
  printf("-->le monstre attaque \n");
  if((monstre->degats - perso->pt_armure) < 0){
    perso->pv = perso->pv;
  }else{
    perso->pv = perso->pv - (monstre->degats - perso->pt_armure);
  }
  printf("  il vous reste %d pv \n", perso->pv);
  return perso;
}
