#ifndef MATRIZ_H
#define MATRIZ_H

//Struct para a Matriz
typedef struct matriz Matriz;

//Criacao da matriz
Matriz* mat_cria (int m, int n);

//Libera memoria alocada para a matriz
void mat_libera ( Matriz* mat);

//Acessa algum valor da matriz:
float mat_acessa ( Matriz* mat, int i, int j);

//Altera o valor de um elemento da matriz
void mat_atribui ( Matriz* mat, int i, int j, float v);

//Retorna quantidade de linhas
int mat_linhas ( Matriz* mat);

//Retorna quantidade de colunas:
int mat_colunas (Matriz* mat);

//Cria Matriz transposta:
Matriz* mat_transposta(Matriz* mat);

//Exibe matriz:
void mat_exibir(Matriz* mat);

#endif