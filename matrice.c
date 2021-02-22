#include <stdio.h>
#include <stdlib.h>
#include "matrice.h"
#include "fonction.h"


int ** initMatrice(FILE * fichier, int * m, int * n)
/* initMatrice : initialise la matrice à partir d'un fichier
   Entrée : fichier où se trouvent les valeurs de la matrice
            m lignes
	    n colonnes
   Sortie : mat la matrice des coûts de production
            m lignes
	    n colonnes */
{
  fscanf(fichier, "%d %d", m, n);
  int ** mat = malloc(*m * sizeof(int *));
  int i = 0;
  int j = 0;
  /* char ligne[BUFSIZ]; */
  if(mat)
    {
      int erreur = 0;
      while(i < *m && !erreur)
	{
	  mat[i] = malloc(*n * sizeof(int));
	  if(!mat[i])
	    {
	      fprintf(stderr, "Erreur d'allocation de mémoire\n");
	      erreur = 1;
	      // Libérer tous les blocs déjà alloués
	      for(j=0; j<i; j++)
		{
		  free(mat[j]);
		}
	      free(mat);
	    }
	  i++;
	}

      // Lire les valeurs dans le fichier et remplir la matrice
      if (!erreur)
      	{
      	  for(i=0; i<*m; i++)
      	    {
	      for(j=0; j<*n; j++)
		{
		  fscanf(fichier, "%d", &mat[i][j]);
		}
	    }
	}
    }
  else
    {
      fprintf(stderr, "Erreur d'allocation de mémoire\n");
    }
  return mat;
}

void afficherMatrice(int ** mat, int m, int n)
/* afficherMatrice  : affiche la matrice
   Entrée : matrice à afficher
            m lignes
	    n colonnes */
{
  int i = 0;
  int j = 0;
  for(i=0; i<m; i++)
    {
      for(j=0; j<n; j++)
	{
	  printf("%d ", mat[i][j]);
	}
      printf("\n");
    }
}

void libereMatrice(int ** mat, int m)
/* libereMatrice : libère la matrice
   Entrée : mat la matrice à libérer
            m lignes */
{
  int i = 0;
  for(i=0; i<m; i++)
    {
      free(mat[i]);
    }
  free(mat);
}
