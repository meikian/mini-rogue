jeux.exe: main.o personnage.o monstre.o potion.o position.o grille.o event.o
	gcc main.o personnage.o monstre.o potion.o position.o grille.o event.o -o jeux.exe -lm
main.o: main.c personnage.h
	gcc -c main.c
personnage.o: personnage.h personnage.c
	gcc -c personnage.c
monstre.o: monstre.h monstre.c
	gcc -c monstre.c
potion.o: potion.h potion.c
	gcc -c potion.c
position.o: position.h position.c
	gcc -c position.c
grille.o: grille.h grille.c
	gcc -c grille.c
event.o: event.h event.c
	gcc -c event.c


