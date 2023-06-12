#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

int main(){
	setlocale(LC_ALL, "Portuguese");
	
	int numeros[10] = {5, 2, 3, 12, 9, 4, 11, 53, 22, 1};
	int numeroProcurado = 12;
	int i = 0;
	
	for (i = 0; i < 10; i++) {
		if (numeros[i] == numeroProcurado) {
			printf("A posição do elemento %i é %i\n\n", numeroProcurado, i);
		}
	}
	system("PAUSE");
}
