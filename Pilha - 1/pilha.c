// pilha.c

#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

void CriarPilha(pilha *topo) {
    *topo = NULL;
}

int PilhaVazia(pilha *topo) {
    return (*topo == NULL);
}

void Empilhar(pilha *topo, int x) {
    pt_nodo aux;
    aux = (pt_nodo)malloc(sizeof(tnodo));
    aux->e = x;
    aux->prox = *topo;
    *topo = aux;
}

int Desempilhar(pilha *topo) {
    int x;
    pt_nodo aux;
    aux = *topo;
    *topo = (*topo)->prox;
    x = aux->e;
    free(aux);
    return x;
}
