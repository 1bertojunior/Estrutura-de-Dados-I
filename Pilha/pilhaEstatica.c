#include <stdio.h>

#define MAX 3

typedef int tdado;
typedef struct{
    tdado e[MAX];
    int topo;
} Pilha;

void init(Pilha *p);
int push(Pilha *p, tdado e);
void printStack(Pilha p);
tdado pop(Pilha *p);
tdado top(Pilha p);
int menu();


int isEmpty(Pilha p);

int main(){

    Pilha p1;
    int op, r;
    tdado e;

    init(&p1);

    do{
        op = menu();

        if(op == 1) {
            printf("Elemento: ");
            scanf("%d", &e);

            if(push(&p1, e)) printf("Success!\n");
            else printf("[!] - Erro!\n");
        }
        if(op == 2) {
            if(!isEmpty(p1)){
                r = pop(&p1);
                if(r) printf("SUCESS!\nE = %d\n", r);
                else printf("[!] - Erro!\n");
            }else printf("[!] - Pilha vazia!\n");
        }
        if(op == 3){
            printf("Topo: %d\n", top(p1));
            if(!isEmpty(p1)) printf("Dado do topo: %d\n", top(p1));
            else printf("[!] - Pilha Vazia!\n");
        }


    }while(op != 0);


    return 0;
}

//menu
int menu(){
    int op;
    printf("[0] - Sair\n[1] - Push(Empilhar)\n[2]- Pop(Desempilhar)\n[3] - Top (Topo)\n[4] - Mostar pilha\n");
    printf("OPÇÃO: ");
    scanf("%d", &op);
    return op;
}

//inicializar pilha com topo em -1
void init(Pilha *p){
    p->topo = -1;
} 
//operações básicas 
//empilhar elemento na pilha
int push(Pilha *p, tdado e){
    if(p->topo == MAX-1) return 0;
    
    p->topo++;
    p->e[p->topo] = e;

    return 1; 
}
//imprimir pilha
void printStack(Pilha p){
    while(p.topo != -1){
        printf("%d\n", p.e[p.topo]);
        p.topo--;
    }
}
//desempilhar elemento na pilha
tdado pop(Pilha *p){
    tdado a;
    if(p->topo == -1) return 0;

    a = p->e[p->topo];
    p->topo--;

    return a;
}
// verrificar se a pilha está vazia
int isEmpty(Pilha p){
    return p.topo == -1;
}
//get o topo
tdado top(Pilha p){
    return p.e[p.topo];
}
