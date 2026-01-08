#include "ListasCirculares.h"
#include <stdio.h>

//Esse teste eu tirei do livro:
int main(void){
    Lista* l = lst_cria(); 
    
    lst_insere(l, 23); 
    lst_insere(l, 45); 
    lst_insere(l, 56); 
    lst_insere(l, 78); 
    
    printf("Primeiro teste:\n");
    lst_imprime(l); 
    
    lst_retira(l, 78);
    
    printf("Segundo teste:\n");
    lst_imprime(l); 

    printf("Terceiro teste:\n");
    lst_retira(l, 45);
    lst_imprime(l); 
    
    lst_libera(l);
    
    return 0;
}