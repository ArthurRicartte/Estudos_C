#ifndef FILASL_H
#define FILASL_H

//Tipo estrututrado da fila:
typedef struct listano ListaNo;
typedef struct fila Fila;

//Criando fila: 
Fila* fila_cria (void );

//Criando No:
ListaNo* cria_no(int valor);

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