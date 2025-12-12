/*Escreva:
Uma função para converter uma matriz representada por um vetor numa
matriz representada por um vetor de ponteiros:
float ** converte_a (int m, int n, float * mat);
Uma função para converter uma matriz representada por um vetor de
ponteiros numa matriz representada por um vetor:
float * converte_b (int m, int n, float ** mat);
*/

#include <stdio.h>
#include <stdlib.h>

//Funcao que converte um vetor em um vetor de ponteiros:
float** Converte_a(int m, int n, float* mat){
    //Inciando a alocacao dinamica:
    float ** matriz = (float**) malloc(sizeof(float*) * m);

    //Inicializando a alocacao em cada espaco do vetor (Alocacao da alocacao):
    for (int i = 0; i < m; i++){
        matriz[i] = (float*) malloc(sizeof(float) * n); 

        for (int j = 0; j < n; j++){
            /*
                i * n + j -> como esta tudo de forma linear no vetor, essa eh a logica para pegar o valor certo para a posicao da matriz:
                m[0][0] = mat[0 * 3 + 0]
                m[0][1] = mat[0 * 3 + 1]
                ...
            */                       
           
            matriz[i][j] = mat[i * n + j];
        }   
    }

    return matriz;
}

//Funcao que converte um vetor de ponteiros em um vetor:
float* Converte_b(int m, int n, float** mat){
    float* matriz;
    matriz = (float*) malloc(sizeof(float) * m*n);
  
    //Realizando a logica invera do converte_A:
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            matriz[i * n + j] = mat[i][j];
        }  
    }
    
    return matriz;
}

//Funcao para exibir a matriz A:
void Exibir_MatrizA(int m, int n, float** mat){
   for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%6.1f", mat[i][j]);
        }  
        printf("\n");
    }
    printf("\n");
}

//Funcao para exibir a matriz B:
void Exibir_MatrizB(int m, int n, float* mat){
   printf("Valores:");
    for (int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            printf("%6.1f", mat[i * n + j]);
        }      
    }
}

int main(void){

    //Definindo variaveis:
    float** mat_a;
    float* mat_b;
    float matriz[9] = {1.1, 1.2, 1.3, 2.1, 2.2, 2.3,3.1, 3.2, 3.3,};

    //Converter uma matriz representada por um vetor de ponteiros numa matriz representada por um vetor:
    mat_a = Converte_a(3, 3, matriz);
    mat_b = Converte_b(3,3, mat_a);
    
    //Exibindo resultados:
    printf("Vetor -> Vetor de ponteiros:\n");
    Exibir_MatrizA(3,3, mat_a);

    printf("Vetor de ponteiros -> Vetor:\n");
    Exibir_MatrizB(3,3, mat_b);
    return 0;
}