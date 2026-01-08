#include "ListasCirculares.h"
#include <stdio.h>
#include <stdlib.h>

//Criando as estruturas:

struct lista{
    ListaNo* cabeca;
};

struct listano{
    int info;
    ListaNo* proximo;
};

//Criar lista vazia:
Lista* lst_cria (void){
    Lista* l = (Lista*) malloc(sizeof(Lista));
    l -> cabeca = NULL;
    return l;
}

//Insere valor no inicio:
void lst_insere (Lista* l, int v){
    //Caso a lista nao exista:
    if (!l){
        printf("Lista nao existe (1)\n");
        return;
    }
    
    //Criando o novo no:
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    //Caso de erro na alocacao:
    if (!novo){
        printf("Error ao alocar memoria (2)\n");
        exit(1);
    }

    //Atribuindo valor ao novo no:
    novo -> info = v;

    //Caso a lista esteja vazia:
    if (!l -> cabeca){
        l -> cabeca = novo;
        novo -> proximo = novo; //Aponta para ele mesmo
    }else{
        //Encontrando o ultimo no:
        ListaNo* ultimo = l -> cabeca;

        while (ultimo -> proximo != l -> cabeca){
            ultimo = ultimo -> proximo;
        }

        //Inserindo no inicio:
        novo -> proximo = l -> cabeca; // Novo aponta para a antiga cabeca
        l -> cabeca = novo; // cabeca aponta para o novo no
        ultimo -> proximo = novo; // Ultimo aponta para a nova cabeca
    }
}

//Insere valor de forma ordenada:
void lst_insere_ordenado (Lista* l, int v){
    //Caso a lista nao exista:
    if (!l){
        printf("Lista nao existe (3)\n");
        return;
    }
    
    //Criando o novo no:
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));
    if (!novo){
        printf("Error ao alocar memoria (4)\n");
        exit(1);
    }

    novo -> info = v;

    //Caso a lista esteja vazia:
    if (!l -> cabeca){
        l -> cabeca = novo;
        novo -> proximo = novo;
        return;
    }

    //Caso 2: Insere antes do primeiro elemento (Um valor menor que todo mundo):
    if (v < l -> cabeca -> info){
        //Encontrando o ultimo no:
        ListaNo* ultimo = l -> cabeca;

        while (ultimo -> proximo != l -> cabeca){
            ultimo = ultimo -> proximo;
        }

        //Inserindo no inicio:
        novo -> proximo = l -> cabeca;
        l -> cabeca = novo;
        ultimo -> proximo = novo;
        return;
    }

    //Caso 3: Insere no meio ou no final da lista:
    ListaNo* ant = l -> cabeca;
    ListaNo* atual = l -> cabeca -> proximo;
    

    //Determinando o ant e o atual para o valor v:
    while (atual -> proximo != l -> cabeca && atual -> info < v){
        ant = atual;
        atual = atual -> proximo;
    }

    //Inserindo o novo no entre ant e atual:
    novo -> proximo = atual;
    ant -> proximo = novo;

}

//Retira um valor especifico da lista:
void lst_retira (Lista* l, int v){
     //Caso a lista nao exista:
    if (!l){
        printf("Lista nao existe (5)\n");
        return;
    }

    if (!l || !l -> cabeca){
        printf("Lista vazia ou nao existe (6)\n");
        return;
    }

    ListaNo* aux = l -> cabeca;
    ListaNo* ant = NULL;

    //Procurando o valor v na lista:
    while(aux -> info != v){
        if (aux -> proximo == l -> cabeca){
            printf("Valor %d nao encontrado na lista (7)\n", v);
            return;
        }

        ant = aux;
        aux = aux -> proximo;
    }

    //Caso 1: Lista com um no:
    if (aux -> proximo == aux){
        l -> cabeca = NULL;
        free(aux);
        return;
    }else if (aux == l -> cabeca){ //Caso 2: Removendo a cabeca:
        
        //Encontrando o ultimo no:
        ListaNo* ultimo = l -> cabeca;

        //Percorrendo ate o ultimo no:
        while (ultimo -> proximo != l -> cabeca){
            ultimo = ultimo -> proximo;
        }

        //Atualizando a cabeca e o ultimo no:
        l -> cabeca = aux -> proximo;
        ultimo -> proximo = l -> cabeca;
        free(aux);
        return;
    }
    
    //Retirando do meio da lista:
    ant -> proximo = aux -> proximo;
    free(aux);
}

//Libera a memoria alocada para a lista:
void lst_libera (Lista* l){
    //Caso a lista nao exista:
    if (!l){
        printf("Lista nao existe (8)\n");
        return;
    }

    //Verifcar se a lista eh vazia:
    if (!l -> cabeca){
        free(l);
        return;
    }

    ListaNo* atual = l -> cabeca;
    ListaNo* aux = NULL;

    //Liberando um no de cada vez:
    while(atual -> proximo != l -> cabeca){
        aux = atual;
        atual = atual -> proximo;
        free(aux);
    }

    free(atual); //Liberando o ultimo no
    free(l); //Liberando a estrutura da lista
}

//Verifica se a lista eh vazia:
int lst_vazia (Lista* l){
    return (l -> cabeca == NULL);
}

//Verfica se o valor pertence a lista:
int lst_pertence (Lista* l, int v){
    //Verificando possiveis erros:
    if (v < 0 || !l || !l -> cabeca){
        printf("Valor invalido ou lista vazia (9)\n");
        return 0;
    }

    //Percorrendo a lista para encontrar o valor v:
    ListaNo* atual = l -> cabeca;

    while (atual -> proximo != l -> cabeca){
        if (atual -> info == v){
            printf("Valor %d pertence a lista\n", v);
            return 1;
        }
    }

    //Valor nao encontrado:
    printf("Valor %d nao pertence a lista (10)\n", v);
    return 0;
}

//Imprime os valores da lista:
void lst_imprime (Lista* l){
    //Verificando se a lista existe:
    if (!l){
        printf("Lista nao existe (11)\n");
        return;
    }

    //Verificando se a lista esta vazia:
    if (!l -> cabeca){
        printf("Lista vazia (12)\n");
        return;
    }

    //Exibindo os valores:
    int i = 0;
    ListaNo* atual = l -> cabeca;
    while (1){
        printf("No %d || Valor = %d || Aponta para: %d\n", i, atual -> info, atual -> proximo -> info);
        atual = atual -> proximo;
        i++;

        //Verificando se ja percorreu toda a lista:
        if (atual == l -> cabeca){
            break;
        }
    }
}