#include "pilhaV.h "
#include <stdio.h>

int main(){
    Pilha* p = pilha_cria();

    pilha_push(p, 1.5);
    pilha_push(p, 2.5);
    pilha_push(p, 3.5);

    pilha_exibe(p);

    printf("Elemento removido: %.2f\n", pilha_pop(p));
    printf("Elemento removido: %.2f\n", pilha_pop(p));

    pilha_exibe(p);

    pilha_libera(p);
    return 0;
}