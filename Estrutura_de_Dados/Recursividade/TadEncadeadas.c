#include <stdio.h>
#include <stdlib.h>
#include "ListaEncadeadas.h"

int main(void) {
    ListaNo* minhaLista = lista_cria();

    lista_insere(&minhaLista, 10);
    lista_insere(&minhaLista, 20);
    lista_insere(&minhaLista, 30);

    printf("Lista original:\n");
    lista_imprime(&minhaLista);
    printf("\n");

    ListaNo* elementoRemovido = lista_retira(&minhaLista, 20);
    if (elementoRemovido != NULL) {
        printf("Elemento %d removido da lista\n", elementoRemovido->info);
        free(elementoRemovido);
    }

    printf("Lista apos remocao:\n");
    lista_imprime(&minhaLista);
    printf("\n");

    int valorBuscado = 30;

    ListaNo* elementoEncontrado = lista_busca(&minhaLista, valorBuscado);

    if (elementoEncontrado != NULL)
        printf("Elemento %d encontrado na lista\n", valorBuscado);
    else
        printf("Elemento %d nao encontrado na lista\n", valorBuscado);

    int quantidade = lista_conta_rec(&minhaLista);
    printf("Quantidade de elementos na lista: %d\n", quantidade);

    lista_libera(&minhaLista);
    return 0;
}