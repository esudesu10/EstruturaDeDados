#include <stdio.h>

#define MIN_NUMEROS 2
#define MAX_NUMEROS 10

// Função para validar se um número é ímpar e não é múltiplo de 3
int le_valida_num() {
    int num;
    do {
        printf("Informe um numero par nao multiplo de 5 (entre 1 e 99): ");
        scanf("%d", &num);

        // if para avisar ao usuario que o numero n pode ser multiplo de 3
        if (num % 5 == 0 || num % 2 == 1) {
            printf("Erro: O numero nao pode ser multiplo de 5 e nem impar.\n");
        }
    } while ((num % 2 != 0) || (num % 5 == 0));

    return num;
}

//crescente
void bubbleSortCrescente (int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//decrescente
void bubbleSortDecrescente(int arr[], int n) {
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

    printf("Informe no minimo 2 e no maximo 10 numeros inteiros.\n");

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

    // Ordenação dos números em ordem crescente
    bubbleSortCrescente(numeros, n);
    // Exibição dos números ordenados
    printf("\numeros em ordem crescente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    bubbleSortDecrescente(numeros, n);
    printf("\numeros em ordem decrescente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
