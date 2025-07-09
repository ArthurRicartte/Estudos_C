#include <stdio.h>
#include <string.h>

typedef struct {
    int ano;
    int mes;
    int dia;
}Nascimento;



typedef struct{
        char nome[50];
        int idade;
        Nascimento nascido;
        float peso;
        float altura;
} Pessoa;

int main(void){

    Pessoa p = {"junin", 1212, {1023, 1, 13}, 78, 7.6};

    printf("%s", p.nome);
   
    
    return 0;
}
