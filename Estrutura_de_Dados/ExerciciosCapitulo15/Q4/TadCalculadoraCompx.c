#include "CalcCpx.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main() {
    // Cria a calculadora com formato de saída (ex: "(4.00,6.00)")
    Calc* calc = calc_cria("(%.2f,%.2f)\n");

    printf("============================================\n");
    printf("Calculadora Pos-Fixada para Numeros Complexos\n");
    printf("============================================\n");
    printf("- Digite operandos no formato (a,b) (ex: (1,2))\n");
    printf("- Digite operadores: +, -, *, /\n");
    printf("- Digite 'q' para sair\n");
    printf("- Espacos e quebras de linha são ignorados\n");
    printf("Exemplo: (1,2) (3,4) + (5,6) *\n");
    printf("--------------------------------------------\n");

    char linha[256];
    while (1) {
        printf("> ");
        if (fgets(linha, sizeof(linha), stdin) == NULL) {
            break; // fim de arquivo (Ctrl+D)
        }

        for (int i = 0; linha[i] != '\0'; i++) {
            char c = linha[i];
            if (isspace(c)) {
                continue; // ignora espaços e tabulações
            }

            // Verifica se é operador
            if (c == '+' || c == '-' || c == '*' || c == '/') {
                calc_operador(calc, c);
            }
            // Verifica se é comando de sair
            else if (c == 'q' || c == 'Q') {
                calc_libera(calc);
                printf("Calculadora encerrada.\n");
                return 0;
            }
            // Tenta ler um número complexo no formato (a,b)
            else if (c == '(') {
                double real, imag;
                int n; // número de caracteres lidos
                if (sscanf(&linha[i], "(%lf,%lf)%n", &real, &imag, &n) == 2) {
                    Complexo* v = Criar_Complexo(real, imag);
                    calc_operando(calc, v);
                    i += n - 1; // avança o índice para depois do número lido
                } else {
                    printf("Erro: formato inválido para número complexo. Use (a,b)\n");
                }
            }
            // Qualquer outro caractere é ignorado com aviso
            else {
                printf("Aviso: caractere '%c' ignorado.\n", c);
            }
        }
    }

    calc_libera(calc);
    return 0;
}