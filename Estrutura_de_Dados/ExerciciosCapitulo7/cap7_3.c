/*Escreva funções para lidar com matrizes triangulares inferiores de dimensão
n × n, onde todos os elementos abaixo da diagonal são iguais a zero e não
devem ser alocados. No entanto, um acesso a um elemento abaixo da
diagonal deve retornar o valor zero. Escreva as seguintes funções, usando a
estratégia de vetor de ponteiros para armazenar a matriz.
Função para criar uma matriz, onde n representa a dimensão da matriz,
inicialmente com os valores todos iguais a zero:

float ** ti_cria (int n);
Função para atribuir o valor de um elemento da matriz, assumindo que i
>= j:
void ti_atribui (int i, int j, float x);
Função para acessar o valor de um elemento da matriz, inclusive
elementos acima da diagonal:
float ti_acessa (int i, int j);
Função para liberar a memória da matriz alocada:
void ti_libera (int n, float ** mat);
Escreva uma função main para testar as funções implementadas..*/

#include <stdio.h>
#include <stdlib.h>

//Funcao necessaria para criar a matriz:
float ** Ti_Cria(int n){
    float **mat = (float**) malloc(sizeof(float *) * n);

    //alocar para cada linha:
    for (int i = 0; i < n; i++){
        mat[i] = (float*) malloc((i + 1) * sizeof(float));

        //inicializa com zeros:
        for (int j = 0; j <= i; j++){
            mat[i][j] = 0.0f;
        }
        
    }

    return mat;
    
}

//Atribuir valores para certa posicao da matriz:
void Ti_Atribuir(float** mat, int i, int j, float x){
    
    //So interessa os valores da diagonal principal e abaixo dela:
    if (i >= j){
        mat[i][j] = x;
    }
    
}

//Acessar um valor especifico da matriz:
float Ti_acessa(float** mat, int i, int j){
    //Caso tente acessar os valores acima da diagonal principal -> retorna 0
    if (i < j){
        return 0.0f;
    }

    return mat[i][j];
}

//Liberando o espaco alocado na memoria:
void Ti_libera(int n, float **mat){
    for (int i = 0; i < n; i++){
        free(mat[i]);
    }

    free(mat);
}

//Exibir a matriz completa:
void Ti_Exibe(float** mat, int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            printf("%6.1f", Ti_acessa(mat, i, j));
        }
        
        printf("\n");
    }
    
}

//Exibir os valores somente armazenados:
void Ti_Exibe_Armazenados(float** mat, int n){
    printf("Elementos armazenados:\n");

    for (int i = 0; i < n; i++){
        printf("Linha %d", i);
        
        //(nao interessa os valores acima da diagonal principal)
        for (int j = 0; j <= i; j++){ 
            printf("%6.1f", Ti_acessa(mat, i, j));
        }
        printf("\n");
    }
    
}

int main(void){

    //Criando variaveis:
    int n = 3;
    float ** matriz;

    printf("Matriz triangular %dx%d\n", n,n);
    
    //Inicializando a matriz
    matriz = Ti_Cria(n);

    Ti_Exibe(matriz, n);
    printf("\n");

    //Atrbuindo valores a matriz:
    Ti_Atribuir(matriz, 0, 0, 1.3);
    Ti_Atribuir(matriz, 1, 0, 1.5);
    Ti_Atribuir(matriz, 1, 1, 4.3);
    Ti_Atribuir(matriz, 2, 0, 5.3);
    Ti_Atribuir(matriz, 2, 1, 7.3);
    Ti_Atribuir(matriz, 2, 2, 1.3);
    
    //Exibindo resultados:
    Ti_Exibe(matriz, n);
    printf("\n");

    Ti_Exibe_Armazenados(matriz, n);
    return 0;
}