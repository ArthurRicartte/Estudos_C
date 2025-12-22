#include "VetorDin.h"
#include <stdio.h>

void ExibirVetor (VetorDin* vd){
    printf("EXIBINDO:\n");
    for (int i = 0; i < vd_tam(vd); i++){
        printf("vd[%d] = %.2f\n", i, vd_acessa(vd, i));
    }
}

int main (void){
    //Testando TAD:
    printf("=======================Vetores dinamicos=======================\n");

    VetorDin* vetor = vd_cria();
    vd_insere(vetor, 1.1);
    vd_insere(vetor, 1.2);
    vd_insere(vetor, 1.3);
    vd_insere(vetor, 1.4);

    ExibirVetor(vetor);
    printf("\n\n");

    vd_insere(vetor, 1.5);
    vd_insere(vetor, 1.6);
    ExibirVetor(vetor);

    vd_libera(vetor);
    return 0;
}