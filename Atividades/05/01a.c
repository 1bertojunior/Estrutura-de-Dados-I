#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 3

typedef char tdado[TAM];

typedef struct {
    tdado v[11];
    int topo;
} Pilha;

int menu();
int pilhaCheia(int topo);
int pilhaVazia(int topo);
void empilhar(Pilha *p, char e[TAM][11]);
void desempilhar(Pilha *p, char *e);

int main(){

    Pilha p;
    int op;
    char e[TAM];
    p.topo = -1;

    do{
        op = menu();

        if(op == 1) {
            if(!pilhaCheia(p.topo)){
                printf("Str: ");
                setbuf(stdin, NULL);
                scanf("%[^\n]", e);
                setbuf(stdin, NULL);
                empilhar(&p, e);
            }else printf("[!] - Pilha cheia!\n\n");
        }
        if(op == 2) {
            if(!pilhaVazia(p.topo)) {
                desempilhar(&p,&e);
                printf("E = %s\n", e);
            }else printf("[!] - Pilha vazia!\n\n");
        }

    }while (op !=0 );

    return 0;
}

int menu(){
    int op;
    printf("[0] - Sair\n[1] - Empilhar\n[2] - Desempilhar\n");
    printf("OPÇÃO: ");
    scanf("%d", &op);
    return op;
}

int pilhaCheia(int topo){
    return topo == TAM-1 ? 1 : 0;
}

int pilhaVazia(int topo){
    return topo == -1 ? 1 : 0;
}

void empilhar(Pilha *p, char e[TAM][11]){
    if(!pilhaCheia(p->topo)){
        p->topo += 1;
        strcpy(p->v[p->topo],e);
    }
}


void desempilhar(Pilha *p, char *e){
    if(!pilhaVazia(p->topo)){
        strcpy(e, p->v[p->topo]);
        p->topo--;
    }
}
