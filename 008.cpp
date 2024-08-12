#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    
    file = fopen("arquivo008.txt", "w");

    if (file == NULL) {
        printf("Erro na criação do arquivo.");
        return  EXIT_FAILURE;
    }

    // escreve os números de 1 a 100 no arquivo
    for (int i = 1; i <= 100; i++) {
        fprintf(file, "%d\n", i);
    }

    fclose(file);
    printf("Os arquivo foi gerado e os números de 1 a 100 foram escritos com sucesso.");

    return EXIT_SUCCESS;
}