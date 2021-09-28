#include <stdio.h>
#include <stdlib.h>

typedef struct termo
{
  int potencia;
  int coeficiente;
} Termo;

typedef struct lista
{
  Termo termo;
  struct lista *Prox;
  struct lista *Ant;
} Lista;

int menu();
int lerInteiro(char frase[300]);
void inicializar(Lista **I, Lista **F);
void leitura(int *coeficiente, int *potencia);
void inserir(Lista **I, Lista **F, Lista *No);
void imprime(Lista *I);
int lerInteiro(char frase[300]);
Lista *alocaNo(int coeficiente, int potencia);

int main()
{
  Lista *I, *F, *No;
  int opcao, coeficiente, potencia, codigo, i, j, cont;
  int vetor1[100], vetor2[2];

  i = j = cont = 0;

  do
  {
    opcao = menu();
    switch (opcao)
    {
    case 1:
      inicializar(&I, &F);
      while (i < 3)
      {
        while (j < 3)
        {
          leitura(&coeficiente, &potencia);
          No = alocaNo(coeficiente, potencia);
          inserir(&I, &F, No);
          j++;
        }
        i++;
      }
      codigo = lerInteiro("Digite o código dessa polinômio");
      // vetor2[0] = codigo;
      // vetor2[1] = I;
      // vetor1[cont] = vetor1;
      cont++;
      //for (i = 0; i < cont; i++)
      imprime(I);
      break;
    default:
      break;
    }
  } while (opcao != 2);
  return 0;
}

void inicializar(Lista **I, Lista **F)
{
  I = NULL;
  F = NULL;
}

int menu()
{
  int opcao;
  do
  {
    printf("\n[1] - Inserir \n");
    printf("[2] - Sair\nOpcão: ");
    scanf("%d", &opcao);
  } while (opcao < 1 || opcao > 2);

  return opcao;
}

void leitura(int *coeficiente, int *potencia)
{
  *coeficiente = lerInteiro("Digite o primeiro termo:");
  *potencia = lerInteiro("Digite a potencia do primeiro termo:");
}

Lista *alocaNo(int coeficiente, int potencia)
{
  Lista *No;

  No = NULL;
  No = (Lista *)malloc(sizeof(Lista));
  No->Prox = NULL;
  No->Ant = NULL;
  No->termo.coeficiente = coeficiente;
  No->termo.potencia = potencia;

  return No;
}

void inserir(Lista **I, Lista **F, Lista *No)
{
  Lista *Aux;

  if (*I == NULL)
  {
    *I = No;
    *F = (*I)->Prox = (*I)->Ant = *I;
  }
  else
  {
    if (No->termo.coeficiente <= (*I)->termo.coeficiente) // Verificamos se número da struct é menor do que o início da lista, se for  a struct será o novo início
    {
      (*No).Prox = *I;
      *I = No;
      (*I)->Ant = *I;
      (*F)->Prox = *I;
    }
    else if (No->termo.coeficiente >= (*F)->termo.coeficiente) // Verificamos se número da struct é maior do que o fim da lista, se for a struct será o novo fim
    {
      (*No).Prox = *I;
      (*No).Ant = *F;
      (*F)->Prox = No;
      *F = No;
    }
    else
    {
      // Aqui íremos adicionar o struct no meio da lista
      Aux = *I;
      while (No->termo.coeficiente > (*F)->termo.coeficiente)
      {
        Aux = (*Aux).Prox;
      }
      No->Ant = Aux->Ant;
      No->Prox = Aux;
      Aux->Ant->Prox = No;
      No->Prox = Aux;
      No->Prox->Ant = No;
    }
  }
}

void imprime(Lista *I)
{
  Lista *Aux;

  Aux = I;

  if (I != NULL)
    do
    {
      printf("\n%d - %d", (*Aux).termo.coeficiente, (*Aux).termo.potencia);
      Aux = Aux->Prox;
    } while (Aux != I);
}

int lerInteiro(char frase[300])
{
  int inteiro;

  printf("%s", frase);
  scanf("%d", &inteiro);

  return inteiro;
}
