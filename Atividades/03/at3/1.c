#include<stdio.h>
#include<stdlib.h>
#define TAM 5

/*
A função inter tem uma série de erros!
Erro 1 - No primeiro if. Se deixarmos || a função não finalizará quando só um dos
contadores iqualar ao tamanho dos vetores.
Correção: if(i < q1 && j < q2)

Erro 2 - inter é do tipo void, logo não pode ser atibuida a uma variável
Correção: inter(V1,V2,V3,i,j+1,q1,q2,q3), apenas.

Erro 3 - Caso os números sejam diferentes a incrementação é feita de acordo com
o menor valor!
Correção:  if(V1[i] < V2[j]), então, i++(na chamada da função).

Erro 4 - Passar o endereço do ponteiro na função!
Correção: inter(V1,V2,V3,i,j+1,q1,q2,q3).

Erro 5 - q3 é um ponteiro, logo, quando quisermos modificar ou ter acesso ao
valor ques está no endereço apontado pelo ponteiro devemos fazer *q3
Correção: V3[*q3] = V1[j];

Erro 6 - A incrementação de um vetor errada!
Correção: (*ponteiro)++ ou p += 1

Erro 7 - Tipo void não admite return!
Correção: Apague return(q3);
*/

void inter1(int v1[],int v2[],int v3[]){
  // Função reescrita sem recursividade!
  int k = 0;
  for(int i = 0; i < TAM; i++){
    for(int j = 0; j < TAM; j++){
      if(v1[i] == v2[j]){
        v3[k] = v1[i];
        k++;
      }
    }
  }
}
int main(){
  int v1[TAM] = {1,2,3,6,5};
  int v2[TAM] = {2,3,6,7,8};
  int v3[TAM];
  int q3 = 0;
  inter2(v1,v2,v3,0,0,TAM,TAM,&q3);
  for(int i = 0;i < q3; i++){
    printf("%d ",v3[i]);
  }
  printf("\n");
  return 0;
}
