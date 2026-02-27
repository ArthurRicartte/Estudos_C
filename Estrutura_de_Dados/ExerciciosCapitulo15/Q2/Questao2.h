#ifndef QUESTAO_H
#define QUESTAO_H

//Constante que define o tamanho incial da fila:
#define MAX 4

//Definindo um fator de aumento:
#define FATOR_AUMENTO 2

//Tipo estruturado para a fila:
typedef struct fila Fila;

//Criar a fila:
Fila* fila_cria(void );

//Inserir no final da fila:
void fila_insere (Fila* f, float v);

//Retirar do inicio:
float fila_retira (Fila* f);

//Combina duas filas intercaladamente em uma terceira fila:
void combina_filas (Fila* f_res, Fila* f1 , Fila* f2 );

//Fila esta vazia?
int fila_vazia (Fila* f);

//Fila esta cheia?
int fila_cheia (Fila* f);

//Exibir a fila:
void fila_exibe (Fila* f);

//Liberar a fila:
void fila_libera (Fila** f);

#endif