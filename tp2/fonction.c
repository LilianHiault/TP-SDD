#include "fonction.h"
#include "pile.h"

#include <stdio.h>
#include <stdlib.h>

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

int CNP_iter(int n, int p)
{
  int ni = n;
  int pi = p;
  int r = 0;
  pile_t * pile = creerPile(MAX);

  do
    {
      if (ni != pi || pi != 0)
	{
	  couple_t c = {ni, pi};
	  empiler(c);
	  ni = ni - 1;
	  pi = pi - 1;
	}
      else
	{
	  r = r + 1;
	}
    } while (!estVide(pile));
  return r;
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
