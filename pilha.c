#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

typedef struct {
    int items[SIZE];
    int ultimoElemento;
} Pilha;

// função que inicializa uma Pilha, ela recebe um ponteiro para uma Pilha e seta os ponteiros do primeiro elemento e do ultimo para -1
void inicializar(Pilha* Pilha) {
    Pilha->ultimoElemento = -1;
}

// se o primeiroElemento da lista é -1, então, a lista está vazia
int isEmpty(Pilha* Pilha) {
    if (Pilha->ultimoElemento == -1)
        return 1;
    else
        return 0;
}

int isFull(Pilha* Pilha) {
    if ((Pilha->ultimoElemento == SIZE - 1))
        return 1;
    else
        return 0;
}

void adicionarElemento(Pilha* Pilha, int valor) {
    if (isFull(Pilha)) {
        printf("Não é possível adicionar elemento, lista cheia!.\n");
    } else {
        if (isEmpty(Pilha)) Pilha->ultimoElemento = 0;
        Pilha->ultimoElemento++;
        Pilha->items[Pilha->ultimoElemento] = valor;
        printf("Elemento %d inserido.\n", valor);
    }
}

// simulando a função pop
void removerElemento(Pilha* Pilha) {
    if (isEmpty(Pilha)) {
        printf("Não é possível tirar elementos de uma pilha vazia!.\n");
    } else {
        printf("Elemento %d removido.\n", Pilha->items[Pilha->ultimoElemento]);
        Pilha->ultimoElemento = Pilha->ultimoElemento - 1;
    }
}

void apresentarElementos(Pilha* Pilha) {
	int i = 0;
	
    if (isEmpty(Pilha)) {
        printf("[]\n");
    } else {
        printf("[");

		for (i = 1; i < Pilha->ultimoElemento; i++) {
			printf("%i, ", Pilha->items[i]);
		}

        printf("%d]\n", Pilha->items[i]);
    }
}

int main() {
    Pilha Pilha;
    inicializar(&Pilha);

    adicionarElemento(&Pilha, 1);
    adicionarElemento(&Pilha, 2);
    adicionarElemento(&Pilha, 3);
    adicionarElemento(&Pilha, 4);
    adicionarElemento(&Pilha, 5);
    adicionarElemento(&Pilha, 6);

    apresentarElementos(&Pilha);

    removerElemento(&Pilha);
    removerElemento(&Pilha);    
	removerElemento(&Pilha);

    apresentarElementos(&Pilha);
}
