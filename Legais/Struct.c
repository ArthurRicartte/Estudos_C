#include <stdio.h>
#include <string.h>

typedef struct{
        char nome[50];
        int idade;
        float peso;
        float altura;
} Pessoa;

int main(void){

    Pessoa pessoas[3];

    for (int i = 0; i < 3; i++){
        printf("Digite os dados da pessoa %d\n", i + 1);

        printf("Nome: ");
        fgets(pessoas[i].nome, 50, stdin); //leitura do nome da pessoa
        pessoas[i].nome[strcspn(pessoas[i].nome, "\n")] = '\0'; //subistituindo o \n por \0

        printf("Idade: ");
        scanf("%d", &pessoas[i].idade);

        printf("Peso: ");
        scanf("%f", &pessoas[i].peso);

        
        printf("Altura: ");
        scanf("%f", &pessoas[i].altura);

        getchar(); //Limpeza do Buffer
        printf("\n");
    }

    printf("Exibindo dados:\n");
    for (int i = 0; i < 3; i++){
        printf("Pessoa %d\n", i + 1);
        printf("Nome: %s\n", pessoas[i].nome);
        printf("Idade: %d\n", pessoas[i].idade);
        printf("Nome: %.2f\n", pessoas[i].peso);
        printf("Nome: %.2f\n", pessoas[i].altura);
        printf("\n");
    }
    
    return 0;
}
