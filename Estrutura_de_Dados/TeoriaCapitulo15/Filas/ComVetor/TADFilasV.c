#include "FilasV.h"
#include <stdio.h>

int main(void){
    //Criando uma fila:
    Fila* fila = fila_cria();

    //adicioando elementos:
    fila_insere(fila, 1);
    fila_insere(fila, 2);
    fila_insere(fila, 3);

    //Exibindo fila:
    printf("Apos a insercao de 3 elementos:\n");
    exibir_fila(fila);
    
    //Retirando um elemento:
    fila_retira(fila);
    printf("Apos a remorcao de 1 elementos:\n");
    exibir_fila(fila);

    //Libera da memoria:
    fila_libera(fila);
}