#include <stdio.h>
#include "rb_tree.h"

extern Node *NIL_PTR;

int main() {
	Node *t = NIL_PTR;
	int n;
	while (scanf("%d", &n) && n != -1) {
		rbInsert(&t, new_node(n));
		printf("-------------------------------------------\n");
		test(t, 0);
	}
	return 0;
}
