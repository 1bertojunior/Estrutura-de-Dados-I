#include<stdio.h>
#include<stdlib.h>

typedef struct{
    int id, processingTime, priority, count;
}tdado;

typedef struct tfila{
    tdado dado;
    struct tfila *next;
} tfila;

typedef struct{
    tfila *s, *e;
    int tam;
} Queue;

int menu();
tdado set();
void init(Queue *f);
int isEmpty(Queue f);
int enqueue(Queue *f, tdado x);
int enqueuePriority(Queue *f1, Queue *f2, Queue *f3, tdado x);
tdado dequeue(Queue *f);
void show(Queue f);
tdado scheduler(Queue *f1, Queue *f2, Queue *f3);
void scheduler2(Queue *f1, Queue *f2, tdado *x, int tf);
void useProcessor(tdado *x);

int getNextUseProcessor(Queue *f1, Queue *f2, Queue *f3, tdado *x);
int getTheAmount(Queue f);
int missingHowLong(Queue *f, int tf);
int missingHowLong2(Queue *f);
int search(Queue *f, int id);
int processingTimeForProcess(Queue *f, int id, int tf);

int main(){
    
    Queue f1, f2, f3;
    tdado x;
    int op, op2, result=0;

    init(&f1);
    init(&f2);
    init(&f3);

    if(1){ // teste
        x.id = 1;
        x.processingTime = 3;
        x.priority = 1;
        enqueue(&f1,x);

        x.id = 2;
        x.processingTime = 2;
        x.priority = 1;
        enqueue(&f1,x);

        x.id = 3;
        x.processingTime = 1;
        x.priority = 1;
        enqueue(&f1,x);

        x.id = 4;
        x.processingTime = 4;
        x.priority = 2;
        enqueue(&f2,x);

        x.id = 5;
        x.processingTime = 5;
        x.priority = 3;
        enqueue(&f3,x);

        x.id = 6;
        x.processingTime = 10;
        x.priority = 1;
        enqueue(&f1,x);

    }

    do{
        op = menu();

        switch(op){
            case 1:
                x = set();
                if(enqueuePriority(&f1,&f2,&f3,x)) printf("#SUCCESS!\n");
                else printf("[!] Erro!\n");
                break;

            case 2:
                if(!isEmpty(f1) || !isEmpty(f2) || !isEmpty(f3)){
                    x = scheduler(&f1,&f2,&f3);
                    printf("ID = %d | TEMPO = %d | PRIORIDADE = %d | COUNT = %d\n", x.id, x.processingTime, x.priority, x.count);
                }else printf("[!] - Filas vazia!\n");
                break;
            case 3:
                printf("# F1 = %d\n", f1.tam);
                show(f1);
                printf("# F2 = %d\n", f2.tam);
                show(f2);
                printf("# F3 = %d\n", f3.tam);
                show(f3);
                break;  
            
            case 4:
                if(!isEmpty(f1) || !isEmpty(f2) || !isEmpty(f3)){
                    result = getNextUseProcessor(&f1,&f2,&f3, &x);
                    printf("ID = %d | TEMPO = %d | PRIORIDADE = %d | COUNT = %d\n", x.id, x.processingTime, x.priority, x.count);
                } else printf("[!] - Filas vazias!\n");
                break;                      
            case 5:
                printf("FILA (1,2,3): ");
                scanf("%d", &op2);
                switch (op2){
                    case 1:
                        result = getTheAmount(f1);
                        printf("# Quantidade de processos da f1 = %d\n", result);
                        break;
                    case 2:
                        result = getTheAmount(f2);
                        printf("# Quantidade de processos da f1 = %d\n", result);
                        break;
                    case 3:
                        result = getTheAmount(f3);
                        printf("# Quantidade de processos da f1 = %d\n", result);
                        break;
                
                    default:
                    printf("[!] Fila não existente!\n");
                        break;
                }
                break;
            case 6:
                printf("FILA (1,2,3): ");
                scanf("%d", &op2);
                switch (op2){
                    case 1:
                        result = missingHowLong(&f1,0);
                        printf("# Tempo falta da f1 = %d\n", result);
                        break;
                    case 2:
                        result = missingHowLong(&f2,0);
                        printf("# Tempo falta da f2 = %d\n", result);
                        break;
                    case 3:
                        result = missingHowLong(&f3,1);
                        printf("# Tempo falta da f3 = %d\n", result);
                        break;
                }
                break;
            case 7:
                printf("# SEARCH\nID: ");
                scanf("%d", &x.id);
                result = search(&f1,x.id);
                if(result){
                    printf("# ACHOU NA F1\n");
                    result = processingTimeForProcess(&f1, x.id, 0);
                    printf("# TEMPO QUE FALTA: %d\n", result);
                }else if(search(&f2,x.id)){
                    printf("# ACHOU NA F2\n");
                    result = missingHowLong(&f1,0);
                    result += processingTimeForProcess(&f2, x.id, 0);                    
                    printf("# TEMPO QUE FALTA: %d\n", result);
                }else if(search(&f3, x.id)){
                    printf("# ACHOU NA F3\n");
                    printf("F3 = %d\n", processingTimeForProcess(&f3, x.id, 0));
                    result = processingTimeForProcess(&f1, x.id, 1);
                    result += missingHowLong(&f2,0) + processingTimeForProcess(&f3, x.id, 0);
                    printf("# TEMPO QUE FALTA: %d\n", result);
                }else printf("[!] Não encontrado!\n");
                break;
            case 8:
                printf("# TEMPO TOTAL QUE RESTA TODAS AS FILAS\n");
                result = result = missingHowLong2(&f1) + missingHowLong2(&f2) + missingHowLong2(&f3);
                printf("# TEMPO = %d\n", result);
                break;
            default:
                break;
        }

    }while(op != 0);


    return 0;
}


// FUNÇÕES
int menu(){
    int op;
    printf("\n[1] - Inserir\n[2] - Escalonador\n[3] - Todos\n[4] - Próximo\n[5] - Quantidade de processos\n[6] - Tempo falta de uma fila\n[7] - Tempo para um processo\n[8] - Tempo total dos processos\n");
    printf("OPÇÃO: ");
    scanf("%d", &op)  ;
    return op;
}

tdado set(){
    tdado x;
    printf("ID: ");
    scanf("%d", &x.id);
    setbuf(stdin, NULL);
    printf("TEMPO (SEG): ");
    scanf("%d", &x.processingTime);
    setbuf(stdin, NULL);
    printf("PRIORIDADE (1,2 ou 3): ");
    scanf("%d", &x.priority);
    setbuf(stdin, NULL);
    x.count = 0;
    return x;
}

void init(Queue *f){
    f->s = f->e = NULL;
    f->tam = 0;
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
        f->tam++;

        if(f->s == NULL) f->s = new;
        else f->e->next = new;

        f->e = new;
    }
    return 1;
}

int enqueuePriority(Queue *f1, Queue *f2, Queue *f3, tdado x){
    int result = 0;

    switch(x.priority){
        case 1:
            result = enqueue(f1, x);
            break;
        case 2:
            result = enqueue(f2, x);
            break;
        case 3:
            result = enqueue(f3, x);
            break;
        default:
            result = 0;
            break;
    }

    return result;
}

tdado dequeue(Queue *f){
    tfila *aux = f->s;
    tdado x;
    if(aux != NULL){
        f->s = aux->next;
        aux->next = NULL;
        f->tam--;

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
            printf("ID = %d | TEMPO = %d | PRIORIDADE = %d | COUNT = %d\n", x->dado.id, x->dado.processingTime, x->dado.priority, x->dado.count);
            x = x->next;       
        }    

    }else printf("[!] Fila vazia!\n");
}

tdado scheduler(Queue *f1, Queue *f2, Queue *f3){
    tdado x;

    if(!isEmpty(*f1)) scheduler2(f1,f2, &x, 0);
    else if(!isEmpty(*f2)) scheduler2(f2,f3, &x, 0);
    else if(!isEmpty(*f3)) scheduler2(f3,f3, &x, 1);
    else printf("Filas Vazias!\n");

    return x;
}

void scheduler2(Queue *f1, Queue *f2, tdado *x, int tf){
    *x = dequeue(f1);

    if(tf == 0){
        useProcessor(x);
        if((*x).processingTime != 0){
            if((*x).count == 2) {
                (*x).count = 0;
                enqueue(f2,*x);
            }else enqueue(f1,*x);
        }
    }else if(tf == 1){
        useProcessor(x);
        if(x->processingTime != 0) enqueue(f1,*x);
    }
    
}

void useProcessor(tdado *x){
    x->count++;
    x->processingTime--;
}

//new att

int getNextUseProcessor(Queue *f1, Queue *f2, Queue *f3, tdado *x){
    int result = 0;

    if(!isEmpty(*f1)) {
        *x = f1->s->dado;
        result = 1;
    } else if(!isEmpty(*f2)){
        *x = f2->s->dado;
        result = 1;
    }else if(!isEmpty(*f3)){
        *x = f3->s->dado;
        result = 1;
    }

    return result;
}

int getTheAmount(Queue f){
    return f.tam;
}

int missingHowLong(Queue *f, int tf){ // Faltando quanto tempo
    Queue a;
    tdado x;
    int result=0;

    init(&a);
    
    while(f->s != NULL){
        x = dequeue(f);
        enqueue(&a, x);

        if(tf==0){
            while(x.processingTime != 0 && x.count != 2){
                useProcessor(&x);
                result++;
            }
        }else if(tf == 1){
            while(x.processingTime != 0){
                useProcessor(&x);
                result++;
            }
        }
    }  
      
    init(f);

    while(a.s != NULL){
        x = dequeue(&a);
        enqueue(f,x);
    }

    return result;
}

int missingHowLong2(Queue *f){ // Faltando quanto tempo
    Queue a;
    tdado x;
    int result=0;

    init(&a);

    while(f->s != NULL){
        x = dequeue(f);
        enqueue(&a, x);

        result += x.processingTime;
    }

    init(f);

    while(a.s != NULL){
        x = dequeue(&a);
        enqueue(f,x);
    }

    return result;
}

int search(Queue *f, int id){
    Queue a;
    tdado x;
    int result = 0;

    init(&a);

    while(f->s != NULL){
        x = dequeue(f);
        enqueue(&a, x);

        if(x.id == id) result = 1;
    }
    
    init(f);

    while(a.s != NULL){
        x = dequeue(&a);
        enqueue(f, x);
    }

    return result;
}

int processingTimeForProcess(Queue *f, int id, int tf){ // Faltando quanto tempo
    Queue a;
    tdado x;
    int result=0, result2 = 0;

    init(&a);

    if(tf == 0){
        while(f->s != NULL){
            x = dequeue(f);
            enqueue(&a, x);
            
            useProcessor(&x);

            if(x.id == id) result = 1; 
            if(result == 0) result2++;
        }
    }else if(tf == 1){
         while(f->s != NULL){
            x = dequeue(f);
            enqueue(&a, x);

            if(x.processingTime >= 4 && x.count == 0) result2 += 4;
            else if(x.processingTime >=4 && x.count == 1) result2 += 3;
            else result2 += x.processingTime;
        }
    }
    

    init(f);

    while(a.s != NULL){
        x = dequeue(&a);
        enqueue(f,x);
    }

    return result2;
}