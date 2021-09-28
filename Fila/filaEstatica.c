#include <stdio.h>

#define MAX 5
#define C 11

typedef struct{
    char chassi[18];
    char placa[8];
    char modelo[C];
    char marca[C];
    char cor[C];
    int ano;
} tdado;

typedef struct {
    tdado v[MAX];
    int s,e, qtd;
}Queue;

void initFilha(Queue *f){
    f->s = 0;
    f->e = -1;
    f->qtd=0;
}
int isEmpty(Queue f){
    return f.qtd == 0;
}
int enqueue(Queue *f, tdado x){
    if(f->s == MAX-1) return 0;
    
    f->e++;
    f->v[f->e] = x;
    f->qtd++;

    return 1;
}
tdado dequeue(Queue *f){
    tdado r = f->v[f->s];
    f->s++;
    f->qtd--;
    return r;
}
// imprimir Fila
void printQueue(Queue f){
    while (f.s <= f.e){
        printf("# FILA\n");
        printf("CHASSI: %s\n", f.v[f.s].chassi);
        printf("PLACA: %s\n", f.v[f.s].placa);
        printf("MODELO: %s\n", f.v[f.s].modelo);
        printf("MARCA: %s", f.v[f.s].marca);
        printf("COR: %s\n", f.v[f.s].cor);
        printf("ANO: %d\n", f.v[f.s].ano);
        f.s++;
    }
}
int menu(){
    int op;
    printf("[1] - Enqueue (Inserir)\n[2] - Dequeue (Remover)\n[3] - Primeiro e último\n[4] - Full\n");
    printf("OPÇÃO: ");
    scanf("%d", &op)  ;
    return op;
}

int main(){
    Queue f;
    tdado e;
    int op;

    int v[5];

    initFilha(&f);

    do{
        printf("# Inicio %d, Fim %d\n", f.s, f.e);

        printQueue(f); // mostarndo a fila

        op = menu();

        if(op == 1){
            printf("CHASSI: ");
            scanf("%s", e.chassi);
            printf("PLACA: ");
            scanf("%s", e.placa);
            printf("MODELO: ");
            scanf("%s", e.modelo);
            printf("MARCA: ");
            scanf("%s", e.marca);
            printf("COR: ");
            scanf("%s", e.cor);
            printf("ano: ");
            scanf("%d", &e.ano);
            if(enqueue(&f, e)) printf("# Inserirdo com sucesso!\n");
            else printf("# [!] - Fila cheia\n");
        }
        if(op == 2){
            if(!isEmpty(f)){
                e = dequeue(&f);
                printf("# Carro removido: %s\n", e.modelo);
            }else printf("# [!] - Fila vazia!\n");
        }

        if(op == 4) printQueue(f);

    }while(op != 0);

    return 0;
}
