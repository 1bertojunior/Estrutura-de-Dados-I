/*
  Errors:
  1 - A função inter é do tipo void (sem retorno);
  2 - Uso do operador relacional || (OU) no primeiro if, ou seja, só entrará na condição de parada quando os dois índices for  menores que o tamanho dos vetores;
  3 - Passagem de ponteiro na função, sendo que não é necessário, pois a mesma já armazena um endereço;
  4 - Incremento no conteúdo do ponteiro q3, para manipular o conteúdo que q3 aponta, é necessário usar o *.
*/

// Algoritmo sem recurssão
#include<stdio.h>

#define TAM 5

void inter1(int v1[],int v2[],int v3[]){
  int k = 0;
  for(int i=0; i<TAM;i++) for(int j = 0; j < TAM; j++) if(v1[i] == v2[j]) v3[k++] = v1[i];
}