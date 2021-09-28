/*
os testes foram realizados nos exemplos abaixo!
Apenas compile com o gcc e rode o programa. Não é necessário nenhuma entrada
por parte do usuário.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  int matricula;
  char nome[31];
  char curso[31];
  int periodo;
}ALUNO;

void ordena(ALUNO aluno[],int n){
  int x,i,p;
  char no[31],c[31];
  if(n > 1){
    ordena(aluno,n-1);
    i = n-1;
    while(i > 0 && aluno[i-1].matricula > aluno[i].matricula){
      x = aluno[i-1].matricula;
      strcpy(no,aluno[i-1].nome);
      strcpy(c,aluno[i-1].curso);
      p = aluno[i-1].periodo;

      aluno[i-1].matricula = aluno[i].matricula;
      strcpy(aluno[i-1].nome,aluno[i].nome);
      strcpy(aluno[i-1].curso,aluno[i].curso);
      aluno[i-1].periodo = aluno[i].periodo;

      aluno[i].matricula = x;
      strcpy(aluno[i].nome,no);
      strcpy(aluno[i].curso,c);
      aluno[i].periodo = p;
      i--;
    }
  }
}
void alunoNoCurso(ALUNO aluno[],int n,int i,char *curso,int *p){
  // funciona!!!!
  if(i < n){
    if(!strcmp(curso,aluno[i].curso)) (*p)++;
    alunoNoCurso(aluno,n,i+1,curso,p);
  }
}

int busca(ALUNO aluno[], int i, int f, int v) {
  int k;
  if (i > f)
    return -1;
  else {
    k = (i+f)/2;
    if (aluno[k].matricula == v) return k;
    else
      if (v < aluno[k].matricula)
        return busca(aluno,i,k-1, v);
      else
        return busca(aluno,k+1,f, v);
  }
}

void nomePeriodo(ALUNO aluno[],int n,ALUNO *aluno_p,int num, int *k,int i){
  if(i < n){
    if(aluno[i].periodo == num){
      aluno_p[*k] = aluno[i];
      (*k)++;
    }
    nomePeriodo(aluno,n,aluno_p,num,k,i+1);
  }
}

int main(int argc, char *argv[]){
  ALUNO aluno[3];

  // aluno 1
  aluno[0].matricula = 123;
  strcpy(aluno[0].nome,"Adão");
  strcpy(aluno[0].curso,"Sistemas de Informação");
  aluno[0].periodo = 3;
  //aluno 2
  aluno[1].matricula = 125;
  strcpy(aluno[1].nome,"Pedro");
  strcpy(aluno[1].curso,"História");
  aluno[1].periodo = 8;

  // aluno 3
  aluno[2].matricula = 124;
  strcpy(aluno[2].nome,"Bia");
  strcpy(aluno[2].curso,"Matemática");
  aluno[2].periodo = 1;

  // chamada de ordena
  ordena(aluno,3);
  printf("DADOS ORDENADOS\n");
  for(int i = 0; i < 3; i++){
    printf("%d\n",aluno[i].matricula);
    printf("%s\n",aluno[i].nome);
    printf("%s\n",aluno[i].curso);
    printf("%d\n",aluno[i].periodo);
  }
  ALUNO alun_per[3];
  char curso[] = "Matemática";
  int p = 0;
  int class = 0;
  int matricula = 125;
  int periodo = 3;
  int i = 0;
  int k = 0;
  printf("Alunos do periodo %d\n",periodo);
  nomePeriodo(aluno,3,alun_per,periodo,&k,i);
  for(int j = 0; j < k; j++){
    printf("%s\n",alun_per[j].nome);
  }
  alunoNoCurso(aluno,3,0,curso,&p);
  if(p == 0) printf("Não há alunos no curso ou esse curso não exite!\n");
  else printf("No curso de %s tem %d aluno(s)\n",curso,p);
  class = busca(aluno,0,3,matricula);
  printf("class = %d\n",class);
  printf("%d\n",aluno[class].matricula);
  printf("%s\n",aluno[class].nome);
  printf("%s\n",aluno[class].curso);
  printf("%d\n",aluno[class].periodo);
  return 0;
}
