#include <stdio.h>
#include <stdlib.h>
#include "affichage.h"
/*Cette fonction est la fonction qui lit les fichiers (laby.txt) pour permettre la construction
 * du labyrinthe. Pour l'utilisation on l'appel dans la fonction main par son prototype qui est
 * la ligne suivante tout en incluant sa bibliothéque dans les directives de préprocesseurs */
int construire(FILE* fichier,int laby[TAILLE_X][TAILLE_Y]);
void cAse(int x,int y, int d);
int expansion(int laby[TAILLE_X][TAILLE_Y],int depart[2],int arrivee[2],int caseVoisine[2]);
