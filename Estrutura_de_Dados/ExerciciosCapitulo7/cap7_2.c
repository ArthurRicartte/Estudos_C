/*Escreva uma função que receba um vetor de inteiros e tenha como valor de
retorno um novo vetor, alocado dinamicamente, apenas com os elementos
pares do vetor original. A função deve ter como valor de retorno o ponteiro
do vetor alocado e preencher o endereço de memória passado com a
dimensão do novo vetor, seguindo o protótipo:
int * somente_pares (int n, int * v, int * npares);
Faça uma função main para testar sua função. Na função main, não esqueça
de liberar a memória alocada pela função auxiliar.*/

#include <stdio.h>
#include <stdlib.h>

int *NumPares(int *vetor, int size, int* npares){
    int* SoPares;
    int contPar = 0;

    for (int i = 0; i < size; i++){
        if (vetor[i] % 2 == 0){
            contPar++;
        }    
    }

    
    //Verificando se existem numeros pares:
    if (contPar == 0){
        return NULL;
    }

    //Alocando memoria dinamicamente para o vetor Sopares:
    *npares = contPar;
    SoPares = (int*) malloc(sizeof(int) * contPar);

    //Adicionando pares no vetor:
    int indicePares = 0;
    for (int i = 0; i < size; i++){
        if (vetor[i] % 2 == 0){
            SoPares[indicePares] = vetor[i];
            indicePares++;
        }    
    }
    
    return SoPares;
}

//Funcao para Escrever numeros no vetor:
void Escrever(int *vetor, int size){
    for (int i = 0; i < size; i++)
    {
        printf("Numero %d: ", i);
        scanf("%d", & vetor[i]);
    }
    
}

//Funcao para exibir numeros:
void Exibir(int *vetor, int size){
    for (int i = 0; i < size; i++)
    {
        printf("Numero %d: %d\n", i, vetor[i]);
    }
    
}

int main(void){

    //Definindo variaveis:
    int qtdnumeros;
    int *numeros, *pares, qtdPares;

    printf("Digite a quantidade de numeros: ");
    scanf("%d", &qtdnumeros);

    numeros = (int*) malloc(sizeof(int) * qtdnumeros);
    
    //Passar numeros e qtdnumeros para preencher o array:
    Escrever(numeros, qtdnumeros);
    pares = NumPares(numeros, qtdnumeros, &qtdPares);
    printf("\n\n");
    
    //Exibindo resultados:
    Exibir(numeros, qtdnumeros);
    
    printf("Numeros pares:\n");
    
    if (pares != NULL && qtdPares > 0){
        Exibir(pares, qtdPares);
    }else{
        printf("Nao ha numeros pares!\n");
    }
    
    //Desalocando da memoria:
    free(numeros);
    
    if (pares != NULL){
        free(pares);
    }

    return 0;
}