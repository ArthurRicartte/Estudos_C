#ifndef FILASV_H
#define FILASV_H

//Tipo estrututrado da fila:
typedef struct fila Fila;

//Criando fila: 
Fila* fila_cria (void );

//Insere elemento no final da fila:
void fila_insere (Fila* f, int v);

//Remove elemento do inicio da fila:
int fila_retira (Fila* f);

//Fila vazia?
int fila_vazia (Fila* f);

//Exibir fila:
void exibir_fila(Fila* f);

//Liberando a fila:
void fila_libera (Fila* f);

#endif