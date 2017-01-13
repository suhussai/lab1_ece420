#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>
#include "time.h"
#include "lab1_IO.h"

// load the matrix
int **A; int **B; int **C; int n; int p;

#include <time.h>

#define GET_TIME(now) { \
   struct timeval t; \
   gettimeofday(&t, NULL); \
   now = t.tv_sec + t.tv_usec/1000000.0; \
}

void *multiply_matrix(void* rank) {
  long k = (long) rank;
  int x, y;
  x = floor(k / sqrt(p));
  y = k % (long)sqrt(p);

  int i_upper_bound = (n / sqrt(p)) * (x + 1) - 1;
  int i_lower_bound = (n / sqrt(p)) * x;
  int j_upper_bound = (n / sqrt(p)) * (y + 1) - 1;
  int j_lower_bound = (n / sqrt(p)) * y;
  int my_row; int my_col; int r;

  for (my_row = i_lower_bound; my_row <= i_upper_bound; my_row++) {
    for (my_col = j_lower_bound; my_col <= j_upper_bound; my_col++) {
      C[my_row][my_col] = 0.0;
      for (r = 0; r < n; r++){
	C[my_row][my_col] = C[my_row][my_col] + (A[my_row][r] * B[r][my_col]);
      }
    }
  }

  return NULL;
}


int main(int argc, char* argv[]){
  long       thread;
  pthread_t* thread_handles;
  double start = 0.0; double end = 0.0;
  printf("starting main\n");

  if (argc != 2) return 0;
  p = atoi(argv[1]);
  // sanitize thread count: check for evenness
  thread_handles = malloc(p*sizeof(pthread_t));

  Lab1_loadinput(&A, &B, &n);

  // allocate space for matrix C, the resultant matrix
  C = malloc(n * sizeof(int*));
  int i;
  for (i = 0; i <= n; i++)
    {
      (C)[i] = malloc(n * sizeof(int));
    }
  GET_TIME(start);
  for (thread = 0; thread < p; thread++) {
    printf("creating threads %ld\n", thread);
    pthread_create(&thread_handles[thread], NULL,
		   multiply_matrix, (void*) thread);
  }

  for (thread = 0; thread < p; thread++) {
    pthread_join(thread_handles[thread], NULL);
  }
  GET_TIME(end);

  printf("saving output %f\n", end - start);
  Lab1_saveoutput(C, &n, end-start);


  free(A);
  free(B);
  free(C);
  
  return 0;
}
