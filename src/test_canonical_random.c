#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void gen_random(int bufsize, int seed) {
  printf("bufsize %d seed %d\n", bufsize, seed);
  struct random_data data;
  char *statebuf = malloc(bufsize); 
  initstate_r((int) seed,statebuf,bufsize,&data);
  int32_t result;
  for(int index = 0; index < bufsize * 2; ++index) {
    random_r(&data, &result);
    printf("random number 0x%08x %d\n", result, result);
  }
  free(statebuf);
}

int main() {
  gen_random(32, 10000);
  gen_random(64, 10000);
  gen_random(128, 10000);
  gen_random(256, 10000);
  return 0;
}
