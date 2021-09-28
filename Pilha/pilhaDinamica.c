#include <stdio.h>
#include <stdlib.h>

typedef int tdado;

typedef struct no{
    tdado e;
    struct no *next;    
} tstack;

typedef struct{
    tstack *top;
    int qtd;
} Stack;

void init(Stack *p){
    p->top = NULL;
    p->qtd = 0;
}

int push(Stack *p, tdado x){
    tstack *new = (tstack *)malloc(sizeof(tstack)); // alocando memória

    if(new == NULL) return 0; // erro ao alocar memória

    new->e = x;
    new->next = p->top;
    p->top = new;
    p->qtd++;

    return 1;
}

tdado pop(Stack *p){
    tstack *a = p->top;
    tdado x;

    if(a != NULL){
        p->top = a->next;
        a->next = NULL;
        x = a->e;
        free(a);
    }

    return x;
}

void show(Stack p){
    printf("# END    CONT    NEXT\n");
    while(p.top != NULL){
        printf("%d %d %d\n", p.top, p.top->e, p.top->next);
        p.top = p.top->next;
    }

}

int menu(){
    int op;
    printf("[0] - Exit\n[1] - Push\n[2] - Pop\n[3] - Show\n");
    printf("OPÇÃO: ");
    scanf("%d", &op);

    return op;
}


int main(){

    Stack p1;
    tdado x;
    int op, r;

    init(&p1);

    do{
        op = menu();

        switch (op){
            case 1:
                printf("# PUSH\nTdado: ");
                scanf("%d", &x);
                
                if(push(&p1, x)) printf("# SUCCESS!\n");
                else printf("[!] = ERRO!\n");

                break;
            case 2:
                printf("# POP\n");
                x = pop(&p1);

                printf("X = %d", x);

                break;
            case 3:
                printf("#SHOW\n");
                show(p1);
            
            default:
                break;
        }

    }while(op != 0);


    return 0;
}