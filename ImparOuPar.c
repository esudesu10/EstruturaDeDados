#include <stdio.h>

int main()
{
    int number[10], pares[10], impar[10], j = 0, x = 0;

    for (int i = 0; i < 10; i++)
    {
        printf("Digite um numero: ");
        scanf("%d", &number[i]);
    }
    printf("Todos os numeros: \n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d", number[i]);
    }

    for (int i = 0; i < 10; i++)
    {
        if (number[i] % 2 == 0)
        {
            pares[j++] = number[i];
        }
        else
        {
            impar[x++] = number[i];
        }
    }
    printf("\nSomente os numeros pares: \n");
    for (int i = 0; i < j; i++)
    {
        printf("%d ", pares[i]);
    }

    for (int i = 0; i < j - 1; i++)
    {
        for (int y = 0; y < j - i - 1; y++)
        {
            if (pares[y] > pares[y + 1])
            {
                int aux;
                aux = pares[y];
                pares[y] = pares[y + 1];
                pares[y + 1] = aux;
            }
        }
    }

    printf("\nSomente os numeros pares ordenados: \n");
    for (int i = 0; i < j; i++)
    {
        printf("%d ", pares[i]);
    }

    for (int i = 0; i < x - 1; i++)
    {
        for (int y = 0; y < x - i - 1; y++)
        {
            if (impar[y] < impar[y + 1])
            {
                int aux;
                aux = impar[y];
                impar[y] = impar[y + 1];
                impar[y + 1] = aux;
            }
        }
    }

    printf("\nSomente os numeros impares ordenados: \n");
    for (int i = 0; i < j; i++)
    {
        printf("%d ", impar[i]);
    }
    return 0;
}