#include <stdio.h>

int Verifica(float a, float b, float c){

    if (a + b > c){
        if (b + c > a){
            if (a + c > b){
                return 1;       
            }
        }
    }

    return 0;
}


int main (void){

    float a, b, c;
    float result;

    scanf("%f %f %f", &a, &b, &c);
    
    int ehTriangulo = Verifica(a, b, c);

    if (ehTriangulo){
        result = a + b + c;
        printf("Perimetro = %.1f\n", result);
    } else{
        result = ((a + b)* c)/ 2;
        printf("Area = %.1f\n", result);
    }
        
    return 0;
}