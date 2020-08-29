#include <stdlib.h>
#include <stdio.h>
#include "random_r.h"


#define BUFSIZE 128
static struct alt_random_data data;
static char statebuf[BUFSIZE];

int main() {
//  int seed = getpid();
  // uncomment next line to have deterministic start state
  int seed = 10000;
  printf("seed %d\n", seed);
  alt_initstate_r((int) 1,statebuf,BUFSIZE,&data);
  alt_srandom_r(seed,&data);


  int32_t result; 
  alt_random_r(&data, &result);
  printf("%d\n", result);

  alt_random_r(&data, &result);
  printf("%d\n", result);

  alt_random_r(&data, &result);
  printf("%d\n", result);

  return 0;
}
