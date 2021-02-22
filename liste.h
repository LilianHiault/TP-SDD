#ifndef list_h
#define liste_h

typedef struct cellule
{
  int val;
  int i;
  int j;
  struct cellule * suiv;
} cellule_t;


void afficherListe(cellule_t * adr);
/* afficherListe : affiche la liste
   Entrée : cellule_t* adresse de la première cellule
   Sortie : */
  
cellule_t ** rechercheTri(cellule_t ** a0, int v);
/* rechercheTri : cherche v dans une liste triée
   Entrée : cellule_t* a0 adresse de la première cellule
            int v la valeur à chercher
   Sortie : cellule_t prec l'adresse du précédent pointant vers la première occurence de v*/

cellule_t * nouvCellule(int v, int i, int j);
/* nouvCellule : crée une nouvelle cellule
   Entrée : int v la valeur
            int i l'usine
	    int j la période
   Sortie : cellule_t* l'adresse de la cellule crée*/

void adjCellule(cellule_t ** prec, cellule_t * nouv);
/* adjCellule : insère une cellule dans la liste
   Entrée : cellule_t** prec la cellule après laquelle il faut insérer
            cellule_t* nouv la cellule à insérer
   Sortie : */

#endif
