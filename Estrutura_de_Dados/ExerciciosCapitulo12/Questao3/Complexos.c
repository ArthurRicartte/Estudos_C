#include "Complexos.h"
#include <stdio.h>
#include <stdlib.h>

//Criando struct que representara os complexos:
struct complexo{
    double real;
    double imaginaria;
};


//Implementando funcao para criar numeros complexos:
Complexo* Criar_Complexo(double a, double b){
    Complexo* novo = (Complexo*) malloc(sizeof(Complexo));

    //Caso de error ao alocar memoria:
    if (!novo){
        printf("ERROR AO CRIAR COMPLEXO!");
        exit(1);
    }
    
    //Atribuindo valores:
    novo -> real = a;
    novo -> imaginaria = b;

    return novo;
}

//Implementando funcao para liberar complexo da memoria:
void Libera_Complexo(Complexo* coplx){
    free(coplx);
}

//Implementando funcao para somar dois numeros complexos:
Complexo* Sum_Complexo(Complexo* c1, Complexo* c2){
    //Verificando parametros:
    if(!c1 || !c2){
        printf("ERROR -> SOMA DE COMPLEXOS -> ALGO VAZIO\n");
        exit(1);
    }

    /*(a + bi) + (c + di) = (a + c) + (b + d)i
    Criando duas variaveis para guardar a parte real e imaginaria:*/
    double real = (c1 -> real) + (c2 -> real);
    double imaginaria = (c1 -> imaginaria) + (c2 -> imaginaria);

    //Retorno criar_complexo, passando real e imaginaria como parametros:
    return Criar_Complexo(real, imaginaria);
}

//Implementando funcao para subtrair dois numeros complexos:
Complexo* Sub_Complexo(Complexo* c1, Complexo* c2){
    //Verificando parametros:
    if(!c1 || !c2){
        printf("ERROR -> SUBTRACAO DE COMPLEXOS -> ALGO VAZIO\n");
        exit(1);
    }

    /*(a + bi) − (c + di) = (a − c) + (b − d)i
    Criando duas variaveis para guardar a parte real e imaginaria:*/
    double real = (c1 -> real) - (c2 -> real);
    double imaginaria = (c1 -> imaginaria) - (c2 -> imaginaria);

    //Retorno criar_complexo, passando real e imaginaria como parametros:
    return Criar_Complexo(real, imaginaria);
}

//Implementando funcao para multiplicar dois numeros complexos:
Complexo* Mult_Complexo(Complexo* c1, Complexo* c2){
    //Verificando parametros:
    if(!c1 || !c2){
        printf("ERROR -> MULTIPLICACAO DE COMPLEXOS -> ALGO VAZIO\n");
        exit(1);
    }

    //(a + bi)(c + di) = (ac − bd) + (bc + ad)i

    //Variaveis auxiliares:
    double a = c1 -> real;
    double b = c1 -> imaginaria;
    double c = c2 -> real;
    double d = c2 -> imaginaria;

    //Criando duas variaveis para guardar a parte real e imaginaria:
    double real = a * c - b * d;
    double imaginaria = b * c + a * d;

    //Retorno criar_complexo, passando real e imaginaria como parametros:
    return Criar_Complexo(real, imaginaria);
}

//Implementando funcao para dividir dois numeros complexos:
Complexo* Div_Complexo(Complexo* c1, Complexo* c2){    
    //Verificando parametros:
    if(!c1 || !c2){
        printf("ERROR -> DIVISAO DE COMPLEXOS -> ALGO VAZIO\n");
        exit(1);
    }

    //(a + bi) / (c + di) = [(ac + bd)/(c² + d²)] + [(bc - ad)/(c² + d²)]i

    //Variaveis auxiliares:
    double a = c1 -> real;
    double b = c1 -> imaginaria;
    double c = c2 -> real;
    double d = c2 -> imaginaria;

    double denominador = (c*c + d*d);

    //Verificando se existe algum error de divisao:
    if (denominador == 0){
        printf("ERROR! DENOMINADOR IGUAL A ZERO\n");
        exit(1);
    }
    
    //Criando duas variaveis para guardar a parte real e imaginaria:
    double real = (a * c + b * d) / denominador;
    double imaginaria = (b*c - a*d) / denominador;

    //Retorno criar_complexo, passando real e imaginaria como parametros:
    return Criar_Complexo(real, imaginaria);
}

//Exibir complexos:
void Exibir_Complexo(Complexo* c){
    if (!c){
        printf("Nada para exibir!");
        return;
    }

    printf("Parte real: %.2f\nParte imaginaria: %.2fi\n", c -> real, c -> imaginaria);
}
