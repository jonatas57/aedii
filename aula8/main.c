#include <stdio.h>
#include "ext_sort.h"
#include "util.h"

int main() {
  FILE **file = (FILE**)malloc(12 * sizeof(FILE*));
  int page_size = 4000;
  for (int i = 0;i < 12;i++) {
    char *name;
    sprintf(name, "./r%d.txt", i);
    file[i] = open_file(name, "r");
  }
  char out[] = "./end.txt";
  FILE* output = open_file(out, "w");
  merge_files(out, file[0], file[1], page_size);
  return 0;
}
