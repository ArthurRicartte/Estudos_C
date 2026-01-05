// main.c - Versão Aprimorada para Testes
#include "Alunos.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Função auxiliar para imprimir informações do vetor
void vet_imprime_info(Vetor* vet) {
    if (!vet) {
        printf("Vetor: NULL\n");
        return;
    }
    printf("Tamanho: %d | Capacidade: %d\n", 
           vet_tamanho(vet), vet->limite);
}

// Função para criar arquivo de exemplo se não existir
void criar_arquivo_exemplo(const char* nome_arquivo) {
    FILE* arquivo = fopen(nome_arquivo, "w");
    if (!arquivo) {
        printf("Erro ao criar arquivo de exemplo\n");
        return;
    }
    
    // Criando dados de exemplo
    fprintf(arquivo, "Ana Silva\n");
    fprintf(arquivo, "8.5 7.0 9.0\n");
    fprintf(arquivo, "Bruno Santos\n");
    fprintf(arquivo, "9.0 8.5 9.5\n");
    fprintf(arquivo, "Carlos Oliveira\n");
    fprintf(arquivo, "6.5 7.5 8.0\n");
    fprintf(arquivo, "Daniela Costa\n");
    fprintf(arquivo, "10.0 9.5 9.0\n");
    fprintf(arquivo, "Eduardo Lima\n");
    fprintf(arquivo, "7.0 6.5 8.5\n");
    fprintf(arquivo, "Fernanda Rocha\n");
    fprintf(arquivo, "8.0 8.0 8.0\n");
    fprintf(arquivo, "Gabriel Alves\n");
    fprintf(arquivo, "5.5 6.0 7.0\n");
    fprintf(arquivo, "Helena Martins\n");
    fprintf(arquivo, "9.5 9.0 9.5\n");
    
    fclose(arquivo);
    printf("Arquivo de exemplo criado: %s\n", nome_arquivo);
}

// Função para testar redimensionamento dinâmico
void teste_redimensionamento() {
    printf("\n=== TESTE DE REDIMENSIONAMENTO DINAMICO ===\n");
    
    Vetor* vet = vet_cria();
    printf("Vetor criado: ");
    vet_imprime_info(vet);
    
    // Adicionar alunos até forçar redimensionamento
    Aluno temp;
    
    printf("\n--- Adicionando alunos (deve redimensionar ao atingir limite) ---\n");
    for (int i = 0; i < 10; i++) {
        sprintf(temp.nome, "Aluno%02d", i+1);
        temp.p1 = 7.0 + (i % 3);
        temp.p2 = 8.0 + (i % 2) * 0.5;
        temp.p3 = 6.0 + (i % 4) * 0.5;
        
        printf("\nAntes de adicionar '%s': ", temp.nome);
        vet_imprime_info(vet);
        
        vet_adiciona(vet, &temp);
        
        printf("Depois de adicionar: ");
        vet_imprime_info(vet);
    }
    
    vet_libera(vet);
}

// Função principal de teste
void teste_completo() {
    const char* nome_arquivo = "alunos.txt";
    
    // Verificar se arquivo existe, senão criar
    FILE* teste = fopen(nome_arquivo, "r");
    if (!teste) {
        criar_arquivo_exemplo(nome_arquivo);
    } else {
        fclose(teste);
    }
    
    printf("=== TESTE DE LEITURA DE ARQUIVO ===\n");
    printf("Lendo dados do arquivo: %s\n", nome_arquivo);
    
    // Abrir arquivo para leitura
    FILE* arquivo = fopen(nome_arquivo, "r");
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo\n");
        return;
    }

    // Criar vetor
    Vetor* vetor = vet_cria();
    Aluno temp;
    char linha[81];

    printf("\n--- Processando arquivo ---\n");
    // Ler cada linha do arquivo até encontrar fim
    while (fgets(linha, sizeof(linha), arquivo) != NULL) {
        // Remover o '\n' do final do nome
        linha[strcspn(linha, "\n")] = '\0';
        strcpy(temp.nome, linha);

        // Ler as três notas
        if (fgets(linha, sizeof(linha), arquivo) == NULL) {
            break;
        }

        // Ler as três notas e armazenar em temp
        if (sscanf(linha, "%f %f %f", &temp.p1, &temp.p2, &temp.p3) == 3) {
            printf("Lendo aluno: %s | Notas: %.1f, %.1f, %.1f\n", 
                   temp.nome, temp.p1, temp.p2, temp.p3);
            vet_adiciona(vetor, &temp);
        } else {
            printf("Erro ao ler notas para: %s\n", temp.nome);
        }
    }

    // Fechar arquivo
    fclose(arquivo);
    
    printf("\n--- Status apos leitura do arquivo ---\n");
    vet_imprime_info(vetor);
    
    // Exibir todos os alunos
    printf("\n=== ALUNOS CADASTRADOS ===\n");
    for(int i = 0; i < vet_tamanho(vetor); i++) {
        Aluno* a = vet_acessa(vetor, i);
        float media = (a->p1 + a->p2 + a->p3) / 3.0;
        printf("%2d. %-20s | Notas: %5.1f, %5.1f, %5.1f | Media: %5.2f\n", 
               i+1, a->nome, a->p1, a->p2, a->p3, media);
    }
    
    // Testar remoção por nome
    printf("\n=== TESTE DE REMOÇÃO ===\n");
    
    // Tentar remover aluno existente
    char nome_remover[] = "Carlos Oliveira";
    printf("Removendo aluno '%s'...\n", nome_remover);
    if (vet_remove_nome(vetor, nome_remover)) {
        printf("Aluno removido com sucesso!\n");
    } else {
        printf("Aluno não encontrado.\n");
    }
    vet_imprime_info(vetor);
    
    // Tentar remover aluno inexistente
    printf("\nTentando remover aluno 'Nolo' (inexistente)...\n");
    if (vet_remove_nome(vetor, "Nolo")) {
        printf("Aluno removido com sucesso!\n");
    } else {
        printf("Aluno 'Nolo' não encontrado (comportamento esperado).\n");
    }
    
    // Exibir alunos após remoção
    printf("\n=== ALUNOS APOS REMOCAO ===\n");
    for(int i = 0; i < vet_tamanho(vetor); i++) {
        Aluno* a = vet_acessa(vetor, i);
        printf("%2d. %s\n", i+1, a->nome);
    }
    
    // Testar remoção por índice
    printf("\n=== TESTE DE REMOCAO POR INDICE ===\n");
    printf("Removendo aluno na posição 2...\n");
    vet_remove(vetor, 1); // Índice 1 = segundo elemento
    
    printf("Status apos remocao: ");
    vet_imprime_info(vetor);
    
    // Adicionar novo aluno manualmente
    printf("\n=== TESTE DE ADICAO MANUAL ===\n");
    Aluno novo = {"Novo Aluno", 6.0, 7.0, 8.0};
    printf("Adicionando '%s'...\n", novo.nome);
    vet_adiciona(vetor, &novo);
    vet_imprime_info(vetor);
    
    // Testar acesso inválido (deve mostrar erro)
    printf("\n=== TESTE DE ACESSO INVALIDO ===\n");
    printf("Tentando acessar indice -1...\n");
    // Isso vai imprimir erro e sair, mas para teste:
    // Aluno* invalido = vet_acessa(vetor, -1);
    
    printf("Tentando acessar indice fora dos limites...\n");
    // Aluno* fora = vet_acessa(vetor, vet_tamanho(vetor) + 1);
    
    // Mostrar lista final
    printf("\n=== LISTA FINAL DE ALUNOS ===\n");
    printf("Total: %d alunos\n", vet_tamanho(vetor));
    for(int i = 0; i < vet_tamanho(vetor); i++) {
        Aluno* a = vet_acessa(vetor, i);
        printf("%2d. %-20s (%.1f, %.1f, %.1f)\n", 
               i+1, a->nome, a->p1, a->p2, a->p3);
    }
    
    // Testar redimensionamento após várias remoções
    printf("\n=== TESTE DE REDIMENSIONAMENTO PARA MENOS ===\n");
    printf("Removendo varios alunos para testar reducao de capacidade...\n");
    
    int tamanho_inicial = vet_tamanho(vetor);
    for (int i = 0; i < tamanho_inicial - 2; i++) {
        vet_remove(vetor, 0); // Sempre remove o primeiro
        printf("Apos remocao %d: ", i+1);
        vet_imprime_info(vetor);
    }
    
    // Liberar memória
    vet_libera(vetor);
    printf("\nVetor liberado da memoria.\n");
}

int main(void) {
    printf("=== PROGRAMA DE TESTE DO VETOR DINAMICO DE ALUNOS ===\n\n");
    
    // Executar teste de redimensionamento primeiro
    teste_redimensionamento();
    
    // Executar teste completo
    teste_completo();
    
    printf("\n=== FIM DOS TESTES ===\n");
    return 0;
}