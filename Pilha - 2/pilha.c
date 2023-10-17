// pilha.c

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"

void CriarPilha(Pilha *topo) {
    *topo = NULL;
}

int PilhaVazia(Pilha *topo) {
    return (*topo == NULL);
}

void Empilhar(Pilha *topo, Livro livro) {
    PtNodo aux;
    aux = (PtNodo)malloc(sizeof(TNodo));
    aux->livro = livro;
    aux->prox = *topo;
    *topo = aux;
}

Livro Desempilhar(Pilha *topo) {
    Livro livro;
    PtNodo aux;
    aux = *topo;
    *topo = (*topo)->prox;
    livro = aux->livro;
    free(aux);
    return livro;
}

void ImprimirPilha(Pilha topo) {
    PtNodo atual = topo;
    while (atual != NULL) {
        printf("Título: %s\nAutor: %s\nEdição: %d\n\n", atual->livro.titulo, atual->livro.autor, atual->livro.edicao);
        atual = atual->prox;
    }
}

void ImprimirPilhaParaArquivo(Pilha topo, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "wb");
    if (arquivo != NULL) {
        PtNodo atual = topo;
        while (atual != NULL) {
            fwrite(&atual->livro, sizeof(Livro), 1, arquivo);
            atual = atual->prox;
        }
        fclose(arquivo);
    } else {
        printf("Não foi possível criar o arquivo.\n");
    }
}

int LerPilhaDeArquivo(Pilha *topo, const char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "rb");
    if (arquivo != NULL) {
        Livro livro;
        while (fread(&livro, sizeof(Livro), 1, arquivo) == 1) {
            Empilhar(topo, livro);
        }
        fclose(arquivo);
        return 1;  // Indica que a leitura foi bem-sucedida
    } else {
        printf("Não foi possível abrir o arquivo.\n");
        return 0;  // Indica que a leitura falhou
    }
}

int ContarLivrosParaTitulo(Pilha topo, const char *tituloDesejado) {
    PtNodo atual = topo;
    int contagem = 0;

    while (atual != NULL) {
        contagem++;
        if (strcmp(atual->livro.titulo, tituloDesejado) == 0) {
            return contagem;
        }
        atual = atual->prox;
    }

    return -1;  // Indica que o livro não foi encontrado na pilha
}

