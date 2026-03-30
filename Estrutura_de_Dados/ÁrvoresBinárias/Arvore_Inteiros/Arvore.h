#ifndef ARVORE_H
#define ARVORE_H

//Struct que representa o no da arvore:
typedef struct No{
    int info;
    struct No* fe; 
    struct No* fd; 
}No;

//Struct para arvore:
typedef struct{
    No* raiz;
}ArvoreBinaria;

//Criar No:
No* criar_No(int valor);

//Criar Arv:
ArvoreBinaria* cria_Arv(void);

//Inserir No na arvore:
int inserir_Arv(ArvoreBinaria* arv, int v);

//Inserir No em um dos filhos:
int inserir_No(No* no, int info);

//buscar um valor na arvore:
No* busca_arv(ArvoreBinaria* arv, int v);

//Busca a partir de um no (Auxiliar de busca_Arv):
No* busca_no(No* no, int v);

//Imprimir Arvore:
void imprime_Arv(ArvoreBinaria* arv);

//Imprime No:
void imprime_no(No* no);

//Altura da arvore:
int altura_Arv(ArvoreBinaria* arv);

//Altura de cada No:
int altura_No(No* no);

//Q1: quantida de nos com info par:
int pares(ArvoreBinaria* a);

//Auxilia na Q1:
int pares_no(No* no);

//Q2: Conta e rotorna a quantidade de folhas (Folhas são nós que não tem filhos) na árvore:
int folhas(ArvoreBinaria* a);

//Auxilia na Q2:
int folhas_no(No* no);

//Q3: Retorna a quantidade de nós da árvore que possuem apenas um filho:
int um_filho(ArvoreBinaria* a);

//Auxila na Q3:
int no_um_filho(No* no);

//Q4: Comparando se duas árvores são iguais:
int igual(ArvoreBinaria* a, ArvoreBinaria* b);

//Auxilia em Q4:
int no_igual(No* a1, No* b1);

//Q5: Realizar uma cópia de árvore:
ArvoreBinaria* copia(ArvoreBinaria* a);

//Auxilia em Q5:
No* copia_no(No* no);

//Q6: Retorna a quantidade de nós folhas (Só os nós que não tem filhos) com info maior que x:
int nfolhas_maiores(ArvoreBinaria* a, int x);

//Auxila na Q6:
int no_maior(No* no, int x);

//Q7: Soma todos os nós que estão entre: y e x (y <= n <= x):
int soma_xy(ArvoreBinaria* a, int x, int y);

//Auxilia na Q7:
int soma_xy_no(No* no, int x, int y);

//Q8: Encontra x e retorna o nível dele:
int nivel(ArvoreBinaria* a, int x);

//Auxilia na Q8:
int nivel_no(No* no, int x, int nivel_atual);

//Libera Arvore:
void libera_Arv(ArvoreBinaria** arv);

//Libera cada No:
void libera_No(No* no);
#endif