#include <stdio.h>
#include "MinhasFuncoes.h"
#include "minhasFuncoes.c"

int main(void){
    int numero;

    printf("Digite um numero para testar:");
    scanf("%d", &numero);

    MeuNome();
    printf("\tO numero %d %s primo\n", numero, EhPrimo(numero) ? "eh" : "Nao eh");
    printf("\tTestando Fibonacci: o %d termo da sequencia eh: %d\n", numero, ValorDeFibonacci(numero));
    return 0;
}
