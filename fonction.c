#include <stdlib.h>
#include "fonction.h"
#include "matrice.h"

#define ERREUR -1

cellule_t * coutFaibles(int k, int ** C, int m, int n)
/* coutFaibles : crée la liste des K plus petites valeurs de la matrice C
   Entrée : k valeurs à mettre dans la liste
   C la matrice en 2 dimensions de taille m * n
   m lignes dans C
   n colonnes dans C
   Sortie :
   adresse vers la première cellule */
{
  cellule_t * liste = NULL;
  int i = 0;
  int j = 0;
  int val = 0;
  int erreur = 0;
  int compt = 0;
  // On rempli d'abord la liste de K valeurs
  // La liste est triée dans l'ordre décroissant, on a donc la plus grande valeur dans le 1er maillon
  while(i < m && compt < k)
    {
      while(j < n && compt < k)
	{
	  cellule_t * c = creerCell(C[i][j], i, j);
	  if(c)
	    {
	      insererCell(&liste, c);
	    }
	  j++;
	  compt++;
	}
      i++;
    }

  // On parcours chaque case de la matrice
  for(i=i; i<m; i++)
    {
      for(j=j; j<n; j++)
	{
	  // Si la valeur est plus petite que la valeur du 1er maillon (plus grande valeur de la liste)
	  val = valeurTete(liste, &erreur);
	  if(!erreur)
	    {
	      if(C[i][j] < val)
		{
		  // Alors on supprime le 1er maillon et on insére dans la liste triée la nouvelle valeur
		  supprTete(&liste);
		  cellule_t * c = creerCell(C[i][j], i, j);
		  if(c)
		    {
		      insererCell(&liste, c);
		    }
		}
	    }
	}
    }
  libereMatrice(C, m);
  return liste;
}


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
  (void) p_tete;
  /* supprTete : supprime la tete de la liste
     Entrée : tete la cellule a la tete de la liste
     Sortie : tete */
  /* if (*p_tete != NULL) */
  /*   *p_tete = *(p_tete)->suiv; */
}

void insererCell(cellule_t ** p_tete, cellule_t * cell) {
  (void) p_tete;
  (void) cell;
  /* insererCell : insérer la cellule dans la liste triée
     Entrée : tete la cellule a la tete de la liste
     cell la cellule a insérer
     Sortie : tete */
  /* int val = cell->val; */
  /* if (*p_tete == NULL) { */
  /*   *p_tete = cell; */
  /* } */
  /* else { */
  /*   cellule_t * cour = *p_tete; */
  /*   cellule_t * prec = p_tete; */
  /*   while (cour!=NULL && cour->val>val) { */
  /*     prec = &(cour->suiv); */
  /*     cour = cour->suiv; */
  /*   } */
  /*   prec->suiv = cell; */
  /*   cell->suiv = cour; */
  /* } */
}
