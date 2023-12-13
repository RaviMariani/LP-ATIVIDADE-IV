/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidade;
};


void realizarCompra(struct Produto *produto) {
    int quantidadeCompra;
    printf("Digite a quantidade que deseja comprar: ");
    scanf("%d", &quantidadeCompra);

    if (quantidadeCompra <= produto->quantidade && quantidadeCompra > 0) {
        float valorTotal = quantidadeCompra * produto->preco;
        produto->quantidade -= quantidadeCompra;

        printf("Compra realizada com sucesso!\n");
        printf("Quantidade subtraída do estoque: %d\n", quantidadeCompra);
        printf("Valor total da compra: %.2f\n", valorTotal);
    } else {
        printf("Quantidade inválida ou insuficiente em estoque.\n");
    }
}


void consultarEstoque(struct Produto produto) {
    printf("\nProduto: %s\n", produto.nome);
    printf("Quantidade em estoque: %d\n", produto.quantidade);
    printf("Preço unitário: %.2f\n\n", produto.preco);
}

int main() {

    struct Produto produtoLoja = {"Camiseta", 29.99, 50};

    int opcao;
    do {
        printf("Escolha uma opção:\n");
        printf("1 - Realizar uma compra\n");
        printf("2 - Consultar estoque\n");
        printf("3 - Sair do programa\n");
        printf("Opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                realizarCompra(&produtoLoja);
                break;
            case 2:
                consultarEstoque(produtoLoja);
                break;
            case 3:
                printf("Encerrando o programa...\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    } while (opcao != 3);

    return 0;
}

