#ifndef liste_h
#define liste_h

#include <stdio.h>

typedef struct cellule {
    int val;
    int i;
    int j;
    struct cellule suiv;
} cellule_t;

cellule_t creerCell(int, int, int);
int valeurTete(cellule_t *, int *);
void supprTete(cellule_t *);
void insererCell(cellule_t *, cellule_t *);

#endif