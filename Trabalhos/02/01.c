#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 10

typedef struct{
    char plate[21];
    int qtdManeuvered; // vezes que saiu pra fora
    int qtdCarsManeuvered; // qtd carros que foram movimentados
} Car;

typedef struct{
    Car v[MAX];
    int s,e,qtd;
} Queue;

int menu();

void initQueue(Queue *f);
int enqueue(Queue *f, Car x);
int isEmpty(Queue f);
int isFull(Queue f);
Car dequeue(Queue *f);
void showQueue(Queue *f);
int searchQueue(Queue *f, char plate[21]);
int maneuver(Queue *f, Car *c, char plate[21]);


int main(){

    Queue f1;
    Car a;
    int op, search;
    char op2;

    initQueue(&f1); // init stack
    if(1){
        strcpy(a.plate, "abc123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");
            
        strcpy(a.plate, "qwe123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");

        strcpy(a.plate, "xyz123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");

        strcpy(a.plate, "hjr123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");

        strcpy(a.plate, "test123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");
        
        strcpy(a.plate, "pia123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");

        strcpy(a.plate, "zeb123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");

        strcpy(a.plate, "ovo123");
        a.qtdCarsManeuvered = a.qtdManeuvered = 0;
        if(enqueue(&f1, a)) printf("# SUCCESS!\n");
    }
    

    do{ 
        op = menu();

        switch (op){
        case 1:
            printf("Placa: ");
            scanf("%s", a.plate);
            setbuf(stdin, NULL);

            printf("(E) - ENTRAR (S) - SAIR\nOPÇÃO: ");
            scanf("%c", &op2);
            setbuf(stdin, NULL);

            if(op2 == 69 || op2 == 101){
                if(searchQueue(&f1, a.plate)) printf("[!] - Já pertence!\n");
                else{
                    a.qtdCarsManeuvered = a.qtdManeuvered = 0;
                    if(enqueue(&f1, a)) printf("# SUCCESS!\n");
                    else printf("[!] - CHEIO!\n");
                }                
            } else if(op2 == 83 || op2 == 115){
                if(searchQueue(&f1, a.plate)){
                    printf("Testando sair.. \n");
                    if(maneuver(&f1,&a, a.plate)) {
                        printf("#Sucesso ao sair!\n");
                        printf("CAR | Placa: %s - Mov carro: %d - Qtd carros mov: %d\n", a.plate, a.qtdManeuvered, a.qtdCarsManeuvered);
                    }
                    else printf("[!] Erro ao remover!\n");
                }else printf("[!] - Carro não encontrado!\n");
            }

            break;

        case 2:
            printf("# FILA 1\n");
            showQueue(&f1);
            break;    

            break;
        
        default:
            break;
        }
    }while (op != 0);

    return 0;
}

int menu(){
    int op;
    printf("[0] - Exit\n[1] - Estacionamento\n[2] - Show\nOPÇÃO: ");
    scanf("%d", &op);
    return op;
}

void initQueue(Queue *f){
    f->s = 0;
    f->qtd = 0;
    f->e = -1;
}
int enqueue(Queue *f, Car x){
    if(f->e == MAX-1)  return 0;
    
    f->e++;
    f->v[f->e] = x;
    f->qtd++;

    return 1;
}

int isEmpty(Queue f){
    return f.qtd == 0;
}

int isFull(Queue f){
    return f.qtd == MAX;
}

Car dequeue(Queue *f){
    Car a = f->v[f->s];
    f->s++;
    return a;
}

void showQueue(Queue *f){
    Queue a;
    Car x;

    initQueue(&a);

    while(f->s <= f->e){
        x = dequeue(f);
        enqueue(&a, x);
        printf("CAR | Placa %s - Qtd mov %d - Qtd carros mov %d\n", x.plate, x.qtdManeuvered, x.qtdCarsManeuvered);
        f->qtd++;
    }
    
    initQueue(f);

    while (a.s <= a.e){
        x = dequeue(&a);
        enqueue(f, x);
        a.qtd++;
    }
    
}

int searchQueue(Queue *f, char plate[21]){
    Queue a;
    Car x;
    int result = 0;

    initQueue(&a);

    while(f->s <= f->e){
        x = dequeue(f);
        enqueue(&a, x);

        if(strcmp(x.plate, plate) == 0) result = 1;

        f->qtd++;
    }
    
    initQueue(f);

    while (a.s <= a.e){
        x = dequeue(&a);
        enqueue(f, x);
        a.qtd++;
    }

    return result;
}


int maneuver(Queue *f, Car *c, char plate[21]){
    Queue a;
    Car x;
    int result =0,  mov = 0;

    initQueue(&a);

    while(f->s <= f->e){
        x = dequeue(f);  

        if(strcmp(x.plate, plate) == 0) {
            x.qtdCarsManeuvered += mov;
            result = 1;
            *c = x;
        } else{
            if( result == 0) x.qtdManeuvered++;
            mov++;
            enqueue(&a, x);
        }
    }
    
    initQueue(f);

    while (a.s <= a.e){
        x = dequeue(&a);
        enqueue(f, x);
        //a.qtd++;
    }

    return result;
}