#include "grille.h"



struct Grille create_map(){
  struct Grille map;
  srand (time (NULL));
  int i=0 ,j=0;
  for(i=0; i<T_MAP ;i++){
    for(j=0; j<T_MAP ; j++){
        map.etat_case[i][j] = ' ';
        map.type_case[i][j] = (rand()%4)+1;
    }
  }
  map.etat_case[0][0] = 'P';
  map.case_perso[0] = 0;
  map.case_perso[1] = 0;
  return map;
}



void affiche_map(struct Grille map){
  int i=0 ,j=0;
  for(i=0; i<T_MAP ;i++){
    printf("- - - - - - - - - - - - - - - - - - - \n");
    for(j=0; j<T_MAP ; j++){
      if( j == (T_MAP-1)){
        printf("| %c |", map.etat_case[i][j]);
      }else{
        printf("| %c ", map.etat_case[i][j]);
      }
    }printf("\n");
  }printf("- - - - - - - - - - - - - - - - - - - \n");

  printf("%d %d \n", map.case_perso[0], map.case_perso[1]);
    /*for(i=0; i<9 ;i++){
      printf("\n");
      for(j=0; j<9 ; j++){
          printf("| %d ", map.type_case[i][j]);
      }printf("\n");
  }*/
}


struct Grille move_perso(struct Grille *map){
  char deplacement='z';

  map->etat_case[map->case_perso[1]][map->case_perso[0]] = '.';
  printf("ou voulez-vous allez? \n");
  scanf("%c",&deplacement);
  while(getchar() != '\n');

  while(((deplacement != 'q') && (deplacement != 'z') && (deplacement != 's') && (deplacement != 'd')|| ((deplacement== 'q') && (map->case_perso[0] == 0))) || ((deplacement== 'z') && (map->case_perso[1] == 0)) || ((deplacement== 'd') && (map->case_perso[0] == (T_MAP-1))) || ((deplacement== 's') && (map->case_perso[1] == (T_MAP-1)))){
    printf("deplacement non connue et/ou impossible \n");
    scanf("%c",&deplacement);
    while(getchar() != '\n');
  }
  switch (deplacement) {
    case 'q':
        map->case_perso[0] = map->case_perso[0]-1 ;
    break;
    case 'z':
        map->case_perso[1] =map->case_perso[1]- 1 ;
    break;
    case 'd':
        map->case_perso[0] = map->case_perso[0]+1;
    break;
    case 's':
        map->case_perso[1] = map->case_perso[1]+1;
    break;
  }
  map->etat_case[map->case_perso[1]][map->case_perso[0]] = 'P';
  return *map;
}
