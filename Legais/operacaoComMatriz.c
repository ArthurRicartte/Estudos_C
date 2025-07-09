#include <stdio.h>

float somaLinhaMatriz(float matriz[12][12], int linhaDesejada){
    float soma = 0;
    for (int coluna = 0; coluna < 12; coluna++){
        soma += matriz[linhaDesejada][coluna];
    }

    return soma;
}

int main(void){

    int linhaDesejada;
    float matriz[12][12];
    char operacao;

    scanf("%d", &linhaDesejada);
    scanf(" %c", &operacao);

    /*Lendo Valores para a matriz*/
    for (int linha = 0; linha < 12; linha++){
        for (int coluna = 0; coluna < 12; coluna++){
            scanf("%f", &matriz[linha][coluna]);
        }
    }


    /*Analisando qual operacao o usuario quer que seja realizada*/
    float soma = somaLinhaMatriz(matriz, linhaDesejada);
    float media = 0;

    
    if (operacao == 'S'){
        printf("%.1f\n", soma);
    }
    
    else if (operacao == 'M'){
        media = soma / 12.0;
        printf("%.1f\n", media);
    }
    
}