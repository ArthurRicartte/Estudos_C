#include "FilaL.h"
#include <stdio.h>
#include <stdlib.h>

//Desenvolvendo estruras:
struct listano{
    int info;
    ListaNo* prox;
};


struct fila{
    ListaNo* inicio;
    ListaNo* fim;
};

//Criando fila: 
Fila* fila_cria (void){
    Fila* nova = (Fila*) malloc(sizeof(Fila));

    //Verificando se a alocacao deu certo:
    if (nova == NULL){
        printf("ERRO NA ALOCAO (1)\n");
        exit(1);
    }

    //Setando os ponteiros da nova fila:
    nova -> inicio = NULL;
    nova -> fim = NULL;

    return nova;
}

//Criando No:
ListaNo* cria_no(int valor){
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    //Verificando se alaocacao deu certo:
    if (novo == NULL){
        printf("ERRO NA ALOCAO (2)\n");
        exit(1);
    }
    
    //Setando ponteiros do novo No:
    novo -> info = valor;
    novo -> prox = NULL;
}

//Insere elemento no final da fila:
void fila_insere (Fila* f, int v){
    //Verificando se a Fila existe:
    if (f == NULL){
        printf("ERRO Fila INEXISTENTE (3)\n");
        exit(1);
    }

    //Criando no a partir de v:
    ListaNo* novo = cria_no(v);

    //Caso 1: Fila vazia
    if (f -> inicio == NULL){
        f -> inicio = novo;
    }else{
        //Caso 2: Fila tem inicio e fim
        f -> fim -> prox = novo;
    }

    //Setando o fim:
    f -> fim = novo;
    f -> fim -> prox = NULL;
}

//Remove elemento do inicio da fila:
int fila_retira (Fila* f){
    //Verificando se a Fila existe:
    if (f == NULL){
        printf("ERRO Fila INEXISTENTE (4)\n");
        exit(1);
    }

    //Verificando se o inicio da lista esta vazio:
    if (f -> inicio == NULL){
        printf("Remocao falhou = nada para retirar\n");
        return -1;
    }

    //Armazenando no a ser retirado:
    ListaNo* aux = f -> inicio;
    f -> inicio = f -> inicio -> prox;
    return aux -> info;
    free(aux);
}

//Fila vazia?
int fila_vazia (Fila* f){
    return (f -> inicio == NULL);
}

//Exibir fila:
void exibir_fila(Fila* f){
    //Verificando se a Fila existe:
    if (f == NULL){
        printf("ERRO Fila INEXISTENTE (5)\n");
        exit(1);
    }

    //Verificando se a fila esta vazia:
    if (f -> inicio == NULL){
        printf("ERROR ! NADA PARA EXIBIR (6)");
        exit(1);
    }

    //Criando auxiliar para ajudar a exibir:
    ListaNo* atual = f -> inicio;

    //Percorrendo a Fila:
    int i = 0;
    while (atual != NULL){
        printf("No = %d || Valor = %d || prox = ", i, atual -> info);
        if (atual -> prox == NULL){
            printf("Null\n");
        }else{
            printf("%d\n", atual -> prox -> info);
        }
        i++;
        atual = atual -> prox;
    }
}

//Liberando a fila:
void fila_libera (Fila* f){
    //Verificando se a Fila existe:
    if (f == NULL){
        printf("ERRO Fila INEXISTENTE (7)\n");
        exit(1);
    }

    //Criando auxiliar para ajudar a liberar:
    ListaNo* atual = f -> inicio;
    ListaNo* aux = NULL;

    //Percorrendo a Fila:
    while (atual != NULL){
       aux = atual;
       free(aux);
       atual = atual -> prox;
    }

    free(f);
}