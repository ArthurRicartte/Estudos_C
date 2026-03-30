#include "ArvAluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//Criar uma árvore vazia:
Arv* arv_cria (void){
    Arv* tree = (Arv*) malloc(sizeof(Arv));

    //Verificando se a criacao deu certo:
    if(tree == NULL){
        printf("ERRO ao criar arvore (1)\n");
    }

    //Setando a raiz para null:
    tree -> raiz = NULL;

    return tree;
}

//Inserir um aluno na árvore:
void arv_insere (Arv* a, char * nome ,float p1 , float p2 , float p3 ){
    //Verificar se a árvore existe:
    if(a == NULL){
        printf("ERRO ARVORE INVALIDA (2)\n");
        return;
    }

    //Funcao auxiliar para inserir no:
    a -> raiz = insere_no(a -> raiz, nome, p1, p2, p3);
}

No* insere_no (No* no, char * nome ,float p1 , float p2 , float p3 ){
    //Caso encontre uma posição vazia, vc insere o nó:
    if (no == NULL){
        No* novo = (No*) malloc(sizeof(No));

        //Verifica se a criação deu certo:
        if (novo == NULL){
            printf("ERRO ao alocar novo no!(3)\n");
            return NULL;
        }

        //Copia os dados do aluno para o nó:
        strcpy(novo -> info.nome, nome);
        novo -> info.p1 = p1;
        novo -> info.p2 = p2;
        novo -> info.p3 = p3;

        //Setando os filhos:
        novo -> fe = NULL;
        novo -> fd = NULL;

        //retorna o novo no:
        return novo;
    }

    //Caso nao esteja vazio: vai para a esquerda ou direita:
    if(strcmp(nome, no -> info.nome) < 0){
        //Vai para a esquerda (nomes menores):
        no -> fe = insere_no(no -> fe, nome, p1, p2, p3);
    }else if(strcmp(nome, no -> info.nome) > 0){
        //Vai para a direita (nomes maiores):
        no -> fd = insere_no(no -> fd, nome, p1, p2, p3);
    }else{
        printf("Aluno %s ja existe na arvore!\n", nome);
    }

    //Retorna no:
    return no;
}

//Busca o aluno e retorna a a média das notas:
float arv_media(Arv* a, char* nome){
    //Caso a arvore esteja vazia, ou a raiz, retorna -1.0;
    if(a == NULL || a -> raiz == NULL){
        printf("Nenhuma nota para calcular (4)\n");
        return -1.0;
    }

    //Vamos buscar o aluno na arvore:
    return no_media(a -> raiz, nome);
}

//Auxila na busca para média das notas:
float no_media(No* no, char* nome){
    //Caso no esteja vazio:
    if(no == NULL){
        return -1.0;
    }

    //Encontrando o aluno -> calcula a média:
    if (strcmp(nome, no -> info.nome) == 0){
        //Calcula a média:
        return (((no -> info.p1) + (no -> info.p2) + (no -> info.p3)) / 3.0);
    }else if(strcmp(nome, no -> info.nome) < 0){
        //Vamos para a esquerda:
        return no_media(no -> fe, nome);
    }else{
        //Vamos para a direita:
        return no_media(no -> fd, nome);
    }
}

//Retirar um aluno da árvore:
void arv_retira(Arv* a, char* nome){
    //Caso a arvore esteja vazia, ou a raiz;
    if(a == NULL){
        printf("Arvore invalida!(5)\n");
        return;
    }

    //chamando função auxiliar para buscar o nó:
    a -> raiz = no_retira(a -> raiz, nome);
}

//Auxilia na retirada de um aluno:
No* no_retira(No* no, char* nome){
    //Caso o nó esteja vazio:
    if (no == NULL){
        return NULL;
    }

    //Buscar o nó a ser removido:
    if(strcmp(nome, no -> info.nome) < 0){
        //Para a esquerda:
        no -> fe = no_retira(no -> fe, nome);
        return no;
    }else if(strcmp(nome, no -> info.nome) > 0){
        //Para a direita:
        no -> fd = no_retira(no -> fd, nome);
        return no;
    }else{
        //Encontrou o nó:

        //Caso seja uma folha:
        if(no -> fe == NULL && no -> fd == NULL){
            free(no);
            return NULL;
        }

        //Caso tenha 1 filho (na esquerda):
        if (no -> fe != NULL && no -> fd == NULL){
            No* temp = no -> fe;
            free(no);
            return temp;
        }
        
        //Caso tenha 1 filho (na direita):
        if (no -> fe == NULL && no -> fd != NULL){
            No* temp = no -> fd;
            free(no);
            return temp;
        }

        //Caso tenha dois filhos: Encontrar o menor do lado direito:
        No* menor = encontra_menor(no -> fd);

        //Copia os dados do menora para a raiz:
        strcpy(no -> info.nome, menor -> info.nome);
        no -> info.p1 = menor -> info.p1;
        no -> info.p2 = menor -> info.p2;
        no -> info.p3 = menor -> info.p3;

        //Remove o menor pelo lado direto:
        no -> fd = no_retira(no -> fd, menor-> info.nome);

        return no;
    }
}


//Auxilia a encontrar o menor nó pela direita:
No* encontra_menor(No* no){
    No* atual = no;

    //Como queremos o menor do lado direito, sempre vamos para a esquerda do nó:
    while(atual -> fe != NULL){
        atual = atual -> fe;
    }

    return atual;
}


//Comparar se duas árvore de alunos são iguais:
int arv_iguais(Arv* a, Arv* b){
    //Verifica se ambas são vazias (são iguais tecnicamente):
    if(a == NULL && b == NULL){
        return 1;
    }

    //Caso só uma seja vazia:
     if(a == NULL || b == NULL){
        return 0;
    }

    //Chama a função de comparar dois nós:
    return no_iguais(a -> raiz, b -> raiz);
}

//Compara se os nós são iguais:
int no_iguais(No* n1, No* n2){
    //Verifica se ambos são vazios (são iguais tecnicamente):
    if(n1 == NULL && n2 == NULL){
        return 1;
    }

    //Caso só um seja vazio:
     if(n1 == NULL || n2 == NULL){
        return 0;
    }

    //Caso não sejam vazios, vamos analisar seus valores:
    if(strcmp(n1 -> info.nome, n2 -> info.nome) != 0) return 0;
    if(n1 -> info.p1 != n2 -> info.p1) return 0;
    if(n1 -> info.p2 != n2 -> info.p2) return 0;
    if(n1 -> info.p3 != n2 -> info.p3) return 0;

    //Compara recursivamente cada filho:
    return no_iguais(n1 -> fe, n2 -> fe) && no_iguais(n1 -> fd, n2 -> fd);

}

//Copiar dados de uma árvore:
Arv* arv_copia(Arv* a){
    //Caso a árvore esteja vazia:
    if(a == NULL){
        printf("Arvore invalida (6)\n");
        return NULL;
    }

    //Criando a árvore:
    Arv* nova = arv_cria();

    //Verificando criação:
    if(nova == NULL){
        return NULL;
    }

    //Copiando os valores para nova árvore:
    nova -> raiz = no_copia(a -> raiz);
    return nova;
}

//Copia cada nó da árvore:
No* no_copia(No* no){
    //Caso o nó esteja vazio:
    if (no == NULL){
        return NULL;
    }

    //Criando novo nó:
    No* novo = (No*) malloc(sizeof(No));

    //Verifica se deu erro:
    if(novo == NULL){
        return NULL;
    }

    //Copia os dados de no para novo:
    strcpy(novo -> info.nome, no -> info.nome);
    novo -> info.p1 = no -> info.p1;
    novo -> info.p2 = no -> info.p2;
    novo -> info.p3 = no -> info.p3;

    //Copia os filhos de forma recursiva:
    novo -> fe = no_copia(no -> fe);
    novo -> fd = no_copia(no -> fd);

    return novo;
}

//Libera árvore:
void arv_libera (Arv** a){
    //Caso a árvore já estela vazia:
    if(a == NULL || *a == NULL){
        printf("Arvore ja esta vazia\n");
        return;
    }

    //Libera cada nó por vez:
    no_libera((*a) -> raiz);

    //Libera a estrutura da árvore:
    free(*a);
    *a = NULL;

}

//Libera o nó:
void no_libera(No* no){
    //Caso o nó não esteja vazio:
    if(no != NULL){
        //Vamos libetar em pós-ordem:
        no_libera(no -> fe);
        no_libera(no -> fd);
        free(no);
    }
}
