#include <stdio.h>

//Define para armazenar valores fixos que não podem ser modificados durante a execução
#define MIN_NUMEROS 10
#define MAX_NUMEROS 20

//void para fazer a função de leitura e validação
void le_valida_num(int *num) {
    int valido = 0;
    while (!valido) {
        printf("Digite um numero inteiro entre 1 e 99: ");
        scanf("%d", num);
        if (*num >= 1 && *num <= 99) {
            valido = 1;
        } else {
            printf("Digite um numero inteiro entre 1 e 99 apenas.\n");
        }
    }
}

//void para o bubbleSort
void bubbleSort(int numeros[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (numeros[j] > numeros[j + 1]) {
                int temp = numeros[j];
                numeros[j] = numeros[j + 1];
                numeros[j + 1] = temp;
            }
        }
    }
}


int main() {
    //declaração de variáveis
    int numeros[MAX_NUMEROS];
    int qtde_numeros = 0;
    int i;

    printf("Digite pelo menos %d e no máximo %d números inteiros.\n", MIN_NUMEROS, MAX_NUMEROS);

    // leitura de dados
    for (i = 0; i < MAX_NUMEROS; i++) {
        int num;
        le_valida_num(&num);//aqui é a chamada da função para verificar se o número esta entre 1 e 99

        numeros[i] = num;
        qtde_numeros++;

        //if para decidir se quer continuar ou não
        if (qtde_numeros >= MIN_NUMEROS) {
            char opcao;
            printf("Deseja sair? (S/N): ");
            scanf(" %c", &opcao);
            if (opcao == 'S' || opcao == 's') { // || para aceitar tanto S maiúsculo quanto minúsculo
                break;
            }//o deseja sair vai rodar a cada vez que passar de 10 por estar dentro de um for
        }
    }

    // Ordenação utilizando bubble sort
    bubbleSort(numeros, qtde_numeros);

    // Apresentação dos números ordenados
    printf("Numeros em ordem crescente:\n");
    for (i = 0; i < qtde_numeros; i++) {
        printf("%d ", numeros[i]);
    }
    printf("\n");

    return 0;
}
