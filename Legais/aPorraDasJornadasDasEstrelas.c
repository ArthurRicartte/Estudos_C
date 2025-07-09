#include <stdio.h>

int main() {
    unsigned int casos;
    scanf("%d", &casos);
    
    int estrelas[casos];
    int visitadas[casos];

    for (int i = 0; i < casos; i++) {
        scanf("%d", &estrelas[i]);
    }
    
    int atacadas = 0;
    
    /*Ninguem foi visitado ainda*/
    for (int i = 0; i < casos; i++) {
        visitadas[i] = 0;
    }
    
    int pos = 0;

    while (pos >= 0 && pos < casos) {
        
        /*Verificando se ja foi visitado*/
        if (visitadas[pos] == 0){   
            atacadas++;
            visitadas[pos] = 1;
        }
        
        
        if (estrelas[pos] > 0) {

            if (estrelas[pos] % 2 == 1) {
                estrelas[pos]--; /*Rouba um carneiro*/
                pos++; /*Segue para a próxima estrela*/
            
            } else {
                estrelas[pos]--; /*Rouba um carneiro*/
                pos--; /*Volta para a estrela anterior*/
            }
        } else {
            break; /*Se não há carneiros na estrela atual, encerra*/
        }
    }
    
    long long int carneiros_restantes = 0;
    for (int i = 0; i < casos; i++) {
        carneiros_restantes += estrelas[i];
    }
    
    printf("%d %lld\n", atacadas, carneiros_restantes);
    
    return 0;
}
