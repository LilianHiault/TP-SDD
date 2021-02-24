#ifndef fonction_h
#define fonction_h

#include "liste.h"
#include <stdio.h>

cellule_t * coutFaibles(int, int **, int, int);
/* coutFaibles : crée la liste des K plus petites valeurs de la matrice C
   Entrée : k valeurs à mettre dans la liste
            C la matrice en 2 dimensions de taille m * n
	    m lignes dans C
	    n colonnes dans C
   Sortie : adresse vers la première cellule */

void listToFile(FILE * fichier, cellule_t * liste);
/* listToFile : écrit la liste dans un fichier de la manière suivante par ligne : valeur usine periode
   Entrée : fichier le fichier ou l'on veut écrire
            liste la liste que l'on souhaite écrire
   Sortie : */

void suppUsine(cellule_t ** a0, int u);
/* suppUsine : supprime toutes les occurences d'une usine dans une liste
   Entrée : cellule_t * a0 l'adresse de la première cellule
            int u l'usine à supprimer
   Sortie : */
#endif
