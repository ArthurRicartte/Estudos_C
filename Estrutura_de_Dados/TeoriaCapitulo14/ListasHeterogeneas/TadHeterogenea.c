#include "Heterogeneas.h"
#include <stdio.h>

int main (void){
    ListaHet* lista = cria_lista();

    //Criando figuras:
    ListaNoHet* ret = cria_ret(1.2, 1.2);
    ListaNoHet* tri = cria_tri(1.2, 1.2);
    ListaNoHet* circ = cria_circ(1.2);

    //Adicionando na lista:
    insere_inicio(lista, ret);
    insere_inicio(lista, tri);
    insere_inicio(lista, circ);

    //Exibir:
    printf("Teste 1:\n");
    imprime_lista(lista);

    //Retirando um elemento da lista:
    remove_no(lista, ret);

    //Exibir:
    printf("\nTeste 2:\n");
    imprime_lista(lista);
}