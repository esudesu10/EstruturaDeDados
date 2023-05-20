#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FABRICANTES 5
#define MAX_PRODUTOS 50
#define UF_LENGTH 3

typedef struct {
    char descricao[100];
    float peso;
    float valorCompra;
    float valorVenda;
    float valorLucro;
    float percentualLucro;
    char fabricante[50];
} Produto;

typedef struct {
    char marca[50];
    char site[100];
    char telefone[15];
    char uf[UF_LENGTH];
} Fabricante;

void listarMarcas(Fabricante fabricantes[], int numFabricantes) {
    printf("Marcas cadastradas:\n");
    for (int i = 0; i < numFabricantes; i++) {
        printf("%d. %s\n", i + 1, fabricantes[i].marca);
    }
}

void listarProdutos(Produto produtos[], int numProdutos) {
    printf("Produtos cadastrados:\n");
    for (int i = 0; i < numProdutos; i++) {
        printf("%d. %s\n", i + 1, produtos[i].descricao);
    }
}

void listarProdutosPorEstado(Produto produtos[], int numProdutos, Fabricante fabricantes[], int numFabricantes, char estado[]) {
    printf("Produtos cadastrados no estado %s:\n", estado);
    for (int i = 0; i < numProdutos; i++) {
        int fabricanteIndex = -1;
        for (int j = 0; j < numFabricantes; j++) {
            if (strcmp(produtos[i].fabricante, fabricantes[j].marca) == 0) {
                fabricanteIndex = j;
                break;
            }
        }
        if (fabricanteIndex != -1 && strcmp(fabricantes[fabricanteIndex].uf, estado) == 0) {
            printf("%s\n", produtos[i].descricao);
        }
    }
}

void listarProdutosPorMarca(Produto produtos[], int numProdutos, char marca[]) {
    printf("Produtos cadastrados da marca %s:\n", marca);
    for (int i = 0; i < numProdutos; i++) {
        if (strcmp(produtos[i].fabricante, marca) == 0) {
            printf("%s\n", produtos[i].descricao);
        }
    }
}

void encontrarProdutoMaisCaro(Produto produtos[], int numProdutos, Fabricante fabricantes[], int numFabricantes) {
    float maxValor = -1;
    char estados[MAX_PRODUTOS][UF_LENGTH];
    int numEstados = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda > maxValor) {
            maxValor = produtos[i].valorVenda;
            int fabricanteIndex = -1;
            for (int j = 0; j < numFabricantes; j++) {
                if (strcmp(produtos[i].fabricante, fabricantes[j].marca) == 0) {
                    fabricanteIndex = j;
                    break;
                }
            }
            if (fabricanteIndex != -1) {
                strcpy(estados[0], fabricantes[fabricanteIndex].uf);
                numEstados = 1;
            }
        } else if (produtos[i].valorVenda == maxValor) {
            int fabricanteIndex = -1;
            for (int j = 0; j < numFabricantes; j++) {
                if (strcmp(produtos[i].fabricante, fabricantes[j].marca) == 0) {
                    fabricanteIndex = j;
                    break;
                }
            }
            if (fabricanteIndex != -1) {
                int found = 0;
                for (int k = 0; k < numEstados; k++) {
                    if (strcmp(estados[k], fabricantes[fabricanteIndex].uf) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    strcpy(estados[numEstados], fabricantes[fabricanteIndex].uf);
                    numEstados++;
                }
            }
        }
    }
    printf("Estado(s) onde está registrado o produto mais caro:\n");
    for (int i = 0; i < numEstados; i++) {
        printf("%s\n", estados[i]);
    }
}

void encontrarProdutoMaisBarato(Produto produtos[], int numProdutos, Fabricante fabricantes[], int numFabricantes) {
    float minValor = produtos[0].valorVenda;
    char fabricantesBaratos[MAX_PRODUTOS][50];
    int numFabricantesBaratos = 0;
    for (int i = 0; i < numProdutos; i++) {
        if (produtos[i].valorVenda < minValor) {
            minValor = produtos[i].valorVenda;
            strcpy(fabricantesBaratos[0], produtos[i].fabricante);
            numFabricantesBaratos = 1;
        } else if (produtos[i].valorVenda == minValor) {
            int found = 0;
            for (int j = 0; j < numFabricantesBaratos; j++) {
                if (strcmp(fabricantesBaratos[j], produtos[i].fabricante) == 0) {
                    found = 1;
                    break;
                }
            }
            if (!found) {
                strcpy(fabricantesBaratos[numFabricantesBaratos], produtos[i].fabricante);
                numFabricantesBaratos++;
            }
        }
    }
    printf("Fabricante(s) onde está registrado o produto mais barato:\n");
    for (int i = 0; i < numFabricantesBaratos; i++) {
        printf("%s\n", fabricantesBaratos[i]);
    }
}

int compararValorLucro(const void* a, const void* b) {
    Produto* produtoA = (Produto*)a;
    Produto* produtoB = (Produto*)b;
    return produtoA->valorLucro - produtoB->valorLucro;
}

void listarProdutosPorValorLucroCrescente(Produto produtos[], int numProdutos) {
    printf("Produtos em ordem crescente de valor do lucro:\n");
    qsort(produtos, numProdutos, sizeof(Produto), compararValorLucro);
    for (int i = 0; i < numProdutos; i++) {
        printf("%s\n", produtos[i].descricao);
    }
}

int compararValor(const void* a, const void* b) {
    Produto* produtoA = (Produto*)a;
    Produto* produtoB = (Produto*)b;
    return produtoA->valorVenda - produtoB->valorVenda;
}

void listarProdutosPorValorCrescente(Produto produtos[], int numProdutos) {
    printf("Produtos em ordem crescente de valor:\n");
    qsort(produtos, numProdutos, sizeof(Produto), compararValor);
    for (int i = 0; i < numProdutos; i++) {
        printf("%s\n", produtos[i].descricao);
    }
}

int main() {
    Fabricante fabricantes[MAX_FABRICANTES];
    Produto produtos[MAX_PRODUTOS];
    int numFabricantes = 0;
    int numProdutos = 0;

    int opcao;
    do {
        printf("\n======= MENU =======\n");
        printf("1. Cadastrar fabricante\n");
        printf("2. Cadastrar produto\n");
        printf("3. Listar todas as marcas\n");
        printf("4. Listar todos os produtos\n");
        printf("5. Listar os produtos de um determinado estado\n");
        printf("6. Listar os produtos de uma determinada marca\n");
        printf("7. Apresentar o(s) estado(s) onde está registrado o produto mais caro\n");
        printf("8. Apresentar o(s) fabricante(s) onde está registrado o produto mais barato\n");
        printf("9. Listar todos os produtos em ordem crescente de valor do lucro\n");
        printf("10. Listar todos os produtos em ordem crescente de valor\n");
        printf("0. Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1: {
                if (numFabricantes < MAX_FABRICANTES) {
                    Fabricante fabricante;
                    printf("Digite a marca: ");
                    scanf(" %[^\n]s", fabricante.marca);
                    printf("Digite o site: ");
                    scanf(" %[^\n]s", fabricante.site);
                    printf("Digite o telefone: ");
                    scanf(" %[^\n]s", fabricante.telefone);
                    printf("Digite a UF: ");
                    scanf(" %[^\n]s", fabricante.uf);
                    fabricantes[numFabricantes] = fabricante;
                    numFabricantes++;
                    printf("Fabricante cadastrado com sucesso!\n");
                } else {
                    printf("Número máximo de fabricantes atingido!\n");
                }
                break;
            }
            case 2: {
                if (numProdutos < MAX_PRODUTOS) {
                    Produto produto;
                    printf("Digite a descrição: ");
                    scanf(" %[^\n]s", produto.descricao);
                    printf("Digite o peso: ");
                    scanf("%f", &produto.peso);
                    printf("Digite o valor de compra: ");
                    scanf("%f", &produto.valorCompra);
                    printf("Digite o valor de venda: ");
                    scanf("%f", &produto.valorVenda);
                    produto.valorLucro = produto.valorVenda - produto.valorCompra;
                    produto.percentualLucro = (produto.valorLucro / produto.valorCompra) * 100;
                    printf("Digite o fabricante: ");
                    scanf(" %[^\n]s", produto.fabricante);
                    produtos[numProdutos] = produto;
                    numProdutos++;
                    printf("Produto cadastrado com sucesso!\n");
                } else {
                    printf("Número máximo de produtos atingido!\n");
                }
                break;
            }
            case 3: {
                listarMarcas(fabricantes, numFabricantes);
                break;
            }
            case 4: {
                listarProdutos(produtos, numProdutos);
                break;
            }
            case 5: {
                char estado[UF_LENGTH];
                printf("Digite o estado: ");
                scanf(" %[^\n]s", estado);
                listarProdutosPorEstado(produtos, numProdutos, fabricantes, numFabricantes, estado);
                break;
            }
            case 6: {
                char marca[50];
                printf("Digite a marca: ");
                scanf(" %[^\n]s", marca);
                listarProdutosPorMarca(produtos, numProdutos, marca);
                break;
            }
            case 7: {
                encontrarProdutoMaisCaro(produtos, numProdutos, fabricantes, numFabricantes);
                break;
            }
            case 8: {
                encontrarProdutoMaisBarato(produtos, numProdutos, fabricantes, numFabricantes);
                break;
            }
            case 9: {
                listarProdutosPorValorLucroCrescente(produtos, numProdutos);
                break;
            }
            case 10: {
                listarProdutosPorValorCrescente(produtos, numProdutos);
                break;
            }
            case 0: {
                printf("Encerrando o programa...\n");
                break;
            }
            default: {
                printf("Opção inválida!\n");
                break;
            }
        }
    } while (opcao != 0);

    return 0;
}
