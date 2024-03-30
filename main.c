#include "personnage.h"
#include "monstre.h"
#include "grille.h"
#include "event.h"

int main(){
struct Personnage myperso;
struct Monstre mechantmonstre;
struct Grille map_test;


myperso = init_perso("bloubi", 10, 8, 0, 1, 20, "normal");
mechantmonstre =  init_monstre("mechantmonstre", 20, -3, 10, 5);

affiche_perso(myperso);
affiche_monstre(mechantmonstre);

map_test = create_map(map_test);

affiche_grille(map_test);

rencontre_monstre(mechantmonstre,myperso);

  return 0;
}
