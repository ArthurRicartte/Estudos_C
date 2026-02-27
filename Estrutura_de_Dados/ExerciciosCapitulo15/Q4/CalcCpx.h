#ifndef QUESTAO3_H
#define QUESTAO3_H

#include "Compx.h"

typedef struct calc Calc;
Calc* calc_cria (char * f);
void calc_operando (Calc* c, Complexo* v);
void calc_operador (Calc* c, char op);
void calc_libera (Calc* c);

#endif