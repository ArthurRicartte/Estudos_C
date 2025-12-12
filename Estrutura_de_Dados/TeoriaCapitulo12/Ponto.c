#include "Ponto.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct ponto{
    float x;
    float y;
};

Ponto* pto_cria(float x, float y){
    Ponto* p = (Ponto*) malloc(sizeof(Ponto));

    if (!p)
    {
        printf("Memoria insuficiente\n");
        exit(1);
    }
    
    p -> x = x;
    p -> y = y;

    return p;
}

void pto_libera(Ponto* p){
    free(p);
}

void pto_acessa(Ponto* p, float *x, float *y){
    *x = p -> x;
    *y = p -> y;
}

void pto_atribuir(Ponto* p, float x, float y){
    p -> x = x;
    p -> y = y;
}

float pto_distancia(Ponto* p1, Ponto* p2){
    float aux1 = pow(p2 -> x - p1 -> x, 2);
    float aux2 = pow(p2 -> y - p1 -> y, 2);

    return sqrt(aux1 + aux2);
}