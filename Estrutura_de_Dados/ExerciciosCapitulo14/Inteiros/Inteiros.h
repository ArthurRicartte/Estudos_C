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

//Questao 5: retira as ocorrencias de um valor x na lista:
void retira_n (ListaInt* l, int x);

//Questaoo 6: separa a lista em duas a partir de um valor x:
ListaInt* separa (ListaInt* l, int x);

//Questao 7: Intercalar os valores de duas listas em uma terceira lista:
ListaInt* merge (ListaInt* l1 , ListaInt* l2 );

//Questao 8: Inverter a lista:
void inverte (ListaInt* l);

//Questao 9: Fazer uma copia da lista:
ListaInt* copiaIterativa (ListaInt* l);

//Questão 9: Fazer uma copia da lista (De forma recursiva):
ListaInt* copiaRecursiva (ListaInt* l);

//Funcao que vai auxilar na copia recursiva:
Inteiro* copiaNoRecursivo (Inteiro* no_Orig);

//Questao 10: Transforma lista simplimente encadeada em lista circular:
void para_circular (ListaInt* l);

//Funcao auxilar da questao 10: Exibir lista circular:
void exibirListaCircular(ListaInt* lista);

//Funcao auxilar da questao 10: Liberar lista circular:
void liberaCircular(ListaInt* lista);

#endif
