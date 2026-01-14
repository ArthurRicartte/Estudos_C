#include "Heterogeneas.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Desenvolvendo as estruturas:
//Temos tres figuras geometricas:
struct retangulo {
    float base;
    float altura;
};

struct triangulo {
    float base;
    float altura;
}; 

struct circulo {
    float raio;
};

//Serve para identificar o tipo da figura:
enum tipo {
    RETANGULO,
    TRIANGULO,
    CIRCULO
};

//No:
struct listanohet{
    Tipo tipo;
    void* info;
    ListaNoHet* prox;
};

//Lista de Nos:
struct listahet {
    ListaNoHet* cabeca;
};

//Criar Lista:
ListaHet* cria_lista(){
    //Tentando alocar a lista:
    ListaHet* lista = (ListaHet*) malloc (sizeof(ListaHet));
    if (!lista){
        printf("Error: Nao foi possivel alocar a lista! (1)\n");
        return NULL;
    }

    //Atribuindo informacoes:
    lista -> cabeca = NULL;
    return lista;
}

//Funcao para criar um retangulo;
ListaNoHet* cria_ret(float b, float h){
    //Alocando figura:
    Retangulo* ret = (Retangulo*) malloc (sizeof(Retangulo));

    //Caso algum erro ocorra:
    if (!ret){
        printf("Error: Nao foi possivel alocar o retangulo! (2)\n");
        return NULL;
    }

    //Atribuindo valores para o retangulo:
    ret -> base = b;
    ret -> altura = h;

    //Alocando No:
    ListaNoHet* no = (ListaNoHet*) malloc (sizeof(ListaNoHet));

    //Caso nao seja possivel alocar o No:
    if (!no){
        printf("Error: Nao foi possivel alocar o No! (3)\n");
        free(ret);
        return NULL;
    }

    //Inserindo informacoes no No:
    no -> tipo = RETANGULO;
    no -> info = ret;
    no -> prox = NULL;

    return no;
}

//Funcao para criar um triangulo;
ListaNoHet* cria_tri(float b, float h){
    //Alocando figura:
    Triangulo* tri = (Triangulo*) malloc (sizeof(Triangulo));

    //Caso algum erro ocorra:
    if (!tri){
        printf("Error: Nao foi possivel alocar o triangulo! (4)\n");
        return NULL;
    }

    //Atribuindo valores para o triangulo:
    tri -> base = b;
    tri -> altura = h;

    //Alocando No:
    ListaNoHet* no = (ListaNoHet*) malloc (sizeof(ListaNoHet));

    //Caso nao seja possivel alocar o No:
    if (!no){
        printf("Error: Nao foi possivel alocar o No! (5)\n");
        free(tri);
        return NULL;
    }

    //Inserindo informacoes no No:
    no -> tipo = TRIANGULO;
    no -> info = tri;
    no -> prox = NULL;

    return no;
}

//Funcao para criar um circulo;
ListaNoHet* cria_circ(float r){
    //Alocando figura:
    Circulo* circ = (Circulo*) malloc (sizeof(Circulo));

    //Caso algum erro ocorra:
    if (!circ){
        printf("Error: Nao foi possivel alocar o circulo! (6)\n");
        return NULL;
    }

    //Atribuindo valor do raio para o circulo:
    circ -> raio = r;

    //Alocando No:
    ListaNoHet* no = (ListaNoHet*) malloc (sizeof(ListaNoHet));

    //Caso nao seja possivel alocar o No:
    if (!no){
        printf("Error: Nao foi possivel alocar o No! (7)\n");
        free(circ);
        return NULL;
    }

    //Inserindo informacoes no No:
    no -> tipo = CIRCULO;
    no -> info = circ;
    no -> prox = NULL;

    return no;
}

//Funcao para inserir um No no inicio da lista:
void insere_inicio(ListaHet* lista, ListaNoHet* no){
    //Verificar se a lista existe:
    if (!lista){
        printf("Error: Lista nao existe! (8)\n");
        return;
    }

    //Verificar se o No existe:
    if (!no){
        printf("Error: No nao existe! (9)\n");
        return;
    }

    //Mudar os ponteiros:
    no -> prox = lista -> cabeca;
    lista -> cabeca = no;
}

//Criando funcao que vai auxiliar na liberacao do no:
void libera_no(ListaNoHet* no){
    //Caso o no nao exista:
    if (!no){
        printf("No inexistente (10)\n");
        return;
    }

    //Caso no tenha alguma informacao:
    if (no -> info){
        free(no -> info);
    }

    free(no);
}

//Criando a funcao principal de liberacao:
int remove_no(ListaHet* lista, ListaNoHet* no){
    //Primeiro, vamos verificar se a lista e/ou o no eh vazio:
    if (!lista || !no || !lista -> cabeca){
        printf("Impossivel remover um no (11)");
        return 0; //falhou
    }

    //Caso 1: remover a cabeca:
    if (no -> info == lista -> cabeca){
        lista -> cabeca = no -> prox;
        libera_no(no);
        return 1; //sucesso!
    }

    //Caso 2: procurar o no meio da lista:
    ListaNoHet* ant = NULL;
    ListaNoHet* atual = lista -> cabeca;
    
    while (atual != NULL && atual != no){
        ant = atual;
        atual = atual -> prox;
    }

    //Encontrou o no:
    if (atual == no){
        ant -> prox = atual -> prox;
        libera_no(atual);
        return 1;
    }

    //Nao encontrou o no:
    printf("ERROR No nao encontrado (12)\n");
    return 1;
}

//Funcao para liberar a lista heterogenea:
void libera_lista(ListaHet* lista){
    //Vericar se a lista esta vazia:
    if (!lista){
        printf("ERROR: NAO HA NADA PARA LIBERAR (13) \n");
        return;
    }

    ListaNoHet* ant = NULL;
    ListaNoHet* p = lista -> cabeca;

    //Percorrendo a lista:
    while (p != NULL){
        ant = p;
        p = p -> prox;

        //Liberando a figura geometrica:
        if (ant -> info != NULL){
            free(ant -> info);
        }

        //Libera o no:
        free(ant);    
    }

    //Liberando a estrutura em si:
    free(lista);
}

//Criando funcoes auxiliares para calculo de area:
float area_ret(Retangulo* ret){
    return ret -> altura * ret -> base;
}

float area_tri(Triangulo* tri){
    return ((tri -> base * tri -> altura )/ 2);
}

#define PI 3.14
float area_circ(Circulo* circ){
    return (PI * circ -> raio * circ -> raio);
}

//Funcao geral para calcular a area das figuras:
float area_figura(ListaNoHet* no){
    //Verificando se o No eh vazio:
    if (!no){
        printf("No vazio: impossivel calcular area (14)\n");
        return 0.0f;
    }
    
    switch (no -> tipo){
        case RETANGULO:
            /*Eh um retangulo*/
            return area_ret((Retangulo*) no -> info);
    
        case TRIANGULO:
            /*Eh um triangulo*/
            return area_tri((Triangulo*) no -> info);

        case CIRCULO:
            /*Eh um circulo*/
            return area_circ((Circulo*) no -> info);

        default:
            printf("Figura indefinida\n");
            return 0.0f;
    }
}

//Funcao para imprimir a lista heterogenea:
void imprime_lista(ListaHet* lista){
    //Caso a lista esteja vazia, nao faz sentido exibir nada:
    if (!lista || !lista -> cabeca){
        printf("Lista vazia: nada para exibir (15)\n");
        return;
    }

    //Exibindo a lista:
    ListaNoHet* atual = lista -> cabeca;
    
    int i = 0;
    while(atual != NULL){
        //Criando variaveis auxiliares:
        const char* tipo;

        //Determinando o tipo da figura:
        switch (atual -> tipo){
            case RETANGULO:
                /*Eh um retangulo*/
                tipo = "Retangulo";
                break;
        
            case TRIANGULO:
                /*Eh um triangulo*/
                tipo = "Triangulo";
                break;

            case CIRCULO:
                /*Eh um circulo*/
                tipo = "Circulo  ";
                break;

            default:
                tipo = "Nda";
                break;
    }

        //Exibindo informacoes:
        float area = area_figura(atual);
        printf("Figura %d || Tipo: %s || area: %.2f m2\n", i, tipo, area);

        //Passando para o prox no:
        atual = atual -> prox;
        i++;
    }
}