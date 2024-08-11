#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f1, *f2; // Declara dois ponteiros para os arquivos f1 e f2

    int x; // Declara uma variável do tipo inteiro chamada "x"
    f1 = fopen("entrada.txt", "r"); // Abre o arquivo de texto "entrada.txt" no modo de leitura
    f2 = fopen("saida.bin", "w"); // Abre o arquivo binário "saida.bin" no modo de escrita. Caso esse arquivo não exista, ele será criado.

    fscanf(f1, "%d", &x); // Lê um número inteiro no arquivo f1 (entrada.txt) e o armazena na variável "x"
    fprintf(f2, "%d", x); // Escreve o valor de "x" no arquivo f2 (saida.bin)

    fclose(f1); // Fecha o arquivo "entrada.txt"
    fclose(f2); // Fecha o arquivo "saida.bin"

    return 0;
}