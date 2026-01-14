#ifndef HETEROGENEAS_H
#define HETEROGENEAS_H  

//Definindo as estruturas necessarias:

//Estruturas das figuras geometricas:
typedef struct retangulo Retangulo;

typedef struct triangulo Triangulo;

typedef struct circulo Circulo;

//Um enumerador para identificar o tipo da figura:
typedef enum tipo Tipo;

//No da lista heterogenea:
typedef struct listanohet ListaNoHet;

//Lista heterogenea:
typedef struct listahet ListaHet;

//Criar Lista:
ListaHet* cria_lista();

//Funcoes para criar os nos de acordo com a figura geometrica:
ListaNoHet* cria_ret(float b, float h);

ListaNoHet* cria_tri(float b, float h);

ListaNoHet* cria_circ(float r);

//Funcao para inserir um No no inicio da lista:
void insere_inicio(ListaHet* lista, ListaNoHet* no);

//Funcao auxiliar na remocao do no:
void libera_no(ListaNoHet* no);

//Funcao para remover um no especifico:
int remove_no(ListaHet* lista, ListaNoHet* no);

//Funcao para liberar a lista heterogenea:
void libera_lista(ListaHet* lista);

//Funcoes axuliares para calcular a area das figuras:
float area_ret(Retangulo* ret);

float area_tri(Triangulo* tri);

float area_circ(Circulo* circ);

//Funcao principal para calcular a area:
float area_figura(ListaNoHet* no);

//Funcao para imprimir a lista heterogenea:
void imprime_lista(ListaHet* lista);

#endif