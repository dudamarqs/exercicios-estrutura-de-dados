#include <stdio.h>
#include <stdlib.h>

int main() {
    char nomeProduto[50];
    int quant, count = 1;
    float valorUnitario, valorTotal, total = 0.0;

    FILE *file;
    file = fopen("lista-compras.txt", "r");
    if (file == NULL){
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    while (fscanf(file, "%s %d %f", nomeProduto, &quant, &valorUnitario) != EOF){
        valorTotal = quant * valorUnitario;
        total += valorTotal;
        printf("%d) %s: %d * %.2f = %.2f\n", count++, nomeProduto, quant, valorUnitario, valorTotal);
    }

    if (feof(file)) {
        printf("\nValor total da compra: R$ %.2f\n", total);
    } else {
        printf("\nErro na leitura do arquivo.\n");
    }

    fclose(file);

    return 0;
}