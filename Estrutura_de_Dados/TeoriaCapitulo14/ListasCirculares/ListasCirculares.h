#ifndef LISTAS_CIRCULARES_H
#define LISTAS_CIRCULARES_H

//Definindo as estruturas necessarias:
typedef struct lista Lista;

typedef struct listano ListaNo; //No propiamente dito

//Cria lista vazia
Lista* lst_cria (void);

//Insere valor no inicio:
void lst_insere (Lista* l, int v);

//Insere valor de forma ordenada:
void lst_insere_ordenado (Lista* l, int v);

//Retira um valor especifico da lista:
void lst_retira (Lista* l, int v);

//Libera a memoria alocada para a lista:
void lst_libera (Lista* l);

//Verifica se a lista eh vazia:
int lst_vazia (Lista* l);

//Verfica se o valor pertence a lista:
int lst_pertence (Lista* l, int v);

//Imprime os valores da lista:
void lst_imprime (Lista* l);

#endif