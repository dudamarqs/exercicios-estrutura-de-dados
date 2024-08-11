#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file;

    file = fopen("arquivo.txt", "w");

    if (file == NULL){
        printf("Erro na abertura do arquivo.");
        exit(1);
    }

    fclose(file);

    return 0;
}