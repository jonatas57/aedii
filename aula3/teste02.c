#include "abb.h"

int main(int argc, char *argv[]) {
    int i, valor;
    int n = atoi(argv[1]);
    no *raiz = NULL;
    no *aux = NULL;

    for (i=0; i<n; i++) {
        scanf("%d", &valor);
        aux = inserir_no_na_arvore(raiz, valor);
        if (aux != NULL) {
          raiz = aux;
        }
    }

    // Altura da arvore
    printf("\nAltura da arvore:%d", altura(raiz));
}
