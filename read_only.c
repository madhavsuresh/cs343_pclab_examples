/*
 * Source:  https://www.classes.cs.uchicago.edu/archive/2014/spring/12300-1/labs/lab4/
 */ 
#include <pthread.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void *data_access(void *ptr);
void *square(void *param);

uint64_t shared_value;
#define NUM_THREADS 100
int main() {

  shared_value = 343;
  pthread_t threads[NUM_THREADS];
  int *params[NUM_THREADS];

  for (long t = 0; t < NUM_THREADS; t++) {
    params[t] = malloc(sizeof(int));
    *params[t] = t + 1;
    pthread_create(&threads[t], NULL, data_access, (void *)params[t]);
  }

  for (long t = 0; t < NUM_THREADS; t++) {
    pthread_join(threads[t], NULL);
    free(params[t]);
  }

  exit(0);
}

void *data_access(void *ptr) {
  printf("%d\n", (int)shared_value);
  pthread_exit(NULL);
}
