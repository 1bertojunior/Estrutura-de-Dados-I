#include<stdio.h>
#include<stdlib.h>

#define TAM 3

typedef struct {
    int v[TAM];
    int topo;
} Pilha;

int pilhaCheia(int topo);
int pilhaVazia(int topo);
void empilhar(Pilha *p, int e);
int desempilhar(Pilha *p);
int menu();

int main(){

    Pilha p;
    int e, op;
    p.topo = -1;

    do{
        op = menu();

        if(op == 1) {
            if(!pilhaCheia(p.topo)){
                printf("Valor: ");
                setbuf(stdin, NULL);
                scanf("%d", &e);
                setbuf(stdin, NULL);
                empilhar(&p, e);
            }else printf("[!] - Pilha cheia!\n");
        }
        if(op == 2) {
            if(!pilhaVazia(p.topo)) printf("D = %d\n", desempilhar(&p));
            else printf("[!] - Pilha vazia!\n");
        }

    }while (op !=0 );
    

    printf("Teste\n");

    return 0;
}

int pilhaCheia(int topo){
    return topo == TAM-1 ? 1 : 0;
}
int pilhaVazia(int topo){
    return topo == -1 ? 1 : 0;
}

void empilhar(Pilha *p, int e){
    if(!pilhaCheia(p->topo)){
        p->topo++;
        p->v[p->topo] = e;
    }
}

int desempilhar(Pilha *p){
    int e;
    if(!pilhaVazia(p->topo)){
        e = p->v[p->topo];
        p->topo--;
    }

    return e;
}

int menu(){
    int op;
    printf("[0] - Sair\n[1] - Empilhar\n[2] - Desempilhar\n[3] - Mostrar\n");
    printf("OPÇÃO: ");
    scanf("%d", &op);
    return op;
}