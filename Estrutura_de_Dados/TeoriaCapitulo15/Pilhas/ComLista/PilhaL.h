#ifndef PILHAL_H
#define PILHAL_H

//Estrutura de dados para pilha usando lista
typedef struct pilhaNo PilhaNo;

//Criando No:
PilhaNo* cria_no (int v);

//Inserindo elemento no topo da pilha:
void pilha_push (PilhaNo** phead, int v);

//Removendo elemento do topo da pilha:
int pilha_pop (PilhaNo** phead);

//Pilha vazia?
int pilha_vazia (PilhaNo** phead);

//Exibir pilha:
void pilha_exibe (PilhaNo** phead);

//Liberando a pilha:
void pilha_libera (PilhaNo** phead);

#endif