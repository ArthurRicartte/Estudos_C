#include <stdio.h>
#include <math.h>
#include <time.h>

/*Funcao EhPrimo*/
int EhPrimo(int numero){
    
    /*Numeros negativos nao sao considerados*/
    if (numero <= 1)
        return 0;
    /*O 2 eh primo de cara (nao precisa verificar ele no for)*/
    if (numero == 2)
        return 2;
    
    /*Numeros pares nunca vao ser primos*/
    if (numero % 2 == 0)
        return 0;
    
    double raiz = sqrt(numero);
    /*Se o numero nao tiver nenhum divisor ate sua raiz quadrada -> nao eh primo; contador += 2, pois numero par nunca eh primo (exceto o 2);
    comeca com contador = 3, pois ja verificamos o 2 e o 1.*/
    for (int contador = 3; contador <= raiz; contador += 2){
        if (numero % contador == 0)
            return 0;
    }

    return 1;
}

int main(void){
    
    int casos, num1;
    clock_t inivio, fim;

    inivio = clock();
    scanf("%d", &casos);

    for (int contador = 1; contador <= casos; contador++){
        
        scanf("%d", &num1);
        printf("%sPrime\n", EhPrimo(num1) ? "" : "Not ");
    }
    fim = clock();

    double tempo_de_cpu = ((double) (fim - inivio)) / CLOCKS_PER_SEC;
    printf("%lf", tempo_de_cpu);
    return 0;
}