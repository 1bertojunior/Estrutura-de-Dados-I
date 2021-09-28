#include <stdio.h>
#include <stdlib.h>

void ordenarPorInsercao(int v1[6], int tam, int k, int j, int cont);
int uniao(int v1[6], int v2[6], int v3[12], int i, int j, int k);

int main()
{
  int v1[6] = {7, 4, 8, 2, 2, 5}, v2[6] = {7, 8, 9, 5, 3, 2}, v3[12], tam;
  ordenarPorInsercao(v1, 0, 1, 0, 5);
  ordenarPorInsercao(v2, 0, 1, 0, 5);
  tam = uniao(v1, v2, v3, 0, 6, 12);

  for (int i = 0; i < 6; i++)
  {
    printf("%d ", v3[i]);
  }
  printf("\n");

  return 0;
}

void ordenarPorInsercao(int v[], int i, int j, int inicio, int fim)
{
  int aux;
  if (j <= fim){
    if (v[i] > v[j]){
      aux = v[i];
      v[i] = v[j];
      v[j] = aux;
      if (i > inicio){
        ordenarPorInsercao(v, i - 1, i, inicio, fim);
      }else{
        ordenarPorInsercao(v, j, j + 1, inicio, fim);
      }
    }
    ordenarPorInsercao(v, j, j + 1, inicio, fim);
  }
}

int uniao(int v1[6], int v2[6], int v3[12], int i, int j, int k)
{
  for (i = 0; i < 6; i++)
  {
    v3[i] = v2[i];
  }
  for (j = 0; j < 6; j++)
  {
    printf("- %d", j);
    v3[i] = v1[j];
    i++;
  }
  printf("\n");
}