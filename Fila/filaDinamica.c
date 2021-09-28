#include<stdio.h>
#include<stdlib.h>

typedef int tdado;

typedef struct tfila{
    tdado dado;
    struct tfila *next;
} tfila;

typedef struct{
    tfila *s, *e;
} Queue;

void init(Queue *f){
    f = (Queue *)malloc(sizeof(Queue));
    f->s = f->e = NULL;
}

int isEmpty(Queue f){
    return f.s == NULL;
}

int enqueue(Queue *f, tdado x){
    tfila *new = (tfila *)malloc(sizeof(tfila));

    if(new == NULL) return 0;
    else{
        new->dado = x;
        new->next = NULL;  

        if(f->s == NULL) f->s = new;
        else f->e->next = new;

        f->e = new;
    }

    return 1;
}

tdado dequeue(Queue *f){
    tfila *aux = f->s;
    tdado x;
    if(aux == NULL) return;
    else{
        f->s = aux->next;
        aux->next = NULL;

        x = aux->dado;
        free(aux);

        if(f->s == NULL) f->s = NULL;
    }

    return x;
}

void show(Queue f){
    tfila *x = f.s;

    if(x != NULL){
        while(x != NULL){
            printf("%d\n", x->dado);
            x = x->next;       
        }    

    }else printf("[!] Fila vazia!\n");
}

int menu(){
    int op;
    printf("[1] - Enqueue (Inserir)\n[2] - Dequeue (Remover)\n[3] - Primeiro e último\n[4] - Full\n");
    printf("OPÇÃO: ");
    scanf("%d", &op)  ;
    return op;
}

int main(){
    
    Queue f1;
    int op, x;

    init(&f1);

    do{
        op = menu();

        switch(op){
            case 1:
                printf("X = ");
                scanf("%d", &x);
                enqueue(&f1, x);
                break;
            case 2:
                x = dequeue(&f1);
                printf("# %d\n", x);
                break;
            case 3:
                show(f1);
                break;            
            
            default:
                break;
        }

    }while(op != 0);


    return 0;
}
