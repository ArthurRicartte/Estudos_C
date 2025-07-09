#include <stdio.h>
#include <string.h>

/*Funcao qque vai analisar se eh ou nao vogal*/
int EhVogal(char letra){
    return (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u');
}

int main (void){
    char risada[51];
    char vogais[51];
    int pos = 0;

    /*Lendo risada digitada*/
    fgets(risada, sizeof(risada), stdin);

    /*Remove o \n*/
    risada[strcspn(risada, "\n")] = '\0';

    /*Pegando as vogais*/
    for (int i = 0; risada[i] != '\0'; i++){
        if (EhVogal(risada[i])){
            vogais[pos++] = risada[i];
        }  
    }

    vogais[pos] = '\0'; //a pos apos a ultima letra da risada eh o \0
    
    int len = strlen(vogais);
    int engracado = 1;

    /*Analisando se a sequencia de vogais ehh engracada -> analisa ate a metade
    pois como analisamos de 2 em 2, uma hora vai se repetir*/
    for (int i = 0; i < len / 2; i++){
        if (vogais[i] != vogais[len - 1 - i]){
            engracado = 0;
            break;
        }
    }
    
    printf("%s\n", engracado? "S" : "N");

    return 0;
}