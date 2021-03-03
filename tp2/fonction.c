#include "fonction.h"
#include <stdio.h>
#include <stdlib.h>


int CNP(int n, int p) {
  if (n == p || p == 0) {
    return 1;
  }
  else {
    return CNP(n-1, p) + CNP(n-1, p-1);
  }
}  
