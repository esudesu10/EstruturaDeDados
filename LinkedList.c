/*
	Autor: CAIO OLIVEIRA MARQUES
	Projeto: constru��o de uma lista ligada com v�rias opera��es
*/


#include<stdio.h>
#include<stdlib.h>
#include<locale.h>

// defini��o do tipo elemento, que tem o valor (no caso inteiro) e aponta para um pr�ximo elemento
typedef struct Elemento{
	struct Elemento *proximo;
	int valor;
} Elemento;

// declara��o de todas as fun��es que ser�o implementadas posteriomente
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
	// declara��o das vari�veis que v�o ser usadas no programa
	int escolha, numeroInicial, i, n, quantidade;
	Elemento *lista;
	
	setlocale(LC_ALL, "Portuguese");
	
	// menu inicial, com apenas duas op��es
	printf("====== LISTA LIGADA ========\n\n");
	printf("1) Criar lista\n");
	printf("2) Sair do programa\n\n");
	printf("Digite a sua escolha: ");
	scanf("%i", &escolha);
	fflush(stdin);
	
	switch (escolha){
		case 1: 
			// pedir o primeiro n�mero que vai come�ar a lista
			printf("Digite o n�mero inicial: ");
			scanf("%i", &numeroInicial);
			fflush(stdin);
			
			//criando a lista
			lista = criarElemento(numeroInicial);
			break;
		case 2:
			// terminando o programa
			return 0;
		default: 
			// caso o usu�rio digite um n�mero que n�o est� na lista de op��es, o programa � reiniciado
			printf("N�o conseguimos entender... tente novamente\n\n");
			system("PAUSE");
			system("CLS");
			main();
			break;
	}
	
	// agora � a segunda lista, que tem as op��es de manipula��o da lista j� criada anteriormente
	while(1){
		// exibi��o do menu
		system("CLS");
		printf("====== LISTA LIGADA ========\n\n");
		printf("1) Adicionar elemento no in�cio\n");
		printf("2) Adicionar elemento no final\n");
		printf("3) Adicionar elemento em qualquer posi��o\n");
		printf("4) Remover elemento no in�cio\n");
		printf("5) Remover elemento no final\n");
		printf("6) Remover elemento em qualquer posi��o\n");
		printf("7) Imprimir a lista na tela\n");
		printf("8) Contar quantos elementos tem na lista\n");
		printf("9) procurar n�mero por posi��o\n");
		printf("10) Encerrar o programa\n\n");
		
		//capta a escolha do usu�rio
		printf("Digite a sua escolha: ");
		scanf("%i", &escolha);
		fflush(stdin);
	
		// verifica a escolha do usu�rio
		switch (escolha){
			case 1:
				//adiciona um elemento digitado pelo usu�rio no in�cio 
				n = 0;
				printf("Digite o n�mero adicionado: ");
				scanf("%i", &n);
				fflush(stdin);
				lista = adicionarElementoInicio(n, lista);
				break;
			case 2:
				//adiciona um elemento digitado pelo usu�rio no final
				n = 0;
				printf("Digite o n�mero adicionado: ");
				scanf("%i", &n);
				fflush(stdin);
				lista = adicionarElementoFinal(n, lista);
				break;
			case 3:
				// trecho de c�digo que capta qual o n�mero que o usu�rio quer colocar na lista.
				n = 0;
				puts("Digite o n�mero adicionado: ");
				scanf("%i", &n);
				fflush(stdin);
				
				// trecho de c�digo que capta em que posi��o o usu�rio quer que o n�mero seja adicionado na lista
				i = 0;
				puts("Digite a posi��o da lista que o n�mero ser� adicionado: ");
				scanf("%i", &i);
				fflush(stdin);
				
				// chama a fun��o que � incumbida de fazer isso e termina a execu��o do switch.
				lista = adicionarElementoPosicao(lista, i, n);
				break;				
			case 4:
				// chama a fun��o que remove um elemento no in�cio
				lista = removerElementoNoInicio(lista);
				break;
			case 5:
				// chama a fun��o que remove um elemento no final
				lista = removerElementoNoFinal(lista);
				break;
			case 6:
				// trecho de c�digo que capta a posi��o da lista que o usu�rio quer que seja removida.	
				i = 0;
				printf("Digite a posi��o da lista que o n�mero ser� removido: ");
				scanf("%i", &i);
				fflush(stdin);
				
				lista = removerElementoPosicao(lista, i);
				break;				
			case 7:
				// chama a fun��o que imprime todos os elementos da lista nesse formato: [1, 2, 3]
				imprimeLista(lista);
				printf("\n\n");
				// pausa a execu��o do programa para o usu�rio conseguir ver o resultado.
				system("PAUSE");
				break;
			case 8:
				// retorna a quantidade de elementos que j� est�o dentro da lista
				quantidade = contarElementos(lista);
				// imprime o resultado e encerra a execu��o do switch
				printf("\n\nA quantidade de elementos na lista �: %i\n\n", quantidade);
				system("PAUSE");
				break;
			case 9:
				// trecho de c�digo que capta a posi��o que o usu�rio quer que seja consultada dentro da lista
				n = 0;
				printf("Digite a posi��o que voc� quer consultar: ");
				scanf("%i", &n);
				fflush(stdin);
				
				// chama a fun��o que faz isso passando como argumento o que o usu�rio escreveu.
				imprimeNumeroNaPosicao(lista, n);
				break;

			case 10:
				// finaliza o programa
				return 0;
			default: 
				// caso o usu�rio tenha digitado uma op��o que n�o est� no menu, explique para ele, e reinicia o programa
				printf("N�o conseguimos entender... tente novamente\n\n");
				system("PAUSE");
				system("CLS");
				continue;
		}
	}
}

// devolve o n�mero que est� na posi��o da lista passadas como argumento.
void imprimeNumeroNaPosicao(Elemento *lista, int posicao){
	// trecho de c�digo que verifica se a posi��o passada pelo usu�rio existe dentro da lista
	int quantidadeElementos = contarElementos(lista);
	if(quantidadeElementos <= posicao){
		printf("N�o existe nenhum n�mero nessa posi��o...\n\n");
		system("PAUSE");
		return 0;
	}
	
	// declara��o de vari�veis
	int numero = 0;
	Elemento *temp = lista;
	int contador = 0;

	// percorre a lista em busca do elemento na posi��o passada como argumento
	while(1){
		// se o elemento n�o tiver um pr�ximo (�ltimo elemento da lista
		// ou se o contador encontrou a posi��o desejada, o n�mero � o valor do elemento nessa posi��o, 
		//o la�o � interrompido.	
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
	printf("\n\nO n�mero que est� na posi��o %i �: %i\n\n", posicao, numero);
	system("PAUSE");
}


// fun��o que recebe uma lista e um n�mero que indica de qual posi��o � o elemento que deve ser removido 
// da lista, retorna uma vers�o da lista com esse elemento removido.
Elemento *removerElementoPosicao(Elemento *lista, int posicao){
	if(lista == NULL){
		printf("N�o h� nenhum elemento nessa lista...\n\n");
		system("PAUSE");
		return NULL;
	}

	// se a posi��o passada � 0 a fun��o � delegada para outra, que remove o elemento da primeira posi��o
	if(posicao == 0) return removerElementoNoInicio(lista);

	
	Elemento *temp = lista, *removido;
	int contador = 0;
	
	// percorre a lista at� chegar na posi��o desejada
	while(temp->proximo != NULL){
		if(contador == posicao - 1){
			// na posi��o desejada deve-se trocar o ponteiro do anterior para o elemento a duas posi��es a frente dele, assim deixando o elemento do meio sem ningu�m apontando para ele.
			removido = temp->proximo;
			temp->proximo = temp->proximo->proximo;
			// libera a mem�ria do objeto removido;
			free(removido);
		}
		temp = temp->proximo;
		contador++;
	}
	// retorna a lista com o elemento da posi��o passada j� removido
	return lista;
}


// adiciona um n�mero na lista na posi��es passados pelo usu�rio (vale lembrar que a primeira posi��o � 0
Elemento *adicionarElementoPosicao(Elemento *lista, int posicao, int valor){
	// verifica se a posi��o � 0 pois � s� usar outra fun��o que j� adiciona um n�mero no in�cio
	if(posicao == 0){
		return adicionarElementoInicio(valor, lista);
	}
	
	//protegendo o c�digo contra uma lista nula, exibindo uma mensagem para o usu�rio
	if(lista == NULL){
		printf("Imposs�vel adicionar o elemento nessa posi��o...\n\n");
		system("PAUSE");
		return NULL;		
	} 
	
	// cria um elemento com o valor passado pelo usu�rio, cria um contador e uma vari�vel refer�ncia temp
	Elemento *novo = criarElemento(valor);
	int contador = 0;
	Elemento *temp = lista;
	
	// percorre a fun��o at� o final ou at� o contador achar a posi��o passada como argumento
	while(temp->proximo != NULL){
		// ao achar a posi��o, trocam-se os ponteiros e termina a fun��o
		if(contador == posicao - 1){
			novo->proximo = temp->proximo;
			temp->proximo = novo;
			break;
		}
		// caso ainda n�o se achou a posi��o pedida para o usu�rio, aumenta um no contador e percorre o
		//pr�ximo elemento.
		contador++;
		temp = temp->proximo;
	}
	
	// retorna a lista com o n�mero adicionado
	return lista;
}

int contarElementos(Elemento *lista){
	// se n�o tiver nenhum elemento na lista, retorne 0
	if(lista == NULL) return 0;

	int quantidade = 1;
	Elemento *temp = lista;
	// se tiver 2 elementos ou mais, percorra a lista contando um a cada elemento que passar
	while(temp->proximo != NULL){
		quantidade++;
		temp = temp->proximo;
	}
	// no final retorne esse n�mero.
	return quantidade;
}

// fun��o que recebe o primeiro elemento de uma lista e retorna uma vers�o dela sem o �ltimo elemento
Elemento *removerElementoNoFinal(Elemento *lista){
	// se a lista estiver vazia deve-se retornar NULL e mostrar para o usu�rio.
	if(lista == NULL){
		printf("N�o foi poss�vel realizar a opera��o...\n\n");
		system("PAUSE");
		return NULL;
	}
	
	Elemento *temp = lista;
	
	// percorrer a lista at� a vari�vel "temp" apontar para o pen�ltimo elemento.
	for(temp = lista; temp->proximo->proximo != NULL; temp = temp->proximo);
	
	// ao descobrir o pen�ltimo elemento da lista, o programa vai liberar o espa�o do �ltimo, e vai trocar a refer�ncia de "pr�ximo" do pen�ltimo para NULL
	free(temp->proximo);
	temp->proximo = NULL;
	return lista;
}

// esse programa recebe o primeiro elemento de um lista e retorna uma vers�o da mesma sem o primeiro elemento
Elemento *removerElementoNoInicio(Elemento *lista){
	// se a lista estiver vazia deve-se retornar NULL e mostrar para o usu�rio.
	if(lista == NULL){
		printf("N�o foi poss�vel realizar a opera��o...\n\n");
		system("PAUSE");
		return NULL;
	}	
	
	Elemento *segundoElemento = lista->proximo;
	
	
	// se s� tem um elemento, retorna nulo
	if(lista->proximo == NULL){
		// libera o endere�o da mem�ria do primeiro elemento da lista e retorna uma lista vazia

		free(lista);
		return NULL;	
	} 
	// se tiver 2 elementos ou mais, retorna o pr�ximo elemento depois do primeiro
	else{
		// libera o endere�o da mem�ria do primeiro elemento da lista e retorna o segundo.
		free(lista);
		return segundoElemento;
	}
}

// fun��o que recebe uma lista ligada e um n�mero
// e devolve uma vers�o desta lista com o n�mero passado no final.
Elemento *adicionarElementoFinal(int valor, Elemento *lista){	
	// cria um elemento com o valor passado
	Elemento *novo;
	novo = criarElemento(valor);
	
	// se a lista estiver vazia, apenas devolva o elemento digitado pelo usu�rio
	if(lista == NULL){
		return novo;
	}

	// caso contr�rio percorra a lista at� achar o �ltimo elemento, colocando a vari�vel "pr�ximo"
	// dele como o elemento constru�do com o valor passado na fun��o
	Elemento *temp = lista;
	while(1){
		if(temp->proximo){
			temp = temp->proximo;
		}
		else{
			temp->proximo = novo;
			// retorna a lista com o novo n�mero adicionado
			return lista;	
		}
	}
}

// fun��o que recebe uma lista e um n�mero, retornando uma vers�o da lista passada com o elemento passado
// como argumento da fun��o como valor inicial dessa lista.
Elemento *adicionarElementoInicio(int valor, Elemento *lista){
	// criando um elemento com o valor passado como argumento
	Elemento *novo = criarElemento(valor);

	/*
		caso a fun��o n�o esteja vazia, o programa vai usar o nodo passado como argumento para referenciar
		a lista, e depois retornar� (se a lista passada for vazia, o programa s� ir� retornar o pr�prio
		nodo criado.
	*/
	
	if(lista != NULL) novo->proximo = lista;
	return novo;
}

// fun��o que cria um nodo (apelidado nesse programa como "elemento", recebendo
Elemento *criarElemento(int valor){
	//alocando espa�o pra um elemento usando a fun��o malloc
	Elemento *criado = (struct Elemento*)malloc(sizeof(struct Elemento));
	// o valor desse nodo � passado pelo usu�rio e n�o referencia nenhum outro nodo
	criado->valor = valor;
	criado->proximo = NULL;
	// por fim esse nodo � retornado para a parte do c�digo na qual foi chamado
	return criado;
}

// fun��o que imprime na tela a lista nesse formado: [1, 2, 3, 4]
void imprimeLista (Elemento *inicial){
	Elemento *temp;
	
	// se a fun��o estiver vazia, imprime "[]" e finalize a fun��o
	if(inicial == NULL){
		printf("[]");
		return;
	}
	
	// trecho de c�digo que percorre a lista imprimindo seus elementos um por um.	
	printf("[");
	for(temp = inicial; temp->proximo != NULL; temp = temp->proximo){
		printf("%i, ", temp->valor);
	}
	
	printf("%i]", temp->valor);
}
