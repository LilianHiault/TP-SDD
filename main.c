#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "liste.h"
#include "fonction.h"


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
	  printf("Matrice : \n");
	  afficherMatrice(mat, m, n);
	  cellule_t * liste = coutFaibles(6, mat, m, n);
	  printf("Liste :\n");
	  afficherListe(liste);
	  
	  libereMatrice(mat, m);
	  suppUsine(&liste, 2);
	  suppUsine(&liste, 2);
	  printf("Liste :\n");
	  afficherListe(liste);

	  printf("Fichier :\n");
	  listToFile(stdout, liste);
	  libereListe(liste);
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
