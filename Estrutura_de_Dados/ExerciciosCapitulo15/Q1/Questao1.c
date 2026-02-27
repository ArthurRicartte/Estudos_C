#include "Questao1.h"
#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da pilha
struct pilha{
    float* valores;
    int armazenados;
    int capacidade;
};

//Criar pilha:
Pilha* pilha_cria(void){
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));

    //Verificando se a pilha foi alocada:
    if (p == NULL) {
        printf("Erro ao alocar memória para a pilha (1).\n");
        exit(1);
    }

    p -> valores = (float*) malloc(sizeof(float) * MAX);

    if (p -> valores == NULL){
        printf("Erro ao alocar memória para os valores da pilha (2).\n");
         free(p);
        exit(1);
    }

    //Setando valores:
    p->armazenados = -1;
    p -> capacidade = MAX;
    return p;
}

//Insere no topo:
void pilha_push (Pilha* p, float v){
    //Verificando se a pilha existe:
    if (p == NULL) {
        printf("Erro: pilha não existe (3).\n");
        exit(1);
    }

    //Alocando:
    if (pilha_cheia(p)) {
        int nova_capacidade = p -> capacidade * FATOR_AUMENTO;
        float* novos_valores = (float*) realloc(p -> valores, sizeof(float) * nova_capacidade);
        
        if (novos_valores == NULL) {
            printf("Erro ao realocar memória para os valores da pilha (4).\n");
            return;
        }

        p -> valores = novos_valores;
        p -> capacidade = nova_capacidade;
    }

    //Inserindo 1 na quantidade armazenada:
    p ->armazenados++;
    p->valores[p->armazenados] = v;
}

//Retirando do topo:
float pilha_pop (Pilha* p, float* v){
    //Verifcando se a pilha existe:
    if (p == NULL) {
        printf("Erro: pilha não existe (5).\n");
        return -1;
    }

    //Verificando se a pilha esta vazia:
    if (pilha_vazia(p)) {
        printf("Erro: pilha vazia (6).\n");
        return -1;
    }

    //Salvando o valor retirado:
    *v = p -> valores[p -> armazenados];
    
    //Decrementando a quantidade armazenada:
    p -> armazenados--;

    return 1;
}

//Eh vazia?
int pilha_vazia (Pilha* p){
    return (p -> armazenados == -1);
}

//Esta cheia?
int pilha_cheia (Pilha* p){
    return (p -> armazenados == p -> capacidade - 1);
}

//Retorna o valor do topo:
float pilha_topo (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL) {
        printf("Erro: pilha não existe (7).\n");
        exit(1);
    }

    //Pilha vazzia:
    if (pilha_vazia(p)) {
        printf("Erro: pilha vazia (8).\n");
        exit(1);
    }

    //Retornando o topo:
    return p -> valores[p -> armazenados];
}

//Concatena pilha de forma recursiva:
void concatena_pilhas_rec (Pilha* p1 , Pilha* p2 ){
    //Verificando se p1 esta vazia (Nao roda a funcao):
    if (p1 == NULL || p2 == NULL) {
        printf("Pilha 1 ou 2 nulas.\n");
        return;
    }
    
    //Verificando se p2 esta vazia, momento em que a recursao para
    if (pilha_vazia(p2)) {
       return;
    }

    float valor;

    //Retirando valor do topo:
    pilha_pop(p2, &valor);

    //Chamando a funcao recursivamente:
    concatena_pilhas_rec(p1, p2);

    //Inserindo o valor no inicio de p1:
    pilha_push(p1, valor);
}

//Concatena pilha usando pilha auxiliar:
void concatena_pilhas_aux (Pilha* p1 , Pilha* p2 ){
    //Verificano se p1 e p2 existem:
    if (p1 == NULL || p2 == NULL) {
        printf("Erro: pilha 1 ou 2 vazia (9).\n");
        return;
    }
    
    //Caso p2 esteja vazia:
    if (pilha_vazia(p2)) {
        return;
    }

    //Criando p3:
    Pilha* p3 = pilha_cria();
    float valor;

    //Iterando p2 para concatenar em p3:
    while (!pilha_vazia(p2)) {
        pilha_pop(p2, &valor);
        pilha_push(p3, valor);
    }

    //Iterando p3 para concatenar em p1:
    while (!pilha_vazia(p3)) {
        pilha_pop(p3, &valor);
        pilha_push(p1, valor);
    }
    
    //Liberando p3 da memoria:
    pilha_libera(&p3);
    
}

//Funcao para copiar pilha:
Pilha* copia_pilha (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL) {
        printf("Erro: pilha não existe (10).\n");
        return NULL;
    }

    //Criando nova pilha:
    Pilha* nova_pilha = pilha_cria();

    //Caso de error na criacao:
    if (nova_pilha == NULL) {
        printf("Erro: não foi possível criar a nova pilha (11).\n");
        return NULL;
    }

    //Iterando p1 para copiar em nova_pilha:
    for (int i = 0; i <= p -> armazenados; i++) {
        pilha_push(nova_pilha, p -> valores[i]);
    }

    return nova_pilha;
}

//Exibir pilha:
void pilha_exibe (Pilha* p){
    //Verificando se a pilha existe:
    if (p == NULL) {
        printf("Erro: pilha não existe (12).\n");
        exit(1);
    }

    printf("Pilha:\n");
    for (int i = p -> armazenados; i >= 0; i--) {
        printf("indice = %d || Valor = %.2f\n", i, p -> valores[i]);
    }
    printf("\n");
}

//Libera pilha:
void pilha_libera (Pilha** p){
    //Verificando se a pilha existe:
    if (p == NULL || *p == NULL) {
        printf("Erro: pilha não existe (13).\n");
        exit(1);
    }
    
    //Liberando a pilha:
    free((*p) -> valores);
    free(*p);
    *p = NULL;
}