#include "hash.h"

int div_hash(int key, int m) {
  return key % m;
}

int mul_hash(int key, int m, float a) {
  return (int)(m * ((key * a) - (int)(key * a)));
}

void printFile(char* file, int *v, int n) {
  FILE *pFile;
  pFile = fopen(file, "w");
  fprintf(pFile, "hash,colisoes\n");
  for (int i = 0;i < n;i++) {
    fprintf(pFile, "%d,%d\n", i, v[i]);
  }
  fclose(pFile);
}
