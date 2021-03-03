#include "pile.h"
#include <stdio.h>
#include <stdlib.h>


pile_t * creerPile(int nbElm) {
  /* creerPile : créer et initialise une pile
     Entrée : nbElm le nombre d'éléments max dans la pile
     Sortie : pile la pile */
  pile_t * pile = malloc(sizeof(pile_t));
  if (pile != NULL) {
    pile->nbElm = nbElm;
    pile->adr = 0;
    pile->val = malloc(nbElm * sizeof(element_t));
  }
  return pile;
}  

void libererPile(pile_t pile) {
  /* libererPile : libère une pile
     Entrée : pile la pile a libérer
     Sortie : */
  free(pile->val);
  free(pile);
}

int estVide(pile_t pile) {
  /* estVide : teste si la pile est vide
     Entrée : pile la pile que l'on souhaite tester
     Sortie : vide vaut 1 si la pile est vide, 0 sinon */
  int vide = 1;
  if (pile->adr != 0) {
    vide = 0;
  }
  return vide;
}

int estPleine(pile_t pile) {
  /* estPleine : teste si la pile est pleine
     Entrée : pile la pile que l'on souhaite tester
     Sortie : pleine vaut 1 si la pile est pleine, 0 sinon */
  int pleine = 1;
  if (pile->adr != pile->nbElm - 1) {
    pleine = 0;
  }
  return pleine;
}

element_t tete(pile_t pile) {
  /* tete : retour la valeur de la tete de la pile
     Entrée : pile la pile ou l'on souhaite connaitre la valeur de la tete
     Sortie : la valeur de la tete */
  return pile->val[pile->adr];
}

void empiler(pile_t pile, element_t elm) {
  /* empiler : permet d'empiler un element dans une pile
     Entrée : la pile ou empiler
              elm l'élément à empiler
     Sortie : */
  if (estPleine) {
    printf("erreur : la pile est pleine\n");
  }
  else {
    (pile->adr)++;
    pile->val[pile->adr] = elm;
  }  
}

void depiler(pile_t pile) {
  /* depiler : permet de dépiler un element dans une pile
     Entrée : la pile ou l'on veut dépiler
     Sortie : */
  if (estVide) {
    printf("erreur : la pile est vide\n");
  }
  else {
    (pile->adr)--;
  }
}  
