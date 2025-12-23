#ifndef ALUNOS_H
#define ALUNOS_H

//Qualquer arquivo que incluir .h pode usar de forma direta essa struct (por issp esta aqui)
typedef struct aluno Aluno;
struct aluno {
    char nome[81];
    float p1, p2, p3;
};

typedef struct vetor Vetor;

// Cria um vetor vazio
Vetor* vet_cria(void);

// Libera a memória do vetor e dos alunos armazenados
void vet_libera(Vetor* v);

// Adiciona um aluno ao final do vetor (copia os dados)
void vet_adiciona(Vetor* v, Aluno* a);

// Retorna o número de alunos no vetor
int vet_tamanho(Vetor* v);

// Retorna o aluno na posição i
Aluno* vet_acessa(Vetor* v, int i);

#endif