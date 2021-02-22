#ifndef fonction_h
#define fonction_h

typedef struct cellule {
    int val;
    int i;
    int j;
    struct cellule * suiv;
} cellule_t;


cellule_t * coutFaibles(int, int **, int, int);
/* coutFaibles : crée la liste des K plus petites valeurs de la matrice C
   Entrée : k valeurs à mettre dans la liste
            C la matrice en 2 dimensions de taille m * n
	    m lignes dans C
	    n colonnes dans C
   Sortie :
   adresse vers la première cellule */

cellule_t * creerCell(int, int, int);
int valeurTete(cellule_t *, int *);
void supprTete(cellule_t **);
void insererCell(cellule_t **, cellule_t *);

#endif
