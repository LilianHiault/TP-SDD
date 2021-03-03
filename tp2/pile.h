#ifndef pile_h
#define pile_h

typedef int element_t;
#define  FORMAT %d

typedef struct pile {
  int nbElm;
  int adr;
  element_t val[];
} pile_t;  

pile_t * creerPile(int nbElm);
  /* creerPile : créer et initialise une pile
     Entrée : nbElm le nombre d'éléments max dans la pile
     Sortie : pile la pile */

pile_t * creerPile(int nbElm);
  /* creerPile : créer et initialise une pile
     Entrée : nbElm le nombre d'éléments max dans la pile
     Sortie : pile la pile */

int estVide(pile_t pile);
  /* estVide : teste si la pile est vide
     Entrée : pile la pile que l'on souhaite tester
     Sortie : vide vaut 1 si la pile est vide, 0 sinon */

int estPleine(pile_t pile);
  /* estPleine : teste si la pile est pleine
     Entrée : pile la pile que l'on souhaite tester
     Sortie : pleine vaut 1 si la pile est pleine, 0 sinon */

element_t tete(pile_t pile);
  /* tete : retour la valeur de la tete de la pile
     Entrée : pile la pile ou l'on souhaite connaitre la valeur de la tete
     Sortie : la valeur de la tete */

void empiler(pile_t pile, element_t elm);
  /* empiler : permet d'empiler un element dans une pile
     Entrée : la pile ou empiler
              elm l'élément à empiler
     Sortie : */

void depiler(pile_t pile);
  /* depiler : permet de dépiler un element dans une pile
     Entrée : la pile ou l'on veut dépiler
     Sortie : */

#endif
