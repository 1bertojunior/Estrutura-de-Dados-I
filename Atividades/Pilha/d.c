#include<stdio.h>
#include<stdlib.h>

typedef struct{
    char Info;
    PilhaD *a;
} PilhaD;

char lerElemento(){
    char E;
    printf("Caractere: ");
    scanf("%c", &E);

    return E;
}

void empilhar(PilhaD **Topo, PilhaD *No, char E){
    if(No != NULL){
        (*No).Info = E;
        (*No).a = *Topo;
        *Topo = No;
    }
}

char desempilhar(PilhaD **Topo){
    char e;
    PilhaD *aux;

    if(*Topo != NULL){
        e = (**Topo).Info;
        aux = *Topo;
        *Topo = (**Topo).a;
        free(aux);
    }

    

    return e;
}

PilhaD *alocaNo(){
    PilhaD *Novo,  *No;
   

    return Novo;
}

int main(){
    int op;
    PilhaD *Topo, *No;
    char E;
    Topo = NULL;

    do{
        No = alocaNo();
        E = lerElemento();
        empilhar(&Topo, No, E);

        printf("[0] - Stop\n[1] - Next\n");
        scanf("%d", &op);
    }while(op != 0);

    do{
        E = desempilhar(&Topo);
        printf("C %c\n", E);
    }while(Topo != NULL);

    
    return 0;
}