#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include <stdio.h>

int main(int argc, char * argv[])
{
  int n, m;
  int ** mat = NULL;
  if(argc > 1)
    {
      FILE * fichier = fopen(argv[1], "r");
      if (fichier)
	{
	  mat = initMatrice(fichier, &m, &n);
	  afficherMatrice(mat, m, n);
	}
      else
	{
	  fprintf(stderr, "Erreur d'ouverture du fichier\n");
	}
    }
  else
    {
      fprintf(stderr, "Aucun fichier spécifié en ligne de commande\n");
    }
  return 0;
}
