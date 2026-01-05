#include "Alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Criando constantes:
#define CAPACIDADE_INCIAL 4

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

// Redimensiona o vetor de alunos:
void vet_redimensiona(Vetor* v){
    if(!v){
        return;
    }

    //Caso precise aumentar o tamanho:
    if(v -> cadastrados >= v -> limite){
        
        //Adiciona 1 para incluir o novo aluno:
        int necessario = v -> cadastrados + 1;
        
        //Aqui precisamos determinar o novo limite: se eh necessario ou o dobro do limite
        int novoLimite = (necessario > 2 * v -> limite) ? necessario : 2 * v -> limite;

        //Realocando:
        Aluno** novos_alunos = (Aluno**) realloc(v -> alunos, sizeof(Aluno*) * novoLimite);
        if (!novos_alunos){
            printf("ERROR AO REDIMENSIONAR VETOR DE ALUNOS (3)\n");
            exit(1);
        }

        //Alterando variaveis do vetor:
        v -> alunos = novos_alunos;
        v -> limite = novoLimite;
    }

    //Caso precise dimunuir o tamanho:
    else if (v -> cadastrados < (v -> limite / 2) && v -> limite > CAPACIDADE_INCIAL){
        int novaCapacidade = v -> limite / 2;

        //Garante uma capacidade minima:
        if (novaCapacidade < CAPACIDADE_INCIAL){
            novaCapacidade = CAPACIDADE_INCIAL;
        }

        //Garente que caiba todos os elementos:
        if (novaCapacidade >= v -> cadastrados){
            Aluno** temp = (Aluno**) realloc(v-> alunos, sizeof(Aluno*) * novaCapacidade);

            if (!temp){
                printf("ERROR AO REDIMENSIONAR VETOR DE ALUNOS (4)\n");
                exit(1);
            }

            //Realocando valores:
            v -> alunos = temp;
            v -> limite = novaCapacidade;
        }
    }
}

//Funcao que redimensiona o vetor pelo numero exato de cadastrados:
void vet_redimensiona_exato(Vetor* v){
    //Verificando incosistencias:
    if (!v || v -> cadastrados == v -> limite){
        return;
    }

    //Redimensionando de forma direta para a capacidade inicial:
    int novaCapacidade = v -> cadastrados;
    if (novaCapacidade < CAPACIDADE_INCIAL){
        novaCapacidade = CAPACIDADE_INCIAL;
    }

    Aluno** temp = (Aluno**) realloc(v -> alunos, sizeof(Aluno*) * novaCapacidade);
    
    v -> alunos = temp;
    v -> limite = novaCapacidade;
}

//Funcao para remover aluno por indice:
void vet_remove(Vetor* v, int i){
    //Verificando se i eh valido:
    if (i < 0 || i >= v -> cadastrados){
        printf("ERROR INDICE INVALIDO PARA REMOCAO (5)\n");
        exit(1); 
    }

    //Verificando se v eh valido:
    if (!v){
        printf("ERROR VETOR INVALIDO PARA REMOCAO (6)\n");
        exit(1);
    }

    //Liberando aluno da memoria:
    free(v -> alunos[i]);

    //Deslocando elementos para preencher o espaco vazio:
    for (int j = 0; j < v -> cadastrados - 1; j++){
        v -> alunos[j] = v -> alunos[j + 1];
    }
    
    //Decrementando o numero de cadastrados:
    v -> cadastrados--;

    //Verificando se precisa redimensionar:
    vet_redimensiona(v);
}

//Funcao para remover aluno por nome:
int vet_remove_nome(Vetor* v, const char* nome){
    //Vericando se os paramentros sao validos:
    if (!v || !nome){
        printf("ERROR PARAMETROS INVALIDOS PARA REMOCAO POR NOME (7)\n");
        exit(1);
    }

    //Procurando o aluno pelo nome:
    for (int i = 0; i < v -> cadastrados; i++){
        if (strcmp(v -> alunos[i] -> nome, nome) == 0){
            vet_remove(v, i);
            return 1;
        }    
    }

    return 0;
}

// Adiciona um aluno ao final do vetor (copia os dados)
void vet_adiciona(Vetor* v, Aluno* a){
    //Verificar se o numero de armazenados atingiu o limite:
    if (v -> cadastrados == v -> limite){
        vet_redimensiona(v);
    }

    //Aloca um novo aluno e copia os dados:
    Aluno* novo = (Aluno*) malloc(sizeof(Aluno)); //Necessario, pois caso algum valor de a mude na main, aqui vai mudar tambem
    if (!novo){
        printf("ERROR AO CRIAR NOVO ALUNO (8)");
        exit(1);
    }

    //Copiando dados:
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
    if (!v || i < 0 || i >= v -> cadastrados){
        printf("ERROR NADA PARA ACESSAR (9)\n");
        exit(1);
    }

    return v -> alunos[i];
}