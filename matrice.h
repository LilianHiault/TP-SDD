#ifndef matrice_h
#define matrice_h

#include <stdio.h>

int ** initMatrice(FILE *, int *, int *);
/* initMatrice : initialise la matrice à partir d'un fichier
   Entrée : fichier où se trouvent les valeurs de la matrice
            m lignes
	    n colonnes
   Sortie : mat la matrice des coûts de production
            m lignes
	    n colonnes */

void afficherMatrice(int **, int, int);
/* afficherMatrice  : affiche la matrice
   Entrée : matrice à afficher
            m lignes
	    n colonnes */

#endif
