#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


typedef struct{
    char plate[21];
    int qtdManeuvered; // vezes que saiu pra fora
    int qtdCarsManeuvered; // qtd carros que foram movimentados
} Car;  

typedef struct tfila{
    Car dado;
    struct tfila *next;
} tfila;

typedef struct{
    tfila *s, *e;
} Queue;


int menu();
void init(Queue *f);
int isEmpty(Queue f);
int enqueue(Queue *f, Car x);
Car dequeue(Queue *f);
void show(Queue f);
int searchQueue(Queue *f, char plate[21]);
int maneuver(Queue *f, char plate[21]);

int main(){

    Queue f1;
    Car x;
    int op;
    char op2;

    init(&f1); // init queue

    if(1){
        strcpy(x.plate, "abc123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");

        strcpy(x.plate, "qwe123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");

        strcpy(x.plate, "xyz123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");

        strcpy(x.plate, "hjr123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");

        strcpy(x.plate, "test123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");
        
        strcpy(x.plate, "pia123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");

        strcpy(x.plate, "zeb123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");

        strcpy(x.plate, "ovo123");
        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
        if(enqueue(&f1, x)) printf("# SUCCESS!\n");

    }

    do{
        op = menu();

        switch(op){
            case 1:
                printf("Placa: ");
                scanf("%s", x.plate);
                setbuf(stdin, NULL);

                printf("(E) - ENTRAR (S) - SAIR\nOPÇÃO: ");
                scanf("%c", &op2);
                setbuf(stdin, NULL);

                if(op2 == 69 || op2 == 101){
                    if(searchQueue(&f1, x.plate)) printf("[!] - Já pertence!\n");
                    else{
                        x.qtdCarsManeuvered = x.qtdManeuvered = 0;
                        if(enqueue(&f1, x)) printf("# SUCCESS!\n");
                        else printf("[!] - CHEIO!\n");
                    }                
                } else if(op2 == 83 || op2 == 115){
                    if(searchQueue(&f1, x.plate)){
                        printf("Testando sair.. \n");
                        if(maneuver(&f1, x.plate)) printf("#Sucesso ao remover!\n");
                        else printf("[!] Erro ao remover!\n");
                    }else printf("[!] - Carro não encontrado!\n");
                }

                break;
            case 2:
                show(f1);
                break;
            case 3:
                printf("# BUscar\n");
                break;
            case 4:
                x = dequeue(&f1);
                printf("CAR | Placa %s - Qtd mov %d - Qtd carros mov %d\n", x.plate, x.qtdManeuvered, x.qtdCarsManeuvered);
            case 5:
                if(searchQueue(&f1, "qwe123")) printf("# Achou!\n");
                break;
            default:
                break;
        }

    }while(op != 0);

    return 0;
}

int menu(){
    int op;
    printf("[0] - Exit\n[1] - Estacionamento\n[2] - Show\n[3] - Buscar\nOPÇÃO: ");
    scanf("%d", &op);
    return op;
}

void init(Queue *f){
    f->s = f->e = NULL;
}

int isEmpty(Queue f){
    return f.s == NULL;
}

int enqueue(Queue *f, Car x){
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

Car dequeue(Queue *f){
    tfila *aux = f->s;
    Car x;
    if(aux != NULL){
        f->s = aux->next;
        aux->next = NULL;

        x = aux->dado;
        free(aux);

        if(f->s == NULL) f->e = NULL;
    }

    return x;
}

void show(Queue f){
    tfila *x = f.s;

    if(x != NULL){
        while(x != NULL){
            printf("CAR | Placa %s - Qtd mov %d - Qtd carros mov %d\n", x->dado.plate, x->dado.qtdManeuvered, x->dado.qtdCarsManeuvered);
            x = x->next;       
        }    

    }else printf("[!] Fila vazia!\n");
}

int searchQueue(Queue *f, char plate[21]){
    Queue a;
    Car x;
    int result = 0;

    init(&a);

    while(f->s != NULL){
        x = dequeue(f);
        enqueue(&a, x);
        if(strcmp(x.plate, plate) == 0) result = 1;
        //printf("CAR | Placa %s - Qtd mov %d - Qtd carros mov %d\n", x.plate, x.qtdManeuvered, x.qtdCarsManeuvered);
    }    

    init(f);

    while(a.s != NULL){
        x = dequeue(&a);
        enqueue(f,x);
    }
    
    return result;
}

int maneuver(Queue *f, char plate[21]){
    Queue a;
    Car x;
    int result = 0, mov = 0;

    init(&a);

    while(f->s != NULL){
        x = dequeue(f);

        if(strcmp(x.plate, plate) == 0) {
            x.qtdCarsManeuvered += mov;
            result = 1;
            printf("CAR | Placa %s - Qtd mov %d - Qtd carros mov %d\n", x.plate, x.qtdManeuvered, x.qtdCarsManeuvered);
        }else{
            if(result == 0) x.qtdManeuvered++;
            mov++;
            enqueue(&a, x);            
        }
    }    

    init(f);

    while(a.s != NULL){
        x = dequeue(&a);
        enqueue(f,x);
    }
    
    return result;
}
