#include "ArvAluno.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    printf("=== TESTE DA ARVORE DE ALUNOS ===\n\n");
    
    // Criando arvore
    Arv* arv = arv_cria();
    
    // Inserindo alunos
    printf("1. Inserindo alunos:\n");
    arv_insere(arv, "Ana", 8.5, 7.0, 9.0);
    arv_insere(arv, "Bruno", 9.0, 8.5, 9.5);
    arv_insere(arv, "Carlos", 7.0, 6.5, 8.0);
    arv_insere(arv, "Daniel", 8.0, 7.5, 9.0);
    arv_insere(arv, "Eduarda", 9.5, 9.0, 10.0);
   
    // Testando media
    printf("\n2. Testando medias:\n");
    printf("   Media da Ana: %.2f\n", arv_media(arv, "Ana"));
    printf("   Media do Bruno: %.2f\n", arv_media(arv, "Bruno"));
    printf("   Media do Carlos: %.2f\n", arv_media(arv, "Carlos"));
    printf("   Media do Joao (inexistente): %.2f\n", arv_media(arv, "Joao"));
    
    // Testando copia
    printf("\n3. Testando copia da arvore:\n");
    Arv* copia = arv_copia(arv);
    if(copia != NULL) {
        printf("   Copia criada com sucesso!\n");
        
        // Comparando original com copia
        if(arv_iguais(arv, copia)) {
            printf("   Arvore original e copia sao IGUAIS!\n");
        }
        
        // Inserindo aluno diferente na copia
        arv_insere(copia, "Fernanda", 8.0, 7.0, 9.0);
     
        // Verificando se ainda sao iguais
        if(!arv_iguais(arv, copia)) {
            printf("   Agora as arvores sao DIFERENTES (como esperado)\n");
        }
    }
    
    // Testando remocao
    printf("\n4. Testando remocao:\n");
    printf("   Media do Bruno antes: %.2f\n", arv_media(arv, "Bruno"));
    arv_retira(arv, "Bruno");
    printf("   Bruno removido!\n");
    printf("   Media do Bruno depois: %.2f\n", arv_media(arv, "Bruno"));
    
    // Testando remocao de aluno inexistente
    printf("\n   Tentando remover Joao (inexistente):\n");
    arv_retira(arv, "Joao");
    
    // Testando comparacao com arvore vazia
    printf("\n5. Testando comparacao:\n");
    Arv* vazia = arv_cria();
    if(arv_iguais(arv, vazia)) {
        printf("   Arvores sao iguais?\n");
    } else {
        printf("   Arvore com alunos e arvore vazia: DIFERENTES\n");
    }
    
    // Testando arvores vazias
    Arv* vazia1 = arv_cria();
    Arv* vazia2 = arv_cria();
    if(arv_iguais(vazia1, vazia2)) {
        printf("   Duas arvores vazias: IGUAIS\n");
    }
    
    // Liberando memoria
    printf("\n6. Liberando memoria:\n");
    arv_libera(&arv);
    arv_libera(&copia);
    arv_libera(&vazia);
    arv_libera(&vazia1);
    arv_libera(&vazia2);
    
    return 0;
}