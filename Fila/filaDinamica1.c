#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char info;
    Fila *prox;
    
}Fila;

void insereFila(Fila **s, Fila **e, Fila *no){
    if(*s == NULL) *s = *e =  no;
    else{
        (*e)->prox = no; // (**e).prox
        *e = no;
    }
}

void *aloca(char E){
    Fila *no;
    no = (Fila *)malloc(sizeof(Fila));
    no->info = E;
    no->prox = NULL;

    return no;
}

int main(){
    Fila *s, *e, *no;
    int op;
    char E;
    
    s = e = NULL;

    do{ 
        printf("[0] - Sair\n[1] - Inserir\n");

        if(op == 1){
            printf("E: ");
            scanf("%c", E);
            no == aloca(E);
            insereFila(&s,&e,no);
        }
        

    }while(op != 0);



    return 0;
}