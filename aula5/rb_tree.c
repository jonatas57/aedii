#include "rb_tree.h"

/** Funcao auxiliar que cria um novo Node, alocando memoria,
* para um valor de chave passado como parametro.
* Note que os valores dos ponteiros left/right/parent sao
* mantidos como NULL
*
* Parametros:
* key: a chave para o novo Node
*
* Devolve:
* Um novo Node em caso de sucesso, NULL caso nao consiga alocar
* a memoria para o novo Node
*/
Node* new_node(int key) {
    Node *ret_val = (Node*) malloc(sizeof(Node));
    if(NULL == ret_val) return NULL;
    ret_val->key = key;
    ret_val->color = BLACK;
    ret_val->left = NULL;
    ret_val->right = NULL;
    ret_val->parent = NULL;
    return ret_val;
}

/* Valor de sentinela, indica que chegamos em alguma folha ou entao
a raiz da arvore */
Node NIL_NODE;

/* Ponteiro para o valor de sentinela */
Node *NIL_PTR = &NIL_NODE;

/**
* A funcao abaixo insere uma nova chave em uma arvore RB
* sem realizar o balanceamento.
*
* Parametros:
* T: aponta para a raiz da arvore onde devemos inserir a chave
* key: valor da nova chave
*
* Devolve:
* O novo Node inserido em caso de sucesso, NULL caso nao
* seja possivel inserir o novo valor
*/
Node* tree_insert(Node** T, int key) {
  Node*	x = new_node(key);
  if (*T == NULL) {
    *T = x;
  }
	else {
	  Node *y = NULL, *z = *T;
		while (z != NULL) {
			y = z;
			if (key < y->key) {
				z = z->left;
			}
			else if (key > y->key) {
				z = z->right;
			}
			else return NULL;
		}
		x->parent = y;
		if (y->key < key) y->right = x;
		else y->left = x;
	}
  return x;
}

/**
* Realiza uma rotacao simples para a esquerda
*
* Parametros:
* T: aponta para a raiz da arvore onde a rotacao sera realizada
* x: Node pertencente a arvore em torno do qual faremos a rotacao
*
*/
void left_rotate(Node** T, Node* x) {
	Node *y = x->right;
	x->right = y->left;
	y->left = x;
	y->parent = x->parent;
	if (*T == x) {
		*T = y;
	}
	else {
		if (x->parent->left == x) x->parent->left = y;
		else x->parent->right = y;
	}
	x->parent = y;
}

/**
* Realiza uma rotacao simples para a direita
*
* Parametros:
* T: aponta para a raiz da arvore onde a rotacao sera realizada
* x: Node pertencente a arvore em torno do qual faremos a rotacao
*
*/

void right_rotate(Node** T, Node* x) {
	Node *y = x->left;
	x->left = y->right;
	y->right = x;
	y->parent = x->parent;
	if (*T == x) {
		*T = y;
	}
	else {
		if (x->parent->right == x) x->parent->right = y;
		else x->parent->left = y;
	}
	x->parent = y;
}

/**
* Realiza a troca de cor em alguns nos, caso esses satisfacam
* algumas condicoes.
*
* Parametros:
* T: aponta para a raiz da arvore onde a rotacao sera realizada
* x: Node pertencente a arvore em torno do qual faremos a rotacao
*
*/
#define par(a) a->parent
#define gpar(a) a->parent->parent


Node* uncle(Node* x) {
	if (gpar(x)->left == par(x)) {
		return gpar(x)->right;
	}
	return gpar(x)->left;
}
void flip_color(Node** T, Node* x) {
	if (x->color == RED && par(x)->color == RED && uncle(x)->color == RED && gpar(x)->color == BLACK) {
		gpar(x)->color = RED;
		par(x)->color = BLACK;
		uncle(x)->color = BLACK;
	}
	(*T)->color = BLACK;
}


void rbInsertFixup(Node **T, Node *z) {
	if (par(z) != NIL_PTR && gpar(z) != NIL_PTR) {
		Node *y = uncle(z);
		while (par(z)->color == RED) {
			if (y == gpar(z)->left) {
				if (y->color == RED) {
					par(z)->color = BLACK;
					y->color = BLACK;
					gpar(z)->color = RED;
					z = gpar(z);
				}
				else {
					if (z == par(z)->right) {
						z = par(z);
						left_rotate(T, z);
					}
					par(z)->color = BLACK;
					gpar(z)->color = RED;
					right_rotate(T, gpar(z));
				}
			}
			else {
				break;
			}
		}
	}
	(*T)->color = BLACK;
}

void rbInsert(Node **T, Node *z) {
  Node *y = NIL_PTR, *x = *T;
	while (x != NIL_PTR) {
		y = x;
		if (z->key < y->key) x = x->left;
		else x = x->right;
	}
	par(z) = y;
	if (y == NIL_PTR) *T = z;
	else if (z->key < y->key) y->left = z;
	else y->right = z;
	z->left = NIL_PTR;
	z->right = NIL_PTR;
	z->color = RED;
	rbInsertFixup(T, z);
}
// T(nil,   1, nil,   A)b    T
//A (  1,   2, nil,   B)b
//B (  A,   3, nil,   C)r    
//C (  B,   4, nil, nil)r    z
/*@*/
void test(Node* t, int a) {
	if (t == NIL_PTR) return;
	for (int i = 0;i < a;i++) {
		printf("-");
	}
	printf("\x1b[%dm%9p <- |%9p = %3d| -> %9p\x1b[m\n", (t->color == RED ? 31 : 32), t->left, t, t->key, t->right);
	test(t->left, a+1);
	test(t->right, a+1);
}/*@*/
