#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX 3
#define C 21

typedef struct{
    char v[MAX][21];
    int topo, tam;
} Stack;

int menu();
void initStack(Stack *p);
int isEmpty(int topo);
int isFull(Stack p);
void printStack(Stack p);
void push(Stack *p, char x[21]);
void pop(Stack *p, char *e[21]);

int isVowel(int c);

int main(){

    Stack p1,p2,p3;
    int op, m, n;
    char e[21], ev[MAX][21];

    initStack(&p1);
    initStack(&p2);
    initStack(&p3);

    printf("Quantidade de elemets para P1: ");
    scanf("%d", &p1.tam);
    printf("Quantidade de elemets para P2: ");
    scanf("%d", &p2.tam);

    do{
        op = menu();

        if(op == 1) {
            if(!isFull(p1)){
                printf("Str: ");
                setbuf(stdin, NULL);
                scanf(" %[^\n]", e);
                setbuf(stdin, NULL);
                push(&p1);
            }else printf("[!] - Pilha 1 cheia!\n\n");
        }        

    }while (op !=0 );


    return 0;
}

int menu(){
    int op;
    printf("[0] - Sair\n[1] - Empilhar P1\n[2] - Empilhar P2\n[3] - Desempilhar P1\n[4] - Desempilhar P2\n[5] - Mostra uma pilha\n[6] - Str que inciam com consoantes\n");
    printf("OPÇÃO: ");
    scanf("%d", &op);
    return op;
}
void initStack(Stack *p){
    p->topo = -1;
}
int isEmpty(int topo){
    return topo == -1;
}
int isFull(Stack p){
   return p.topo == p.tam;
} 
void printStack(Stack p){
    while(p.topo != -1){
        printf("%d\n", p.v[p.topo]);
        p.topo--;
    }
}
void push(Stack *p, char x[21]){
    if(!isFull(*p)){
        p->topo +=1;
        strcpy(p->v[p->topo], x);
    }
}
void pop(Stack *p, char *e[21]){
    if(!isEmpty(p->topo)){
        strcpy(e, p->v[p->topo]);
        p->topo--;
    }
}

int isVowel(int c){
    return c == 97  || c == 101 || c == 105 || c == 111 || c == 117 ? 1 : 0;
}








