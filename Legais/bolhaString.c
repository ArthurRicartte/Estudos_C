#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(void){

    int testes, trocou;
    char livros[1000][5], aux[5];

    while (scanf("%d", &testes) != EOF){

        for (int i = 0; i < testes; i++){ //leitura
            scanf("%s", livros[i]);
        }
        
        trocou = 1;
        while (trocou){
            trocou = 0;

            for (int j = 0; j < testes - 1; j++){ //ordenando
                
                if (atoi(livros[j]) > atoi(livros[j + 1])){
                    strcpy(aux, livros[j]);
                    strcpy(livros[j], livros[j + 1]);
                    strcpy(livros[j + 1], aux);
                    trocou = 1;
                }
                
            }
            
        }
        
        for(int k = 0; k < testes; k++){ //exibindo array de strings ordenados
            printf("%s\n", livros[k]);
        }

        
    }
    
    return 0;
}