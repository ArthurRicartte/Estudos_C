#ifndef PILHAV_H
#define PILHAV_H

//Estrutura de dados para pilha usando vetor
typedef struct pilha Pilha;

//Criando Pilha:
Pilha* pilha_cria (void );

//Inserindo elemento no topo da pilha:
void pilha_push (Pilha* p, float v);

//Removendo elemento do topo da pilha:
float pilha_pop (Pilha* p);

//Pilha cheia?
int pilha_cheia (Pilha* p);

//Pilha vazia?
int pilha_vazia (Pilha* p);

//Exibir pilha:
void pilha_exibe (Pilha* p);

//Liberando a pilha:
void pilha_libera (Pilha* p);

#endif