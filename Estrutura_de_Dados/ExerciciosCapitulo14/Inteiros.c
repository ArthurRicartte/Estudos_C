#include "Inteiros.h"
#include <stdio.h>
#include <stdlib.h>

//Desenvolvendo estruturas:
struct inteiro{
    int info;
    Inteiro* prox;
};

struct listaInt{
    Inteiro* cabeca;
};

//Criando lista vazia:
ListaInt* cria_list(){
    //Criando lista e alocando memoria:
    ListaInt* lista = (ListaInt*) malloc(sizeof(ListaInt));

    //Verificando se deu certo:
    if (!lista){
        printf("ERRO AO ALOCAR MEMORIA (1)\n");
        exit(1);
    }

    //Modificando ponteiro de lista:
    lista -> cabeca = NULL;

    return lista;
}

//Inserir no inicio da lista:
void insere_inicio(int num, ListaInt* lista){
    //Verificando procedencia da lista:
    if (!lista){
        printf("ERROR LISTA INVALIDA (2)\n");
        return;
    }

    //Criando um novo no:
    Inteiro* novo = (Inteiro*) malloc(sizeof(Inteiro));

    //Verificando se no foi alocado dinamicamente:
    if (!novo){
        printf("ERRO AO ALOCAR MEMORIA PARA O NOVO NO (3)\n");
        return;
    }

    //Novo No recebe num:
    novo -> info = num;

    //Novo No aponta para a antiga cabeca:
    novo -> prox = lista -> cabeca;
    
    //Cabeca passa a ser o novo No:
    lista -> cabeca = novo;
}

//Libera lista da memoria:
void libera(ListaInt* lista){
    //verifica se a lista existe:
    if (!lista){
        printf("ERRO LISTA INVALIDA(4)\n");
        return;
    }

    //Percorrendo lista para liberar cada No:
    Inteiro* atual = lista -> cabeca;
    Inteiro* aux = NULL;
    
    while (atual != NULL){
        aux = atual;
        atual = atual -> prox;
        free(aux);
    }
    
    //Liberando a estrutura da memoria:
    free(lista);
}

//Exibe Lista:
void exibirLista(ListaInt* lista){
    //verifica se a lista eh vazia:
    if (!lista){
        printf("ERRO: PONTEIRO DE LISTA INVALIDO (5)\n");
        return;
    }

    // Lista vazia:
    if (lista -> cabeca == NULL){
        printf("Lista vazia\n");
        return;
    }

    //Percorrendo lista para exibir:
    Inteiro* atual = lista -> cabeca;
    int cont = 0;
   
    while (atual != NULL){
        
        printf("No %d || Valor: %d ||", cont, atual -> info);

        //Determinando a info do prox:
        if (atual -> prox != NULL){
            printf("Prox: %d\n", atual -> prox -> info);
        }else{
            printf("NULL\n");
        }
        
        atual = atual -> prox;
        cont++;
    }
}

//Questao 1: Uma funcao que retorne o comprimento da lista (Quantos nos ela tem:)
int comprimento (ListaInt* l){
    //Verificando se a lista eh valida:
    if (!l){
        return -1; //Deu errado
    }

    //Percorrendo a lista para determinar a quantidade de nos:
    int contador = 0;
    Inteiro* atual = l -> cabeca;

    while (atual != NULL){
        contador++;
        atual = atual -> prox;
    }

    //retornando a quantidade de nos:
    return contador;
}

//Questao 2: uma funcao que retorna a quantida de nos que tenham info maior que um x:
int maiores (ListaInt* l, int x){
    //Verificando se a lista eh valida:
    if (!l){
        return -1; //Deu errado
    }

    //Percorrendo a lista para determinar a quantidade de nos:
    int contador = 0;
    Inteiro* atual = l -> cabeca;

    while (atual != NULL){
        
        //Verificando se existe algum no com info maior que x:
        if (atual -> info > x){
            contador++;
        }
        atual = atual -> prox;
    }

    //retornando a quantidade de nos especificos:
    return contador;
}

//Questao 3: retorna o ultimo valor da lista:
int ultimo (ListaInt* l){
    //Verificando se a lista eh valida:
    if (!l){
        return -1; //Deu errado
    }

    //retornando -2 caso a lsita seja vazia:
    if (l -> cabeca == NULL){
        return -2;
    }
    
    //Percorrendo a lista para determinar o ultimo no:
    Inteiro* atual = l -> cabeca;

    while (atual != NULL){
        
        //Verificando ultimo elemento:
        if (atual -> prox == NULL){
            return atual -> info;
        }
        atual = atual -> prox;
    }

    //Caso alguma coisa inesperada aconteca:
    return -3;
}

//Questao 4: concatena 2 listas:
void concatena (ListaInt* l1 , ListaInt* l2 ){
    //Verificar se as listas sao validas:
    if (!l1 || !l2){
        printf("ERRO: PONTEIRO DE LISTA INVALIDO (6)\n");
        return;
    }

    //Caso 1: l2 vazia = faz nada
    if (l2 -> cabeca == NULL){
        return;
    }

    //Caso 2: l1 vazia = recebe l2
    if (l1 -> cabeca == NULL){
        l1 -> cabeca = l2 -> cabeca;
        l2 -> cabeca = NULL;
        return;
    }

    //Caso 3: Ambas nao vazias = encontrar fim de l1
    Inteiro* atual = l1 -> cabeca;

    //Percorrendo ate o ultimo no de l1:
    while (atual -> prox != NULL){
        atual = atual -> prox;
    }

    //Concatenando l1 e l2:
    atual -> prox = l2 -> cabeca;
    l2 -> cabeca = NULL;
}