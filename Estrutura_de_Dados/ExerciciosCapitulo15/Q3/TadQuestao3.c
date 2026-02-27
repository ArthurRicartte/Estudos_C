#include "Questao3.h"
#include "pilha.h"
#include <stdio.h>
#include <stdlib.h>

int main(void) {
    /* cria calculadora com formato de duas casas decimais */
    //%.2f\n vai ser armazenado em f, e quando exibir f vai exibir a formatacao de float
    Calc* calc = calc_cria("%.2f\n");

    while (1) {
        char c;
        /* lê próximo caractere não branco */
        scanf(" %c", &c);

        /* processa caractere lido */
        if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^' || c == '~' || c == '#') {
            calc_operador(calc, c);
        } else if (c == 'q') {
            break;          /* aborta programa */
        } else {
            /* devolve caractere lido e tenta ler número */
            ungetc(c, stdin);
            float v;
            if (scanf("%f", &v) == 1) {
                calc_operando(calc, v);
            } else {
                printf("Erro na leitura\n");
                exit(1);
            }
        }
    }

    calc_libera(calc);
    return 0;
}