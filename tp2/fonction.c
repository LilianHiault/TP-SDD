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

  /*
  CNP(5, 3)
  <=> CNP(4, 3) + CNP(4, 2)
  <=> CNP(3, 3) + CNP(3, 2) + CNP(3, 2) + CNP(3, 1)
  <=> 1 + CNP(2, 2) + CNP(2, 1) + CNP(2, 2) + CNP(2, 1) + CNP(2, 1) + CNP(2, 0)
  <=> 1 + 1 + CNP(1, 1) + CNP(1, 0) + 1 + CNP(1, 1) + CNP(1, 0) + CNP(1, 1) + CNP(1, 0) + 1
  <=> 4 + 1 + 1 + 1 + 1 + 1 + 1
  <=> 8
  */
