#include <stdio.h>
#include "MinhasFuncoes.h"

const char * MeuNome(){
    return "Ricartte";
}

/*eh primo?*/
int EhPrimo(int num){
    for (int contador = 2; contador < num; contador++){
        if (num % contador == 0)
            return 0;
    }
           
    return 1;
}

/*Calcular o termo n da sequencia de Fibonacci*/
int ValorDeFibonacci(int i){
    int valor, a3;
    /*O a1 representa o (n-1) e o a2 ((n-1) -1)*/
    int a1 = 1;
    int a2 = 1;

    /*Nao interessa os dois primeiros termos (1 e 1) da sequencia, e o for vai ate o antecessor de i 
    pois um numero ja eh divisel por ele mesmo*/
    for (int contador = 3; contador <= i; contador++){
        a3 = a1 + a2;
        a2 = a1;
        a1 = a3;
    }

    return a3;
}