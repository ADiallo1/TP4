#include <stdio.h>
#include <stdlib.h>

#include "affichage.h"

int construire(FILE* fichier,int laby[TAILLE_X][TAILLE_Y],int depart[2],int arrivee[2]){
	int x=0,y=0;
	if(fichier==NULL){
		return 0;
	}
	else
	for(x=0;x<=TAILLE_X;x++){
			for(y=0;y<=TAILLE_Y;y++){
				fscanf(fichier,"%d",&laby[x][y]);
			}
	}
	return 1;
}


int main(){
	initAffichage();
	int laby[TAILLE_X][TAILLE_Y];
	int depart[2],arrivee[2];
	FILE* fichier=fopen("laby1.txt","r");
	construire(fichier,laby,depart,arrivee);
	afficheLabyrinthe(laby,depart,arrivee,0);
	}

