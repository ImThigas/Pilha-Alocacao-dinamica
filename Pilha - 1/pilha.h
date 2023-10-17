// pilha.h

#ifndef PILHA_H
#define PILHA_H

#define VERDADEIRO 1
#define FALSO 0

typedef struct nodo *pilha;
typedef struct nodo *pt_nodo;

typedef struct nodo {
    int e;
    pt_nodo prox;
} tnodo;

void CriarPilha(pilha *topo);
int PilhaVazia(pilha *topo);
void Empilhar(pilha *topo, int x);
int Desempilhar(pilha *topo);

#endif
