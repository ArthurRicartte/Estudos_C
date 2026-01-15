#include "Inteiros.h"
#include <stdio.h>

int main(void){
    //Criando lista:
    ListaInt* lista1 = cria_list();

    //Add Inteiros:
    insere_inicio(4, lista1);
    insere_inicio(3, lista1);
    insere_inicio(2, lista1);
    insere_inicio(1, lista1);

    //Exibir Lista:
    printf("Lista 1:\n");
    exibirLista(lista1);

    //Testando funcoes:
    printf("\nComprimento lista1 = %d nos\n", comprimento(lista1));
    printf("Nos de lista1 maiores que 2 = %d nos\n", maiores(lista1, 2));
    printf("Ultimo no de lista1 = %d\n\n", ultimo(lista1));
    
    //Criando segunda lista:
    ListaInt* lista2 = cria_list();

    //Add Inteiros:
    insere_inicio(8, lista2);
    insere_inicio(7, lista2);
    insere_inicio(6, lista2);
    insere_inicio(5, lista2);

    //Exibindo:
    printf("Lista 2:\n");
    exibirLista(lista2);
    printf("\n");

    //Concatenando as duas listas:
    concatena(lista1, lista2);

    //Exibindo lista concatenada:
    printf("Lista 1 + Lista 2:\n");
    exibirLista(lista1);
    
    //Liberando listas:
    libera(lista1);
    libera(lista2);

    return 0;
}