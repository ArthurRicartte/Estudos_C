#include<stdio.h>
#include<math.h>

void contPar(int vetor[], int size){

    int cont = 1;
    for (int i = 0; i < size / 2; i++){
        int temp = vetor[i];
        vetor[i] = vetor[size - cont];
        vetor[size - cont] = temp;

        cont++;
    }

    for(int i = 0; i < size; i++){
        printf("%d\n", vetor[i]);
    }
}


int main (void){

    int numeros[] = {1,2,3,4,5};

    
    contPar(numeros, 5);
    
    return 0;
}