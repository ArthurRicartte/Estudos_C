#include "Matriz.h"
#include <stdio.h>

int main(void){
    //Criando matriz:
    Matriz* A = mat_cria(2,3);

    //Preencher a matriz:
    mat_atribui(A, 0, 0, 1.0);
    mat_atribui(A, 0, 1, 2.0);
    mat_atribui(A, 0, 2, 3.0);
    mat_atribui(A, 1, 0, 4.0);
    mat_atribui(A, 1, 1, 5.0);
    mat_atribui(A, 1, 2, 6.0);

    mat_exibir(A);
    
    //Acessar algum valor:
    printf("A[0][0] = %f\n", mat_acessa(A, 0, 0));

    //Atibuir valor:
    mat_atribui(A, 0, 0, 13.1);

    mat_exibir(A);

    //Linhas e colunas:
    printf("Linhas de A = %d\nColunas de A = %d\n", mat_linhas(A), mat_colunas(A));


    printf("Transposta:\n");
    //Criando matriz transposta:
    Matriz* B = mat_transposta(A);

    //Acessar algum valor:
    printf("A[0][0] = %f\n", mat_acessa(B, 0, 0));

    //Atibuir valor:
    mat_atribui(B, 0, 0, 13.1);

    mat_exibir(B);

    //Linhas e colunas:
    printf("Linhas de B = %d\nColunas de B = %d\n", mat_linhas(B), mat_colunas(B));

    //Liberar da memoria:
    mat_libera(A);
    mat_libera(B);

    return 0;
}