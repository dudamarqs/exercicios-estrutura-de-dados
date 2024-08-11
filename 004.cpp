#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    FILE *file; // Declara um ponteiro para o arquivo file

    int X; // Declara uma variável do tipo inteiro para armazenar os números lidos do arquivo
    file = fopen("entrada.txt", "r"); // Abre o arquivo "entrada.txt" no modo de leitura 

    // Verifica se o arquivo foi aberto com sucesso 
    if (file == NULL){
        printf("Erro ao abrir o arquivo!"); // Caso não tenha sido, imprime essa mensage na tela e sai do programa usando exit(1)
        exit(1);
    }

    while (fscanf(file, "%d", &X) != EOF){  // Lê um número inteiro do arquivo "entrada.txt" e armazena em X. 
        printf("%d\n", X);                  //Retorna o número de de intens lidos ou EOF (fim do arquivo) 
    }
    
    fclose(file); // Fecha o arquivo "entrada.txt"

    return 0;
}