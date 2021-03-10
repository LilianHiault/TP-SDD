#include <stdio.h>
#include <stdlib.h>
#include "pile.h"
#include "file.h"
#include "fonction.h"

int main() {

  int testRec = CNP(5, 3);
  int testIter = CNP_iter(5, 3);
  printf("CNP(5, 3) = %d\n", testRec);
  printf("CNP_iter(5, 3) = %d\n", testIter);
  return 0;
}  
