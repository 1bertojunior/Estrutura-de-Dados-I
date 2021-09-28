#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

void menu(){
  printf("0 - Sair\n");
  printf("1 - Empilhar\n");
  printf("2 - Imprimir\n");
  printf("3 - Verificar Vogal\n");
}

#define T 100
struct pilha{
  char vetor[T][50];
  int topo;
};

int pilhaCheia(int topo){
  int cheia = 0;
	if(topo == T-1) cheia = 1;
	return cheia;
}

int pilhaVazia(int topo){
  int vazia = 0;
  if(topo == -1) vazia = 1;
  return vazia;
}

void empilhar(struct pilha *p,int t){
  char e[T];
  for(int i = 0; i < t; i++){
    if(!pilhaCheia((p)->topo)){
      (p)->topo++;
      scanf("%s",e);
      strcpy(p->vetor[p->topo],e);
    }
    else{
      printf("A pilha esta cheia!\n");
    }
  }
}

void desempilhar(struct pilha *p,struct pilha *p3){
  if(!pilhaVazia(p->topo)){
    strcpy((p3)->vetor[(p3)->topo],p->vetor[(p)->topo][0]);
    p->topo--;
  }
}

void imprimir(struct pilha *p){
  for(int i = (p)->topo; i >= 0; i--){
    printf("Str = %s\n",(p)->vetor[i]);
  }
}

int isVogal(char c){
  /* se o char for vogal maiuscula ele retorna 1*/
  if(c == 'A' ||c == 'E' ||c == 'I' ||c == 'O' ||c == 'U') return 0;
  else return 1;
}

void iniConsoant(struct pilha *p1, struct pilha *p2,struct pilha *p3){
  if(p1->topo != -1 && p2->topo != -1){
    if(isalpha(p1->vetor[p1->topo][0] > 0)){
      int vogal = isVogal(toupper(p1->vetor[p1->topo][0]));
      printf("Vogal = %d\n",vogal);
      if(vogal == 1) desempilhar(p1,p3);
    }
    else
    if(isalpha(p2->vetor[p2->topo][0] > 0)){
      int vogal = isVogal(toupper(p2->vetor[p2->topo][0]));
      printf("Vogal = %d\n",vogal);
      if(vogal == 1) desempilhar(p2,p3);
    }
  }
}

int main(int argc, char *argv[]){
  int tamanho1 = 2;
  int tamanho2 = 2;
  int cd;
  struct pilha p1[tamanho1];
  struct pilha p2[tamanho2];
  struct pilha p3[tamanho1];
  (p1)->topo = -1;
  (p2)->topo = -1;
  (p3)->topo = -1;
  char string[T];
  char e[T];

  /*printf("Número de strings: ");
  scanf("%d",&tamanho);*/

  do{
    menu();
    scanf("%d",&cd);
    if(cd == 1){
      printf("Empilhando pilha 1\n");
      empilhar(p1,tamanho1);
      printf("Empilhando pilha 2\n");
      empilhar(p2,tamanho2);
    }
    else
    if(cd == 2){
      int escolha;
      printf("Escolha(1/2): ");
      scanf("%d",&escolha);
      if(escolha == 1)
        imprimir(p1);
      else if(escolha == 2)
        imprimir(p2);
      else printf("Entrada inválida!\n");
    }
    else
    if( cd == 3){
      p3->topo++;
      for(int i = 0; i <  tamanho1; i++){
        iniConsoant(p1,p2,p3);
      }
      printf("Imprimir p3\n");
      imprimir(p3);
    }
  }while(cd != 0);
  return 0;
}
