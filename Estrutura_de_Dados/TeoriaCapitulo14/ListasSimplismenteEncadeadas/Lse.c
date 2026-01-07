#include "Lse.h"
#include <stdio.h>
#include <stdlib.h>

//Definindo as estruturas:

struct lista{
    ListaNo* primeiro;
};

struct listano{
    int info;
    ListaNo* prox;
};

//Cria lista vazia:
Lista* lst_cria (void ){
    Lista* l = (Lista*) malloc (sizeof(Lista));
    l -> primeiro = NULL;
    return l;
}

//Insere valor no inicio:
void lst_insere (Lista* l, int v){
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));

    //Definindo para onde cada no aponta:
    novo -> info = v;
    novo -> prox = l -> primeiro;
    l -> primeiro = novo;
}

//Insere valor de forma ordenada:
void lst_insere_ordenado (Lista* l, int v){
    ListaNo* ant = NULL;

    ListaNo* p = l -> primeiro;

    //Descobrindo o valor anterior:
    while(p != NULL && ant -> info < v){
        ant = p;
        p = p -> prox;
    }

    //Criando um novo no:
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));
    novo -> info = v;

    //Caso nao tenha anterior:
    if(ant == NULL){
        //Insere no inicio:
        lst_insere(l, v);
    }else{
        //Inserindo de forma ordenada:
        novo -> prox = ant -> prox;
        ant -> prox = novo;
    }
}

//Retira um valor especifico da lista:
void lst_retira (Lista* l, int v){
    ListaNo* ant = NULL;
    ListaNo* p = l -> primeiro;

    //Se o valor nao for encontrado:
    if (!lst_pertence(l, v)){
        printf("Valor %d nao encontrado na lista.\n", v);
        return;
    }

    //Procurando valor anterior ao que sera retirado:
    while(p != NULL && p -> info != v){
        ant = p;
        p = p -> prox;
    }

    //Remover o valor:
    
    //Caso nao tenha anterior:
    if (ant == NULL){
        l -> primeiro = p -> prox;
    }else{
        ant -> prox = p -> prox;
    }

    free(p);
}

//Libera a memoria alocada para a lista:
void lst_libera (Lista* l){
    //Criando variaveis auxiliares:
    ListaNo* p = l -> primeiro;
    ListaNo* aux;

    //Liberando no por no:
    while(p != NULL){
        aux = p -> prox;
        free(p);
        p = aux;
    }

    //No final libera a estrutura em si:
    free(l);
}

//Verifica se a lista eh vazia:
int lst_vazia (Lista* l){
    return (l -> primeiro == NULL);
}

//Verfica se o valor pertence a lista:
int lst_pertence (Lista* l, int v){
    ListaNo* p = l -> primeiro;
    
    //Caminhando a lista:
    while (p -> prox != NULL){
        if (p -> info == v){
            return 1; //Pertence
        }

        p = p -> prox;
    }

    return 0; //Nao pertence
}

//Imprime os valores da lista:
void lst_imprime (Lista* l){

    int i = 0;
    for (ListaNo* p = l -> primeiro; p != NULL; p = p -> prox){
        printf("Item %d : Valor = %d\n", i, p -> info);
        i ++;
    }
}