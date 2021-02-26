#include "liste.h"
#include <stdio.h>
#include <stdlib.h>

void afficherListe(cellule_t * adr)
/* afficherListe : affiche la liste
   Entrée : cellule_t* adresse de la première cellule
   Sortie : */
{
  cellule_t * cour = adr;
  while(cour != NULL)
    {
      printf("L'usine %d à la période %d produit %d\n", cour->usine, cour->periode, cour->val);
      cour = cour->suiv;
    }
}

cellule_t ** rechercheTri(cellule_t ** a0, int v)
/* rechercheTri : cherche v dans une liste triée
   Entrée : cellule_t* a0 adresse de la première cellule
            int v la valeur à chercher
   Sortie : cellule_t prec l'adresse du précédent pointant vers la première occurence de v*/
{
  cellule_t ** prec = a0;
  cellule_t * cour = *a0;
  while(cour != NULL && cour->val > v)
    {
      prec = &(cour->suiv);
      cour = cour->suiv;
    }
  return prec;
}

cellule_t * nouvCellule(int v, int i, int j)
/* nouvCellule : crée une nouvelle cellule
   Entrée : int v la valeur
            int i l'usine
	    int j la période
   Sortie : cellule_t* l'adresse de la cellule crée*/
{
  cellule_t * nouv;
  nouv = malloc(sizeof(cellule_t));
  if(nouv != NULL)
    {
      nouv->val = v;
      nouv->usine = i;
      nouv->periode = j;
      nouv->suiv = NULL;
    }
  return nouv;
}

void adjCellule(cellule_t ** prec, cellule_t * nouv)
/* adjCellule : insère une cellule dans la liste
   Entrée : cellule_t** prec la cellule après laquelle il faut insérer
            cellule_t* nouv la cellule à insérer
   Sortie : */
{
  nouv->suiv = *prec;
  *prec = nouv;
}
      
void supprCellule(cellule_t ** prec)
/* supprCellule : supprime une cellule dans une liste
   Entrée : prec la cellule précédante de celle a supprimer
   Sortie : */
{
  cellule_t * sauv = *prec;
  *prec = sauv->suiv;
  free(sauv);
}  

int valeur(cellule_t * cell)
/* valeur : retourne la valeur de la cellule
   Entrée : cell la cellule
   Sortie : la valeur */
{
  return cell->val;
}

int usine(cellule_t * cell)
/* usine : retourne l'usine de la cellule
   Entrée : cell la cellule
   Sortie : l'usine */
{
  return cell->usine;
}  

void libereListe(cellule_t * a0)
/* libereListe : libère la liste
   Entrée : cellule_t * a0 l'adresse du premier élément de la liste */
{
  cellule_t * cour = a0;
  cellule_t * suivant = NULL;
  while(cour != NULL)
    {
      suivant = cour->suiv;
      free(cour);
      cour = suivant;
    }
}
