#include "PilhaL.h"
#include <stdio.h>

int main (void){
    PilhaNo* pilha = NULL; //Criando uma pilha vazia

    //Adicionando elementos na pilha
    pilha_push(&pilha, 10);
    pilha_push(&pilha, 20);
    pilha_push(&pilha, 30);

    //Exibindo a pilha
    printf("Pilha apos insercoes:\n");
    pilha_exibe(&pilha);

    //Removendo elementos da pilha
    printf("Elemento removido: %d\n", pilha_pop(&pilha));
    printf("Elemento removido: %d\n", pilha_pop(&pilha));

    //Exibindo a pilha após remoções
    printf("Pilha apos remocoes:\n");
    pilha_exibe(&pilha);

    //Liberando a pilha
    pilha_libera(&pilha);
    
    return 0;
}