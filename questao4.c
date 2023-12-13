#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ContaBancaria {
    int numeroConta;
    char nomeTitular[50];
    float saldo;
    char tipoConta[20];
};


void depositar(struct ContaBancaria *conta, float valor) {
    conta->saldo += valor;
    printf("Depósito realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
}


void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > conta->saldo) {
        printf("Saldo insuficiente.\n");
    } else {
        conta->saldo -= valor;
        printf("Saque realizado com sucesso. Novo saldo: %.2f\n", conta->saldo);
    }
}


void imprimirSaldo(struct ContaBancaria conta) {
    printf("Saldo atual: %.2f\n", conta.saldo);
}

int main() {
    struct ContaBancaria minhaConta;
    minhaConta.numeroConta = 123456;
    strcpy(minhaConta.nomeTitular, "Fulano");
    minhaConta.saldo = 1000.00;
    strcpy(minhaConta.tipoConta, "corrente");

    int escolha;
    float valor;

    do {
        printf("\nEscolha uma operacao:\n");
        printf("1 - Depositar\n");
        printf("2 - Sacar\n");
        printf("3 - Ver saldo\n");
        printf("0 - Sair\n");
        scanf("%d", &escolha);

        switch (escolha) {
            case 1:
                printf("Digite o valor para depositar: ");
                scanf("%f", &valor);
                depositar(&minhaConta, valor);
                break;
            case 2:
                printf("Digite o valor para sacar: ");
                scanf("%f", &valor);
                sacar(&minhaConta, valor);
                break;
            case 3:
                imprimirSaldo(minhaConta);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida. Escolha novamente.\n");
        }
    } while (escolha != 0);

    return 0;
}

