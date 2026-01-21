#include "Questao12.h"
#include <stdio.h>
#include <stdlib.h>

//Criando as estruturas:
struct lista{
    ListaNo* primeiro;
    ListaNo* ultimo;
};

struct listano{
    int info;
    ListaNo* proximo;
    ListaNo* anterior;
};

//Criar lista vazia:
Lista* lst_cria (void){
    Lista* l = (Lista*) malloc(sizeof(Lista));

    //Verificando se a alocacao foi bem sucedida:
    if (!l){
        printf("Error ao alocar memoria (1)\n");
        exit(1);
    }

    //Prenchendo lista vazia:
    l -> primeiro = NULL;
    l -> ultimo = NULL;
    return l;
}

//Funcao auxiliar para criar No:
ListaNo* cria_no(int v){
    //Alocando memoria para o novo no:
    ListaNo* novo = (ListaNo*) malloc(sizeof(ListaNo));

    //Verificando se a alocacao deu certo:
    if (!novo){
        printf("Error ao alocar memoria (2)\n");
        exit(1);
    }

    //Preenchendo o no:
    novo -> info = v;
    novo -> proximo = NULL;
    novo -> anterior = NULL;

    //Retornando o novo no:
    return novo;
}

//Insere valor no inicio:
void lst_insere_inicio(Lista* l, int v){
    //Caso a lista nao exista:
    if (!l){
        printf("Lista nao existe (2)\n");
        return;
    }

    //Criando novo no:
    ListaNo* novo = cria_no(v);

    //Caso a lista esteja vazia:
    if(l -> primeiro == NULL){
        //Lista vazia:
        l -> primeiro = novo;
        l -> ultimo = novo;

        //Definindo os ponteiros do novo no:
        novo -> proximo = novo;
        novo -> anterior = novo;
    }else{
        //Mais de um elemento:
        ListaNo* ultimo = l -> ultimo;
        
        //Atualizando os ponteiros:
        novo -> proximo = l -> primeiro;
        novo -> anterior = ultimo;

        //Ultimo aponta para o novo:
        l -> primeiro -> anterior = novo;
        ultimo -> proximo = novo;
        l -> primeiro = novo;
    }
}

//Insere valor no final:
void lst_insere_final(Lista* l, int v){
    //Verificando se a lista existe:
    if (!l){
        printf("Lista nao existe (3)\n");
        return;
    }

    //Criando novo no:
    ListaNo* novo = cria_no(v);

    //Caso a lista esteja vazia:
    if (l -> primeiro == NULL){
        
        //Lista vazia:
        l -> primeiro = novo;
        l -> ultimo = novo;

        //No aponta para ele mesmo:
        novo -> proximo = novo;
        novo -> anterior = novo;
    }else{
        //Nao esta vazia:
        ListaNo* ultimo = l -> ultimo;

        //Atualizando os ponteiros:
        novo -> proximo = l -> primeiro;
        novo -> anterior = ultimo;
        
        //O antigo ultimo aponta para o novo:
        ultimo -> proximo = novo;

        //O primeiro aponta para o novo ultimo:
        l -> primeiro -> anterior = novo;
        
        //Definindo o novo ultimo:
        l -> ultimo = novo;
    }
}

//Insere valor de forma ordenada:
void lst_insere_ordenado (Lista* l, int v){
    //Caso a lista nao exista:
    if (!l){
        printf("Lista nao existe (3)\n");
        return;
    }

    //Criando no:
    ListaNo* novo = cria_no(v);

    //Caso 1: a lista esteja vazia:
    if (!l -> primeiro){
        lst_insere_inicio(l, v);
        return;
    }

    //Caso 2: inserir no inicio (menor que o primeiro):
    if (v < l -> primeiro -> info){
        lst_insere_inicio(l, v);
        return;
    }

    //Caso 3: Inserindo no meio:
    ListaNo* atual = l -> primeiro -> proximo;
    ListaNo* ant = l -> primeiro; //Ultimo no
    
    do {
        //Encontrando a posicao correta:
        if (v <= atual -> info){
            
            //Novo sera inserido entre ant e atual:
            novo -> proximo = atual;
            novo -> anterior = ant;

            //Mudando a referencia dos nos vizinhos:
            ant -> proximo = novo;
            atual -> anterior = novo;

            return;
        }

        //Passando adiante:
        ant = atual;
        atual = atual -> proximo;
    }while (atual != l -> primeiro);

    //Caso 4: Inserindo no final:
    lst_insere_final(l, v);
}

//Retira um valor do inicio da lista:
int lst_retira_inicio (Lista* l){
    //Verificando se a lista eh vazia ou invalida:
    if (!l || !l-> primeiro){
        printf("Lista vazia ou invalida (4)\n");
        return -1;
    }

    //Armazendo o vNo a ser retirado:
    ListaNo* retira = l -> primeiro;;
    
    //Caso tenha so um elemento:
    if (retira -> proximo == l -> primeiro){
        l -> primeiro = NULL;
        l -> ultimo = NULL;
    }else{
        //So um elemento:
        ListaNo* ultimo = l -> ultimo;
        ListaNo* segundo = retira -> proximo;

        //Novo primeiro:
        l -> primeiro = segundo;
        
        //Novo primeiro aponta para o ultimo:
        segundo -> anterior = ultimo;
        ultimo -> proximo = segundo;
    }

    //Removendo o antigo primeiro:
    free(retira);
    return 1;
}

//Retira um valor do final da lista:
int lst_retira_final (Lista* l){
    //Verificando se a lista eh vazia ou invalida:
    if (!l || !l-> primeiro){
        printf("Lista vazia ou invalida (4)\n");
        return -1;
    }

    //Armazendo o No a ser retirado:
    ListaNo* retira = l -> ultimo;

    //Caso tenha apenas um elemento:
    if (l-> ultimo == l -> primeiro){
        l -> primeiro = NULL;
        l -> ultimo = NULL;
    }else{
        //Mais de um elemento:
        ListaNo* penultimo = retira -> anterior;

        //Penultimo sera o novo ultimo:
        penultimo -> proximo = l -> primeiro;
        l -> primeiro -> anterior = penultimo;
        
        //Atualizando o ultimo da lista:
        l -> ultimo = penultimo;
    }

    //Removendo o antigo ultimo:
    free(retira);
    return 1;
}

//Libera a memoria alocada para a lista:
void lst_libera (Lista* l){
    //Caso a lista nao exista:
    if (!l){
        printf("Lista nao existe (8)\n");
        return;
    }

    //Verifcar se a lista eh vazia:
    if (!l -> primeiro){
        free(l);
        return;
    }

    //Caso a lista tenha elementos:
    if (l -> primeiro){
        ListaNo* atual = l -> primeiro;
        ListaNo* temp;

        //Percorrendo a lista e liberando os nos:
        do{
            temp = atual;
            atual = atual -> proximo;
            free(temp);

        }while (atual != l -> primeiro);
        
    }

    //Liberando a estrutura da lista:
    free(l);
}

//Imprime os valores da lista:
void lst_imprime (Lista* l){
    //Verificando se a lista existe:
    if (!l){
        printf("Lista nao existe (11)\n");
        return;
    }

    //Verificando se a lista esta vazia:
    if (!l -> primeiro){
        printf("Lista vazia (12)\n");
        return;
    }

    //Exibindo os valores:
    int i = 0;
    ListaNo* atual = l -> primeiro;
    while (1){
        printf("No %d || Valor = %d || Ant: %d || Prox: %d\n", i, atual -> info, atual -> anterior -> info, atual -> proximo -> info);
        atual = atual -> proximo;
        i++;

        //Verificando se ja percorreu toda a lista:
        if (atual == l -> primeiro){
            break;
        }
    }
}