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
  int i = 0; // usines
  int j = 0; // périodes
  int val = 0; // Valeur à insérer dans la liste
  int compt = 0;
  cellule_t ** prec = NULL;
  // On rempli d'abord la liste de K valeurs
  // La liste est triée dans l'ordre décroissant, on a donc la plus grande valeur dans le 1er maillon
  while(i < m && compt < k)
    {
      while(j < n && compt < k)
	{
	  cellule_t * c = nouvCellule(C[i][j], i, j);
	  if(c)
	    {
	      if(liste != NULL)
		{
		  val = valeur(liste);
		  prec = rechercheTri(&liste, val);
		  adjCellule(prec, c);
		}
	      else
		{
		  adjCellule(&liste, c);
		}
	    }
	  j++;
	  compt++;
	}
      j = 0;
      i++;
    }

  // On parcours chaque case de la matrice
  for(i=i; i<m; i++)
    {
      for(j=j; j<n; j++)
	{
	  // Si la valeur est plus petite que la valeur du 1er maillon (plus grande valeur de la liste)
	  val = valeur(liste);
	  if(C[i][j] < val)
	    {
	      // Alors on supprime le 1er maillon et on insére dans la liste triée la nouvelle valeur
	      supprCellule(&liste);
	      cellule_t * c = nouvCellule(C[i][j], i, j);
	      if(c)
		{
		  prec = rechercheTri(&liste, valeur(liste));
		  adjCellule(&liste, c);
		}
	    }
	}
    }
  return liste;
}

void suppUsine(cellule_t ** a0, int u)
/* suppUsine : supprime toutes les occurences d'une usine dans une liste
   Entrée : cellule_t * a0 l'adresse de la première cellule
   int u l'usine à supprimer
   Sortie : */
{
  cellule_t ** prec = a0;
  cellule_t * cour = *a0;
  while(cour != NULL)
    {
      while(cour != NULL && cour->usine == u)
	{
	  supprCellule(prec);
	}
      prec = &cour->suiv;
      cour = cour->suiv;
    }
}

void listToFile(FILE * fichier, cellule_t * liste)
/* listToFile : écrit la liste dans un fichier de la manière suivante par ligne : valeur usine periode
   Entrée : fichier le fichier ou l'on veut écrire
   liste la liste que l'on souhaite écrire
   Sortie : */
{
  cellule_t * cour = liste;
  while (cour != NULL)
    {
      fprintf(fichier, "%d %d %d\n", cour->val, cour->usine, cour->periode);
      cour = cour->suiv;
    }  
}  

