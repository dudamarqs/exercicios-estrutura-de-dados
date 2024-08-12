#include <stdio.h>
#include <stdlib.h>

#define CHAR_SIZE 100

int main() {
    char file1[CHAR_SIZE], file2[CHAR_SIZE];
    char ch1, ch2;
    int pos = 1;
    FILE *fp1, *fp2;

    // realiza a leitura dos nomes dos arquivos:
    printf("Digite o nome do primeiro arquivo: ");
    scanf("%s", file1);
    printf("Digite o nome do segundo arquivo: ");
    scanf("%s", file2);

    // abre os arquivos no modo de leitura:
    fp1 = fopen(file1, "r");
    fp2 = fopen(file2, "r");

    //verifica se os programas foram aberto corretamente:
    if (fp1 == NULL || fp2 == NULL) {
        printf("Erro ao abrir os arquivos.");
        return 1;
    }

    // lê caractere por caractere até o final dos arquivos:
    while ((ch1 = fgetc(fp1)) != EOF || (ch2 = fgetc(fp2) != EOF)){
        if (ch1 != ch2){
            printf("\nOs arquivos sao diferentes.");
            printf("\nA primeira diferenca esta na posicao %d.", pos);
            printf("\nArquivo %s: %c.", file1, ch1);
            printf("\nArquivo %s: %c.", file2, ch2);

            fclose(fp1);
            fclose(fp2);
            return 0;
        }
        pos++;
    }

    // verifica se os arquivos são do mesmo tamanho:
    if (fgetc(fp1) != EOF || fgetc(fp2) != EOF){
        printf("Os arquivos têm tamanhos diferentes.");
    } else {
        printf("Os arquivos têm tamanhos iguais.");
    }

    return 0;
}