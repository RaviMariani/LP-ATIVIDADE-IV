#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FUNCIONARIOS 100
#define MAX_CARGOS 10
#define MAX_NOME 50

struct Funcionario {
    char nome[MAX_NOME];
    char cargo[MAX_NOME];
    float salario;
};

float calcularMediaSalarial(struct Funcionario funcionarios[], int numFuncionarios, const char cargoBuscado[]) {
    float somaSalarios = 0.0;
    int contador = 0;

    for (int i = 0; i < numFuncionarios; i++) {
        if (strcmp(funcionarios[i].cargo, cargoBuscado) == 0) {
            somaSalarios += funcionarios[i].salario;
            contador++;
        }
    }

    if (contador == 0) {
        return 0.0; 
    }

    return somaSalarios / contador;
}

int main() {
    struct Funcionario funcionarios[MAX_FUNCIONARIOS];
    int numFuncionarios = 0;
    char cargos[MAX_CARGOS][MAX_NOME];

    printf("Para encerrar o cadastro, digite 'fim' como cargo.\n");

    int numCargos = 0;
    while (1) {
        printf("\nDigite o nome do cargo ou 'fim' para encerrar: ");
        scanf("%s", cargos[numCargos]);

        if (strcmp(cargos[numCargos], "fim") == 0 || numCargos >= MAX_CARGOS) {
            break;
        }

        printf("Cadastro de funcionarios para o cargo de %s\n", cargos[numCargos]);

        while (1) {
            printf("\nNome do funcionario (ou 'fim' para encerrar o cadastro de %s): ", cargos[numCargos]);
            scanf("%s", funcionarios[numFuncionarios].nome);

            if (strcmp(funcionarios[numFuncionarios].nome, "fim") == 0) {
                break;
            }

            strcpy(funcionarios[numFuncionarios].cargo, cargos[numCargos]);
            printf("Salario: ");
            scanf("%f", &funcionarios[numFuncionarios].salario);

            numFuncionarios++;

            if (numFuncionarios >= MAX_FUNCIONARIOS) {
                printf("Limite de funcionarios atingido.\n");
                break;
            }
        }

        numCargos++;
    }

    for (int i = 0; i < numCargos; i++) {
        float mediaSalarial = calcularMediaSalarial(funcionarios, numFuncionarios, cargos[i]);

        if (mediaSalarial == 0.0) {
            printf("\nNenhum funcionario com o cargo de %s encontrado ou nenhum salario cadastrado para esse cargo.\n", cargos[i]);
        } else {
            printf("\nA media salarial dos %s e: %.2f\n", cargos[i], mediaSalarial);
        }
    }

    return 0;
}

