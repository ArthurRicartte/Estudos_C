#ifndef VETORDIN_H
#define VETORDIN_H

//Struct para o vetor:
typedef struct vetordin VetorDin;

//Cria vetor:
VetorDin* vd_cria (void );

//Insere um valor:
void vd_insere ( VetorDin* vd , float x);

//Retorna o valor:
int vd_tam ( VetorDin* vd);

//Acessa algum valor no vetor:
float vd_acessa ( VetorDin* vd , int i);

//Libera memoria do vetor:
void vd_libera ( VetorDin* vd);
#endif