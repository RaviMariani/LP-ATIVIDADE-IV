#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_CONTATOS 3
#define TAM_NOME 50


struct Contato {
    char nome[200];
    char telefone[200];
    char email[200];
};

char* encontrarTelefonePorNome(struct Contato contatos[], int tamanho, char* nomeBusca) {
    for (int i = 0; i < tamanho; ++i) {
        if (strcmp(contatos[i].nome, nomeBusca) == 0) {
            return contatos[i].telefone;
        }
    }
    return "Contato não encontrado";
}

int main() {
    struct Contato contatos[MAX_CONTATOS]; 

    for (int i = 0; i < MAX_CONTATOS; ++i) {
        printf("Cadastro do Contato %d\n", i + 1);
        printf("Informe o nome do contato: ");
        scanf("%s", contatos[i].nome);
        printf("Informe o número de telefone do contato: ");
        scanf("%s", contatos[i].telefone);
        printf("Informe o email do contato: ");
        scanf("%s", contatos[i].email);
        printf("\n");
    }

    char nomeBusca[TAM_NOME];
    printf("Informe o nome do contato que você deseja encontrar: ");
    scanf("%s", nomeBusca);

    char* telefoneEncontrado = encontrarTelefonePorNome(contatos, MAX_CONTATOS, nomeBusca);

    printf("Telefone de %s: %s\n", nomeBusca, telefoneEncontrado);

    return 0;
}
