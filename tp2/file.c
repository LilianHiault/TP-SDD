#include <stdlib.h>
#include <stdio.h>

#include "file.h"

file_t * initFile(int n)
/* initFile : initialise la file
   Entrée : int n la taille de la file
   Sortie : file_t * un pointeur vers la file */
{
  file_t * f = malloc(sizeof(file_t));
  if (f)
    {
      f->taille = n;
      f->val = malloc(n * sizeof(element_t));
      if(f->val)
	{
	  f->deb = 0;
	  f->fin = n - 1;
	  f->nb_elem = 0;
	}
      else
	{
	  fprintf(stderr, "Erreur d'allocation du tableau de la file\n");
	}
    }
  else
    {
      fprintf(stderr, "Erreur d'allocation de la file\n");
    }
  return f;
}

int enfiler(file_t f, element_t elem)
/* enfiler : ajoute un élément dans la file
   Entrée : file_t f la file
            element_t elem l'élément à ajouter
   Sortie : int vaut 0 si aucune erreur */
{
  int erreur = 0;
  if (filePleine(f))
    {
      erreur = 1;
      fprintf(stderr, "La file est pleine\n");
    }
  else
    {
      f.fin = (f.fin +1) % f.taille;
      f.val[f.fin] = elem;
      f.nb_elem = f.nb_elem + 1;
    }
  return erreur;
}

element_t defiler(file_t f, int * erreur)
/* defiler : supprime l'élément en tête de la file et le supprime
   Entrée : file_t f la file
            int * erreur pointeur vers un entier qui vaut 0 si pas d'erreur
   Sortie : element_t l'élément en tête de file
            int * erreur pointeur vers un entier qui vaut 0 si pas d'erreur*/
{
  int elem = 0;
  if(fileVide(f))
    {
      *erreur = 1;
      fprintf(stderr, "La file est déjà vide\n");
    }
  else
    {
      elem = f.val[(f.deb)];
      f.deb = (f.deb + 1) % f.taille;
      f.nb_elem = f.nb_elem - 1;
      *erreur = 0;
    }
  return elem;
}

int filePleine(file_t f)
/* filePlein : renvoie vrai si la file est pleine faux sinon
   Entrée : file_t f la file
   Sortie : int soit vrai soit faux */
{
  return f.nb_elem == f.taille;
}

int fileVide(file_t f)
/* filePlein : renvoie vrai si la file est vide faux sinon
   Entrée : file_t f la file
   Sortie : int soit vrai soit faux */
{
  return f.nb_elem == f.taille;
}

void libereFile(file_t * f)
/* libereFile : libère la file est ses éléments
   Entrée : file_t f la file
   Sortie : */
{
  free(f->val);
  free(f);
}
 
void afficherFile(file_t f)
/* afficherFile : affiche tous les éléments de la file
   Entrée : file_t f la file
   Sortie : */
{
  int i = 0;
  for(i=0; i<f.nb_elem; i++)
    {
      printf("FORMAT\n", f.val[ (f.deb + i) % f.taille ]);
    }
}
