#ifndef COMPLEXOS_H
#define COMPLEXOS_H
typedef struct complexo Complexo;

//Criar um numero complexo:
Complexo* Criar_Complexo(double a, double b);

//Liberar complexo da memoria:
void Libera_Complexo(Complexo* coplx);

//Somar dois numeros complexos:
Complexo* Sum_Complexo(Complexo* c1, Complexo* c2);

//Subtrair dois numeros complexos:
Complexo* Sub_Complexo(Complexo* c1, Complexo* c2);

//Multiplicar numeros complexos:
Complexo* Mult_Complexo(Complexo* c1, Complexo* c2);

//Dividir numeros complexos:
Complexo* Div_Complexo(Complexo* c1, Complexo* c2);

//Exibir complexos:
void Exibir_Complexo(Complexo* c);

#endif