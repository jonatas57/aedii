#include "abb.h"

void erd (no *r) {
    if (r != NULL) {
        erd(r->esq);
        printf("%d ", r->conteudo);
        erd(r->dir);
    }
}

void imprimir_folhas (no *r) {
    if (r != NULL) {
        imprimir_folhas(r->esq);
        if ((r->esq==NULL) && (r->dir==NULL))
            printf("%d ", r->conteudo);
        imprimir_folhas(r->dir);
    }
}

int altura (no *r) {
    if (r == NULL)
        return -1;
    else {
        int he = altura(r->esq);
        int hd = altura(r->dir);
        if (he<hd)
            return hd+1;
        else
            return he+1;
    }
}

no* primeiro_erd(no *r) {
    while (r->esq != NULL)
        r = r->esq;
    return r;
}

no* ultimo_erd(no *r) {
    while (r->dir != NULL)
        r = r->dir;
    return r;
}

void preenche_pai_aux(no *r) {
  if (r->esq != NULL) {
    r->esq->pai = r;
    preenche_pai(r->esq);
  }
  if (r->dir != NULL) {
    r->dir->pai = r;
    preenche_pai(r->dir);
  }
}

void preenche_pai(no *r) {
  if (r != NULL) {
    r->pai = r;
    preenche_pai_aux(r);
  }
}

no* busca(no* r, int chave) {
    if (r == NULL || r->conteudo==chave)
        return r;
    if (r->conteudo > chave)
        return busca(r->esq, chave);
    else
        return busca(r->dir, chave);
}

no* inserir_no_na_arvore(no* r, int valor) {
  no *aux = NULL;
  if (r == NULL) {
    r = (no *)malloc(sizeof(no));
    r->dir = NULL;
    r->esq = NULL;
    r->conteudo = valor;
  }
  else if (r->conteudo < valor) {
    aux = inserir_no_na_arvore(r->dir, valor);
    if (aux != NULL) {
      r->dir = aux;
    }
  }
  else if (r->conteudo > valor) {
    aux = inserir_no_na_arvore(r->esq, valor);
    if (aux != NULL) {
      r->esq = aux;
    }
  }
  else {
    return r;
  }
  return r;
}
