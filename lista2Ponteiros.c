#include <stdio.h>
#include <conio.h>

int main() {
  //valor é a variável que será apontada pelo ponteiro
  int valor = 27;
  
  //declaração de variável ponteiro usando o *
  int *ptr;
  
  //atribuindo o endereço da variável valor ao ponteiro
  ptr = &valor;
  

  printf("Utilizando ponteiros\n\n");

	//printa o valor da variabel
  printf ("Conteudo da variavel valor: %d\n", valor);
	//o %x serve para ver o endereço de valor
  printf ("Endereco da variavel valor: %x \n", &valor);
	//o %x é para saber o endereço que o ponteiro está apontando
  printf ("Conteudo da variavel ponteiro ptr: %x", ptr);
  
  getch();
  return(0);
}
