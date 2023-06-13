#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int tamanhoLista = 10;
	int numeros[10] = {5, 2, 3, 12, 9, 4, 11, 53, 22, 1};
	int numeroProcurado = 3;
	
	int posicaoNumeroProcurado = buscaBinaria(numeros, tamanhoLista, 0, numeroProcurado);
	printf("O elemento %i estava na posição: %i", numeroProcurado, posicaoNumeroProcurado);
}


int buscaBinaria (int *vetor, int direita, int esquerda, int elementoProcurado) {
	
	while(esquerda <= direita) {
		int posicaoElementoDoMeio = esquerda + (direita - esquerda)/2;
		int elementoDoMeio = vetor[posicaoElementoDoMeio];
		printf("s");
		if (elementoDoMeio == elementoProcurado) {
			return posicaoElementoDoMeio;
		} else if (elementoDoMeio > elementoProcurado) {
			direita = posicaoElementoDoMeio - 1;
		} else {
			esquerda = posicaoElementoDoMeio + 1;
		}
	}
	// indica que a operação não encontrou o elemento igual
	return -1;

}
