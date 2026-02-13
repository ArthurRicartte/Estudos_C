#include "pilhaV.h"
#include <stdio.h>
#include <stdlib.h>

//Definindo tamanho inicial do vetor da pilha
#define TAM_INICIAL 2

//Definindo um fator de crescimento para o vetor da pilha
#define FATOR_CRESCIMENTO 2

//Definindo estrutura da pilha
struct pilha{
    float* vet; //vetor de elementos
    int dim; //Tamanaho limite atual da pilha
    int tam; //tamanho do vetor (Elementos alocados)
};

//Criando Pilha:
Pilha* pilha_cria (void ){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    //Verificnado se a alocacao foi bem sucedida:
    if (p == NULL){
        printf("Erro de alocacao de memoria!(1)\n");
        exit(1);
    }

    p -> dim = TAM_INICIAL;
    p -> tam = -1; //pilha vazia
    p -> vet = (float*) malloc(p -> dim * sizeof(float));

    //Verificando se a alocacao de vet foi bem sucedida:
    if (p -> vet == NULL){
        printf("Erro de alocacao de memoria!(2)\n");
        exit(1);
    }

    return p;
}

//Inserindo elemento no topo da pilha:
void pilha_push (Pilha* p, float v){
    //Verificando se a pilha existe:
    if (p == NULL){
        printf("Pilha nao existe! (3)\n");
        exit(1);
    }

    //Verificando se a pilha esta cheia:
    if (pilha_cheia(p)){
        //Redimensionando o vetor da pilha:
        p -> dim *= FATOR_CRESCIMENTO;
        p -> vet = (float*) realloc(p->vet, p -> dim * sizeof(float));

        //Verificando se a realocacao foi bem sucedida:
        if (p -> vet == NULL){
            printf("Erro de alocacao de memoria!(4)\n");
            exit(1);
        }
    }

    p -> tam++;
    p -> vet[p -> tam] = v;
}

//Removendo elemento do topo da pilha:
float pilha_pop (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL){
        printf("Pilha nao existe! (5)\n");
        exit(1);
    }

    //Guardando o valor a ser removido:
    float v = p -> vet[p -> tam];
    p -> tam--;
    return v;
}

//Pilha cheia?
int pilha_cheia (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL){
        printf("Pilha nao existe! (6)\n");
        exit(1);
    }

    return p -> tam == p -> dim - 1;
}

//Pilha vazia?
int pilha_vazia (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL){
        printf("Pilha nao existe! (6)\n");
        exit(1);
    }

    return p -> tam == -1;
}

//Exibir pilha:
void pilha_exibe (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL){
        printf("Pilha nao existe! (7)\n");
        exit(1);
    }

    printf("Pilha: ");
    for (int i = p -> tam; i >= 0; i--){
        printf("%.2f ", p -> vet[i]);
        if (i != 0) printf("-> ");
    }
    printf("\n");
}

//Liberando a pilha:
void pilha_libera (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL){
        printf("Pilha nao existe! (7)\n");
        exit(1);
    }

    free(p -> vet);
    free(p);
}