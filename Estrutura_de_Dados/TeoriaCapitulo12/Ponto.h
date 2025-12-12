#ifndef PONTO_H
#define PONTO_H

typedef struct ponto Ponto;

//Crair um ponto:
Ponto* pto_cria(float x, float y);
//Liberar ponto da memoria:
void pto_libera(Ponto* p);
//Acessa ponto:
void pto_acessa(Ponto* p, float *x, float *y);
//Atribuir valor:
void pto_atribuir(Ponto* p, float x, float y);
//Calcula distancia:
float pto_distancia(Ponto* p1, Ponto* p2);

#endif