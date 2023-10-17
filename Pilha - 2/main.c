// main.c

#include <stdio.h>
#include <string.h>
#include "pilha.h"

int main() {
    int opcao;
    Pilha acervo;
    Livro livro;
    char tituloDesejado[MAX_TITULO];
    int resultadoLeitura;

    CriarPilha(&acervo);

    do {
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar livro\n");
        printf("2 - Imprimir acervo\n");
        printf("3 - Imprimir acervo em arquivo\n");
        printf("4 - Ler acervo de arquivo\n");
        printf("5 - Contar livros até o título\n");
        printf("6 - Sair\n");

        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Título: ");
                scanf(" %99[^\n]", livro.titulo);
                printf("Autor: ");
                scanf(" %49[^\n]", livro.autor);
                printf("Edição: ");
                scanf("%d", &livro.edicao);
                Empilhar(&acervo, livro);
                break;

            case 2:
                ImprimirPilha(acervo);
                break;

            case 3:
                ImprimirPilhaParaArquivo(acervo, "acervo.dat");
                printf("Acervo impresso em arquivo.\n");
                break;

            case 4:
                resultadoLeitura = LerPilhaDeArquivo(&acervo, "acervo.dat");
                if (resultadoLeitura) {
                    printf("Acervo lido do arquivo.\n");
                }
                break;

            case 5:
                printf("Título desejado: ");
                scanf(" %99[^\n]", tituloDesejado);
                int contagem = ContarLivrosParaTitulo(acervo, tituloDesejado);
                if (contagem >= 0) {
                    printf("Foram necessários %d livros para encontrar o título desejado.\n", contagem);
                } else {
                    printf("Título não encontrado no acervo.\n");
                }
                break;

            case 6:
                break;

            default:
                printf("Opção inválida.\n");
                break;
        }
    } while (opcao != 6);

    return 0;
}

