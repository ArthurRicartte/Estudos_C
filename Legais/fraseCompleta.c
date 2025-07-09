#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

/*Criando funcao para pegar a frase e contar quantas letras do alfabeto apareceram*/
int analisandoLetras(const char *frase){
    /*Pegando as letras da frase*/
    bool letras[26] = {false}; //todas as letras comecam com falso (nao usadas)
    int contadorLetras = 0;

    /*Analisando quantas letras foram usadas*/
    for (int i = 0; frase[i] != '\0' ; i++){
        
        if (isalpha(frase[i])){
            
            char c = tolower(frase[i]); //coloca todo mundo como minusculo
            int index = c - 'a'; //usamos o 'a' como um padrao pois ele eh a primeira letra minuscula (menor valor) na tabela ascii
            if (letras[index] == false){
                letras[index] = true;
                contadorLetras++;
            }   
        }   
    }

    return contadorLetras;
}

int main (void){
    int casos;
    scanf("%d", &casos);

    char frase[1001];
    
    while (casos--){
        getchar();
        fgets(frase, sizeof(frase), stdin);

        /*Tirando o \n*/
        frase[strcspn(frase, "\n")] = '\0';

        /*Chamando a funcao que vai contar as letras da frase*/
        int contaLetras = analisandoLetras(frase);

        /*Classificando a frase*/
        if (contaLetras == 26){
            printf("frase completa\n");
        }

        else if (contaLetras >= 13){
            printf("frase quase completa\n");
        }
        
        else{
            printf("frase mal elaborada\n");
        }
    }
    
    return 0;
}