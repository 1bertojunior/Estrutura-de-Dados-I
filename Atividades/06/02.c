#include<stdio.h>
#include<stdlib.h>


typedef struct {
    int id, year, age;
    char name[21];
} tdado; // Matricula, Nome, Ano Escolar, Idade

typedef struct tfila{
    tdado dado;
    struct tfila *next;
} tfila;

typedef struct{
    tfila *s, *e;
} Queue;

void init(Queue *f){
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
    if(aux != NULL){
        f->s = aux->next;
        aux->next = NULL;

        x = aux->dado;
        free(aux);

        if(f->s == NULL) f->s = NULL;
    }

    return x;
}
int isYearValid(int y){
    return y >= 6 && y <= 9;
}

void showAll(Queue f){
    tfila *x = f.s;

    while(x != NULL){
        showOne(x->dado);
        x = x->next;       
    }    
}

void showOne(tdado x){
    printf("Matricula: %d\n", x.id);
    printf("Nome: %s\n", x.name);
    printf("Ano escolar: %d\n", x.year);
    printf("Idade: %d\n", x.age);  
}

int removeById(Queue *f, int id){
    Queue *faux = (Queue *)malloc(sizeof(Queue)); 
    tdado x;
    int r = 0;

    while(!isEmpty(*f)){
        x = dequeue(f);

        if(x.id == id) r = 1;
        else enqueue(faux, x);
    }

    while(!isEmpty(*faux)){
        x = dequeue(faux);
        enqueue(f, x);
    }

    return r;
}

void separete(Queue *f, Queue *f6,Queue *f7,Queue *f8,Queue *f9){
    tdado x;
    
    while(!isEmpty(*f)){
        x = dequeue(f);

        switch(x.year){
            case 6:
                enqueue(f6, x);
                break;
            case 7:
                enqueue(f7, x);
                break;
            case 8:
                enqueue(f8, x);
                break;
            case 9:
                enqueue(f9, x);
                break;
            default:
                break;
        }

    }
    
}

int menu(){
    int op;
    printf("[0] - Exit\n[1] - Enqueue (Inserir)\n[2] - Dequeue (Remover)\n[3] - Show all\n[4] - Remover por matricula\n[5] - Separar por ano\n");
    printf("OPÇÃO: ");
    scanf("%d", &op)  ;
    return op;
}

int main(){
    Queue *f1 = (Queue *)malloc(sizeof(Queue)), *f6 = (Queue *)malloc(sizeof(Queue)),
    *f7 = (Queue *)malloc(sizeof(Queue)), *f8 = (Queue *)malloc(sizeof(Queue)), 
    *f9 = (Queue *)malloc(sizeof(Queue));
    tdado x;
    int op, id;

    init(f1);
    init(f6);
    init(f7);
    init(f8);
    init(f9);

    do{
        op = menu();

        switch(op){
            case 1:
                printf("# ADD\nMatricula: ");
                scanf("%d", &x.id);
                printf("Nome: ");
                scanf(" %[^\n]", x.name);
                do{
                    printf("Ano escolar (6 ~ 9 ano): ");
                    scanf("%d", &x.year);
                }while(!isYearValid(x.year));               
                printf("Idade: ");
                scanf("%d", &x.age); 

                enqueue(f1, x);
                
                break;
            case 2:
                if(!isEmpty(*f1)){
                    x = dequeue(f1);
                    showOne(x);
                }else printf("[!] Fila vaia!\n");
               
                break;
            case 3:
                if(!isEmpty(*f1)){
                    showAll(*f1);
                }else printf("[!] Fila vaia!\n");
                break;
            case 4:
                if(!isEmpty(*f1)){
                    printf("Matricula: ");
                    scanf("%d", &id);
                    
                    if(removeById(f1, id)) printf("OK\n");
                    else printf("[!] - Error!\n") ;
                }else printf("[!] Fila vaia!\n");
                break;
            case 5:
                printf("# Separar em filas por ano\n");
                separete(f1, f6, f7, f8, f9);

                printf("# Filas de todos os anos\n");
                printf("# 6 ANO\n");
                showAll(*f6);
                printf("# 7 ANO\n");
                showAll(*f7);
                printf("# 8 ANO\n");
                showAll(*f8);
                printf("# 9 ANO\n");
                showAll(*f9);
                break;
            
            default:
                break;
        }

    }while(op != 0);


    return 0;
}