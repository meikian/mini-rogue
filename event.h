#include <stdio.h>
#include "personnage.h"
#include "monstre.h"
#include <time.h>


//lancer de des et reussite
int lancer_des_des(struct Personnage*);


//event generale
struct Personnage rencontre_monstre(struct Monstre* monstre, struct Personnage * perso);

struct Personnage rencontre_piege(struct Personnage*);

struct Personnage rencontre_marchand(struct Personnage*);

struct Personnage rencontre_tresor(struct Personnage*);

//event d'attaque
struct Monstre* personnage_attaque(struct Personnage *perso, struct Monstre *monstre);

struct Personnage* monstre_attaque(struct Monstre *monstre, struct Personnage *perso);
