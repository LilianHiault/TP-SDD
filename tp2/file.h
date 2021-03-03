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
void enfiler(file_t f, element_t elem);
element_t defiler(file_t f);
int filePleine(file_t f);
int fileVide(file_t f);
void libereFile(file_t * f);
void afficherFile(file_t f);


#endif
