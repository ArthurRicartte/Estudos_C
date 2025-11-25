#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 50 //definindo um tamanho limite para os nomes

void LimpaBuffer(){
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
       
}
void Inicio(char **nomes, int n){
    char entrada[SIZE];
    int tamanho = 0;

    for (int i = 0; i < n; i++){
        printf("Nome %d: ", i);
        fgets(entrada, SIZE, stdin);

        //Substituindo \n por \0
        entrada[strcspn(entrada, "\n")] = '\0';

        //Colando o nome digitado para o vetor
        tamanho = strlen(entrada);
        nomes[i] = (char*) malloc((tamanho + 1) * sizeof(char)); // (char) -> aqui vamos guardar um nome, por isso nao precisa do "*"
        strcpy(nomes[i], entrada);

    }

}

void Escrever(char **nomes, int n){
    for (int i = 0; i < n; i++)
    {
        printf("%s\n", nomes[i]);
    }
    
}
int main(void){
    
    //Criacao de variaveis
    char **nomes;
    int quantidade_nomes;

    printf("Quantidade de Strings:");
    scanf("%d", &quantidade_nomes);
    LimpaBuffer();

    //Criando a alocacao dinamica (char**) -> serve como um casting de memoria
    nomes = (char**) malloc(quantidade_nomes * sizeof(char*)); //aqui eh importante char*, pois eh um vetor que vai apontar para outro vetor (bidimensional) e nao para um unico caractere
    Inicio(nomes, quantidade_nomes);
    Escrever(nomes, quantidade_nomes);

    //Desalocando memoria:
    for(int i = 0; i < quantidade_nomes; i++){
        free(nomes[i]);
    }
    free(nomes);

    return 0;
}