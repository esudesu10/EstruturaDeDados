#include <stdio.h>
#include <string.h>

#define MAX_ALUNOS 10

struct Aluno {
    char nome[50];
    int nota;
    char turma[3];
};

int main() {
    struct Aluno alunos[MAX_ALUNOS];
    int i, maxNota = 0, countMaxNota = 0;
    int countTurmaA1 = 0, countTurmaB2 = 0, countTurmaC3 = 0, countTurmaD4 = 0;

    printf("Informe os dados dos alunos:\n");

    // Leitura dos dados dos alunos
    for (i = 0; i < MAX_ALUNOS; i++) {
        printf("Aluno %d:\n", i + 1);

        printf("Nome: ");
        scanf("%s", alunos[i].nome);

        printf("Nota (entre 1 e 10): ");
        scanf("%d", &alunos[i].nota);

        printf("Turma (A1, B2, C3, ou D4) usando caixa alta: ");
        scanf("%s", alunos[i].turma);

        printf("\n");

        // Verifica se a nota do aluno é a maior encontrada até o momento
        if (alunos[i].nota > maxNota) {
            maxNota = alunos[i].nota;
            countMaxNota = 1;
        } else if (alunos[i].nota == maxNota) {
            countMaxNota++;
        }

        // Contagem da quantidade de alunos por turma com a maior nota
        if (alunos[i].nota == maxNota) {
            if (strcmp(alunos[i].turma, "A1") == 0) {
                countTurmaA1++;
            } else if (strcmp(alunos[i].turma, "B2") == 0) {
                countTurmaB2++;
            } else if (strcmp(alunos[i].turma, "C3") == 0) {
                countTurmaC3++;
            } else if (strcmp(alunos[i].turma, "D4") == 0) {
                countTurmaD4++;
            }
        }
    }

    // Exibição dos alunos com a maior nota
    printf("Alunos com a maior nota (%d):\n", maxNota);
    for (i = 0; i < MAX_ALUNOS; i++) {
        if (alunos[i].nota == maxNota) {
            printf("- Nome: %s\n  Turma: %s\n", alunos[i].nome, alunos[i].turma);
        }
    }
    printf("\n");

    // Exibição da quantidade de alunos por turma com a maior nota
    printf("Quantidade de alunos por turma com a maior nota (%d):\n", maxNota);
    printf("- Turma A1: %d\n", countTurmaA1);
    printf("- Turma B2: %d\n", countTurmaB2);
    printf("- Turma C3: %d\n", countTurmaC3);
    printf("- Turma D4: %d\n", countTurmaD4);

    return 0;
}
