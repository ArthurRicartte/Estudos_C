#ifndef QUESTAO1_H
#define QUESTAO1_H

//Constante que define o tamanho incial da pilha:
#define MAX 4

//Definindo um fator de aumento:
#define FATOR_AUMENTO 2

//Strutura de dados para pilha:
typedef struct pilha Pilha;

//Cria pilha:
Pilha* pilha_cria(void);

//Insere no topo:
void pilha_push (Pilha* p, float v);

//Retira do topo:
float pilha_pop (Pilha* p, float* v); 

//Eh vazia?
int pilha_vazia (Pilha* p);

//Esta cheia?
int pilha_cheia (Pilha* p);

//Retorna o valor do topo:
float pilha_topo (Pilha* p);

//Concatena pilha de forma recursiva:
void concatena_pilhas_rec (Pilha* p1 , Pilha* p2 );

//Concatena pilha usando pilha auxiliar:
void concatena_pilhas_aux (Pilha* p1 , Pilha* p2 );

//Funcao para copiar pilha:
Pilha* copia_pilha (Pilha* p);

//Exibir pilha:
void pilha_exibe (Pilha* p);

//Libera pilha:
void pilha_libera (Pilha** p);

#endif