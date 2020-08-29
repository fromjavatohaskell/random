#include <stdlib.h>
#include <stdio.h>
#include "random_r.h"


#define BUFSIZE 128
static struct alt_random_data data;
static char statebuf[BUFSIZE];


void print_data(struct alt_random_data *buf) {
  if(buf == NULL) {
    printf("data null\n");
  }

  printf("type %d deg %d sep %d fptr %d rptr %d end_ptr %d\n", buf->rand_type, buf->rand_deg, buf->rand_sep,
     (int)(buf->fptr - buf->state), (int)(buf->rptr - buf-> state), (int)(buf->end_ptr - buf->state) );

  int32_t *state = buf->state;
  int state_length = (int)(buf->end_ptr - buf->state);

  for(int index = -1; index < state_length; index++) {
    printf("%08x ", state[index]);
    if(index > 0 && ((index + 2) % 8) == 0) {
      printf("\n");
    }
  }
}

int main() {
  alt_initstate_r((int) 1,statebuf,BUFSIZE,&data);
  print_data(&data);


//  int seed = getpid();
  // uncomment next line to have deterministic start state
  int seed = 10000;
  printf("seed %d\n", seed);
  alt_srandom_r(seed,&data);
  print_data(&data);

  int32_t result; 
  alt_random_r(&data, &result);
  printf("random number %08x\n", result);
  print_data(&data);

  alt_random_r(&data, &result);
  printf("random number %08x\n", result);
  print_data(&data);

  alt_random_r(&data, &result);
  printf("random number %08x\n", result);
  print_data(&data);

  return 0;
}
