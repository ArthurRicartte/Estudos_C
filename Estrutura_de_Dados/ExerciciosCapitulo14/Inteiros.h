#ifndef INTEIROS_H
#define INTEIROS_H

//Questoes 1,

//Criando uma estrutura para servir de exemplo:
typedef struct inteiro Inteiro;

//Criando uma estrutura para armazenar os inteiros:
typedef struct listaInt ListaInt;

//Criar lista:
ListaInt* cria_list();

//Inserir no inicio da lista:
void insere_inicio(int num, ListaInt* lista);

//Libera lista da memoria:
void libera(ListaInt* lista);

//Exibe lista:
void exibirLista(ListaInt* lista);

//Questao 1: Uma funcao que retorne o comprimento da lista (Quantos nos ela tem:)
int comprimento (ListaInt* l);

//Questao 2: uma funcao que retorna a quantida de nos que tenham info maior que um x:
int maiores (ListaInt* l, int x);

//Questao 3: retorna o ultimo valor da lista:
int ultimo (ListaInt* l);

//Questao 4: concatena 2 listas:
void concatena (ListaInt* l1 , ListaInt* l2 );

#endif