#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TAM_PILHA 100
#define TAM_STRING 100

typedef struct pilha
{
  char Pilha[TAM_PILHA];
  int topo;
} pilha;

void inicializar(pilha *p);
void pGeral(char expressao[TAM_STRING], pilha *pPos, pilha *pPilha);
void empilhar(pilha *p, pilha *aux, char string);
void transfere_pPilha_pPos(pilha *pPos, pilha *pPilha, pilha *aux);
void imprime(pilha *p);
void imprime2(pilha *p, int i);
int validandoExpressao(char expressao[TAM_STRING]);
char desempilhar(pilha *topo);

int main()
{
  pilha pPos, pPilha;
  char expressao[TAM_STRING], novaExpressao[TAM_STRING];
  int i;

  i = 0;
  inicializar(&pPos);
  inicializar(&pPilha);

  do
  {
    if (i == 1)
    {
      printf("\nExpressão inválida!\n\n");
    }

    i = 1;

    printf("Digite uma expressão válida:");
    scanf("%[^\n]", expressao);
    setbuf(stdin, NULL);

  } while (validandoExpressao(expressao) != 0);

  pGeral(expressao, &pPos, &pPilha);

  printf("\nIn-fixa:%s\n", expressao);
  printf("Pós-fixa:");
  imprime(&pPos);
  printf("\nREC: ");
  imprime2(&pPos, 0);
  printf("\n");
  return 0;
}

void inicializar(pilha *p)
{
  p->topo = -1;
}

int validandoExpressao(char expressao[TAM_STRING])
{
  char str[TAM_STRING], *string;
  int valor, i, j, qtdDeAberturaDeParetes, resultado;
  valor = i = qtdDeAberturaDeParetes = resultado = 0;

  for (i = 0; expressao[i] != '\0'; i++)
  {
    // Quantidade de Parentêses
    if (expressao[i] == '(')
    {
      qtdDeAberturaDeParetes++;
    }
    else if (expressao[i] == ')')
    {
      qtdDeAberturaDeParetes--;
    }
    else if (expressao[i] == '-' || expressao[i] == '+' || expressao[i] == '*' || expressao[i] == '/' || expressao[i] == ')' || expressao[i] == '(')
    {

      if ((int)expressao[0] >= 41 && (int)expressao[0] <= 47 || expressao[0] == 32)
      {
        resultado = 1; // verificando o começo
      }
      else if ((int)expressao[strlen(expressao) - 1] >= 42 && (int)expressao[strlen(expressao) - 1] <= 47 || (int)expressao[strlen(expressao) - 1] == 40)
      {
        resultado = 1; // verificando o final
      }
      if ((int)expressao[i + 1] >= 42 && (int)expressao[i + 1] <= 47)
      {
        resultado = 1; // verificando se tem operadores juntos(Ex: ++)
      }
      else if ((int)expressao[i + 2] < 48 && (int)expressao[i + 2] >= 42)
      {
        resultado = 1; // verificando se tem operadores juntos, mas tendo um espaço entre eles(Ex: + +)
      }
    }
    else if ((int)expressao[i] >= 48 && (int)expressao[i] < 57 && (int)expressao[i + 1] == 32 && (int)expressao[i + 2] >= 48 && (int)expressao[i + 2] < 57)
    {
      resultado = 1; // verificando se tem números juntos, mas tendo um espaço entre eles (Ex: 1 1)
    }
  }

  // validando o digito

  strcpy(str, expressao);

  string = strtok(str, " +*/-()");

  while (string != NULL)
  {
    if (atoi(string) > 1000)
    {
      resultado = 1; // Tem um número maior que 1000
    }
    string = strtok(NULL, " +*/-()");
  }

  return resultado == 0 && qtdDeAberturaDeParetes == 0 ? 0 : 1;
}

void pGeral(char expressao[TAM_STRING], pilha *pPos, pilha *pPilha)
{
  pilha *aux;
  int i = 0;
  printf("%s\n", expressao);
  while (expressao[i] != '\0')
  {
    printf("%c", expressao[i]);
    switch (expressao[i])
    {
    case '+':
    case '-':
      printf("Passei aqui 1\n");
      while ((*pPilha).topo != -1 && (*pPilha).Pilha[(pPilha->topo)] != '(')
      {
        printf("Passei aqui 2\n");
        transfere_pPilha_pPos(pPos, pPilha, aux);
      }
      empilhar(pPilha, aux, expressao[i]);
      break;
    case '*':
    case '/':
      while ((*pPilha).topo != -1 && (*pPilha).Pilha[(pPilha->topo)] != '(' && (*pPilha).Pilha[(pPilha->topo)] != '+' && (*pPilha).Pilha[(pPilha->topo)] != '-')
      {
        printf("Passei aqui 3\n");
        transfere_pPilha_pPos(pPos, pPilha, aux);
      }
      empilhar(pPilha, aux, expressao[i]);
      break;
    case ')':
      while ((*pPilha).topo && (*pPilha).Pilha[(pPilha->topo)] != '(')
      {
        printf("Passei aqui 4\n");
        transfere_pPilha_pPos(pPos, pPilha, aux);
      }
      if ((*pPilha).Pilha[(*pPilha).topo] == '(')
      {
        printf("Passei aqui 5\n");
        desempilhar(pPilha);
      }
      break;
    case '(':
      printf("Passei aqui 6\n");
      empilhar(pPilha, aux, expressao[i]);
      break;
    default:
      printf("Passei aqui 7\n");
      empilhar(pPos, aux, expressao[i]);
      break;
    }
    i++;
  }

  while ((*pPilha).topo != -1)
  {
    printf("Passei aqui 8\n");
    transfere_pPilha_pPos(pPos, pPilha, aux);
  }
}

void empilhar(pilha *p, pilha *aux, char string)
{
  if ((*p).topo < TAM_PILHA)
  {
    (*p).topo += 1;
    (*p).Pilha[(*p).topo] = string;
  }
}

char desempilhar(pilha *topo)
{
  char string;
  pilha *aux;

  if (topo->topo != -1)
  {
    string = (*topo).Pilha[(*topo).topo];
    aux = topo;
    (*topo).topo -= 1;
  }

  return string;
}

void transfere_pPilha_pPos(pilha *pPos, pilha *pPilha, pilha *aux)
{
  (*pPos).topo += 1;
  printf("\n%c\n", (pPos->Pilha[(*pPos).topo] = desempilhar(pPilha)));
}

void imprime2(pilha *p, int i){
  if(i <=  p->topo){
    imprime2(p,i+1);
    printf("%d ", i);
    printf("%c ", p->Pilha[i]);
  }
}

void imprime(pilha *p){
  int aux = 0;
  while (p->topo >= aux){
    printf("%c", p->Pilha[aux]);
    aux++;
  }
}

/*
void imprime(pilha *pPilha)
{
  char str[TAM_STRING];
  int i = 0;
  while(pPilha->topo != -1)
  {
    str[i] = pPilha->Pilha[pPilha->topo];
    pPilha->topo -= 1;
    i++;
  }

  printf("%s\n", str);
}*/