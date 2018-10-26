#include "rb_tree.h"
#include <stdio.h>

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
  ret_val->color = key % 2 == 0 ? RED : BLACK;
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
  Node* x = NULL;
  if (*T == NULL) {
    *T = new_node(key);
  }
  if ((*T)->key < key) {
    if ((*T)->right != NULL) {
      x = tree_insert(&(*T)->right, key);
    }
    else {
      x = (*T)->right = new_node(key);
      x->parent = *T;
    }
  }
  else if ((*T)->key > key) {
    if ((*T)->left != NULL) {
      x = tree_insert(&(*T)->left, key);
    }
    else {
      x = (*T)->left = new_node(key);
      x->parent = *T;
    }
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
  if (x->right != NULL) x->right->parent = x;
  y->left = x;
  y->parent = x->parent;
  x->parent = y;
  if (y->parent != NULL) {
    if (y->parent->key > y->key) {
      y->parent->left = y;
    }
    else {
      y->parent->right = y;
    }
  }
  if (*T == x) {
    *T = y;
  }
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
  if (x->left != NULL) x->left->parent = x;
  y->right = x;
  y->parent = x->parent;
  x->parent = y;
  if (y->parent != NULL) {
    if (y->parent->key > y->key) {
      y->parent->left = y;
    }
    else {
      y->parent->right = y;
    }
  }
  if (*T == x) {
    *T = y;
  }
}

Node* uncle(Node* x) {
  if (x->parent->parent->left == x) {
    return x->parent->parent->right;
  }
  else {
    return x->parent->parent->left;
  }
}
Color uncleColor(Node *x) {
  return uncle(x)->color;
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
void flip_color(Node** T, Node* x) {
  if (x->color == RED && x->parent->color == RED && uncleColor(x) == RED && x->parent->parent->color == BLACK) {
    x->parent->color = BLACK;
    x->parent->parent->color = RED;
    uncle(x)->color = BLACK;
  }
}

#define par(a) a->parent
#define gpar(a) a->parent->parent

void test(Node* x, int a) {
  if (x == NIL_PTR || x == NULL) return;
  for (int i = 0;i < a;i++) {
    printf("-");
  }
  printf("%s%8p -> (%8p <- %8p = %3d -> %8p)\x1B[m\n", x->color == RED ? "\x1B[31m" : "\x1B[34m", x->parent,
      x->left, x, x->key, x->right);
  test(x->left, a + 1);
  test(x->right, a + 1);
}

void rbInsertFixup(Node **T, Node *z) {
  /*@*/printf("1\n");/*@*/
  while (par(z)->color == RED) {
    if (par(z) == gpar(z)->left) {
      Node *y = uncle(z);
      if (y->color == RED) {
        par(z)->color = BLACK;
        y->color = BLACK;
        gpar(z)->color = RED;
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
      while (par(z)->color == RED) {
        if (par(z) == gpar(z)->right) {
          Node *y = uncle(z);
          if (y->color == RED) {
            par(z)->color = BLACK;
            y->color = BLACK;
            gpar(z)->color = RED;
          }
          else {
            if (z == par(z)->left) {
              z = par(z);
              right_rotate(T, z);
            }
            par(z)->color = BLACK;
            gpar(z)->color = RED;
            left_rotate(T, gpar(z));
          }
        }
      }
    }
  }
  (*T)->color = BLACK;
}

void rbInsert(Node **T, Node *z) {
  Node *y = NIL_PTR;
  Node *x = *T;
  while (x != NIL_PTR) {
    y = x;
    if (z->key < y->key) {
      x = y->left;
    }
    else {
      x = y->right;
    }
  }
  par(z) = y;
  if (y == NIL_PTR) {
    *T = z;
  }
  else {
    if (z->key < y->key) {
      y->left = z;
    }
    else {
      y->right = z;
    }
  }
  z->left = NIL_PTR;
  z->right = NIL_PTR;
  z->color = RED;
  rbInsertFixup(T, z);
}
