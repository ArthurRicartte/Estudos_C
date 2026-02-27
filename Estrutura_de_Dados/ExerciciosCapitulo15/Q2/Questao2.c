#include "Questao2.h"
#include <stdio.h>
#include <stdlib.h>

//Tipo estruturado para a fila:
struct fila{
    float* valores;
    int inicio;
    int fim;
    int capacidade;
    int armazenados;
};

//Criar a fila:
Fila* fila_cria(void ){
    //Criando a fila:
    Fila* f = (Fila*) malloc(sizeof(Fila));

    //Verificando se deu certo:
    if (f == NULL){
        printf("Erro ao criar a fila!\n");
        return NULL;
    }

    //Setando valores de f (iniciais):
    f -> valores = (float*) malloc(MAX * sizeof(float));

    //Verificando se a alocacao de memoria para valores deu certo:
    if (f -> valores == NULL){
        printf("Erro ao alocar valores da fila!\n");
        free(f);
        return NULL;
    }

    //Determinando valores iniciais
    f -> inicio = 0;
    f -> fim = 0;
    f -> capacidade = MAX;
    f -> armazenados = -1;
    return f;
}

//Inserir no final da fila:
void fila_insere (Fila* f, float v){
    //Verificando se f existe:
    if (f == NULL){
        printf("Fila nao existe!\n");
        return;
    }

    //Verificando se a fila esta cheia:
    if (fila_cheia(f)){
        //Iniciando realocacao:
        int nova_capacidade = f -> capacidade * FATOR_AUMENTO;
        float* novos_valores = (float*) realloc(f -> valores, nova_capacidade * sizeof(float));

        //Verificando se o realoc deu certo:
        if (novos_valores == NULL){
            printf("Erro ao realocar a fila!\n");
            return;
        }

        //Setando nova capacidade e novos valores:
        f -> capacidade = nova_capacidade;
        f -> valores = novos_valores;

        //Inicio passa a ser 0:
        f->inicio = 0;
        f->fim = f->armazenados + 1; // próxima posição livre
    }

    //Inserindo o valor no final da fila:
    f -> valores [f -> fim] = v;
    f -> armazenados++;
    
    //Atualizando o fim da fila:
    f -> fim = (f -> fim + 1) % f -> capacidade;
}

//Retirar do inicio:
float fila_retira (Fila* f){
    //Verificando se f existe:
    if (f == NULL){
        printf("Fila nao existe!\n");
        return -1; //Valor de erro
    }

    //Verificando se a fila esta vazia:
    if (fila_vazia(f)){
        printf("Fila vazia!\n");
        return -1; //Valor de erro
    }

    //Retirando o valor do inicio da fila:
    float valor = f -> valores[f -> inicio];
    f -> armazenados--;

    //Atualizando o inicio da fila:
    f -> inicio = (f -> inicio + 1) % f -> capacidade;

    return valor;
}

//Combina duas filas intercaladamente em uma terceira fila:
void combina_filas (Fila* f_res, Fila* f1 , Fila* f2 ){
    //Verificando se f1 e f2 existem:
    if (f1 == NULL || f2 == NULL){
        printf("Fila 1 ou fila 2 nao existe!\n");
        return;
    }

    //Iterando f1 e f2 ate ficarem vazias:
    float valor_aux;
    while (!fila_vazia(f1) || !fila_vazia(f2)){
        //Verificando se f1 ainda tem elementos para retirar:
        if (!fila_vazia(f1)){
            valor_aux = fila_retira(f1);
            fila_insere(f_res, valor_aux);
        }

         //Verificando se f2 ainda tem elementos para retirar:
        if (!fila_vazia(f2)){
            valor_aux = fila_retira(f2);
            fila_insere(f_res, valor_aux);
        }
    }
}

//Fila esta vazia?
int fila_vazia (Fila* f){
    return f -> armazenados == -1;
}

//Fila esta cheia?
int fila_cheia (Fila* f){
    return f -> armazenados == f -> capacidade -1;
}

//Exibir a fila:
void fila_exibe (Fila* f){
    //Verificando se f existe:
    if (f == NULL){
        printf("Fila nao existe!\n");
        return;
    }

    //Verificando se a fila esta vazia:
    if (fila_vazia(f)){
        printf("Fila vazia!\n");
        return;
    }

    //Iterando valores da fila e exibindo cada um:
    for (int i = 0; i <= f -> armazenados; i++){
        int indice = (f -> inicio + i) % f -> capacidade;
        printf("Indice = %d || Valor = %.2f\n", indice, f -> valores[indice]);
    }
}
//Liberar a fila:
void fila_libera (Fila** f){
    //Verificando se f existe:'
    if (f == NULL || *f == NULL){
        printf("Fila nao existe!\n");
        return;
    }

    //Liberando valores:
    free((*f) -> valores);

    //Liberando a fila em si:
    free(*f);

    //Setando o ponteiro para fila como NULL:
    *f = NULL;
}