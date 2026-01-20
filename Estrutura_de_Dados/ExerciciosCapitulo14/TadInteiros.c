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
    printf("Ultimo no de lista1 = %d\n", ultimo(lista1));
    
    //Criando segunda lista:
    ListaInt* lista2 = cria_list();

    //Add Inteiros:
    insere_inicio(8, lista2);
    insere_inicio(7, lista2);
    insere_inicio(6, lista2);
    insere_inicio(5, lista2);

    //Exibindo:
    printf("\nLista 2:\n");
    exibirLista(lista2);
    printf("\n");

    //Concatenando as duas listas:
    concatena(lista1, lista2);

    //Exibindo lista concatenada:
    printf("Lista 1 + Lista 2:\n");
    exibirLista(lista1);

    //Criando terceira lista:
    ListaInt* lista3 = cria_list();

    //Add Inteiros:
    insere_inicio(12, lista3);
    insere_inicio(11, lista3);
    insere_inicio(10, lista3);
    insere_inicio(9, lista3);

    //Exibindo:
    printf("\nLista 3:\n");
    exibirLista(lista3);
    printf("\n");

    //Retirando o numero 11 da lista3:
    retira_n(lista3, 11);
    printf("Lista 3 apos retirar o numero 11:\n");
    exibirLista(lista3);

    //Separando a lista3 a partir do numero 10:
    ListaInt* lista4 = separa(lista3, 10);
    printf("\nLista 3 apos separar a partir do numero 10:\n");
    exibirLista(lista3);

    //Criando quinta lista:
    ListaInt* lista5 = cria_list();

    //Add Inteiros:
    insere_inicio(16, lista5);
    insere_inicio(15, lista5);
    insere_inicio(14, lista5);
    insere_inicio(13, lista5);

    //Exibindo:
    printf("\nLista 5:\n");
    exibirLista(lista5);

    //Criando sexta lista:
    ListaInt* lista6 = cria_list();

    //Add Inteiros:
    insere_inicio(20, lista6);
    insere_inicio(19, lista6);
    insere_inicio(18, lista6);
    insere_inicio(17, lista6);

    //Exibindo:
    printf("\nLista 6:\n");
    exibirLista(lista6);
    printf("\n");

    //Intercalando lista5 e lista6:
    ListaInt* lista7 = merge(lista5, lista6);
    printf("Lista 5 e Lista 6 intercaladas:\n");
    exibirLista(lista7);
    printf("\n");

    //Inverter lista7:
    inverte(lista7);
    printf("Lista 7 invertida:\n");
    exibirLista(lista7);
    printf("\n");


    //Fazendo copia iterativa de lista1:
    ListaInt* lista8 = copiaIterativa(lista1);
    printf("Copia iterativa de lista1:\n");
    exibirLista(lista8);
    printf("\n");

    //Fazendo copia recursiva de lista7:
    ListaInt* lista9 = copiaRecursiva(lista7);
    printf("Copia recursiva de lista7:\n");
    exibirLista(lista9);
    printf("\n");

    //Transformando lista1 em circular:
    para_circular(lista1);
    printf("Lista1 transformada em circular:\n");
    exibirListaCircular(lista1);
    printf("\n");

    //Liberando listas:
    liberaCircular(lista1); //Passou a ser uma lista circular
    libera(lista2);
    libera(lista3);
    libera(lista4);
    libera(lista5);
    libera(lista6);
    libera(lista7);
    libera(lista8);
    libera(lista9);

    return 0;
}