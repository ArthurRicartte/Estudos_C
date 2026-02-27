#include "Questao3.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

//Definindo estrutura da calculadora
struct calc{
    Pilha* p; //Pilha de operandos
    char f[21]; //Formato para impressao
};

//Criando calculadora:
Calc* calc_cria (char * f){
    Calc* c = (Calc*) malloc(sizeof(Calc));

    //Verificando se a alocacao foi bem sucedida:
    if (c == NULL){
        printf("Erro de alocacao de memoria!(1)\n");
        return NULL;
    }

    //Copiando formato para a calculadora:
    strcpy(c -> f, f);

    c -> p = pilha_cria();
    return c;
}

//Inserindo operando no topo da calculadora:
void calc_operando (Calc* c, float v){
    //Verificando se a calculadora existe:
    if (c == NULL){
        printf("Calculadora nao existe! (2)\n");
        return;
    }

    //Coloca no topo:
    pilha_push(c -> p, v);

    //Exibe:
    printf(c -> f, v);
}

//Calculando operadores:
void calc_operador (Calc* c, char op){
    //Verifcando se a calculadora existe:
    if (c == NULL || c -> p == NULL){
        printf("Calculadora nao existe! (3)\n");
        return;
    }

    //Desempilhando primeiro operando:
    float v2 = pilha_vazia(c -> p) ? 0.0 : pilha_pop(c -> p);

    //Dterminando e realizando a operacao:
    float res = 0.0;
    
    switch (op){
        case '+':{
            float v1 = pilha_vazia(c -> p) ? 0.0 : pilha_pop(c -> p);    
            res = v1 + v2;
            break;
        }
        case '-':{
            float v1 = pilha_vazia(c -> p) ? 0.0 : pilha_pop(c -> p);
            res = v1 - v2;
            break;
        }
        case '*':{
            float v1 = pilha_vazia(c -> p) ? 0.0 : pilha_pop(c -> p);
            res = v1 * v2;
            break;
        }
        case '/':{
            if (v2 == 0){
                printf("Erro: divisao por zero! (5)\n");
                res = 0.0;
            }else{
                float v1 = pilha_vazia(c -> p) ? 0.0 : pilha_pop(c -> p);
                res = v1 / v2;
            }
            break;
        }
        case '^':{
            float v1 = pilha_vazia(c -> p) ? 0.0 : pilha_pop(c -> p);
            res = pow(v1, v2);
            break;
        }
        case '~':{
            res = -v2;
            break;
        }
        case '#':{
            if (v2 < 0){
                printf("Erro: raiz quadrada de numero negativo! (4)\n");
                res = 0.0;
            }else{
                res = sqrt(v2);
            }
            break;
        }
        default:
            break;
    }

    pilha_push(c -> p, res);
    printf(c -> f, res);
}

//Liberando a calculadora:
void calc_libera (Calc* c){
    if (c == NULL) return;
    pilha_libera(c -> p);
    free(c);
}