#include "Matriz.h"
#include <stdio.h>
#include <stdlib.h>

struct matriz
{
    int linha;
    int coluna;
    float **dados;
};

//Criar matriz
Matriz* mat_cria (int m, int n){
    Matriz* mat = (Matriz*) malloc(sizeof(Matriz));
    
    //Caso a alocacao de error
    if (!mat){
        printf("ERROR DE ALOCACAO DE MEMORIA\n");
        exit(1);
    }

    //Adicionando valores de linha e coluna
    mat -> linha = m;
    mat -> coluna = n;

    //Alocar o vetor de ponteirps para as linha da matriz:
    mat -> dados = (float**) malloc(m * sizeof(float*));
    if (mat-> dados == NULL){
        printf("ERROR AO ALOCAR MEMORIA PARA LINHHAS\n");
        free(mat);
        exit(1);
    }

    //Alocar cada espaço de uma linha:
    for (int i = 0; i < m; i++){
        mat -> dados[i] = (float*) malloc(n * sizeof(float));

        if(mat -> dados[i] == NULL){
            printf("ERROR AO ALOCAR ESPACO PARA CADA VALOR\n");

            //libera o que ja foi alocado antes de sair:
            for (int j = 0; j < i; j++){
                free(mat -> dados[j]);
            }

            free(mat->dados);
            free(mat);
            exit(1);
        }

        //Vamos inicializar tudo com zero:
        for (int j = 0; j < n; j++){
            mat -> dados[i][j] = 0.0f;
        }   
    }

    return mat;   
}

void mat_libera ( Matriz* mat){
    //Caso mat seja null
    if (mat != NULL){
        //Vamos ter que liberar cada linha:
        if (mat -> dados != NULL){
            
            for (int i = 0; i < mat -> linha; i++){
            
                if (mat -> dados[i] != NULL){
                    free(mat -> dados[i]);
                }
            }

            free(mat -> dados);
        }
        
        //Libera a estrutura principal:
        free(mat);
    }

}

float mat_acessa ( Matriz* mat, int i, int j){
    //Verificando se exise algum error nos indices:
    if (i < 0 || i >= mat -> linha || j < 0 || j >= mat -> coluna){
        printf("ERROR AO ACESSAR VALORES DA MATRIZ\n");
        return 0.0f;
    }
    
    return mat -> dados[i][j];  
}

void mat_atribui ( Matriz* mat, int i, int j, float v){
    //Verificar se a matriz esta vazia:
    if (mat -> dados == NULL){
        printf("NAO HA NENHUM VALOR!\n");
        exit(1);
    }

    //Verificar se os inidices sao corretos:
    if (i < 0 || i >= mat -> linha || j < 0 || j >= mat -> coluna){
        printf("INDICES INVALIDOS\n");
        exit(1);
    }
    
    //Tudo esta correto:
    mat -> dados[i][j] = v;
}

//Retornar quantidade de linhas:
int mat_linhas ( Matriz* mat){
    return mat -> linha;
}

//Retornar quantidade de colunas:
int mat_colunas (Matriz* mat){
    return mat -> coluna;
}

//Gerando matriz transposta:
Matriz* mat_transposta(Matriz* mat){
    //Pega informacoes da matriz:
    int linhas = mat_linhas(mat);
    int colunas = mat_colunas(mat);

    //Cria matriz transposta:
    Matriz* transposta = mat_cria(colunas, linhas);

    //Preencher transposta:
    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            float valor = mat_acessa(mat, i, j);
            mat_atribui(transposta, j, i, valor);
        }
        
    }

    return transposta;
}

//Exibir valores:
void mat_exibir(Matriz* mat){
    for (int i = 0; i < mat -> linha; i++){
        for (int j = 0; j < mat -> coluna; j++){
            printf("%6.1f", mat_acessa(mat, i, j));
        }
        printf("\n");
    }
}