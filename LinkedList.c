/*
	Autor: CAIO OLIVEIRA MARQUES
	Projeto: construção de uma lista ligada com várias operações
*/


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// definição do tipo elemento, que tem o valor (no caso inteiro) e aponta para um próximo elemento
typedef struct Elemento{
	struct Elemento *proximo;
	int valor;
} Elemento;

// declaração de todas as funções que serão implementadas posteriomente
Elemento *criarElemento(int valor);
Elemento *adicionarElementoFinal(int valor, Elemento *lista);
Elemento *adicionarElementoInicio(int valor, Elemento *lista);
Elemento *removerElementoNoFinal(Elemento *lista);
Elemento *removerElementoNoInicio(Elemento *lista);
Elemento *adicionarElementoPosicao(Elemento *lista, int posicao, int elemento);
Elemento *removerElementoPosicao(Elemento *lista, int posicao);
void imprimeLista(Elemento *inicial);
int contarElementos(Elemento *lista);
void imprimeNumeroNaPosicao(Elemento *lista, int posicao);

int main(){
	// declaração das variáveis que vão ser usadas no programa
	int escolha, numeroInicial, i, n, quantidade;
	Elemento *lista;
	
	setlocale(LC_ALL, "Portuguese");
	
	// menu inicial, com apenas duas opções
	printf("====== LISTA LIGADA ========\n\n");
	printf("1) Criar lista\n");
	printf("2) Sair do programa\n\n");
	printf("Digite a sua escolha: ");
	scanf("%i", &escolha);
	fflush(stdin);
	
	switch (escolha){
		case 1: 
			// pedir o primeiro número que vai começar a lista
			printf("Digite o número inicial: ");
			scanf("%i", &numeroInicial);
			fflush(stdin);
			
			//criando a lista
			lista = criarElemento(numeroInicial);
			break;
		case 2:
			// terminando o programa
			return 0;
		default: 
			// caso o usuário digite um número que não está na lista de opções, o programa é reiniciado
			printf("Não conseguimos entender... tente novamente\n\n");
			system("PAUSE");
			system("CLS");
			main();
			break;
	}
	
	// agora é a segunda lista, que tem as opções de manipulação da lista já criada anteriormente
	while(1){
		// exibição do menu
		system("CLS");
		printf("====== LISTA LIGADA ========\n\n");
		printf("1) Adicionar elemento no início\n");
		printf("2) Adicionar elemento no final\n");
		printf("3) Adicionar elemento em qualquer posição\n");
		printf("4) Remover elemento no início\n");
		printf("5) Remover elemento no final\n");
		printf("6) Remover elemento em qualquer posição\n");
		printf("7) Imprimir a lista na tela\n");
		printf("8) Contar quantos elementos tem na lista\n");
		printf("9) procurar número por posição\n");
		printf("10) Encerrar o programa\n\n");
		
		//capta a escolha do usuário
		printf("Digite a sua escolha: ");
		scanf("%i", &escolha);
		fflush(stdin);
	
		// verifica a escolha do usuário
		switch (escolha){
			case 1:
				//adiciona um elemento digitado pelo usuário no início 
				n = 0;
				printf("Digite o número adicionado: ");
				scanf("%i", &n);
				fflush(stdin);
				lista = adicionarElementoInicio(n, lista);
				break;
			case 2:
				//adiciona um elemento digitado pelo usuário no final
				n = 0;
				printf("Digite o número adicionado: ");
				scanf("%i", &n);
				fflush(stdin);
				lista = adicionarElementoFinal(n, lista);
				break;
			case 3:
				// trecho de código que capta qual o número que o usuário quer colocar na lista.
				n = 0;
				puts("Digite o número adicionado: ");
				scanf("%i", &n);
				fflush(stdin);
				
				// trecho de código que capta em que posição o usuário quer que o número seja adicionado na lista
				i = 0;
				puts("Digite a posição da lista que o número será adicionado: ");
				scanf("%i", &i);
				fflush(stdin);
				
				// chama a função que é incumbida de fazer isso e termina a execução do switch.
				lista = adicionarElementoPosicao(lista, i, n);
				break;				
			case 4:
				// chama a função que remove um elemento no início
				lista = removerElementoNoInicio(lista);
				break;
			case 5:
				// chama a função que remove um elemento no final
				lista = removerElementoNoFinal(lista);
				break;
			case 6:
				// trecho de código que capta a posição da lista que o usuário quer que seja removida.	
				i = 0;
				printf("Digite a posição da lista que o número será removido: ");
				scanf("%i", &i);
				fflush(stdin);
				
				lista = removerElementoPosicao(lista, i);
				break;				
			case 7:
				// chama a função que imprime todos os elementos da lista nesse formato: [1, 2, 3]
				imprimeLista(lista);
				printf("\n\n");
				// pausa a execução do programa para o usuário conseguir ver o resultado.
				system("PAUSE");
				break;
			case 8:
				// retorna a quantidade de elementos que já estão dentro da lista
				quantidade = contarElementos(lista);
				// imprime o resultado e encerra a execução do switch
				printf("\n\nA quantidade de elementos na lista é: %i\n\n", quantidade);
				system("PAUSE");
				break;
			case 9:
				// trecho de código que capta a posição que o usuário quer que seja consultada dentro da lista
				n = 0;
				printf("Digite a posição que você quer consultar: ");
				scanf("%i", &n);
				fflush(stdin);
				
				// chama a função que faz isso passando como argumento o que o usuário escreveu.
				imprimeNumeroNaPosicao(lista, n);
				break;

			case 10:
				// finaliza o programa
				return 0;
			default: 
				// caso o usuário tenha digitado uma opção que não está no menu, explique para ele, e reinicia o programa
				printf("Não conseguimos entender... tente novamente\n\n");
				system("PAUSE");
				system("CLS");
				continue;
		}
	}
}

// devolve o número que está na posição da lista passadas como argumento.
void imprimeNumeroNaPosicao(Elemento *lista, int posicao){
	// trecho de código que verifica se a posição passada pelo usuário existe dentro da lista
	int quantidadeElementos = contarElementos(lista);
	if(quantidadeElementos <= posicao){
		printf("Não existe nenhum número nessa posição...\n\n");
		system("PAUSE");
		return 0;
	}
	
	// declaração de variáveis
	int numero = 0;
	Elemento *temp = lista;
	int contador = 0;

	// percorre a lista em busca do elemento na posição passada como argumento
	while(1){
		// se o elemento não tiver um próximo (último elemento da lista
		// ou se o contador encontrou a posição desejada, o número é o valor do elemento nessa posição, 
		//o laço é interrompido.	
		if(temp->proximo != NULL || contador == posicao){
			numero = temp->valor;
			break;
		}
		else{
			temp = temp->proximo;
			contador++;	
		}
	}
	
	//imprime o resultado na tela.
	printf("\n\nO número que está na posição %i é: %i\n\n", posicao, numero);
	system("PAUSE");
}


// função que recebe uma lista e um número que indica de qual posição é o elemento que deve ser removido 
// da lista, retorna uma versão da lista com esse elemento removido.
Elemento *removerElementoPosicao(Elemento *lista, int posicao){
	if(lista == NULL){
		printf("Não há nenhum elemento nessa lista...\n\n");
		system("PAUSE");
		return NULL;
	}

	// se a posição passada é 0 a função é delegada para outra, que remove o elemento da primeira posição
	if(posicao == 0) return removerElementoNoInicio(lista);

	
	Elemento *temp = lista, *removido;
	int contador = 0;
	
	// percorre a lista até chegar na posição desejada
	while(temp->proximo != NULL){
		if(contador == posicao - 1){
			// na posição desejada deve-se trocar o ponteiro do anterior para o elemento a duas posições a frente dele, assim deixando o elemento do meio sem ninguém apontando para ele.
			removido = temp->proximo;
			temp->proximo = temp->proximo->proximo;
			// libera a memória do objeto removido;
			free(removido);
		}
		temp = temp->proximo;
		contador++;
	}
	// retorna a lista com o elemento da posição passada já removido
	return lista;
}


// adiciona um número na lista na posições passados pelo usuário (vale lembrar que a primeira posição é 0
Elemento *adicionarElementoPosicao(Elemento *lista, int posicao, int valor){
	// verifica se a posição é 0 pois é só usar outra função que já adiciona um número no início
	if(posicao == 0){
		return adicionarElementoInicio(valor, lista);
	}
	
	//protegendo o código contra uma lista nula, exibindo uma mensagem para o usuário
	if(lista == NULL){
		printf("Impossível adicionar o elemento nessa posição...\n\n");
		system("PAUSE");
		return NULL;		
	} 
	
	// cria um elemento com o valor passado pelo usuário, cria um contador e uma variável referência temp
	Elemento *novo = criarElemento(valor);
	int contador = 0;
	Elemento *temp = lista;
	
	// percorre a função até o final ou até o contador achar a posição passada como argumento
	while(temp->proximo != NULL){
		// ao achar a posição, trocam-se os ponteiros e termina a função
		if(contador == posicao - 1){
			novo->proximo = temp->proximo;
			temp->proximo = novo;
			break;
		}
		// caso ainda não se achou a posição pedida para o usuário, aumenta um no contador e percorre o
		//próximo elemento.
		contador++;
		temp = temp->proximo;
	}
	
	// retorna a lista com o número adicionado
	return lista;
}

int contarElementos(Elemento *lista){
	// se não tiver nenhum elemento na lista, retorne 0
	if(lista == NULL) return 0;

	int quantidade = 1;
	Elemento *temp = lista;
	// se tiver 2 elementos ou mais, percorra a lista contando um a cada elemento que passar
	while(temp->proximo != NULL){
		quantidade++;
		temp = temp->proximo;
	}
	// no final retorne esse número.
	return quantidade;
}

// função que recebe o primeiro elemento de uma lista e retorna uma versão dela sem o último elemento
Elemento *removerElementoNoFinal(Elemento *lista){
	// se a lista estiver vazia deve-se retornar NULL e mostrar para o usuário.
	if(lista == NULL){
		printf("Não foi possível realizar a operação...\n\n");
		system("PAUSE");
		return NULL;
	}
	
	Elemento *temp = lista;
	
	// percorrer a lista até a variável "temp" apontar para o penúltimo elemento.
	for(temp = lista; temp->proximo->proximo != NULL; temp = temp->proximo);
	
	// ao descobrir o penúltimo elemento da lista, o programa vai liberar o espaço do último, e vai trocar a referência de "próximo" do penúltimo para NULL
	free(temp->proximo);
	temp->proximo = NULL;
	return lista;
}

// esse programa recebe o primeiro elemento de um lista e retorna uma versão da mesma sem o primeiro elemento
Elemento *removerElementoNoInicio(Elemento *lista){
	// se a lista estiver vazia deve-se retornar NULL e mostrar para o usuário.
	if(lista == NULL){
		printf("Não foi possível realizar a operação...\n\n");
		system("PAUSE");
		return NULL;
	}	
	
	Elemento *segundoElemento = lista->proximo;
	
	
	// se só tem um elemento, retorna nulo
	if(lista->proximo == NULL){
		// libera o endereço da memória do primeiro elemento da lista e retorna uma lista vazia

		free(lista);
		return NULL;	
	} 
	// se tiver 2 elementos ou mais, retorna o próximo elemento depois do primeiro
	else{
		// libera o endereço da memória do primeiro elemento da lista e retorna o segundo.
		free(lista);
		return segundoElemento;
	}
}

// função que recebe uma lista ligada e um número
// e devolve uma versão desta lista com o número passado no final.
Elemento *adicionarElementoFinal(int valor, Elemento *lista){	
	// cria um elemento com o valor passado
	Elemento *novo;
	novo = criarElemento(valor);
	
	// se a lista estiver vazia, apenas devolva o elemento digitado pelo usuário
	if(lista == NULL){
		return novo;
	}

	// caso contrário percorra a lista até achar o último elemento, colocando a variável "próximo"
	// dele como o elemento construído com o valor passado na função
	Elemento *temp = lista;
	while(1){
		if(temp->proximo){
			temp = temp->proximo;
		}
		else{
			temp->proximo = novo;
			// retorna a lista com o novo número adicionado
			return lista;	
		}
	}
}

// função que recebe uma lista e um número, retornando uma versão da lista passada com o elemento passado
// como argumento da função como valor inicial dessa lista.
Elemento *adicionarElementoInicio(int valor, Elemento *lista){
	// criando um elemento com o valor passado como argumento
	Elemento *novo = criarElemento(valor);

	/*
		caso a função não esteja vazia, o programa vai usar o nodo passado como argumento para referenciar
		a lista, e depois retornará (se a lista passada for vazia, o programa só irá retornar o próprio
		nodo criado.
	*/
	
	if(lista != NULL) novo->proximo = lista;
	return novo;
}

// função que cria um nodo (apelidado nesse programa como "elemento", recebendo
Elemento *criarElemento(int valor){
	//alocando espaço pra um elemento usando a função malloc
	Elemento *criado = (struct Elemento*)malloc(sizeof(struct Elemento));
	// o valor desse nodo é passado pelo usuário e não referencia nenhum outro nodo
	criado->valor = valor;
	criado->proximo = NULL;
	// por fim esse nodo é retornado para a parte do código na qual foi chamado
	return criado;
}

// função que imprime na tela a lista nesse formado: [1, 2, 3, 4]
void imprimeLista (Elemento *inicial){
	Elemento *temp;
	
	// se a função estiver vazia, imprime "[]" e finalize a função
	if(inicial == NULL){
		printf("[]");
		return;
	}
	
	// trecho de código que percorre a lista imprimindo seus elementos um por um.	
	printf("[");
	for(temp = inicial; temp->proximo != NULL; temp = temp->proximo){
		printf("%i, ", temp->valor);
	}
	
	printf("%i]", temp->valor);
}
