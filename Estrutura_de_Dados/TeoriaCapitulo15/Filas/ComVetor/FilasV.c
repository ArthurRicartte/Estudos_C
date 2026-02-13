#include "FilasV.h"
#include <stdio.h>
#include <stdlib.h>

//Definindo tamanho inicial do vetor da fila
#define TAM_INICIAL 2

//Definindo um fator de crescimento para o vetor da fila
#define FATOR_CRESCIMENTO 2


//Criando tipo estruturado da fila:
struct fila{
    int* vet; //vetor de elementos
    int dim; //Tamanho limite atual da fila
    int ini; //Indice do inicio da filaint fim; //Indice do final da fila
    int armazenados; //Quantos foram armazenados
};

//Criando fila:
Fila* fila_cria (void){
    Fila* f = (Fila*) malloc (sizeof(Fila));

    //Verificando se a alocacao foi bem sucedida:
    if (f == NULL){
        printf("Erro de alocacao de memoria!(1)\n");
        exit(1);
    }

    //Definindo informacoes iniciais:
    f -> dim = TAM_INICIAL; 
    f -> ini = 0;
    f -> armazenados = 0;
    f -> vet = (int*) malloc (f -> dim * sizeof(int));

    //Verificando se a alocacao do vetor foi bem sucedida:
    if (f -> vet == NULL){
        printf("Erro de alocacao de memoria!(2)\n");
        exit(1);
    }

    return f;
}

//Insere elemento no final da fila:
void fila_insere (Fila* f, int v){
    //Verificando se a fila eh inexistente:
    if (f == NULL){
        printf("Fila inexistente! Impossivel inserir elemento (3).\n");
        exit(1);
    }

    //Verificando se a fila esta cheia:
    if (f -> armazenados == f -> dim){
        //Aumento a dimensao do vetor:
        f -> dim *= FATOR_CRESCIMENTO;
        f -> vet = (int*) realloc (f -> vet, f -> dim * sizeof(int));
        
        if (f -> vet == NULL){
            printf("Erro de realocacao de memoria!(4)\n");
            exit(1);
        }
    }

    //Inserindo o elemento no final da fila:
    int fim = (f-> ini + f->armazenados) % f-> dim;
    f-> vet[fim] = v;
    f->armazenados++;
}

//Remove elemento do inicio da fila:
int fila_retira (Fila* f){
    //Verificando se esta vazia:
    if (fila_vazia(f)){
        printf("Fila vazia! Impossivel retirar elemento (5).\n");
        exit(1);
    }

    int v = f -> vet[f -> ini];
    f -> ini = (f -> ini + 1) % f -> dim;
    f -> armazenados--;
    return v;
}

//Fila vazia?
int fila_vazia (Fila* f){
    return (f -> armazenados == 0);
}

//Exibir fila:
void exibir_fila(Fila* f){
    //Verificar se a Fila existe:
    if (f == NULL){
        printf("Fila nao existe ! (6)\n");
    }

    //Exibindo lista:
    for (int i=0; i< f->armazenados; i++){
        printf("indice %d || Elemento = %d\n",i, f-> vet[i]);
    }

}

//Liberando a fila:
void fila_libera (Fila* f){
    free (f -> vet);
    free (f);
}
