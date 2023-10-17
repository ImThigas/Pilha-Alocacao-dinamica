// pilha.h

#ifndef PILHA_H
#define PILHA_H

#define MAX_TITULO 100
#define MAX_AUTOR 50

typedef struct Livro {
    char titulo[MAX_TITULO];
    char autor[MAX_AUTOR];
    int edicao;
} Livro;

typedef struct Nodo *Pilha;
typedef struct Nodo *PtNodo;

typedef struct Nodo {
    Livro livro;
    PtNodo prox;
} TNodo;

void CriarPilha(Pilha *topo);
int PilhaVazia(Pilha *topo);
void Empilhar(Pilha *topo, Livro livro);
Livro Desempilhar(Pilha *topo);
void ImprimirPilha(Pilha topo);
void ImprimirPilhaParaArquivo(Pilha topo, const char *nomeArquivo);
int LerPilhaDeArquivo(Pilha *topo, const char *nomeArquivo);
int ContarLivrosParaTitulo(Pilha topo, const char *tituloDesejado);

#endif

