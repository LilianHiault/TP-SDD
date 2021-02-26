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
  int compt = 0;
  cellule_t ** prec = NULL;
  int isauv = 0; // Sauvegarde de i et j entre les 2 boucles
  int jsauv = 0;

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
		  prec = rechercheTri(&liste, valeur(c));
		  adjCellule(prec, c);
		}
	      else
		{
		  adjCellule(&liste, c);
		}
	    }
	  j++;
	  compt++;
	  jsauv = j;
	}
      j = 0;
      i++;
    }

  //printf("Liste %d premiers :\n", k);
  //afficherListe(liste);

  isauv = i-1;

  // On finit de lire la ligne de la matrice
  for(j=jsauv; j<n; j++)
    {
      //printf("Ligne : i:%d, j:%d, valeur=%d | tete=%d\n", isauv, j, C[isauv][j], valeur(liste));
      if(C[isauv][j] <= valeur(liste))
	{
	  // Alors on supprime le 1er maillon et on insére dans la liste triée la nouvelle valeur
	  supprCellule(&liste);
	  cellule_t * c = nouvCellule(C[isauv][j], isauv, j);
	  if(c)
	    {
	      prec = rechercheTri(&liste, valeur(c));
	      adjCellule(prec, c);
	    }
	}
    }

  //printf("Liste fin ligne :\n");
  //afficherListe(liste);
 
  // On parcours chaque case de la matrice
  for(i=isauv+1; i<m; i++)
    {
      for(j=0; j<n; j++)
	{
	  // Si la valeur est plus petite que la valeur du 1er maillon (plus grande valeur de la liste)
	  //printf("i:%d, j:%d, valeur=%d | tete=%d\n", i, j, C[i][j], valeur(liste));
	  if(C[i][j] <= valeur(liste))
	    {
	      // Alors on supprime le 1er maillon et on insére dans la liste triée la nouvelle valeur
	      supprCellule(&liste);
	      cellule_t * c = nouvCellule(C[i][j], i, j);
	      if(c)
		{
		  prec = rechercheTri(&liste, valeur(c));
		  adjCellule(prec, c);
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

