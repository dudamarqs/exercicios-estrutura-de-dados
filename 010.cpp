#include <stdio.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024  

void remove_html_tags (const char *input_filename, const char *output_filename){
    FILE *input_file = fopen(input_filename, "r");
    FILE *output_file = fopen(output_filename, "w");
    char buffer[BUFFER_SIZE];
    int in_tag = 0; //indica se o programa está atualmente dentro de uma tag HTML (1 para dentro, 0 para fora)

    // verifica se os arquivos foram abertos/criados corretamente:
    if (input_file == NULL){
        printf("Erro ao abrir o arquivo de entrada.");
        exit(1);
    }
    if (output_file == NULL){
        printf("Erro ao abrir o arquivo de saída.");
        fclose(output_file);
        exit(1);
    }

    // lê cada caractere do arquivo:
    while (fgets(buffer, sizeof(buffer), input_file)) {
        char *ptr = buffer;

        while (*ptr) {
            if (*ptr == '<') {
                in_tag = 1;
            } 
            else if (*ptr == '>') {
                in_tag = 0;
                ptr++;
                continue;
            }

            // verifica se o caractere atual não está dentro de uma tag HTML
            if (!in_tag) {
                fputc(*ptr, output_file); // escreve o caractereatual no arquivo de saída
            } 

            ptr++; // move o ponteiro para o próximo caractere da linha
        }
    }

    fclose(input_file);
    fclose(output_file);
    printf("Arquivo limpo gerado com sucesso.");
}

int main() {
    const char *input_filename = "entrada.html";
    const char *output_filename = "saida.txt";
    
    remove_html_tags("entrada.html", "saida.txt");

    return 0;
}