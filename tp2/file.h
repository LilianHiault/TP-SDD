#ifndef file_h
#define file_h

#define FORMAT %d
typedef int element_t;

typedef struct file
{
  int taille;
  element_t * val;
  int deb;
  int fin;
  int nb_elem;
} file_t;


file_t * initFile(int n);
/* initFile : initialise la file
   Entrée : int n la taille de la file
   Sortie : file_t * un pointeur vers la file */

void enfiler(file_t f, element_t elem);
/* enfiler : ajoute un élément dans la file
   Entrée : file_t f la file
            element_t elem l'élément à ajouter
   Sortie : */


element_t defiler(file_t f);
/* defiler : supprime l'élément en tête de la file et le supprime
   Entrée : file_t f la file
   Sortie : element_t l'élément en tête de file*/

int filePleine(file_t f);
/* filePlein : renvoie vrai si la file est pleine faux sinon
   Entrée : file_t f la file
   Sortie : int soit vrai soit faux */

int fileVide(file_t f);
/* filePlein : renvoie vrai si la file est vide faux sinon
   Entrée : file_t f la file
   Sortie : int soit vrai soit faux */

void libereFile(file_t * f);
/* libereFile : libère la file est ses éléments
   Entrée : file_t f la file
   Sortie : */

void afficherFile(file_t f);
/* afficherFile : affiche tous les éléments de la file
   Entrée : file_t f la file
   Sortie : */


#endif
