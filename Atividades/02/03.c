#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct{
  char name[31];
  int cpf;
} People;

void change(char *ptr, char n[]){
  strcpy(ptr, n);
}

int main(){

  int menu, tPeople, c = 0;
  People *vp;

  printf("Total de pessoas: ");
  scanf("%d", &tPeople);

  vp =  (People *)malloc(tPeople * sizeof(People));

  do{
    printf("[0] - Sair\n[1] - Listar\n[2] - Add\n[3] - Alterar\n");

    printf("Menu: ");
    scanf("%d", &menu);

    if(menu == 1)  for(int i=0; i<c; i++ ) printf("Nome = %s, CPF = %i, End. %p\n", vp[i].name, vp[i].cpf, &vp[i]);
     
    if(menu == 2){
      char name[21];
      printf("NOME: ");
      scanf(" %[^\n]", name);
      strcpy(vp[c].name, name); 
      printf("CPF: ");
      scanf("%d", &vp[c].cpf);
      c++;
    }

    if(menu == 3){
      char name[21];
      printf("Informe o nome de quem deseja alteara: ");
      scanf(" %[^\n]", name);
      
      for(int i=0; i<c; i++ ) {
        if(strcmp(vp[i].name, name) == 0){
          char newName[21];
          printf("Novo nome: ");
          scanf(" %[^\n]", newName);
          change(&vp[i].name, newName);
          //printf("End. %d\n", vp[i].name);
        }
      }   
    }
  } while(menu != 0);

  free(vp);

  return 0 ;
}