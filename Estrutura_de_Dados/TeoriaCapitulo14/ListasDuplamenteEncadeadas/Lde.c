#include "Lde.h"
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

//Insere valor no inicio:
void lst_insere_inicio (Lista* l, int v){
    //Verificando validade da lista:
    if (!l){
        printf("Lista invalida! (2)\n");
        exit(1);
    }

    //Criando novo no para armazenar v:
    ListaNo* novo = (ListaNo*)malloc(sizeof(ListaNo));

    //Verificar se deu certo:
    if (!novo){
        printf("Erro ao alocar memoria! (3)\n");
        exit(1);
    }

    //Atribuindo valor ao novo no:
    novo -> valor = v;
    novo -> prox = l -> primeiro;
    novo -> ant = NULL;

    //Verificar se a lista eh vazia:
    if (!l -> primeiro){
        l -> ultimo = novo;
    }else{
        l -> primeiro -> ant = novo;
    }

    //Agora, o novo se torna o primeiro:
    l -> primeiro = novo;
}

//Insere valor no fim:
void lst_insere_fim (Lista* l, int v){
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
    novo -> prox = NULL;
    novo -> ant = l -> ultimo;

    //Verificar se a lista eh vazia:
    if (! l -> ultimo){
        l -> primeiro = novo;
    }else{
        l -> ultimo -> prox = novo;
    }

    //Tornando o novo valor como ultimo:
    l -> ultimo = novo;
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

//Retira um valor especifico da lista:
void lst_retira (Lista* l, int v){
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

    //Criando um no auxiliar e percorrendo a lista:
    ListaNo* aux = l -> primeiro;

    while (aux != NULL && aux -> valor != v){
        aux = aux -> prox;
    }

    //Verifica se nao encontrou o valor:
    if (aux == NULL){
        printf("Valor nao encontrado! (7)\n");
        return;
    }

    //Caso 1: Retirar o primeiro no:
    if (l -> primeiro == aux){
        l -> primeiro = aux -> prox;
        
        if (l -> primeiro != NULL){
            l -> primeiro -> ant = NULL;
        }else{
            l -> ultimo = NULL; //Lista ficou vazia
        }
    }

    //Caso 2: Retirar o ultimo no:
    else if (l -> ultimo == aux){
        l -> ultimo = aux -> ant;
        
        if (l -> ultimo != NULL){
            l -> ultimo -> prox = NULL;
        }else{
            l -> primeiro = NULL; //Lista ficou vazia
        }
    }

    //Caso 3: Retiraar do meio:
    else {
        aux -> ant -> prox = aux -> prox;
        aux -> prox -> ant = aux -> ant;
    }

    //Liberando memoria:
    free(aux);
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

//Verifica se a lista eh vazia:
int lst_vazia (Lista* l){
    return (l -> primeiro == NULL);
}


//Verfica se o valor pertence a lista:
int lst_pertence (Lista* l, int v){
    //Verificando validade da lista:
    if (!l){
        printf("Lista invalida! (4)\n");
        exit(1);
    }

    //Verificar se a lista esta vazia:
    if (! l-> primeiro){
        printf("Lista vazia! (6)\n");
        return 0;
    }

    //Percorrendo a lista:
    ListaNo* aux = l -> primeiro;
    while (aux != NULL){
        if (aux -> valor == v){
            return 1; //Valor encontrado
        }

        aux = aux -> prox;
    }

    return 0; //Valor nao encontrado
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
