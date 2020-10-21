#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"
#include "lecture.h"

int main(){
	initAffichage();
	int laby[TAILLE_X][TAILLE_Y];
	int depart[2],arrivee[2],caseSuivante[2];
	FILE* fichier=fopen("laby3.txt","r");
		fscanf(fichier,"%d",&depart[0]);
		fscanf(fichier,"%d",&depart[1]);
		fscanf(fichier,"%d",&arrivee[0]);
		fscanf(fichier,"%d",&arrivee[1]);
		construire(fichier,laby);
	/*Les commandes utilisées pour l'édition de liens et pour la compilation sont:
	 *  gcc -Wall -c affichage.c lecture.c labyrinthe.c -I/usr/include/X11 -I/Bureau/CTP_C/TP4_Diallo
	 *  gcc -Wall -o labyrinthe affichage.o lecture.o labyrinthe.o -I/usr/lib/X11 -lX11 -I/Bureau/CTP_C/TP4_Diallo*/
		afficheLabyrinthe(laby,depart,arrivee,0);
		int cheminRecherche =expansion(laby,depart,arrivee,caseSuivante);
		if(cheminRecherche){
			printf("Plus de chemin");
		}
		
		
	}


