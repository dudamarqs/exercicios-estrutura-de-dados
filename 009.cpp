#include <stdio.h>
#include <stdlib.h>

#define NUM_ALUNOS 10

// define a estrutura de dados dos alunos:
typedef struct
{
    char nome[100];
    float n1;
    float n2;
    float media;
} Aluno;

int main() {
    Aluno alunos[NUM_ALUNOS];
    FILE *file;

    // realiza a leitura dos dados dos alunos:
    for (int i = 0; i <= NUM_ALUNOS; i++) {
        printf("Digite o nome do aluno: ");
        scanf("%99s", alunos[i].nome);

        printf("Digite a N1 de %s: ", alunos[i].nome);
        scanf("%f", &alunos[i].n1);

        printf("Digite a N2 de %s: ", alunos[i].nome);
        scanf("%f", &alunos[i].n2);

        alunos[i].media = (alunos[i].n1 + alunos[i].n2)/2;
    }

    // abre o arquivo no modo de escrita
    file = fopen("dados-alunos.txt", "w");
    if (file == NULL) {
        printf("Erro ao criar o arquivo para escrita.");
        return EXIT_FAILURE;
    }

    // faz a escrita nos dados no arquivo
    for (int i = 0; i <= NUM_ALUNOS; i++) {
        fprintf(file, "Nome do aluno: %s\n", alunos[i].nome);
        fprintf(file, "Nota 1: %.2f\n", alunos[i].n1);
        fprintf(file, "Nota 2: %.2f\n", alunos[i].n2);
        fprintf(file, "Media: %.2f\n", alunos[i].media);
        fprintf(file, "--------------------------------\n");
    }

    fclose(file);
    printf("Arquivo gerado e alunos cadastrados com sucesso.");

}