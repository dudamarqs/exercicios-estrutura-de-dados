#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *f1, *f2; // Declara dois ponteiros para os arquivos f1 e f2

    f1 = fopen("entrada.txt", "r"); // Abre o arquivo de texto "entrada.txt" em modo de leitura 
    f2 = fopen("saida.bin", "w"); // Abre o arquivo binário "saida.bin" em modo de escrita

    fclose(f1); // Fecha o arquivo "entrada.txt" (f1)
    fclose(f2); // Fecha o arquivo "saida.bin" (f2)

    return 0;
}
