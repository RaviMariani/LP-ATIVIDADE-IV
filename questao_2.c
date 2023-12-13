#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Aluno {
    char nome[50];
    char dataNascimento[15];
    float nota1;
    float nota2;
    float media;
};


float calcularMedia(struct Aluno aluno) {
    return (aluno.nota1 + aluno.nota2) / 2.0;
}

void verificarAprovacao(struct Aluno aluno) {
    if (aluno.media >= 7.0) {
        printf("%s Você foi aprovado!\n", aluno.nome);
    } else {
        printf("%s Você foi reprovado!\n", aluno.nome);
    }
}

int main() {

    struct Aluno alunos[5];


    for (int i = 0; i < 5; i++) {
        printf("Informe o nome do aluno %d: ", i + 1);
        scanf("%s", alunos[i].nome);

        printf("Informe a data de nascimento (Dia/Mes/Ano) do aluno %d: ", i + 1);
        scanf("%s", alunos[i].dataNascimento);

        printf("Informe a primeira nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota1);

        printf("Informe a segunda nota do aluno %d: ", i + 1);
        scanf("%f", &alunos[i].nota2);

        alunos[i].media = calcularMedia(alunos[i]);
        printf("\n");
    }


    for (int i = 0; i < 5; i++) {
        printf("Aluno: %s\n", alunos[i].nome);
        printf("Média: %.2f\n", alunos[i].media);
        verificarAprovacao(alunos[i]);
        printf("\n");
    }

    return 0;
}
