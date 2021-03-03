#include <stdlib.h>
#include <stdio.h>

#include "file.h"

file_t * initFile(int n)
{
  file_t * f = malloc(sizeof(file_t));
  f->taille = n;
  f->val = malloc(n * sizeof(element_t));
  /* vérif alloc */
  f->deb = 0;
  f->fin = n - 1;
  f->nb_elem = 0;
  return f;
}

void enfiler(file_t f, element_t elem)
{
  if (filePleine(f))
    {
      fprintf(stderr, "la file est pleine\n");
    }
  else
    {
      f.fin = (f.fin +1) % f.taille;
      f.val[f.fin] = elem;
      f.nb_elem = f.nb_elem + 1;
    }
}

element_t defiler(file_t f)
{
  int elem = 0;
  if(fileVide(f))
    {
      fprintf(stderr, "La file est déjà vide\n");
    }
  else
    {
      elem = f.val[(f.deb)];
      f.deb = (f.deb + 1) % f.taille;
      f.nb_elem = f.nb_elem - 1;
    }
  return elem;
}

int filePleine(file_t f)
{
  return f.nb_elem == f.taille;
}

int fileVide(file_t f)
{
  return f.nb_elem == f.taille;
}

void libereFile(file_t * f)
{
  free(f->val);
  free(f);
}
 
void afficherFile(file_t f)
{
  int i = 0;
  for(i=0; i<f.nb_elem; i++)
    {
      printf("FORMAT\n", f.val[ (f.deb + i) % f.taille ]);
    }
}
