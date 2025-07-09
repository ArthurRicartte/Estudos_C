#include <stdio.h>

/*Criando funcao (nao sei se ficou legal pela quantidade de paramentros)
para saber se realmente existe um padrao os parametros linhas e colunas servem para "alimentar o array", 
com seu tamnho digitado digitado pelo usuario.
*/

int TemPadrao(int linhas, int colunas, int array[linhas][colunas], int linhaCentral, int colunaCentral){
    /*Distancia linha e coluna comecam com -1 pois, so importa os vizinhos (da esquerda (-1) e direita (+)) do 42 
    (nesse caso eh identificado quando ambas as distancias forem 0)*/
    
    for (int distanciaLinha = -1; distanciaLinha <= 1; distanciaLinha++){
        for (int distanciaColuna = -1; distanciaColuna <= 1; distanciaColuna++){
            
            /*Vamos verificar se o for passa na celula central matriz[0][0], se passar
            vamos so ignorar pois queremos saber de seus vizinhos*/

            if (distanciaLinha == 0 && distanciaColuna == 0){
                continue;
            }

            if (array[linhaCentral + distanciaLinha][colunaCentral+ distanciaColuna] != 7){
                return 0;
            }
        } 
    }

    return 1;
    
}

int main(void){
    
    /*l -> linhas; c -> colunas*/
    
    /*Lendo linhas e colunas*/
    int l, c;
    scanf("%d %d", &l, &c); 
    
    /*Lendo os valores para a nmatriz*/

    int matriz[l][c];

    for (int linha = 0; linha < l; linha++){
        for (int coluna = 0; coluna < c; coluna++){
            scanf("%d", &matriz[linha][coluna]);
        }
        
    }

    int x = 0, y = 0;

    /*Esse bloco de código vai encontrar algum valor que seja o 42
    se encontrar -> Salva as coordendas de linha e coluna e manda para a funcao
    que vai analizar os valores vizinhos e ve se eh um sabre.*/
    
    for (int linha = 1; linha < l - 1; linha++){
        for (int coluna = 1; coluna < c - 1; coluna++){
            if (matriz[linha][coluna] == 42){
                int ehSabre = TemPadrao(l, c, matriz, linha, coluna);

                /*Se for sabre, ele vai salvar as coordenada para exibir depois*/
                if (ehSabre){
                    x = linha + 1;
                    y = coluna + 1;
                    break;
                }    
            }
        
        /*A questao pede para que se encontra um padrao, interrompa o codigo*/
        if (x != 0)
            break;
        }
    }
    
    printf("%d %d\n", x, y);
    return 0;
}