#include "Lde.h"
#include <stdio.h>

//Esse teste eu tirei do livro:
int main(void){
    Lista* l = lst_cria(); 
    Lista* l2 = lst_cria();
    Lista* l3 = lst_cria();
    
    printf("Inserindo valores ordenadamente:\n");
    lst_insere_ordenado(l, 23); 
    lst_insere_ordenado(l, 45); 
    lst_insere_ordenado(l, 56); 
    lst_insere_ordenado(l, 78); 
    
    printf("Primeiro teste:\n");
    lst_imprime(l); 
    
    lst_retira(l, 78);
    
    printf("Segundo teste:\n");
    lst_imprime(l); 

    printf("Terceiro teste:\n");
    lst_retira(l, 45);
    lst_imprime(l); 

    printf("\n\nLista 2 - Inserindo no inicio:\n");
    lst_insere_inicio(l2, 13); 
    lst_insere_inicio(l2, 8); 
    lst_insere_inicio(l2, 7); 
    lst_insere_inicio(l2, 20); 
    
    printf("Primeiro teste:\n");
    lst_imprime(l2); 
    
    lst_retira(l2, 7);
    
    printf("Segundo teste:\n");
    lst_imprime(l2); 

    printf("Terceiro teste:\n");
    lst_retira(l2, 13);
    lst_imprime(l2);
   
    printf("\n\nLista 3 - Inserindo no final:\n");
    lst_insere_fim(l3, 19); 
    lst_insere_fim(l3, 22); 
    lst_insere_fim(l3, 81); 
    lst_insere_fim(l3, 25); 
    
    printf("Primeiro teste:\n");
    lst_imprime(l3); 
    
    lst_retira(l3, 7);
    
    printf("Segundo teste:\n");
    lst_imprime(l3); 

    printf("Terceiro teste:\n");
    lst_retira(l3, 19);
    lst_imprime(l3);
    
    printf("Liberando listas...\n");
    lst_libera(l);
    lst_libera(l2);
    lst_libera(l3);

    return 0;
}