#include "PilhaL.h"
#include <stdio.h>
#include <stdlib.h>

//Definindo estrutura da pilha usando lista
struct pilhaNo{
     int valor; //Valor do elemento
    struct pilhaNo* prox; //Ponteiro para o próximo elemento
};

//Criando No:
PilhaNo* cria_no (int v){
    PilhaNo* novo = (PilhaNo*) malloc(sizeof(PilhaNo));

    //Verificando se a alocacao foi bem sucedida:
    if (novo == NULL){
        printf("Erro de alocacao de memoria!(2)\n");
        exit(1);
    }

    novo -> valor = v;
    novo -> prox = NULL;
    return novo;
}

//Adicionando elemento no topo da pilha:
void pilha_push (PilhaNo** phead, int v){
    PilhaNo* novo = cria_no(v);

    //Verificando se novo no foi criado:
    if (novo == NULL){
        printf("Erro de alocacao de memoria!(4)\n");
        exit(1);
    }

    novo -> prox = *phead; //O próximo do novo nó é o atual topo da pilha
    *phead = novo; //O novo nó se torna o topo da pilha
}

//Removendo elemento do topo da pilha:
int pilha_pop (PilhaNo** phead){
    //Veridficando se a pilha existe:
    if (*phead == NULL){
        printf("Pilha nao existe! (5)\n");
        exit(1);
    }

    PilhaNo* temp = *phead; //Armazenando o nó a ser removido
    int valor = temp -> valor; //Guardando o valor do nó a ser removido
    *phead = temp -> prox; //Atualizando o topo da pilha
    free(temp); //Liberando o nó removido
    return valor;
}

//Pilha vazia?
int pilha_vazia (PilhaNo** phead){
    return (*phead == NULL);
}

//Exibir pilha:
void pilha_exibe (PilhaNo** phead){
    //Verificando se a pilha existe:
    if (phead == NULL || *phead == NULL){
        printf("Pilha nao existe! (6)\n");
        exit(1);
    }

    PilhaNo* temp = *phead;

    while (temp != NULL){
        printf("No = %d || Prox = %d\n", temp -> valor, temp -> prox != NULL ? temp -> prox -> valor : -1);
        temp = temp -> prox;
    }
    printf("\n");
}

//Liberando a pilha:
void pilha_libera (PilhaNo** phead){
    //Verificando se a pilha existe:
    if (phead == NULL || *phead == NULL){
        printf("Pilha nao existe! (7)\n");
        exit(1);
    }

    PilhaNo* temp = *phead;

    while (temp != NULL){
        PilhaNo* prox = temp -> prox; //Armazenando o próximo nó
        free(temp); //Liberando o nó atual
        temp = prox; //Avançando para o próximo nó
    }
    free(*phead); //Liberando o ponteiro da pilha
    *phead = NULL; //Definindo o topo da pilha como NULL após liberar todos os nós
}