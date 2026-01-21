#include "Questao11.h"
#include <stdlib.h>
#include <stdio.h>

int main(void){

    //Criando uma lista:
    Lista* minha_lista = lst_cria();

    //Adicionando alguns elementos:
    lst_insere_ordenado(minha_lista, 10);
    lst_insere_ordenado(minha_lista, 11);
    lst_insere_ordenado(minha_lista, 12);
    lst_insere_ordenado(minha_lista, 13);


    //Imprimindo a lista:
    printf("Lista inicial:\n");
    lst_imprime(minha_lista);

    //Removendo o elemento do inicio:
    retira_inicio(minha_lista);
    printf("\nLista apos remover o elemento do inicio:\n");
    lst_imprime(minha_lista);

    //Removendo o elemento do final:
    retira_final(minha_lista);
    printf("\nLista apos remover o elemento do final:\n");
    lst_imprime(minha_lista);

    //Liberando a memoria alocada:
    lst_libera(minha_lista);

    return 0;
}