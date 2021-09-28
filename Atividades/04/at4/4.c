#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  int codigo;
  char nome_curso[31];
  int num_periodo;
}CURSOS;

typedef struct{
	int codigo_disciplina;
	int codigo_curso;
	char nome_disciplina[31];
	int periodo;
	int carga_horaria;
}DISCIPLINAS;


void quickDisciplina(DISCIPLINAS *disciplina, int inicio, int fim){
   int pivo, i, j, meio;
   // importante para a gambiarra de ordenação!
   int cd;
   int cc;
   char n[31];
   int p;
   int ch;
   //
   i = inicio;
   j = fim;
   meio = (int) ((i + j) / 2);
   pivo = disciplina[meio].codigo_disciplina;
   do{
      while (disciplina[i].codigo_disciplina < pivo) i = i + 1;
      while (disciplina[j].codigo_disciplina > pivo) j = j - 1;
      if(i <= j){
        // modo gambiarra (eu acho)
         cd = disciplina[i].codigo_disciplina;
         cc = disciplina[i].codigo_curso;
         strcpy(n,disciplina[i].nome_disciplina);
         p = disciplina[i].periodo;
         ch = disciplina[i].carga_horaria;

         disciplina[i].codigo_disciplina = disciplina[j].codigo_disciplina;
         disciplina[i].codigo_curso = disciplina[j].codigo_curso;
         strcpy(disciplina[i].nome_disciplina,disciplina[j].nome_disciplina);
         disciplina[i].periodo = disciplina[j].periodo;
         disciplina[i].carga_horaria = disciplina[j].carga_horaria;

         disciplina[j].codigo_disciplina = cd;
         disciplina[j].codigo_curso = cc;
         strcpy(disciplina[j].nome_disciplina,n);
         disciplina[j].periodo = p;
         disciplina[j].carga_horaria = ch;
         //
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   if(inicio < j) quickDisciplina(disciplina, inicio, j);
   if(i < fim) quickDisciplina(disciplina, i, fim);
}

void quickCurso(CURSOS *curso, int inicio, int fim){
   int pivo, i, j, meio;
   // importante para a gambiarra de ordenação!
   int cd;
   char n[31];
   int p;
   //
   i = inicio;
   j = fim;
   meio = (int) ((i + j) / 2);
   pivo = curso[meio].codigo;
   do{
      while (curso[i].codigo < pivo) i = i + 1;
      while (curso[j].codigo > pivo) j = j - 1;
      if(i <= j){
        // modo gambiarra (eu acho)
         cd = curso[i].codigo;
         strcpy(n,curso[i].nome_curso);
         p = curso[i].num_periodo;

         curso[i].codigo = curso[j].codigo;
         strcpy(curso[i].nome_curso,curso[j].nome_curso);
         curso[i].num_periodo = curso[j].num_periodo;

         curso[j].codigo = cd;
         strcpy(curso[j].nome_curso,n);
         curso[j].num_periodo = p;
         //
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   if(inicio < j) quickCurso(curso, inicio, j);
   if(i < fim) quickCurso(curso, i, fim);
}

CURSOS cursoMaiorPeriodo(CURSOS *curso, int contador,int num){
  // letra a
  // erro = fazer COM pendencia e aqui ta sem pendencia
  CURSOS c = curso[0];
  int i = contador;
  if(i > 0) c = curso[i];
  if(i == num) return c;
  else{
    if(curso[i+1].num_periodo > curso[i].num_periodo){
      c = curso[i+1];
    }
    cursoMaiorPeriodo(curso,contador + 1,num);
  }
  return c;
}

int aux(CURSOS c[], char *x,int i){
  if(strcmp(x,c[i].nome_curso) == 0){
    return c[i].codigo;
  }
  else aux(c,x,i+1);
  return 1;
  // se retornar 1, não existe esse curso!
}

int qtDiscipCurso(DISCIPLINAS *d,int hash,int contador,int i){
  /*Feito com pendencia!*/
  if(hash == d[i].codigo_curso) contador++;
  else /*contador + */qtDiscipCurso(d,hash,contador,i+1);
  return contador; // se retornar 0 é pq n tem disciplina
}

int disciplinaPerCurso(DISCIPLINAS *d,int hash,int p,int contador,int i){
  /*disciplina,cd curso,periodo,contador*/
  if(i > 0){
    if((hash == d[i].codigo_curso)){
      if(p == d[i].periodo) contador = 1;
      else contador + disciplinaPerCurso(d,hash,p,contador,i-1);
    }
    else disciplinaPerCurso(d,hash,p,contador,i-1);
  }
  return contador;
}

int main(int argc, char *argv[]){
  int total_curso,total_disciplina;
  printf("Digite o total de cursos\n");
  scanf("%d",&total_curso);
  printf("Digite o total de disciplinas\n");
  scanf("%d",&total_disciplina);
	CURSOS curso[total_curso]; // 3 cursos cadastros!
  DISCIPLINAS disciplina[total_disciplina]; // 3 disciplinas cadastradas

	// cadastros cursos
  for(int i = 0; i < total_curso; i++){
    printf("\nCadastrando curso %d\n",i+1);
  	printf("Código do curso: ");
  	scanf("%d",&curso[i].codigo);
  	printf("Nome do curso: ");
  	scanf(" %[^\n]",curso[i].nome_curso);
    printf("Numero de Periodos: ");
    scanf("%d",&curso[i].num_periodo);
  }
  for(int j = 0; j < total_disciplina; j++){
    printf("\nCadastrando disciplina %d\n",j+1);
    printf("Código da disciplina: ");
  	scanf("%d",&disciplina[j].codigo_disciplina);
  	printf("Código do curso: ");
  	scanf("%d",&disciplina[j].codigo_curso);
  	printf("Nome do disciplina: ");
  	scanf(" %[^\n]",disciplina[j].nome_disciplina);
    printf("Periodo: ");
    scanf("%d",&disciplina[j].periodo);
    printf("Carga Horaria: ");
    scanf("%d",&disciplina[j].carga_horaria);
  }
  /*
  // curso 1
  curso[0].codigo = 12347;
  strcpy(curso[0].nome_curso,"Sistemas de Informação");
  curso[0].num_periodo = 8;

  //curso 2
  curso[1].codigo = 12346;
  strcpy(curso[1].nome_curso,"História");
  curso[1].num_periodo = 9;

  // curso 3
  curso[2].codigo = 12345;
  strcpy(curso[2].nome_curso,"Matemática");
  curso[2].num_periodo = 8;

  // cadastros disciplinas

  // disciplina 1
  disciplina[0].codigo_disciplina = 123471;
  disciplina[0].codigo_curso = 12347;
  strcpy(disciplina[0].nome_disciplina,"Estrutura de Dados1");
  disciplina[0].periodo = 3;
  disciplina[0].carga_horaria = 60;

  // disciplina 2
  disciplina[1].codigo_disciplina = 123461;
  disciplina[1].codigo_curso = 12346;
  strcpy(disciplina[1].nome_disciplina,"História do Egito");
  disciplina[1].periodo = 2;
  disciplina[1].carga_horaria = 30;

  // disciplina 3
  disciplina[2].codigo_disciplina = 123451;
  disciplina[2].codigo_curso = 12345;
  strcpy(disciplina[2].nome_disciplina,"Cálculo 1");
  disciplina[2].periodo = 5;
  disciplina[2].carga_horaria = 60;

  // disciplina 4
  disciplina[3].codigo_disciplina = 123452;
  disciplina[3].codigo_curso = 12345;
  strcpy(disciplina[3].nome_disciplina,"Cálculo 2");
  disciplina[3].periodo = 6;
  disciplina[3].carga_horaria = 60;*/

  // ordenação
  printf("Ordenação realizada!\n");
  quickCurso(curso,0,total_curso-1);
  quickDisciplina(disciplina,0,total_disciplina-1);

  int count = 0;
  // letra a
  printf("letra a\n");
  CURSOS e = cursoMaiorPeriodo(curso,count,total_curso);
  printf("Curso com maior número de período = %s\n",e.nome_curso);

  printf("leitura de dados para a letra b e c!\n");
  char deternimadoCurso[30];
  scanf("%s",deternimadoCurso);
  int perCurso;
  scanf("%d",&perCurso);

  // letra b
  printf("letra b\n");
  int d = aux(curso,deternimadoCurso,count);
  int qt = qtDiscipCurso(disciplina,d,count,0);
  if(qt == 0) printf("Curso não tem disciplinas!\n");
  else printf("%s tem %d disciplina(s)\n",deternimadoCurso,qt);

  // letra c
  printf("letra c\n");
  int dis = disciplinaPerCurso(disciplina,d,perCurso,count,total_disciplina);
  if(dis == 0) printf("Não existe disciplina no periodo %d\n",perCurso);
  else printf("Existe %d disciplinas\n",dis);
	return 0;
}
