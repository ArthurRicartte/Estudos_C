#include "Alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void){
    //Lendo o arquivo
    FILE* arquivo = fopen("alunos.txt", "r");

    //Caso tenha algum error
    if (arquivo == NULL){
        printf("Erro ao abrir o arquivo\n");
        return 1;
    }

    //Criando um vetor e variaveis axuliares
    Vetor* vetor = vet_cria();
    Aluno temp;
    char linha[81];

    //Lendo cada linha do arquivo ate ancontrar uma vazia
    while (fgets(linha, sizeof(linha), arquivo) != NULL){
        
        // Remover o '\n' do final do nome
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(temp.nome, linha);

        //Ler as tres notas:
        if (fgets(linha, sizeof(linha), arquivo) == NULL){
            break;
        }

        //Lendo as tres linhas e armazenando em temp
        sscanf(linha, "%f %f %f", &temp.p1, &temp.p2, &temp.p3);
        vet_adiciona(vetor, &temp);
    }

    //fechar arquivo:
    fclose(arquivo);

    //Exibir dados:
    printf("Alunos cadastrados:\n");
    for(int i = 0; i < vet_tamanho(vetor); i++){
        Aluno* a = vet_acessa(vetor, i);
        printf("%s: %.1f %.1f %.1f\n", a -> nome, a -> p1, a -> p2, a -> p3);
    }

    //Liberar vet da memoria:
    vet_libera(vetor);
    return 0;   
}