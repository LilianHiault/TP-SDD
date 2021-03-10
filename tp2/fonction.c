#include <stdio.h>
#include <stdlib.h>
#include "fonction.h"
#include "pile.h"

#define TAILLE 100

#define MAX 100


int CNP(int n, int p)
{
  if (n == p || p == 0) {
    return 1;
  }
  else {
    return CNP(n-1, p) + CNP(n-1, p-1);
  }
}  

  /*
  CNP(5, 3)
  <=> CNP(4, 3) + CNP(4, 2)
  <=> CNP(3, 3) + CNP(3, 2) + CNP(3, 2) + CNP(3, 1)
  <=> 1 + CNP(2, 2) + CNP(2, 1) + CNP(2, 2) + CNP(2, 1) + CNP(2, 1) + CNP(2, 0)
  <=> 1 + 1 + CNP(1, 1) + CNP(1, 0) + 1 + CNP(1, 1) + CNP(1, 0) + CNP(1, 1) + CNP(1, 0) + 1
  <=> 4 + 1 + 1 + 1 + 1 + 1 + 1
  <=> 8
  */

int CNP_iter(int n, int p) {
  int ni = n;
  int pi = p;
  int r = 0;
  int continuer = 1;
  pile_t * pile = creerPile(TAILLE);
  do {
    if (ni != pi && pi != 0) {
      empiler(pile, ni-1);
      empiler(pile, pi);
      ni = ni - 1;
      pi = pi - 1;
    }
    else {
      r = r + 1;
      if (estVide(pile)) {
	continuer = 0;
      }
      else {
	pi = depiler(pile);
	ni = depiler(pile);
      }
    }
  } while(continuer);
  return r;
}  
