#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "search.h"

int main() {
  int n, *array, x;
  time_t runtime;
  scanf("%d", &n);
  array = malloc(n * sizeof(int));
  for (int i = 0;i < n;i++) {
    scanf("%d", array + i);
  }
  time_t init = clock();
  printf("---------------seq----------------\n");
  while (scanf("%d", &x) != 0 && x != -1) {
    runtime = clock();
    printf("%d\n", seq_search(array, n, x));
    printf("%.6f s\n", (double)(clock() - runtime) / CLOCKS_PER_SEC);
  }
  printf("---------------bin----------------\n");

  while (scanf("%d", &x) != 0 && x != -1) {
    runtime = clock();
    printf("%d\n", bin_search(array, n, x));
    printf("%.6f s\n", (double)(clock() - runtime) / CLOCKS_PER_SEC);
  }

  printf("Tempo total = %.6f s\n", (double)(clock() - init) / CLOCKS_PER_SEC);

  return 0;
}
