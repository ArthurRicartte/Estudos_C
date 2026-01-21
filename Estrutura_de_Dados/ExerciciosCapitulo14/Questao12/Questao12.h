/*Questao trabalha com listas circulares duolamente encadeadas, 
entao aproveitei o codigo ja feito para listas circulares:*/

#ifndef QUESTAO12_H
#define QUESTAO12_H

//Definindo as estruturas necessarias:
typedef struct lista Lista;

typedef struct listano ListaNo; //No propiamente dito

//Cria lista vazia
Lista* lst_cria (void);

//Funcao auxiliar para criar No:
ListaNo* cria_no(int v);

//Insere valor no inicio:
void lst_insere_inicio(Lista* l, int v);

//Insere valor no final:
void lst_insere_final(Lista* l, int v);

//Insere valor de forma ordenada:
void lst_insere_ordenado (Lista* l, int v);

//Retira um valor do inicio da lista:
int lst_retira_inicio (Lista* l);

//Retira um valor do final da lista:
int lst_retira_final (Lista* l);

//Libera a memoria alocada para a lista:
void lst_libera (Lista* l);

//Imprime os valores da lista:
void lst_imprime (Lista* l);

#endif