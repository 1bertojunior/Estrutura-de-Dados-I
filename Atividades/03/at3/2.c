/*Concluida com sucesso*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

#define TAM 5

/*
A função misterio1 recebe uma string e devolve todos os digitos,em sequencia,
que existirem nela.
input  = ew21e
output = 21
*/
void misterio1(char str[TAM], int i, int uni, int *valor){
  int n;
  if(i >=0){
    if(isdigit(str[i])){
      n = str[i] - 48;
      *valor = *valor + (n * uni);
      misterio1(str,i -1, uni * 10, valor);
    }
    else misterio1(str,i -1, uni, valor);
  }
}

void misterio2(char str[TAM], int i, int uni, int *valor){
  int n;
  if(i >= 0){
    while(i >= 0){
      if(isdigit(str[i])){
        n = str[i] - 48;
        *valor = *valor + (n * uni);
        uni = uni * 10;
      }
      i -= 1;
    }
  }
}

int main(){
  char str[] = "e4325";
  int v = 0;
  misterio2(str,strlen(str)-1,1,&v);
  printf("%d\n",v);
  return 0;
}
