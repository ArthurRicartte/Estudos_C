/*Envolve listas duplamente encadeadas de inteiros, vou usar o tad que ja implementei
Vou deixar so as funcoes bascias do tad e adicionar as funcoes que a questao pede*/

#ifndef QUESTAO11_H
#define QUESTAO11_H

//Definindo as estruturas necessarias:
typedef struct lista Lista;

typedef struct listano ListaNo; //No propiamente dito

//Cria lista vazia
Lista* lst_cria (void );

//Insere valor de forma ordenada:
void lst_insere_ordenado (Lista* l, int v);

//Libera a memoria alocada para a lista:
void lst_libera (Lista* l);

//Imprime os valores da lista:
void lst_imprime (Lista* l);

//Quantao 11:

//Primeira funcao: retira no do inicio:
void retira_inicio ( Lista* l);

//Segunda funcao: retira no do fim:
void retira_final (Lista* l);

#endif
