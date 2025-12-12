/*Repita as implementações do exercício anterior para uma matriz triangular
superior. Nota: é mais fácil alocar os elementos abaixo da diagonal, e usar o
acesso transposto aos elementos.
*/

#include <stdio.h>
#include <stdlib.h>

//Funcao necessaria para criar a matriz:
float ** Ti_Cria(int n){
    float **mat = (float**) malloc(sizeof(float *) * n);

    //alocar para cada linha:

    for (int i = 0; i < n; i++){
        mat[i] = (float*) malloc((n - i) * sizeof(float));

        //inicializa com zeros:
        for (int j = 0; j < n - i; j++){
                   
             mat[i][j] = 0.0f;    
            
        }
        
    }

    return mat;
    
}

//Atribuir valores para certa posicao da matriz:
void Ti_Atribuir(float** mat, int i, int j, float x){
    
    /*So interessa os valores da diagonal principal e acima dela:
    
    j - i -> nao eh possivel armazenar assim:     y
    nao tem como deixar um espaco em branco, tem que ser tudo em sequencia
    x y z... e nao x....y....z*/
    if (i <= j){
        mat[i][j - i] = x;
    }
    
}

//Acessar um valor especifico da matriz:
float Ti_acessa(float** mat, int i, int j){
    //Caso tente acessar os valores abaixo da diagonal principal -> retorna 0
    if (i > j){
        return 0.0f;
    }

    return mat[i][j - i];
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
        printf("Linha %d: ", i);
        
        //(nao interessa os valores abaixo da diagonal principal)
        for (int j = 0; j < n - i; j++){     
            printf("%6.1f", mat[i][j]);
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
    Ti_Atribuir(matriz, 0, 1, 1.5);
    Ti_Atribuir(matriz, 0, 2, 4.3);
    Ti_Atribuir(matriz, 1, 1, 5.3);
    Ti_Atribuir(matriz, 1, 2, 7.3);
    Ti_Atribuir(matriz, 2, 2, 1.3);
    
    //Exibindo resultados:
    Ti_Exibe(matriz, n);
    printf("\n");

    Ti_Exibe_Armazenados(matriz, n);
    return 0;
}