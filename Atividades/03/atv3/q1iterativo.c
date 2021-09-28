#include <stdio.h>

#define TAM 10

int inter(int V1[TAM], int V2[TAM], int V3[TAM]);

int main(){
  int V1[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, V2[TAM] = {0, 16, 15, 14, 1, 12, 3, 4, 7, 8}, V3[TAM], contador, i;
     
  contador = inter(V1, V2, V3);

  for (i = 0; i < contador; i++){// i < contador pq ainda há um incremento que não será preenchido na função 
    printf("%d\n", V3[i]);
  }
  return 0;
}


int inter(int V1[TAM], int V2[TAM], int V3[TAM]){
  int i, j, contador = 0;
  for (i = 0; i < TAM; i++){
    for (j = 0; j < TAM; j++){
      if (V1[i] == V2[j]){
        V3[contador] = V1[i];//só são adicionados no vetor os valoes que se repetem nos dois 
        contador++;
      }
    }
  }
  return contador;//devolve a qnt de elementos em v3
}