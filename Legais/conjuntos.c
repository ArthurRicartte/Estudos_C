#include <stdio.h>
#define MAX_CONJUNTOS 10000
#define MAX_ELEMENTOS 60

/*Criando funcao para realizar as operacoes necessarias (por ter muito argumento, so to fazendo pra treinar)*/
int Operacoes(int array[][MAX_ELEMENTOS], int conjuntos, int c1, int c2, int operacao){
    int interseccao = 0, uniao = 0;

    for (int i = 0; i < MAX_ELEMENTOS; i++){
        if (array[c1 - 1][i] && array[c2 - 1][i]){
            interseccao += 1;
        }
        
        if (array[c1 - 1][i] || array[c2 - 1][i]){
            uniao += 1;
        }
    }

    if (operacao == 1){
        return interseccao;
    }

    return uniao;
}

int main(void){
    int casos;
    scanf("%d", &casos);

    /*Armazenar os valores digitados em um conjunto*/

    while (casos--){
        
        int conjuntos[MAX_CONJUNTOS][MAX_ELEMENTOS] = {0};
        int qtdConjuntos;
        scanf("%d", &qtdConjuntos);

        /*Analisando se a entrada da problema*/
        if (qtdConjuntos > MAX_CONJUNTOS ){
            return 1;
        }
        
        for (int i = 0; i < qtdConjuntos; i++){
            
            int qtdElementos;
            scanf("%d", &qtdElementos);

            for (int j = 0; j < qtdElementos; j++){
                int valor;
                scanf("%d", &valor);

                /*Analisando se a entrada da problema*/
                if (valor < 1 || valor > MAX_ELEMENTOS){
                    j--;
                    continue;
                }
                
                /*Achei interessante a ideia de armazenar a quantidade de vezes que o numero eh digitado ao inves dele*/
                conjuntos[i][valor - 1] = 1;
            }
        }
    
    /*Realizando operacoes*/
    int qtdOperacoes;
    scanf("%d", &qtdOperacoes);

    while (qtdOperacoes--){
        
        int interseccao = 0, uniao = 0;
        int operacao, conjunto1, conjunto2;

        scanf("%d %d %d", &operacao, &conjunto1, &conjunto2);

        /*Analisando se as entradas dao problema*/
        if (conjunto1 < 1 || conjunto2 < 1 || conjunto1 > qtdConjuntos || conjunto2 > qtdConjuntos){
            continue;
        }
        
        int resultado;
        for (int i = 0; i < MAX_ELEMENTOS; i++){
            resultado = Operacoes(conjuntos, qtdConjuntos, conjunto1, conjunto2, operacao);
        }

        if (operacao == 1){
            printf("%d\n", resultado);
        }
        else if (operacao == 2){
            printf("%d\n", resultado);
        }   
        }
    }
    return 0;
}