#include <stdio.h>
#include <string.h>

int main()
{
    char nome[100], referencia[20], token[20];
    int i, j = 0;

    // solicita o nome completo do usuário
    printf("Digite o nome completo: ");
    fgets(nome, 100, stdin);
    nome[strcspn(nome, "\n")] = 0;

    // gera a referência
    referencia[0] = nome[strlen(nome) - 1];
    referencia[1] = '.';
    j = 2;
    for (i = 0; i < strlen(nome); i++)
    {
        if (nome[i] == ' ')
        {
            referencia[j] = nome[i + 1];
            referencia[j + 1] = '.';
            j += 2;
        }
    }
    referencia[j] = '\0';

    // gera o token
    j = 0;
    for (i = strlen(referencia) - 1; i >= 0; i--)
    {
        if (referencia[i] != ' ' && referencia[i] != '.')
        {
            if (referencia[i] == 'A' || referencia[i] == 'a')
            {
                token[j] = '6';
            }
            else if (referencia[i] == 'E' || referencia[i] == 'e')
            {
                token[j] = '7';
            }
            else if (referencia[i] == 'I' || referencia[i] == 'i')
            {
                token[j] = '8';
            }
            else if (referencia[i] == 'O' || referencia[i] == 'o')
            {
                token[j] = '9';
            }
            else if (referencia[i] == 'U' || referencia[i] == 'u')
            {
                token[j] = '0';
            }
            else
            {
                token[j] = referencia[i];
            }
            j++;
        }
    }
    token[j] = '\0';

    // exibe a referência e o token gerados
    printf("\nReferência: %s\nToken: %s\n", referencia, token);

    return 0;
}
