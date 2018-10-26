#include <stdio.h>
#include "rb_tree.h"

extern Node *NIL_PTR;

// void test(Node* x, int a) {
//   if (x == NIL_PTR || x == NULL) return;
//   for (int i = 0;i < a;i++) {
//     printf("-");
//   }
//   printf("%s%8p -> (%8p <- %8p = %3d -> %8p)\x1B[m\n", x->color == RED ? "\x1B[31m" : "\x1B[34m", x->parent,
//       x->left, x, x->key, x->right);
//   test(x->left, a + 1);
//   test(x->right, a + 1);
// }

int main() {
  Node *t = NIL_PTR;
  int n;
  printf("%p == NIL_PTR", NIL_PTR);
  while (scanf("%d", &n) != 0 && n != -1) {
    rbInsert(&t, new_node(n));
  }
  // test(t, 0);
  return 0;
}
