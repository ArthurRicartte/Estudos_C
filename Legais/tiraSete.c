#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void TiraSete(char *num, int size){
    for (int i = 0; i < size; i++){
        if (num[i] == '7'){
            num[i] = '0';
        }   
    }
    
}

int Operacao(char operacao, int numA, int numB){
    int resultado = 0;

    //Analisa a operacao
    switch (operacao)
    {
    case '+':
        return numA + numB;

    case '-':
        return numA - numB;
    
    case 'x':
        return numA * numB;
    
    default:
        return 0;
    }
}

int main(void){
    char a[6], b[6], resultadoStr[21];
    char sinal;
    
    scanf("%s %c %s", a, &sinal, b);

    //Transforma as strings em inteiros
    

    //Tirando o sete dos numeros digitados (se houver)
    TiraSete(a, strlen(a));
    TiraSete(b, strlen(b));
    
    //Determinar qual operacao quer fazer
    int resultado = Operacao(sinal, atoi(a), atoi(b));

    //sprintf -> pega resultado, tipo inteiro, e passa para a string resultadoStr
    sprintf(resultadoStr, "%d", resultado);
    TiraSete(resultadoStr, strlen(resultadoStr));

    printf("%d\n", atoi(resultadoStr)); //Nao deixa printar 02 04...
    
    return 0;
}