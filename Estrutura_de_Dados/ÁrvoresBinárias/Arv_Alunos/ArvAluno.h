#ifndef ARVALUNO_H
#define ARVALUNO_H

//Estrutura que representa um aluno:
typedef struct aluno {
    char nome[81];
    float p1 , p2 , p3;
}Aluno;

//Estrutura que representa um nó:
typedef struct arvno {
    Aluno info; //não é um ponteiro = acessa como No -> info.oq vc quer acessar
    struct arvno* fe;
    struct arvno* fd;
}No;

//estrutura que representa a árvore:
typedef struct arv {
    No* raiz;
}Arv;


//Criar uma árvore vazia:
Arv* arv_cria (void);

//Inserir um aluno na árvore:
void arv_insere (Arv* a, char * nome ,float p1 , float p2 , float p3 );

//Função auxiliar para inserir no:
No* insere_no (No* no, char * nome ,float p1 , float p2 , float p3 );

//Busca o aluno e retorna a a média das notas:
float arv_media(Arv* a, char* nome);

//Auxila na busca para média das notas:
float no_media(No* no, char* nome);

//Retirar um aluno da árvore:
void arv_retira(Arv* a, char* nome);

//Auxilia na retirada de um aluno:
No* no_retira(No* no, char* nome);

//Auxilia a encontrar o menor nó pela direita:
No* encontra_menor(No* no);

//Comparar se duas árvore de alunos são iguais:
int arv_iguais(Arv* a, Arv* b);

//Compara se os nós são iguais:
int no_iguais(No* n1, No* n2);

//Copiar dados de uma árvore:
Arv* arv_copia(Arv* a);

//Copia cada nó da árvore:
No* no_copia(No* no);

//Libera árvore:
void arv_libera (Arv** a);

//Libera o nó:
void no_libera(No* no);

#endif