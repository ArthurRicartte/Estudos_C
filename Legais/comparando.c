#include <stdio.h>
#include <math.h>

// Função para calcular a distância entre dois pontos (x1, y1) e (x2, y2)
double calcularDistancia(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int C;
    scanf("%d", &C); // Lê o número de casos de teste

    for (int c = 0; c < C; c++) {
        int N;
        scanf("%d", &N); // Lê o número de bolas

        int brancaX, brancaY;
        scanf("%d %d", &brancaX, &brancaY); // Lê a posição da bola branca

        int maisProxima = 1;
        double menorDistancia = -1;

        for (int i = 1; i <= N; i++) {
            int bolaX, bolaY;
            scanf("%d %d", &bolaX, &bolaY); // Lê a posição da bola i

            double distancia = calcularDistancia(brancaX, brancaY, bolaX, bolaY);

            if (menorDistancia == -1 || distancia < menorDistancia) {
                menorDistancia = distancia;
                maisProxima = i;
            }
        }

        printf("%d\n", maisProxima); // Imprime o número da bola mais próxima
    }

    return 0;
}