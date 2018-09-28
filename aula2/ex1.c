#include <stdio.h>
#include <stdlib.h>
#include "hash.h"

int main() {
  int *colisoes = (int*)calloc(97, sizeof(int));
  for (int i = 0;i <= 10000;i++) {
    colisoes[div_hash(i, 97)]++;
  }
  char file[20] = "colisoes.csv";
  printFile(file, colisoes, 97);
  return 0;
}
