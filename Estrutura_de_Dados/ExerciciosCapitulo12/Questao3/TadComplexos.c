#include "Complexos.h"
#include <stdio.h>

int main(void){

    //Testando o TAD:
    Complexo* a = Criar_Complexo(4.0, 5.0);
    Complexo* b = Criar_Complexo(3.0, 2.0);

    printf("a\n");
    Exibir_Complexo(a);
    
    printf("b\n");
    Exibir_Complexo(b);

    //testando funcoes:
    printf("\nSOMA\n");
    Complexo* soma = Sum_Complexo(a, b);
    Exibir_Complexo(soma);
    
    printf("\nSUBTRACAO\n");
    Complexo* subtracao = Sub_Complexo(a, b);
    Exibir_Complexo(subtracao);
    
    printf("\nMULTIPLICACAO\n");
    Complexo* multiplicacao = Mult_Complexo(a, b);
    Exibir_Complexo(multiplicacao);
    
    printf("\nDIVISAO\n");
    Complexo* divisao = Div_Complexo(a, b);
    Exibir_Complexo(divisao);

    Libera_Complexo(a);
    Libera_Complexo(b);
    Libera_Complexo(soma);
    Libera_Complexo(subtracao);
    Libera_Complexo(multiplicacao);
    Libera_Complexo(divisao);
    
    return 0;
}