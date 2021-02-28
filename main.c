#include <stdio.h>
#include <stdlib.h>

#include "matrice.h"
#include "liste.h"
#include "fonction.h"


int main(int argc, char * argv[])
{
  /* argv[1] : fichier à ouvrir */
  /* argv[2] : fichier où écrire */
  /* argv[3] : k nombre d'éléments à chercher */
  int n, m;
  int ** mat = NULL;
  char * nomOuv = argv[1];
  char * nomEcr = argv[2];
  int k = atoi(argv[3]);
  if(argc > 3)
    {
      FILE * fichierOuv = fopen(nomOuv, "r");
      if (fichierOuv)
	{
	  mat = initMatrice(fichierOuv, &m, &n);
	  /* printf("Matrice : \n"); */
	  /* afficherMatrice(mat, m, n); */
	  cellule_t * liste = coutFaibles(k, mat, m, n);
	  /* printf("Liste :\n"); */
	  /* afficherListe(liste); */
	  
	  libereMatrice(mat, m);
	  /* suppUsine(&liste, 2); */
	  /* suppUsine(&liste, 2); */
	  /* printf("Liste :\n"); */
	  /* afficherListe(liste); */

	  /* printf("Fichier :\n"); */
	  FILE * fichierEcr = fopen(nomEcr, "w");
	  {
	    if (fichierEcr)
	      {
		listToFile(fichierEcr, liste);
		printf("Le fichier %s contient la liste des %d plus faibles coûts\n", nomEcr, k);
		libereListe(liste);
	      }
	    else
	      {
		fprintf(stderr, "Erreur d'ouverture du fichier d'écriture\n");
	      }
	  }
	}
      else
	{
	  fprintf(stderr, "Erreur d'ouverture du fichier à lire\n");
	}
    }
  else
    {
      fprintf(stderr, "Nombre d'arguments insuffisant. Utilisez :\nprog fichier_a_ouvrir fichier_ou_ecrire nombre_elements\n");
    }
  return 0;
}
