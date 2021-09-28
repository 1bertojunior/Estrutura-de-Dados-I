/*Erros:

1 - A função inter é do tipo void, então não precisa usar o return.

2 - O primeiro if está errado, pois precisa que os dois sejam maiores que a qnt de
elementos para terminar o código.

  if(i < q1 && i < q2)

  Também tem o erro para finalizar.

3 - q3 = quantidade de números que estão na intersecção. 
E já é incrementado utilizando seu endereço e conteúdo
  q3 = inter(V1, V2, V3, i, j + 1, q1, q2, q3); -> Errado

4 - q3 entra como endereço, para enviá-lo na função recursiva basta escrever 'q3'
  inter(V1, V2, V3, i, j + 1, q1, q2, &q3); -> Errado
  inter(V1, V2, V3, i, j + 1, q1, q2, q3); -> Certo

5 - q3 entra na função com o endereço, para alterar o conteúdo precisa ser  *q3
  V3[q3] = V1[j]; Errado
  V3[*q3] = V1[j];
  Nesse mesma linha tem outro erro.
  V3[q3] = V1[i] -> Devemos colocar o mesmo índice usando na comparação

6 - Incrementação do conteúdo do ponteiro.
  *q3 = q3 + 1; -> errado
  *q3 = *q3 + 1; ou *q3 += 1;-> cento

7 -Números contidos nos dois ventores.
  Basta outro if que verifica se i é !=  e se j é =  ao  vetor
  
  if (i != TAM && j == TAM )
  {
    inter(V1, V2, V3, i + 1, j = 0, q1, q2, q3);
  }

*/

#include <stdio.h>

#define TAM 10

void inter(int V1[TAM], int V2[TAM], int V3[TAM], int i, int j, int q1, int q2, int *q3);

int main()
{
  int V1[TAM] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, V2[TAM] = {0, 16, 15, 14, 1, 12, 3, 4, 7, 8}, V3[TAM], q3 = 0;

  inter(V1, V2, V3, 0, 0, TAM, TAM, &q3);

  for (int i = 0; i < q3; i++)
  {
    printf("%d\n", V3[i]);
  }

  return 0;
}

void inter(int V1[TAM], int V2[TAM], int V3[TAM], int i, int j, int q1, int q2, int *q3)
{
  if (i < q1 && j < q2)
  {
    if (V1[i] < V2[j])
      inter(V1, V2, V3, i, j + 1, q1, q2, q3);
    else if (V1[i] > V2[j])
      inter(V1, V2, V3, i, j + 1, q1, q2, q3);
    else
    {
      V3[*q3] = V1[i];
      (*q3) += 1;
      inter(V1, V2, V3, i + 1, j = 0, q1, q2, q3);
    }
  }

  if (i != TAM && j == TAM)
  {
    inter(V1, V2, V3, i + 1, j = 0, q1, q2, q3);
  }
}