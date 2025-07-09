#include <stdio.h>
#include <string.h>

/*Cada numero tem uma quantidade de leds, vamos fazer uma funcao para indetificar o numero e retornar
quantos leds precisa para "fazer" ele*/

int LedsNumero(char digito){
    /*Cada numero tem uma quantida de leds para ser digitado (acredito que essa forma eh a mais leve de fazer)*/
    switch(digito) {
        case '0': 
            return 6;
        case '1': 
            return 2;
        case '2': 
            return 5;
        case '3': 
            return 5;
        case '4': 
            return 4;
        case '5': 
            return 5;
        case '6': 
            return 6;
        case '7': 
            return 3;
        case '8':
            return 7;
        case '9': 
            return 6;
        default:
            return 0;
    }
}

int main(void){
    int casos;
    char numero[101];

    scanf("%d", &casos);
    getchar(); //limpa o /n digitado pelo usuario

    while(casos--) {
        int totalLeds = 0;
        /*Lendo um numero*/
        scanf("%s", &numero);

        /*Somando a quantidade de leds necessaria para exibir o numero*/
        for(int i = 0; numero[i] != '\0'; i++){
            totalLeds += LedsNumero(numero[i]);
        }

        printf("%d leds\n", totalLeds);
    }

    return 0;
}