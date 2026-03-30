#include "Arvore.h"
#include <stdio.h>
#include <stdlib.h>

//Criando No:
No* criar_No(int v){
    No* novo = (No*) malloc(sizeof(No));

    //Verficar se a alocacao deu certo:
    if(novo == NULL){
        printf("Alocacao de No deu erro(1)\n");
        return NULL;
    }

    //Setar os valores iniciais:
    novo -> info = v;
    novo -> fd = NULL;
    novo -> fe = NULL;

    //Retornando novo no:
    return novo;
}

//Criar Arvore:
ArvoreBinaria* cria_Arv(void){
    ArvoreBinaria* arv = (ArvoreBinaria*) malloc(sizeof(ArvoreBinaria));

    //Verfica se deu certo:
    if(arv == NULL){
        printf("Alocacao de Arvore deu erro(2)\n");
        return NULL;
    }

    //Setando ponteiros de arv:
    arv -> raiz = NULL;
    return arv;
}

//Inserir No na arvore:
int inserir_Arv(ArvoreBinaria* arv, int v){
    //Verficar validade da arv:
    if(arv == NULL){
         printf("Arvore Invalida(3)\n");
        return -1;
    }

    //Caso a raiz esteja vazia:
    if (arv -> raiz == NULL){
        //No sera a raiz:
        arv -> raiz = criar_No(v);
        return(arv -> raiz != NULL);

    }
    
    //Se a raiz nao esta vazia, vamos analisar seus filhos e os filhos dos filhos...    
    return inserir_No(arv -> raiz, v);
}

//Inserir No como filho de outro No (Auxiliar para inserir_Arv):
int inserir_No(No* no, int v){
    //Verificar se no eh valido:
    if(no == NULL){
        printf("no invalido (4)\n");
        //-1 significa que deu error de acesso
        return -1;
    }

    //Verificando se v sera colocado na esquerda ou direita:
    if(v < no -> info){
        //Vai para a esquerda:
        if(no -> fe == NULL){
            no -> fe = criar_No(v);
            return(no -> fe != NULL);
        }

        //Tenta inserir passando o filho esquerdo como novo no a ser avaliado: 
        return inserir_No(no -> fe, v);
    }else{
        //Vai para a direita:
        if(no -> fd == NULL){
            no -> fd = criar_No(v);
            return(no -> fd != NULL);
        }
        
        //Tenta inserir passando o filho diretio como novo no a ser avaliado: 
        return inserir_No(no -> fd, v);
    }   
}

//buscar um valor na arvore:
No* busca_arv(ArvoreBinaria* arv, int v){
    //Verificando se arv eh valido para ser percorrida:
    if (arv == NULL){
        printf("Error! Arvore invalida(5)\n");
        return NULL;
    }

    //Analisando valor de No:
    return busca_no(arv -> raiz, v);
}

//Busca a partir de um no (Auxiliar de busca_Arv):
No* busca_no(No* no, int v){
    //Verificando se No eh valido para ser percorrido:
    if (no == NULL){
        return NULL;
    }

    //Verficando se v eh igual a info do no:
    if (no -> info == v) return no;
    
    //Caso nao seja:

    //Vai para o filho esquerdo:
    if (no -> info > v){
        return busca_no(no -> fe, v);
    }

    //Vai para o filho direito:
    return busca_no(no -> fd, v);
}

//Imprimir Arvore:
void imprime_Arv(ArvoreBinaria* arv){
    //Verificar validade da arvore:
    if(arv == NULL){
        printf("Error! Arvore invalida(6)\n");
        return;
    }

    imprime_no(arv->raiz);
    printf("\n");
}
//Imprime No:
void imprime_no(No* no){
    if(no != NULL){
        printf("%d ", no -> info);
        imprime_no(no -> fe);
        imprime_no(no -> fd);
    }
}

//Altura da arvore:
int altura_Arv(ArvoreBinaria* arv){
    //Para arvores vazias sem nos = altura = -1;
    if (arv == NULL || arv -> raiz == NULL){
        return -1;
    }
    return altura_No(arv -> raiz);
}

//Altura de cada No:
int altura_No(No* no){
    if(no == NULL){
        return -1;
    }

    int altura_esq = altura_No(no->fe);
    int altura_dir = altura_No(no->fd);

    //Utiliza a maior altura:
    return(altura_esq > altura_dir ? altura_esq : altura_dir) + 1;
}

//Q1: quantida de nos com info par:
int pares(ArvoreBinaria* a){
    //Verificar a validade da arvore:
    if(a == NULL){
        printf("Arvore invalida (7)\n");
        return 0; //error
    }

    //Verificar a validade da raiz:
    if(a -> raiz == NULL){
        printf("Raiz invalida (8)\n");
        return 0; //error
    }

    //Chamando a funcao auxilar que percorre os nós da árvore:
    return pares_no(a -> raiz);
}

//Função de pares que percorre a árvore inteira (pré-ordem):
int pares_no(No* no){
    //Verificando se o no é vazio:
    if(no == NULL){
        return 0;
    }

    //Criando contador de pares:
    int cont_pares = 0;

    //Verificando se o no é par:
    if ((no -> info) % 2 == 0){
        cont_pares++;
    }

    //Percorrendo filhos:
    cont_pares += pares_no(no -> fe);
    cont_pares += pares_no(no -> fd);

    return cont_pares;
}

//Q2: conta e rotorna a quantidade de folhas (Folhas são nós que não tem filhos) na árvore:
int folhas(ArvoreBinaria* a){
    //Verificar se a árvore ou a raiz é vazia:
    if (a == NULL || a -> raiz == NULL){
        return 0;
    }

    //Chamando a função auxiliar que vai percorrer os nós da árovore:
    return folhas_no(a -> raiz);
}

//Auxilia na Q2:
int folhas_no(No* no){
    //Caso o nó seja vazio:
    if (no == NULL){
        return 0;
    }

    //Contador para as folhas:
    int cont_folhas = 0;

    //Verificando se o nó não possui filhos (soma 1 em cont_folhas):
    if (no -> fe == NULL && no -> fd == NULL){
        cont_folhas++;
    }

    //Percorre a árvore (pré-ordem):
    cont_folhas += folhas_no(no -> fe);
    cont_folhas += folhas_no(no -> fd);

    //retornando a quantidade de folhas:
    return cont_folhas;
}

//Q3: retorna a quantidade de nós da árvore que possuem apenas um filho:
int um_filho(ArvoreBinaria* a){
    //Verificando se a árovre ou a raiz são vazias:
    if(a == NULL || a -> raiz == NULL){
        return 0; //Não tem nenhum filho
    }
    
    //Chamando função auxiliar:
    return no_um_filho(a -> raiz);
}

//Auxila na Q3:
int no_um_filho(No* no){
    //Caso o nó seja vazio:
    if(no == NULL){
        return 0;
    }

    //Criando um contador para armazenar nós com um único filho:
    int cont_um_filho = 0;

    //Analisando se o nó só tem um filho:
    int so_esquerdo = (no -> fe != NULL && no -> fd == NULL);
    int so_direito = (no -> fe == NULL && no -> fd != NULL);

    if(so_esquerdo || so_direito){
        cont_um_filho++;
    }

    //Aplicando recursividade nos filhos:
    cont_um_filho += no_um_filho(no -> fe);
    cont_um_filho += no_um_filho(no -> fd);

    return cont_um_filho;
}

//Q4: Comparando se duas árvores são iguais:
int igual(ArvoreBinaria* a, ArvoreBinaria* b){
    //Verificando se ambas as árvores são vazias
    if(a == NULL && b == NULL){
        return 1;
    }

    //Verificando se apenas uma árvore é vazia:
    if(a == NULL || b == NULL){
        return 0;
    }

    //Chamando função auxiliar:
    return no_igual(a -> raiz, b -> raiz);
}

//Auxilia em Q4:
int no_igual(No* a1, No* b1){
    //Verificando se ambos os nós são vazios (fim da árvore em ambos os lados)::
    if(a1 == NULL && b1 == NULL){
        return 1;
    }

    //Se só um dos nós forem vazios (estruturas diferentes), retorna 0;
    if(a1 == NULL || b1 == NULL){
        return 0;
    }

    //Criando variável que armazenar se são iguais 1 (Verdadeiro) 0 (Falso):
    int eh_igual = 0;

    //Caso ambos os nós existam, compara se são iguias e se os filhos tambem:
    if(a1 -> info == b1 -> info){
        return no_igual(a1 -> fe, b1 -> fe) && no_igual(a1 -> fd, b1 -> fd);
    }

    //Valores diferente:
    return 0;
}

//Q5: Realizar uma cópia de árvore:
ArvoreBinaria* copia(ArvoreBinaria* a){
    //Verifcando se a árvore está vazia:
    if (a == NULL){
        //árovre vazia
        return NULL;
    }

    //Criando nova árvore:
    ArvoreBinaria* nova = cria_Arv();

    //Caso dê error de criação
    if(nova == NULL){
        printf("ERRO de criação de nova árvore(9)\n");
        return NULL;
    }

    //Realizando cópia recursiva:
    nova -> raiz = copia_no(a -> raiz);

    return nova;
}

//Auxilia em Q5:
No* copia_no(No* no){
    //Verificando se o nó é vazio:
    if (no == NULL){
        return NULL;
    }

    //Criando novo nó:
    No* novo = criar_No(no -> info);

    //Verificando se a criação deu error:
    if (novo == NULL){
        printf("ERRO de criação de novo nó(10)\n");
        return NULL;
    }

    //Copiando recursivamente filhos para o novo nó:
    novo -> fe = copia_no(no -> fe);
    novo -> fd = copia_no(no -> fd);

    return novo;
}

//Q6: Retorna a quantidade de nós folhas (Só os nós que não tem filhos) com info maior que x:
int nfolhas_maiores(ArvoreBinaria* a, int x){
    //Verificar se a árvore é vazia ou a raíz é vazia:
    if(a == NULL || a -> raiz == NULL){
        printf("ERRO, ARVORE invalida (11)\n");
        return 0;
    }

    //Percorre toda a arvore, nao apenas um lado
    return no_maior(a -> raiz, x);
}

//Auxila na Q6:
int no_maior(No* no, int x){
    //Verficando se o nó é vazio:
    if(no == NULL){
        return 0;
    }

    //Variável auxiliar para contar as folhas maiores que x:
    int cont_folhas_maiores = 0;

    //Verificando se é uma folha:
    if((no -> fe == NULL) && (no -> fd == NULL)){
        //Verificando se a folha é maior que x:
        if (no -> info > x){
            cont_folhas_maiores ++;
        }
    }

    //Verificando os filhos:
    cont_folhas_maiores += no_maior(no -> fe, x);
    cont_folhas_maiores += no_maior(no -> fd, x);

    return cont_folhas_maiores;
}

//Q7: Soma todos os nós que estão entre: y e x (y <= n <= x):
int soma_xy(ArvoreBinaria* a, int x, int y){
    //Verificando se a árvore ou a raiz são vazias:
    if (a == NULL || a -> raiz == NULL){
        printf("ERRO arvore invalida (12)\n");
        return 0;
    }

    //Caso x <= y (Tem que ser x > y):
    if (x <= y){
        printf("ERRO intervalo invalido (13)\n");
        return 0;
    }

    //Varrendo árvore para encontrar nós dentro de y e x:
     return soma_xy_no(a -> raiz, x, y);
}

//Auxilia na Q7:
int soma_xy_no(No* no, int x, int y){
    //Verificando se o nó é vazio:
    if(no == NULL){
        return 0;
    }

    //Variável para armazenar a soma:
    int soma = 0;

    //Verificando se o nó está dentro do intervalo:
    if((no -> info) >= y && (no -> info) <= x){
        //Adiciona em soma:
        soma = (no -> info);
    }

    //Passando para os filhos:

    //Caso o nó seja maior que y, vamos para a sua esquerda (filhos menores que ele)
    if((no -> info) > y){
        soma += soma_xy_no(no -> fe, x, y);
    }

     //Caso o nó seja menor que x, vamos para a sua direita (filhos maiores que ele)
    if(no -> info < x){
        soma += soma_xy_no(no -> fd, x, y);  
    }

    return soma;
}

//Q8: Encontra x e retorna o nível dele:
int nivel(ArvoreBinaria* a, int x){
    //Caso a árvore esteja vazia ou o nó esteja vazio:
    if(a == NULL || a -> raiz == NULL){
        return -1;
    }

   //Começa a busca a partir da raíz com nível 0:
   return nivel_no(a -> raiz, x, 0);
}

//Auxilia na Q8:
int nivel_no(No* no, int x, int nivel_atual){
    //verificando se o no é vazio:
    if (no == NULL){
        return -1;
    }

    //Criando uma variável para guardar a altura a partir do nó:
    int altura = -1;

    //Verficando se o nó é igual a x:
    if(no -> info == x){
        //Retorna o nível atual:
        return nivel_atual;
    }

    //Se não encontrou vamos para os filhos:
    if (x < no -> info){
        //Vamos para a esquerda:
        return nivel_no(no -> fe, x, nivel_atual + 1);
    }else{
        //Vai para a diretira:
        return nivel_no(no -> fd, x, nivel_atual + 1);
    }
}

//Libera Arvore:
void libera_Arv(ArvoreBinaria** arv){
     //Verificar validade da arvore:
    if(arv == NULL || *arv == NULL){
        printf("Error! Arvore invalida(14)\n");
        return;
    }

    libera_No((*arv) -> raiz);
    free(*arv);
    *arv = NULL;
}

//Libera cada No:
void libera_No(No* no){
    if(no != NULL){
        libera_No(no -> fe);
        libera_No(no -> fd);
        free(no);
    }
}