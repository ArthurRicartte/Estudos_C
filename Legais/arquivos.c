#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main (void){
    
    FILE *arquivo = fopen("Teste.txt", "w");

    for (int i = 0; i < 13; i++){
        fprintf(arquivo, "OLa mundo!\n");
    }
    
    fclose(arquivo);

    arquivo = fopen("Teste.txt", "r");
    if (arquivo == NULL)
    {
        printf("Deu ruim...");
        return 1;
    }
    char linha[100];

    while (fgets(linha, 100, arquivo) != NULL){
        printf("%s", linha);
    }
    
    fclose(arquivo);

    return 0;
}