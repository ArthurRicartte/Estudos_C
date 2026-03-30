#ifndef LISTAENCADEADAS_H
#define LISTAENCADEADAS_H

//Criando struct para o No da lista:
struct listaNo {
    int info;
    struct listaNo* prox;
};
typedef struct listaNo ListaNo;

//Criando lista:
ListaNo* lista_cria(void);

//Insere no inicio:
void lista_insere (ListaNo** phead, int i);

//Imprime de forma recursiva:
void lista_imprime (ListaNo** phead);

//Lista vazia?
int lista_vazia (ListaNo** phead);

//Busca de forma recursiva:
ListaNo* lista_busca (ListaNo** l, int v);

//Retira elemento
ListaNo* lista_retira (ListaNo** phead, int v);

//Conta numero de elementos:
int lista_conta_rec (ListaNo** phead);

//Libera memoria alocada:
void lista_libera (ListaNo** phead);

#endif