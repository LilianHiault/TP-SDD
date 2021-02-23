#include <stdlib.h>
#include "fonction.h"
#include "matrice.h"
#include "liste.h"

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
	  cellule_t * c = nouvCellule(C[i][j], i, j);
	  if(c)
	    {
	      adjCellule(&liste, c);
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
	  val = valeur(liste);
	  if(!erreur)
	    {
	      if(C[i][j] < val)
		{
		  // Alors on supprime le 1er maillon et on insére dans la liste triée la nouvelle valeur
		  supprCellule(liste);
		  cellule_t * c = nouvCellule(C[i][j], i, j);
		  if(c)
		    {
		      adjCellule(&liste, c);
		    }
		}
	    }
	}
    }
  libereMatrice(C, m);
  return liste;
}

