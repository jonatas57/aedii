#include <stdio.h>
#include "bt_btree.h"

void printkeys(bt_node *T) {
  printf("[");
  for (int i = 0;i < T->num_keys;i++) {
    if (i!= 0) printf(", ");
    printf("%d", T->keys[i]);
  }
  printf("]\n");
}

void test(bt_node *T, int a) {
  if (!T) return;
  for (int i = 0;i < a;i++) {
    printf("-");
  }
  printkeys(T);
  for (int i = 0;i <= T->num_keys;i++) {
    test(T->children[i], a + 1);
  }
}

int main() {
  bt_tree *T = new_tree(2);
  int n;
  while (scanf("%d", &n) != 0 && n != -1) {
    bt_insert(T, n);
    test(T->root, 0);
  }
  print_tree(T);
  return 0;
}
