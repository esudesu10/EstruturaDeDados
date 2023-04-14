#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main()
{
    char nome[100];
    char nomeFormat[100];
    int count[2];
    int j = 0;

    printf("Digite um nome: ");
    fgets(nome, 100, stdin);

    for (int i = 0; i < strlen(nome); i++)
    {
        if (nome[i] == ' ')
        {
            count[j++] = i;
        }
    }
    for (int i = count[--j] + 1; i < strlen(nome) - 1; i++)
    {
        printf("%c", toupper(nome[i]));
        if (i == strlen(nome) - 2)
        {
            printf(" %c. ", toupper(nome[0]));
            for (int x = count[j - j] + 1; x < count[j - j] + 2; x++)
            {
                printf("%c.", toupper(nome[x]));
            }
        }
    }

    printf("\n");

    for (int i = count[j] + 1; i < strlen(nome) - 1; i++)
    {
        printf("%c", toupper(nome[i]));
        if (i == strlen(nome) - 2)
        {
            printf("%c", toupper(nome[0]));
            for (int x = count[j - j] + 1; x < count[j - j] + 2; x++)
            {
                printf("%c", toupper(nome[x]));
            }
        }
    }

    printf("\n");

    for (int i = count[j] + 1; i < strlen(nome) - 1; i++)
    {
        if (toupper(nome[i]) == 'A' || toupper(nome[i]) == 'E' || toupper(nome[i]) == 'I' || toupper(nome[i]) == 'O' || toupper(nome[i]) == 'U')
        {
            printf("%d", toupper(nome[i]));
        }
        else
        {
            printf("%c", toupper(nome[i]));
        }

        if (i == strlen(nome) - 2)
        {
            if (toupper(nome[0]) == 'A' || toupper(nome[0]) == 'E' || toupper(nome[0]) == 'I' || toupper(nome[0]) == 'O' || toupper(nome[0]) == 'U')
            {
                printf("%d", toupper(nome[i]));
            }
            else
            {
                printf("%c", toupper(nome[i]));
            }

            for (int x = count[j - j] + 1; x < count[j - j] + 2; x++)
            {
                if (toupper(nome[x]) == 'A' || toupper(nome[x]) == 'E' || toupper(nome[x]) == 'I' || toupper(nome[x]) == 'O' || toupper(nome[x]) == 'U')
                {
                    printf("%d", toupper(nome[x]));
                }
                else
                {
                    printf("%c", toupper(nome[x]));
                }
            }
        }
    }
}