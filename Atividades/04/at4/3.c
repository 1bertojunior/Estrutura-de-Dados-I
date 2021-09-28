#include<stdio.h>
#include<stdlib.h>
#include<string.h>
/*
casos de teste!
vetor1 = 1,2,3,4,5
vetor2 = 5,4,3,2,1

vetor1 = 7,6,4,2,1
vetor2 = 3,4,1,8,3

*/
int separa (int v[], int p, int r){
   int c = v[r]; // pivô
   int t, j = p;
   for (int k = p; /*A*/ k < r; ++k)
      if (v[k] <= c) {
         t = v[j], v[j] = v[k], v[k] = t;
         ++j;
      }
   t = v[j], v[j] = v[r], v[r] = t;
   return j;
}

void quicksort (int v[], int p, int r){
 if (p < r){
    int j = separa (v, p, r);
    quicksort (v, p, j-1);
    quicksort (v, j+1, r);
  }
}

void inter(int v1[], int v2[], int v3[],int tam, int i, int j, int q1, int q2, int *q3){

  if (i < q1 && j < q2){
    if (v1[i] < v2[j])
      inter(v1, v2, v3,tam, i, j + 1, q1, q2, q3);
    else if (v1[i] > v2[j])
      inter(v1, v2, v3,tam, i, j + 1, q1, q2, q3);
    else{
      v3[*q3] = v1[i];
      *q3 += 1;
      inter(v1, v2, v3,tam, i + 1, j = 0, q1, q2, q3);
    }
  }
  if (i != tam - 1 && j == tam - 1){
    inter(v1, v2, v3,tam, i + 1, j = 0, q1, q2, q3);
  }
}

int main(int argc, char *argv[]){
  printf("digite um tamanho!\n");
  int tamanho;
  scanf("%d",&tamanho);
  int vetor1[tamanho];
  int vetor2[tamanho];
  int vetor3[tamanho];
  printf("digite vetor 1!\n");
  for(int i = 0; i < tamanho; i++){
    scanf("%d",&vetor1[i]);
  }
  printf("digite vetor 2!\n");
  for(int i = 0; i < tamanho; i++){
    scanf("%d",&vetor2[i]);
  }
  printf("Executando programa!\n");
  int t = 0;
  quicksort(vetor1,0,tamanho - 1);
  quicksort(vetor2,0,tamanho - 1);
  inter(vetor1,vetor2,vetor3,tamanho,0,0,tamanho,tamanho,&t);
  for(int i = 0; i < t; i++) printf("%d\n",vetor3[i]);
  return 0;
}
