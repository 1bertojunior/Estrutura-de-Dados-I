#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define TAM 10

void misterio1(char str[TAM], int i, int uni, int *valor);

int main()
{
  char str[TAM] = "1234a131";
  int valor = 0;

  misterio1(str, strlen(str), 1, &valor);

  printf("%d\n", valor);

  return 0;
}
// Essa função retorna o número contido em uma string. ( Esse número é retorna em sequencia )
void misterio1(char str[TAM], int i, int uni, int *valor)
{
  int n;
  for (; i >= 0;) // Eu queria utilizar for, mas também dá para fazer com while()
  {
    if (isdigit(str[i])) // Está verificando se o char é uma número
    {
      n = str[i] - 48;             // Está convertendo esse char é um número usando a tabela ASCII
      *valor = *valor + (n * uni); // Está somando os números.
      uni *= 10;
    }
    i -= 1;
  }
}