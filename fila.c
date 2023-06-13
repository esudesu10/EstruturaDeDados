#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int items[SIZE];
    int primeiroElemento;
    int ultimoElemento;
} Fila;

// função que inicializa uma fila, ela recebe um ponteiro para uma fila e seta os ponteiros do primeiro elemento e do ultimo para -1
void inicializar(Fila* fila) {
    fila->primeiroElemento = -1;
    fila->ultimoElemento = -1;
}

// se o primeiroElemento da lista é -1, então, a lista está vazia
int isEmpty(Fila* fila) {
    if (fila->primeiroElemento == -1)
        return 1;
    else
        return 0;
}

int isFull(Fila* fila) {
    if ((fila->ultimoElemento == 0 && fila->primeiroElemento == SIZE - 1))
        return 1;
    else
        return 0;
}

void adicionarElemento(Fila* fila, int valor) {
    if (isFull(fila)) {
        printf("Não é possível adicionar elemento, lista cheia!.\n");
    } else {
        if (isEmpty(fila)) fila->ultimoElemento = 0;
        fila->primeiroElemento = (fila->primeiroElemento + 1) % SIZE;
        fila->items[fila->primeiroElemento] = valor;
        printf("Elemento %d inserido.\n", valor);
    }
}

void removerElemento(Fila* fila) {
    if (isEmpty(fila)) {
        printf("Não é possível tirar elementos de uma fila vazia!.\n");
    } else {
        printf("Elemento %d removido.\n", fila->items[fila->ultimoElemento]);
        
        if (fila->ultimoElemento == fila->primeiroElemento) {
            inicializar(fila);
        } else {
            fila->ultimoElemento = (fila->ultimoElemento + 1) % SIZE;
        }
    }
}

void apresentarElementos(Fila* fila) {
    if (isEmpty(fila)) {
        printf("[]\n");
    } else {
        printf("[");

        int i = fila->ultimoElemento;
        while (i != fila->primeiroElemento) {
            printf("%d, ", fila->items[i]);
            i = (i + 1) % SIZE;
        }

        printf("%d]\n", fila->items[i]);
    }
}

int main() {
    Fila fila;
    inicializar(&fila);

    adicionarElemento(&fila, 1);
    adicionarElemento(&fila, 2);
    adicionarElemento(&fila, 3);
    adicionarElemento(&fila, 4);
    adicionarElemento(&fila, 5);
    adicionarElemento(&fila, 6);

    apresentarElementos(&fila);

    removerElemento(&fila);
    removerElemento(&fila);    
	removerElemento(&fila);

    apresentarElementos(&fila);
}

