#include "Questao11.h"
#include <stdio.h>
#include <stdlib.h>

//Definindo as estrututras necessarias:

struct lista{
    ListaNo* primeiro;
    ListaNo* ultimo;
};

struct listano{
    int valor;
    ListaNo* prox;
    ListaNo* ant;
};

//Cria lista vazia
Lista* lst_cria (void ){
    
    //Alocando memoria:
    Lista* l = (Lista*) malloc(sizeof(Lista));

    if (!l){
        printf("Erro ao alocar memoria! (1)\n");
        exit(1);
    }
    
    //Atribuindi valores iniciais:
    l -> primeiro = NULL;
    l -> ultimo = NULL;

    return l;
}

//Insere valor de forma ordenada:
void lst_insere_ordenado (Lista* l, int v){
    //Verificando validade da lista:
    if (!l){
        printf("Lista invalida! (4)\n");
        exit(1);
    }

    //Criando novo no para armazenar v:
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));

    //Verificar se deu certo:
    if (!novo){
        printf("Erro ao alocar memoria! (5)\n");
        exit(1);
    }

    //Atribuindo valor ao novo no:
    novo -> valor = v;

    //Caso a lista esteja vazia:
    if (l -> primeiro == NULL){
        novo -> prox = NULL;
        novo -> ant = NULL;

        l -> primeiro = novo;
        l -> ultimo = novo;

        return;
    }

    //Insere no inicio:
    if (l -> primeiro -> valor > v){
            novo -> prox = l -> primeiro;
            novo -> ant = NULL;

            l -> primeiro -> ant = novo;
            l -> primeiro = novo;

            return;
    }

    //Insere no fim:
    if (l -> ultimo -> valor < v){
            novo -> prox = NULL;
            novo -> ant = l -> ultimo;

            l -> ultimo -> prox = novo;
            l -> ultimo = novo;
            return;
    }

    //Determinando a posicao correta para inserir no meio::
    ListaNo* atual = l -> primeiro;

    while (atual != NULL && atual -> valor < v){
        
        atual = atual -> prox;
    }
       
    //Inserindo o novo no antes do atual:
    if (atual != NULL){
        novo -> prox = atual;
        novo -> ant = atual -> ant;

        if (atual -> ant != NULL){
            atual -> ant -> prox = novo;
        }

        atual -> ant = novo;
    }
}    

//Libera a memoria alocada para a lista:
void lst_libera (Lista* l){
    //Verificando validade da lista:
    if (!l){
        printf("Lista invalida! (4)\n");
        exit(1);
    }

    //Verificar se a lista esta vazia:
    if (! l-> primeiro){
        printf("Lista vazia! (6)\n");
        return;
    }

    //Iniciando a liberacao:
    ListaNo* aux = l -> primeiro;
    ListaNo* temp;

    while (aux != NULL){
        temp = aux;
        aux = aux -> prox;
        free(temp);
    }

    //Reinicializando os ponteiros da lista:
    l -> primeiro = NULL;
    l -> ultimo = NULL;
}


//Imprime os valores da lista:
void lst_imprime (Lista* l){
    //Verificando validade da lista:
    if (!l){
        printf("Lista invalida! (4)\n");
        exit(1);
    }

    //Verificar se a lista esta vazia:
    if (! l-> primeiro){
        printf("Lista vazia! (6)\n");
        return;
    }

    //Percorrendo a lista:
    ListaNo* aux = l -> primeiro;
    printf("Lista:\n");
    
    int i = 0;
    while (aux != NULL){
        //Verificando se ant ou prox sao nulos:
        int ant_valor = (aux -> ant) ? aux -> ant -> valor : -1;
        int prox_valor = (aux -> prox) ? aux -> prox -> valor : -1;
        printf("Elemento %d || Valor = %d || Antecessor = %d || Sucessor = %d \n", i, aux -> valor, ant_valor, prox_valor);

        aux = aux -> prox;
        i++;
    }
}

//Quantao 11:

//Primeira funcao: retira no do inicio:
void retira_inicio (Lista* l){
    //Verificando se a lista e valida:
    if (!l){
        printf("Lista invalida! (7)\n");
        exit(1);
    }

    //Verificando se a lista esta vazia:
    if (! l-> primeiro){
        printf("Lista vazia! (8)\n");
        return;
    }

     //Caso especial: so tem um no na lista:
    if (l -> primeiro == l -> ultimo){
        free(l -> ultimo);
        l -> primeiro = NULL;
        l -> ultimo = NULL;
        return;
    }

    //Retirando o no do inicio:
    ListaNo* temp = l -> primeiro;

    l -> primeiro = l -> primeiro -> prox;
    l -> primeiro -> ant = NULL;

    //Liberando o antigo primeiro:
    free(temp);
}

//Segunda funcao: retira no do fim:
void retira_final (Lista* l){
    //Verificando se a lista e valida:
    if (!l){
        printf("Lista invalida! (7)\n");
        exit(1);
    }

    //Verificando se a lista esta vazia:
    if (! l-> primeiro){
        printf("Lista vazia! (8)\n");
        return;
    }

    //Caso especial: so tem um no na lista:
    if (l -> primeiro == l -> ultimo){
        free(l -> primeiro);
        l -> primeiro = NULL;
        l -> ultimo = NULL;
        return;
    }

    //Caso geral: Mais de 1 no na lista:
    ListaNo* temp = l -> ultimo;

    //Atualizando o ultimo:
    l -> ultimo = l -> ultimo -> ant;
    l -> ultimo -> prox = NULL;
    
    //Liberando o antigo ultimo:
    free(temp);
}