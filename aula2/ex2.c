#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
  int *colisoes = (int*)calloc(200, sizeof(int));
  for (int i = 0;i <= 500000;i++) {
    colisoes[mul_hash(i, 200, 0.618/*03398875*/)]++;
  }

  char file[20] = "colisoes2.csv";
  printFile(file, colisoes, 200);
  return 0;
}
