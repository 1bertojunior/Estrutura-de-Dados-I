#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

struct pilha
{
  char Pilha[TAM][TAM];
  int topo;
};

int pilhaCheia(int topo, int quant);
int pilhaVazia(int topo);
int pilha();
int menu();
void empilhar(struct pilha *p, char string[TAM], int quant);
void desempilhar(struct pilha *p, char string[TAM], char e[TAM]);
void imprimir(struct pilha p, int quant);
void intercalar(struct pilha *p, struct pilha *p2, struct pilha *p3, int quant1, int quant2);
void verificando(struct pilha *p, struct pilha *p3, char aux1[TAM][TAM], char vogais[10], int *tam);

int main()
{
  struct pilha p, p2, p3;
  char string[TAM], e[TAM];
  int op, op2, quant1, quant2;
  p.topo = p2.topo = -1;

  printf("A quantidade de elemento de cada pilha: ");
  scanf("%d", &quant1);
  printf("A quantidade de elemento de cada pilha: ");
  scanf("%d", &quant2);

  do
  {
    p3.topo = -1;
    op = menu();
    switch (op)
    {
    case 1:
    {
      printf("Digite a string: ");
      setbuf(stdin, NULL);
      scanf("%s", string);
      op2 = pilha();
      if (op2 == 1)
        empilhar(&p, string, quant1);
      else
        empilhar(&p2, string, quant2);
      break;
    }
    case 2:
    {
      op2 = pilha();

      if (op2 == 1)
        desempilhar(&p, string, e);
      else
        desempilhar(&p2, string, e);
      printf("Elemento topo Pilha\n");
      printf("String: %s\n", e);
      break;
    }
    case 3:
    {
      op2 = pilha();

      if (op2 == 1)
        imprimir(p, quant1);
      else
        imprimir(p2, quant2);
      break;
    }
    case 4:
    {
      intercalar(&p, &p2, &p3, quant1, quant2);
      imprimir(p3, p3.topo + 1);
    }
    break;
    default:
      break;
    }
  } while (op != 5);

  return 0;
}

int menu()
{
  int op;
  printf("[1] - Empilhar\n");
  printf("[2] - Desempilhar\n");
  printf("[3] - Imprimir uma pilha\n");
  printf("[4] - Intercalar os dois vetores com as strings que inicial com consoantes\n");
  printf("[5] - Sair\n");
  printf("Digite a opção:");
  setbuf(stdin, NULL);
  scanf("%d", &op);
  setbuf(stdin, NULL);
  return op;
}

int pilha()
{
  int op;
  printf("[1]-Empilhar na pilha 1\n");
  printf("[2]-Empilhar na pilha 2\n");
  printf("Digite a opção:");
  setbuf(stdin, NULL);
  scanf("%d", &op);
  setbuf(stdin, NULL);
  return op;
}

int pilhaCheia(int topo, int quant)
{
  int cheia = 0;

  if (topo == quant - 1)
    cheia = 1;

  return cheia;
}

int pilhaVazia(int topo)
{
  int vazia = 0;

  if (topo == -1)
  {
    vazia = 1;
  }

  return vazia;
}

void empilhar(struct pilha *p, char string[TAM], int quant)
{
  if (!pilhaCheia((*p).topo, quant))
  {
    (*p).topo++;
    strcpy((*p).Pilha[(*p).topo], string);
  }
  else
  {
    printf("A pilha cheia!\n\n");
  }
}

void desempilhar(struct pilha *p, char string[TAM], char e[TAM])
{
  // Só entrar se não estive vazia
  if (!pilhaVazia((*p).topo))
  {
    strcpy(e, (*p).Pilha[(*p).topo]);
    (*p).topo--;
  }
  else
  {
    printf("A pilha está vazia!\n\n");
  }
}

void imprimir(struct pilha p, int quant)
{
  char e, aux[TAM][TAM];
  int i = -1;

  printf("Começa do topo para baixo:\n");

  while (!pilhaVazia((p).topo))
  {
    i++;
    strcpy(aux[i], (p).Pilha[(p).topo]);
    printf("%s\n", aux[i]);
    (p).topo--;
  };

  printf("\n");

  while (i >= 0)
  {
    empilhar(&p, aux[i], quant);
    i--;
  }
}

void intercalar(struct pilha *p, struct pilha *p2, struct pilha *p3, int quant1, int quant2)
{
  char aux1[TAM][TAM], aux2[TAM][TAM], vogais[] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
  int tam1, tam2;
  tam1 = tam2 = -1;

  do
  {
    verificando(p, p3, aux1, vogais, &tam1);
    verificando(p2, p3, aux2, vogais, &tam2);
  } while (!pilhaVazia((*p).topo) || !pilhaVazia((*p2).topo));

  while (tam1 >= 0)
  {
    empilhar(p, aux1[tam1], quant1);
    tam1--;
  }

  while (tam2 >= 0)
  {
    empilhar(p2, aux2[tam2], quant2);
    tam2--;
  }
}

void verificando(struct pilha *p, struct pilha *p3, char aux1[TAM][TAM], char vogais[10], int *tam)
{
  int i, f, j, cont;

  i = f = -1;
  cont = 0;

  if (!pilhaVazia((*p).topo))
  {
    for (j = 0; j > 10; j++)
    {
      if ((*p).Pilha[(*p).topo][0] == vogais[j])
        cont = 1;
    }
    if (cont != 1)
    {
      *tam++;
      (*p3).topo++;
      strcpy((*p3).Pilha[(*p3).topo], (*p).Pilha[(*p).topo]);
    }
    else
    {
      i++;
      strcpy(aux1[i], (*p).Pilha[(*p).topo]);
    }
    (*p).topo--;
  }
}