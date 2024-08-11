#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomeArquivo1[100], nomeArquivo2[100], nomeArquivo3[100];
    FILE *file1, *file2, *file3;

    printf("Digite o nome do arquivo 1: ");
    scanf("%s", nomeArquivo1);

    printf("Digite o nome do arquivo 2: ");
    scanf("%s", nomeArquivo2);

    printf("Digite o nome do arquivo que sera criado (arquivo 3): ");
    scanf("%s", nomeArquivo3);

    file1 = fopen(nomeArquivo1, "r");
    if (file1 == NULL){
        printf("Erro ao abrir o arquivo %s.", nomeArquivo1);
        exit(1);
    }

    file2 = fopen(nomeArquivo2, "r");
    if (file2 == NULL){
        printf("Erro ao abrir o arquivo %s.", nomeArquivo2);
        exit(1);
    }

    file3 = fopen(nomeArquivo3, "w");
    if (file3 == NULL){
        printf("Erro ao criar o arquivo %s.", nomeArquivo3);
        fclose(file1);
        fclose(file2);
        exit(1);
    }

    // copia o conteúdo do arquivo1 pro arquivo3:
    char ch;
    while ((ch = fgetc(file1)) != EOF){
        fputc(ch, file3);
    }

    // copia o conteúdo do arquivo2 pro arquivo3:
    while ((ch =fgetc(file2)) != EOF){
        fputc(ch, file3);
    }

    fclose(file1);
    fclose(file2);
    fclose(file3);

    printf("Os conteúdos dos arquivos '%s' e '%s' foram copiados para %s.", nomeArquivo1, nomeArquivo2, nomeArquivo3);

    return 0;
}