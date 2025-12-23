#include "Alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando constantes:
#define CAPACIDADE_INCIAL 4
#define FATOR_CRESCIMENTO 2

struct vetor{
    Aluno** alunos;
    int cadastrados;
    int limite;
};


// Cria um vetor vazio
Vetor* vet_cria(void){
    //Criando um vetor
    Vetor* novo = (Vetor*) malloc(sizeof(Vetor));
    if (!novo){
        printf("ERROR AO CRIAR VETOR DE ALUNOS (1)\n");
        exit(1);
    }

    //Atribuir valores iniciais a novo:
    novo -> cadastrados = 0;
    novo -> limite = CAPACIDADE_INCIAL;
    novo -> alunos = (Aluno**) malloc(sizeof(Aluno*) * novo -> limite);

    //Verificando se deu tudo certo:
    if (!novo -> alunos){
        printf("ERROR NAO FOI POSSIVEL CRIAR ESPACO PARA ALUNOS (2)\n");
        free(novo);
        exit(1);
    }

    return novo;
}

// Libera a memória do vetor e dos alunos armazenados
void vet_libera(Vetor* v){
    //Verficando se o vetor tem algo:
    if(v -> alunos != NULL){
        for (int i = 0; i < v -> cadastrados; i++){
            free(v -> alunos[i]); //libera um aluno por vez
        }
    }

    free(v -> alunos); //Libera array de ponteiros
    free(v); //Libera o vetor
}

// Adiciona um aluno ao final do vetor (copia os dados)
void vet_adiciona(Vetor* v, Aluno* a){
    //Verificar se o numero de armazenados atingiu o limite:
    if (v -> cadastrados == v -> limite){
        v -> limite = v -> limite * FATOR_CRESCIMENTO;

        //Realocando memoria:
        v->alunos = (Aluno**)realloc(v->alunos, v->limite * sizeof(Aluno*));

        if (!v -> alunos){
            printf("ERROR NO DIRECIONAMENTO (3)\n");
            exit(1);
        }
        
    }

    //Aloca um novo aluno e copia os dados:
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno));
    if (!novo){
        printf("ERROR AO CRIAR NOVO ALUNO (4)");
        exit(1);
    }

    strcpy(novo -> nome, a -> nome);
    novo->p1 = a->p1;
    novo->p2 = a->p2;
    novo->p3 = a->p3;
    
    v -> alunos[v -> cadastrados] = novo;
    v -> cadastrados++;
}

// Retorna o número de alunos no vetor
int vet_tamanho(Vetor* v){
    return v -> cadastrados;
}

// Retorna o aluno na posição i
Aluno* vet_acessa(Vetor* v, int i){
    //Verficar se v esta vazio ou se i ehhh valido:
    if (!v || i < 0 || i > v -> cadastrados){
        printf("ERROR NADA PARA ACESSAR (5)\n");
        exit(1);
    }

    return v -> alunos[i];
}