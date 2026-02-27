#include "Questao2.h"
#include <stdio.h>

int main(void){
    //Criando filas:
    Fila* f1 = fila_cria();
    Fila* f2 = fila_cria();
    Fila* f_res = fila_cria();

    //Inserindo valores em f1:
    fila_insere(f1, 1.0);
    fila_insere(f1, 2.0);
    fila_insere(f1, 3.0);

    //Inserindo valores em f2:
    fila_insere(f2, 4.0);
    fila_insere(f2, 5.0);
    fila_insere(f2, 6.0);

    //Exibindo filas antes da combinacao:
    printf("Fila 1:\n");
    fila_exibe(f1);
    
    printf("\nFila 2:\n");
    fila_exibe(f2);

    //Combinando filas:
    combina_filas(f_res, f1, f2);

    //Exibindo resultado da combinacao:
    printf("\nFila combinada:\n");
    fila_exibe(f_res);

    //Liberando filas:
    fila_libera(&f1);
    fila_libera(&f2);
    fila_libera(&f_res);

    return 0;
}