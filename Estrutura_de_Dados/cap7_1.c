#include <stdio.h>
#include <stdlib.h>

//Funcao para limpar o buffer (pra mim eh bem mais facil)
void LimpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
    
}


float * Reverso(float *vetor, int size){
    //Criando vetor para retorno:
    float * reverse;
    reverse = (float*)malloc(size*sizeof(float));

    //Invertendo valores do vetor
    for (int i = 0; i < size; i++){
        int posReversa = size - i - 1;

        reverse[i] = vetor[posReversa];
    }
    
    return reverse;

}

//Funcao para armazenar valores em um vetor:
void Escrever(float *vetor, int size){
    for (int i = 0; i < size; i++){
        float num;
        
        printf("Digite o numero %d: ", i);
        scanf("%f", &num);
        LimpaBuffer();
        
        vetor[i] = num;
    }
    
}

int main(void){

    //Criando variaveis:
    float *vetor, *vetorReverso;
    int quantidade;

    printf("Digite quantos numeros voce deseja alocar: ");
    scanf("%d", &quantidade);
    LimpaBuffer();

    //Iniciando a alocacao dinamica:
    vetor = (float*) malloc(quantidade * sizeof(float));

    Escrever(vetor, quantidade);

    vetorReverso = Reverso(vetor, quantidade);

    printf("\n");

    //Exibindo resultados:
    printf("Vetor original: ");
    for (int i = 0; i < quantidade; i++)
    {   
        printf("%.2f ", vetor[i]);
    }
    
    printf("\n\n");

    printf("Vetor Reverso: ");
    for (int i = 0; i < quantidade; i++)
    {   
        printf("%.2f ", vetorReverso[i]);
    }
  
    //Limpando dados da memoria alocada
    free(vetor);
    free(vetorReverso);
}