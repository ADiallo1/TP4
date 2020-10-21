#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"

int construire(FILE* fichier,int laby[TAILLE_X][TAILLE_Y]){
	int x=0,y=0;
	if(fichier==NULL){
		return 0;
	}
	else
	for(y=0;y<TAILLE_Y;y++){
			for(x=0;x<TAILLE_X;x++){
				fscanf(fichier,"%d",&laby[x][y]);
			}
	}
	return 1;
/*Les commandes utilisées pour l'édition de liens et pour la compilation sont:
	 *  gcc -Wall -c affichage.c lecture.c labyrinthe.c -I/usr/include/X11 -I/Bureau/CTP_C/TP4_Diallo
	 *  gcc -Wall -o labyrinthe affichage.o lecture.o labyrinthe.o -I/usr/lib/X11 -lX11 -I/Bureau/CTP_C/TP4_Diallo*/
}

void cAse(int x,int y, int d,int caseVoisine[2]){//Question 4
	if(d==0){
		x-=1;
		caseVoisine[0]=x;
	}
	else if(d==3){
		y-=1;
		caseVoisine[1]=y;
	}
	else if(d==2){
		x+=1;
		caseVoisine[0]=x;
	}
	else if(d==1){
		y+=1;
		caseVoisine[1]=y;
	}
	printf("case voisine(%d,%d)",caseVoisine[0],caseVoisine[1]);
}
int expansion(int laby[TAILLE_X][TAILLE_Y],int depart[2],int arrivee[2],int caseVoisine[2]){
	//Question 7;
	laby[depart[0]][depart[1]]=1;
	int r=1,verifie=0;
	while(laby[arrivee[0]][arrivee[1]]==0){
		verifie=0;
		for( int i=0;i<TAILLE_Y;i++){
			for(int j=0;j<TAILLE_X;j++){
				if(laby[i][j]==r){
					cAse(i,j,0,caseVoisine);
					if(laby[caseVoisine[0]][caseVoisine[1]]==0){
						laby[caseVoisine[0]][caseVoisine[1]]=r+1;
						verifie=1;
					}
					cAse(i,j,1,caseVoisine);
					if(laby[caseVoisine[0]][caseVoisine[1]]==0){
						laby[caseVoisine[0]][caseVoisine[1]]=r+1;
						verifie=1;
					}
					cAse(i,j,2,caseVoisine);
					if(laby[caseVoisine[0]][caseVoisine[1]]==0){
						laby[caseVoisine[0]][caseVoisine[1]]=r+1;
						verifie=1;
					}
					cAse(i,j,3,caseVoisine);
					if(laby[caseVoisine[0]][caseVoisine[1]]==0){
						laby[caseVoisine[0]][caseVoisine[1]]=r+1;
						verifie=1;
					}
				}
			}
		}
		r++;
		if(verifie)
		{
			break;
		}
	}
	return verifie;
}
