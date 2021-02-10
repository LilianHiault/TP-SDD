#include <stdlib.h>
#include "liste.h"

#define ERREUR -1

cellule_t * creerCell(int val, int i, int j) {
  /* creerCell : créer la cellule qui va contenir la valeur val, i et j
     Entrée : val la valeur du cout
     i ligne
     j colonne
     Sortie : cell la cellule créée */
  cellule_t  * cell = malloc(sizeof(cellule_t));
  if(cell)
    {
      cell->val = val;
      cell->i = i;
      cell->j = j;
      cell->suiv = NULL;
    }
  return cell;
}

int valeurTete(cellule_t * tete, int * erreur) {
  /* valeurTete : retourne la valeur de la tete
     Entrée : tete la cellule a la tete de la liste
     erreur un booléen qui indique si tout s'est bien passé
     Sortie : val la valeur de la tete
     erreur */
  int val;
  if (tete != NULL) {
    val = tete->val;
    *erreur = 0;
  }    
  else {
    val = ERREUR;
    *erreur = 1;
  }
  return val; 
}

void supprTete(cellule_t ** p_tete) {
  /* supprTete : supprime la tete de la liste
     Entrée : tete la cellule a la tete de la liste
     Sortie : tete */
  if (*p_tete != NULL)
    *p_tete = *(p_tete)->suiv;
}

void insererCell(cellule_t ** p_tete, cellule_t * cell) {
  /* insererCell : insérer la cellule dans la liste triée
     Entrée : tete la cellule a la tete de la liste
     cell la cellule a insérer
     Sortie : tete */
  int val = cell->val;
  if (*p_tete == NULL) {
    *p_tete = cell;
  }
  else {
    cellule_t * cour = *p_tete;
    cellule_t * prec = p_tete;
    while (cour!=NULL && cour->val>val) {
      prec = &(cour->suiv);
      cour = cour->suiv;
    }
    prec->suiv = cell;
    cell->suiv = cour;
  }
}
