#include <stdio.h>
#include <stdlib.h>

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
  /* char * ligne */
  if(mat)
    {
      int erreur = 0;
      while(i < *m && !erreur)
	{
	  mat[i] = malloc(*n * sizeof(int));
	  if(!mat[i])
	    {
	      fprintf(stderr, "Erreur d'allocation de mémoire");
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
      /* if (!erreur) */
      /* 	{ */
      /* 	  for(i=0; i<m; i++) */
      /* 	    { */
      /* 	      ligne */
    }
  else
    {
      fprintf(stderr, "Erreur d'allocation de mémoire");
    }
  return mat;
}

int main(int argc, char * argv[])
{
  int n, m;
  printf("Hello world !\n");
  FILE * fichier = fopen(argv[1], "r");
  if (fichier)
    {
      initMatrice(fichier, &m, &n);
    }
  else
    {
      fprintf(stderr, "Erreur d'ouverture du fichier");
    }
  return 0;
}
