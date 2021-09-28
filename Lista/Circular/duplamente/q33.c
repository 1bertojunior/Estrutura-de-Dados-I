#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
  int numero;
  struct lista *Prox;
  struct lista *Ant;
} Lista;

Lista *alocaNo(int numero);
int menu();
int remover(Lista **I, Lista **F, int numero);
void inserir(Lista **I, Lista **F, Lista *No);
void imprime(Lista *I);
void inicializarLista(Lista **I);

int main()
{
  Lista *No, *I, *F;
  int i, numero;

  inicializarLista(&I);

  int opcao;
  do
  {
    opcao = menu();

    switch (opcao)
    {
    case 1:
      printf("X: ");
      scanf("%d", &numero);
      No = alocaNo(numero);
      inserir(&I,&F,No);
      break;
    case 2:
      imprime(I);
      printf("\n");
      break;
    case 3:
      printf("Digite o número que você queira remover:");
      scanf("%d", &numero);
      remover(&I, &F, numero);
      break;
    default:
      break;
    }
  } while (opcao != 0);
  return 0;
}

Lista *alocaNo(int numero)
{
  Lista *No;

  No = NULL;
  No = (Lista *)malloc(sizeof(Lista));
  No->Prox = NULL;
  No->Ant = NULL;
  No->numero = numero;

  return No;
}

void inserir(Lista **I, Lista **F, Lista *No)
{
  Lista *Aux, *Ant;

  // Verificamos se a lista for vazia
  if (*I == NULL){
    *I = No;
    (*I)->Prox = *I;
    *F = *I;
  }else{
    if (No->numero <= (**I).numero) // Verificamos se número da struct é menor do que o início da lista, se for  a struct será o novo início
    {
      (*No).Prox = *I;
      *I = No;
      (*F)->Prox = *I;
    }else if (No->numero >= (**F).numero){ // Verificamos se número da struct é maior do que o fim da lista, se for a struct será o novo fim
      (*No).Prox = *I;
      (*No).Ant = *F;
      (*F)->Prox = No;
      *F = No;
    }else{
      // Aqui íremos adicionar o struct no meio da lista
      Aux = *I;
      while (No->numero > (*Aux).numero)
      {
        Aux = (*Aux).Prox;
      }     /// 1 10
      No->Ant = Aux->Ant;
      Aux->Ant->Prox = No;
      No->Prox = Aux;
      No->Prox->Ant = No;
      // (*Ant).Prox = No;   
      // No->Ant = Ant; 
      // No->Prox = Aux;
    }
  }
}

int menu()
{
  int opcao;
  do
  {
    printf("[1] - Imprimir \n");
    printf("[2] - Remover \n");
    printf("[3] - Sair\nOpcão: ");
    scanf("%d", &opcao);
  } while (opcao < 1 || opcao > 3);

  return opcao;
}

void imprime(Lista *I)
{
  Lista *Aux;

  Aux = I;

  if (I != NULL)
    do
    {
      printf("\n%d", (*Aux).numero);
      Aux = Aux->Prox;
    } while (Aux != I);
}

void inicializarLista(Lista **I)
{
  *I = NULL;
}

int remover(Lista **I, Lista **F, int numero)
{
  Lista *Aux;
  int removeu = 1;

  inicializarLista(&Aux);

  if ((**I).numero == numero) // Verificando se o número é o início
  {
    Aux = *I;
    *I = (**I).Prox;
    (*I)->Ant = *F;
    (*F)->Prox = *I;
  }
  else if ((**F).numero == numero) // Verificando se o número é o fim
  {
    Aux = *F;
    *F = (**F).Ant;
    (*F)->Prox = *I;
  }
  else
  {
    printf("Entrou aqui 2\n");
    // O meio da lista
    Aux = (*I)->Prox;

    while (Aux->numero != (*I)->numero && (*Aux).numero != numero)
    {
      Aux = (*Aux).Prox;
    }
    Aux->Ant->Prox = Aux->Prox;
    Aux->Prox->Ant = Aux->Ant;
  }

  free(Aux);

  return removeu;
}