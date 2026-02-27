#include "Questao1.h"
#include <stdio.h>
#include <stdlib.h>

int main(void){
    //Criando a pilha:
    Pilha* p1 = pilha_cria();

    //Inserindo elementos:
    pilha_push(p1, 1.5);
    pilha_push(p1, 2.5);
    pilha_push(p1, 3.5);
    pilha_push(p1, 4.5);

    //Exibindo a pilha:
    pilha_exibe(p1);

    //Removendo elementos:
    float valor;
    pilha_pop(p1, &valor);
    printf("Valor removido: %.2f\n", valor);
    pilha_exibe(p1);

    //Exibindo o topo:
    printf("Valor do topo: %.2f\n", pilha_topo(p1));

    //Concatenado pilhas de forma recursiva:
    Pilha* p2 = pilha_cria();

    //Inserindo elementos:
    pilha_push(p2, 2.5);
    pilha_push(p2, 3.5);
    pilha_push(p2, 4.5);
    pilha_push(p2, 5.5);

    //Concatenando pilhas:
    concatena_pilhas_aux(p1, p2);

    //Exibindo a pilha concatenada:
    pilha_exibe(p1);

     //Concatenado pilhas de forma recursiva:
    Pilha* p3 = pilha_cria();

    //Inserindo elementos:
    pilha_push(p3, 3.5);
    pilha_push(p3, 4.5);
    pilha_push(p3, 5.5);
    pilha_push(p3, 6.5);

    //Concatenando pilhas:
    concatena_pilhas_aux(p1, p3);

    //Exibindo a pilha concatenada:
    pilha_exibe(p1);

    //Copiando pilha:
    Pilha* p4 = copia_pilha(p1);
    
    //Exibindo a pilha copiada:
    pilha_exibe(p4);
    //Exibindo o topo:
    printf("Valor do topo: %.2f\n", pilha_topo(p4));

    //Liberando as pilhas:
    pilha_libera(&p1);
    pilha_libera(&p2);
    pilha_libera(&p3);
    pilha_libera(&p4);
}