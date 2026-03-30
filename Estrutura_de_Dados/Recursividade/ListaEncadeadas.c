#include "ListaEncadeadas.h"
#include <stdio.h>
#include <stdlib.h>

//Criando lista_vazia:
ListaNo* lista_cria(void){
    return NULL;
}

//Insere elemento no inicio:
void lista_insere (ListaNo** phead, int i){
    //Criando novo elemento:
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    novo -> info = i;
    novo -> prox = *phead;
    *phead = novo;
}

//Imprime lista:
void lista_imprime (ListaNo** phead){
    //Verificando se a lista existe:
    if (*phead == NULL){
        return;
    }
    
    printf("Valor do No %d\n", (*phead) -> info);

    //Chamando recursivamente para o proximo No:
    lista_imprime(&((*phead) -> prox));
}

//Lista vazia?
int lista_vazia(ListaNo** phead){
    return (*phead == NULL);
}

//Buscar No na lista:
ListaNo* lista_busca(ListaNo** phead, int v){
    //Verificar se a lista existe:
    if (*phead == NULL){
        return NULL;
    }

    if ((*phead) -> info == v){
        return *phead;
    }

    //Nao encontrou o No:
    return lista_busca(&((*phead) -> prox), v);
}

//Retira No da lista:
ListaNo* lista_retira(ListaNo** phead, int v){
    //Verificar se a lista existe:
    if (*phead == NULL){
        return NULL;
    }

    //Avaliando o No atual:
    if ((*phead) -> info == v){
        ListaNo* temp = *phead;
        *phead = temp -> prox;
        return temp;
    }
    
    //Chamada recursiva:
    return lista_retira(&((*phead) -> prox), v);
}

//Conta numero de elementos:
int lista_conta_rec(ListaNo** phead){
    int qtd = (*phead == NULL) ? 0 : 1 + lista_conta_rec(&((*phead) -> prox));
    return qtd;
}

//Libera a lista:
void lista_libera (ListaNo** phead){
    ListaNo* atual = *phead;
    ListaNo* temp = NULL;

    while (atual != NULL){
        temp = atual -> prox;
        free(atual);
        atual = temp;
    }

    *phead = NULL;
}