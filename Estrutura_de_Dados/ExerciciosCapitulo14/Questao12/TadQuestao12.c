#include "Questao12.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){
    
    //Criando lista:
    Lista* l = lst_cria();

    //Adcionando elementos:
    lst_insere_ordenado(l, 5);
    lst_insere_ordenado(l, 4);
    lst_insere_ordenado(l, 3);
    lst_insere_ordenado(l, 2);

    printf("Lista apos insercoes ordenadas:\n");
    lst_imprime(l);

    //Retirando elementos:
    lst_retira_inicio(l);
    printf("\nDepois de retirar do inicio:\n");
    lst_imprime(l);

    lst_retira_final(l);
    printf("\nDepois de retirar do final:\n");
    lst_imprime(l);
    
    //Liberando memoria:
    lst_libera(l);
 
    return 0;
}