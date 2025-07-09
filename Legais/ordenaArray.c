#include <stdio.h>

/*Funcao analisa se eh multiplo*/

void OrdenaArray(int array[], int size){
    for (int fixo = 0; fixo < size - 1; fixo++){
        /*(casos - fixo - 1) -> analisamos de 2 em 2, entao, nao precisa "ir" ate o ultimo termo do for
        Ex -> se o tamanho do array for 6:
        fixo vai ate o 5
        fixo = 0, dinamico vai ate o 4 (0\1 (dinamico = 0) - 1\2 (dinamico = 1) - 2\3 (dinamico = 2) - 3\4 (dinamico = 3) - 4/5 (dinamico = 4))
        fixo = 1, dinamico vai ate o 3 (0\1 (dinamico = 0) - 1\2 (dinamico = 1) - 2\3 (dinamico = 2) - 3\4 (dinamico = 3))
        */
        for (int dinamico = 0; dinamico < size - fixo - 1; dinamico++){
            
            if (array[dinamico] > array[dinamico + 1]){
                int auxiliar = array[dinamico];
                array[dinamico] = array[dinamico + 1];
                array[dinamico + 1] = auxiliar;
            }
            
        }
    }
}

int main(void){
    int casos;
    scanf("%d", &casos);

    int array[casos];
    int frequencia[2001] = {0}; /*A questao pediu valores entre 0 e 2000*/
    
    /*Addicionando valores np array*/
    for (int i = 0; i < casos; i++){
        scanf("%d", &array[i]);
        frequencia[array[i]]++;
        /*Signifca por exmplo que num array[5] = 1 4 3 3 2:
        frequencia[3] = 2*/
    }
    
    /*Ordenando array*/
    OrdenaArray(array, casos);

    /*Exibindo resultado*/
    for (int contador = 0; contador < casos; contador++){
        /*Para entrar no if o contador tem que ser 0 (primeiro loop -> nao tem sucessor) ou o sucessor != antecessor*/
        if (contador == 0 || array[contador] != array[contador - 1]){
            printf("%d apareceu %d vez(es).\n", array[contador], frequencia[array[contador]]);
        }
        
    }
   
    return 0;
}