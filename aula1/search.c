#include <stdio.h>
#include "search.h"

int seq_search(int array[], int array_size, int key) {
  for (int i = 0;i < array_size;i++) {
    if (array[i] == key) {
      return i;
    }
  }
  return -1;
}

int bin_search(int array[], int array_size, int key) {
  if ((array_size == 1 && array[0] != key) || array_size <= 0) return -1;
  int mid = array_size / 2;
  if (array[mid] == key) {
    while (array[mid - 1] == key) mid--;
    return mid;
  }
  else if (array[mid] > key) {
    return bin_search(array, mid, key);
  }
  else {
    int x = bin_search(array + mid + 1, array_size - mid, key);
    return x == -1 ? -1 : x + mid + 1;
  }
}
