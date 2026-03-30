#include <stdio.h>
#include "Arvore.h"

int main() {
    // Criando uma arvore simples
    ArvoreBinaria* arv = cria_Arv();
    
    if(arv == NULL){
        printf("Erro ao criar arvore!\n");
        return 1;
    }
    
    // Inserindo alguns valores
    printf("Inserindo valores: 50, 30, 70, 20, 40, 60, 80\n");
    inserir_Arv(arv, 50);
    inserir_Arv(arv, 30);
    inserir_Arv(arv, 70);
    inserir_Arv(arv, 20);
    inserir_Arv(arv, 40);
    inserir_Arv(arv, 60);
    inserir_Arv(arv, 80);
    
    // Imprimindo a arvore
    printf("\nArvore em pre-ordem: ");
    imprime_Arv(arv);
    printf("\n");
    
    // Questao 1 - Contar nos pares
    printf("\n[Q1] Nos com valores pares: %d\n", pares(arv));
    
    // Questao 2 - Contar folhas
    printf("[Q2] Quantidade de folhas: %d\n", folhas(arv));
    
    // Questao 3 - Contar nos com um filho
    printf("[Q3] Nos com apenas um filho: %d\n", um_filho(arv));

    //[Q6] - folhas maiores que um certo valor:
    printf("Folhas maiores que 35: %d\n", nfolhas_maiores(arv, 35)); // 40, 60, 80 = 3
    printf("Folhas maiores que 50: %d\n", nfolhas_maiores(arv, 50)); // 60, 80 = 2
    printf("Folhas maiores que 75: %d\n", nfolhas_maiores(arv, 75)); // 80 = 1
    printf("Folhas maiores que 90: %d\n", nfolhas_maiores(arv, 90)); // 0

    //[Q7] - vê se existem nós entre y e x e soma esses nós:
    printf("Soma entre 30 e 60: %d\n\n", soma_xy(arv, 60, 30));

    //[Q8] - Encontra um valor x na árvore e verifica o nível dele:
    printf("Nivel do 50: %d\n", nivel(arv, 50));
    printf("Nivel do 30: %d\n", nivel(arv, 30));
    printf("Nivel do 70: %d\n", nivel(arv, 70));
    printf("Nivel do 20: %d\n", nivel(arv, 20));
    printf("Nivel do 40: %d\n", nivel(arv, 40));
    printf("Nivel do 60: %d\n", nivel(arv, 60)); 
    printf("Nivel do 80: %d\n", nivel(arv, 80));  
    printf("Nivel do 100: %d\n", nivel(arv, 100)); 
    
    // Questao 4 - Comparar arvores
    printf("\n[Q4] Teste de comparacao:\n");
    
    // Criando uma arvore identica
    ArvoreBinaria* arv2 = cria_Arv();
    inserir_Arv(arv2, 50);
    inserir_Arv(arv2, 30);
    inserir_Arv(arv2, 70);
    inserir_Arv(arv2, 20);
    inserir_Arv(arv2, 40);
    inserir_Arv(arv2, 60);
    inserir_Arv(arv2, 80);
    
    printf("  Arvore 1 == Arvore 2? %d (1=sim, 0=nao)\n", igual(arv, arv2));
    
    // Criando uma arvore diferente
    ArvoreBinaria* arv3 = cria_Arv();
    inserir_Arv(arv3, 10);
    inserir_Arv(arv3, 20);
    inserir_Arv(arv3, 30);
    
    printf("  Arvore 1 == Arvore 3? %d (1=sim, 0=nao)\n", igual(arv, arv3));
    
    // Questao 5 - Copiar arvore
    printf("\n[Q5] Teste de copia:\n");
    ArvoreBinaria* copia_arv = copia(arv);
    
    printf("  Arvore original: ");
    imprime_Arv(arv);
    printf("\n");
    
    printf("  Arvore copiada:  ");
    imprime_Arv(copia_arv);
    printf("\n");
    
    printf("  Sao iguais? %d\n", igual(arv, copia_arv));
    
    // Modificando a copia para mostrar independencia
    inserir_Arv(copia_arv, 100);
    printf("\n  Apos inserir 100 na copia:\n");
    printf("  Original: ");
    imprime_Arv(arv);
    printf("\n");
    printf("  Copia:    ");
    imprime_Arv(copia_arv);
    printf("\n");

    // Liberando memoria
    printf("\nLiberando memoria...\n");
    libera_Arv(&arv);
    libera_Arv(&arv2);
    libera_Arv(&arv3);
    libera_Arv(&copia_arv);
        
    return 0;
}