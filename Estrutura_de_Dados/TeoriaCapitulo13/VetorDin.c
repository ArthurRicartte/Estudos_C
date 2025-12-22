#include "VetorDin.h"
#include<stdio.h>
#include<stdlib.h>

//Definindo um fator de aumento e capacidade inicial:
#define CAPCIDADE_INICIAL 4
#define FATOR_AUMENTO 2

//Criando struct para armazenar dinamicamente os valores:
struct vetordin{
    float* elementos; //elementos armazenados
    int tamanho; //quantidade de elementos armazenados
    int capacidade; //qual a capacidade max que pode armazenar
};

//Cria vetor:
VetorDin* vd_cria (void ){
    VetorDin* vd = (VetorDin*) malloc(sizeof(VetorDin));

    //Verificando se o vetor foi criado:
    if (!vd){
        printf("ERROR AO ALOCAR MEMORIA (1)\n");
        exit(1);
    }

    //Alocando tamanho inicial para os elementos:
    vd -> elementos = (float*) malloc(CAPCIDADE_INICIAL * sizeof(float));

    //Verificando se foi criado:
    if (vd -> elementos == NULL){
        printf("ERROR AO ALOCAR ESPACO PARA ELEMENTOS (2)\n");
        free(vd);
        exit(1);
    }

    //Inicializando vetor
    vd -> capacidade = CAPCIDADE_INICIAL;
    vd -> tamanho = 0;

    return vd;
}

//Insere um valor:
void vd_insere ( VetorDin* vd , float x){
    //Verificar se precisa realocar:
    if (vd -> tamanho == vd -> capacidade){
        //Criando nova capacidade:
        int novaCapacidade = vd -> capacidade * FATOR_AUMENTO;
        
        //Realocando memoria para o novo computador
        float* novo = (float*)realloc(vd -> elementos, novaCapacidade * sizeof(float));

        //Verificando se ha erros:
        if (novo == NULL){
            printf("ERROR ao tentar realocar memoria (4)\n");
            exit(1);
        }

        //Alterando elementos e capacidade 
        vd -> elementos = novo;
        vd -> capacidade = novaCapacidade;

        printf("Vetor realocado! nova capacidade: %d\n", vd -> capacidade);
    }
    
    //Adicionando x ao final do vetor
    vd -> elementos[vd -> tamanho] = x;
    vd -> tamanho++;
}


//Retorna o valor:
int vd_tam ( VetorDin* vd){
    return vd -> tamanho;
}

//Acessa algum valor no vetor:
float vd_acessa ( VetorDin* vd , int i){
    //Verificar se esta vazio ou se o indice eh valido:
    if (!vd || i < 0 || i >= vd -> tamanho){
        printf("ERROR NADA PARA ACESSAR (5)\n");
        exit(1);
    }

    //Retornar elemento desejado:
    return vd -> elementos[i];
}

//Libera memoria do vetor:
void vd_libera ( VetorDin* vd){
    free(vd -> elementos);
    free(vd);
}