#ifndef liste_h
#define liste_h

typedef struct cellule
{
  int val;
  int usine;
  int periode;
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

void supprCellule(cellule_t * prec);
/* supprCellule : supprime une cellule dans une liste
   Entrée : prec la cellule précédante
            cell la cellule a suprimer
   Sortie : */

int valeur(cellule_t * cell);
/* valeur : retourne la valeur de la cellule
   Entrée : cell la cellule
   Sortie : la valeur */

int usine(cellule_t * cell);
/* usine : retourne l'usine de la cellule
   Entrée : cell la cellule
   Sortie : l'usine */

void libereListe(cellule_t * a0);
/* libereListe : libère la liste
   Entrée : cellule_t * a0 l'adresse du premier élément de la liste */
#endif
