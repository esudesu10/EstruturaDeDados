#include <stdio.h>

#define MIN_NUMEROS 10
#define MAX_NUMEROS 20

// Função para validar se um número é ímpar e não é múltiplo de 3
int le_valida_num() {
    int num;
    do {
        printf("Informe um numero impar nao multiplo de 3 (entre 1 e 99): ");
        scanf("%d", &num);

        // if para avisar ao usuario que o numero n pode ser multiplo de 3
        if (num % 3 == 0) {
            printf("Erro: O numero nao pode ser multiplo de 3.\n");
        }
    } while ((num < 1 || num > 99) || (num % 2 == 0 || num % 3 == 0));

    return num;
}

// Função para ordenar os números em ordem decrescente
void bubbleSort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int numeros[MAX_NUMEROS];
    int i, n;

    printf("Informe no minimo 10 e no maximo 20 numeros inteiros.\n");

    // Leitura dos números
    for (i = 0; i < MAX_NUMEROS; i++) {
        if (i == MIN_NUMEROS) {
            char resposta;
            printf("Deseja sair? (S/N): ");
            scanf(" %c", &resposta);
            if (resposta == 'S' || resposta == 's') {
                break;
            }
        }
        numeros[i] = le_valida_num();
    }
    n = i;

    // chamada da função Ordenação dos números em ordem decrescente
    bubbleSort(numeros, n);

    // Exibição dos números ordenados
    printf("\numeros em ordem decrescente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
