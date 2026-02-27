#include "CalcCpx.h"
#include "PilhaCpx.h"
#include "Compx.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Definindo estrutura da calculadora
struct calc{
    Pilha* p; //Pilha de operandos
    char f[50]; //Formato para impressao
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
void calc_operando (Calc* c, Complexo* v){
    //Verificando se a calculadora existe:
    if (c == NULL){
        printf("Calculadora nao existe! (2)\n");
        return;
    }

    //Coloca no topo:
    pilha_push(c -> p, v);

    //Exibe:
    printf(c -> f, Parte_Real(v), Parte_Imaginaria(v));
}

//Calculando operadores:
void calc_operador (Calc* c, char op){
    //Verifcando se a calculadora existe:
    if (c == NULL || c -> p == NULL){
        printf("Calculadora nao existe! (3)\n");
        return;
    }

    //Desempilhando operandos:
    Complexo* v2 = pilha_vazia(c -> p) ? NULL : pilha_pop(c -> p);
    Complexo* v1 = pilha_vazia(c -> p) ? NULL : pilha_pop(c -> p);

    //Dterminando e realizando a operacao:
    Complexo* res = NULL;
    
    switch (op){
        case '+':{    
            res = Sum_Complexo(v1, v2);
            break;
        }
        case '-':{
            res = Sub_Complexo(v1, v2);
            break;
        }
        case '*':{
            res = Mult_Complexo(v1, v2);
            break;
        }
        case '/':{
            if (v2 == 0){
                printf("Erro: divisao por zero! (5)\n");
            }else{
                res = Div_Complexo(v1, v2);
            }
            break;
        }
        
        default:
            printf("Operador desconhecido! (4)\n");

            //Liberando complexos desempilhados:
            Libera_Complexo(v1);
            Libera_Complexo(v2);
            break;
    }

    //Liberando complexos operandos (nao serao mais utilizados):
    Libera_Complexo(v1);
    Libera_Complexo(v2);

    pilha_push(c -> p, res);
    printf(c -> f, Parte_Real(res), Parte_Imaginaria(res));
}

//Liberando a calculadora:
void calc_libera (Calc* c){
    if (c == NULL) return;
    pilha_libera(c -> p);
    free(c);
}