#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define TAM 3

typedef struct {
    char v[TAM][11];
    int topo, t;
} Pilha;

int menu();
int pilhaCheia(Pilha p);
int pilhaVazia(int topo);
void empilhar(Pilha *p, char e[TAM][11]);
void desempilhar(Pilha *p, char *e);
void setElement(Pilha *p);
int isVowels(int c);

void stackOfVowel(Pilha *p1, Pilha *p2, Pilha *p3){
    char e1[11], e2[21];
    if(!pilhaVazia(p1->topo) && !pilhaVazia(p2->topo)){
        desempilhar(p1,&e1);
        desempilhar(p2,&e2);
        if(!isVowels(e1)) empilhar(p3,e1);
        else if(!isVowels(e2)) empilhar(p3,e2);
    }else if(!pilhaVazia(p1->topo)) {
        desempilhar(p1,&e1);
        if(!isVowels(e1)) empilhar(p3,e1);
    }else if(!pilhaVazia(p2->topo)) {
        desempilhar(p2,&e2);
        if(!isVowels(e2)) empilhar(p3,e2);
    }

}

int main(){

    Pilha p1,p2,p3;
    char e[TAM][10];
    int op;

    p1.topo = p2.topo = -1;

    printf("Quantidade de elemets para P1: ");
    scanf("%d", &p1.t);
    printf("Quantidade de elemets para P2: ");
    scanf("%d", &p1.t);


    do{
        op = menu();

        if(op == 1) {
            if(!pilhaCheia(p1)){
                setElement(&p1);
            }else printf("[!] - Pilha 1 cheia!\n\n");
        }
        if(op == 1) {
            if(!pilhaCheia(p2)){
                setElement(&p2);
            }else printf("[!] - Pilha 1 cheia!\n\n");
        }

        if(op == 3) {
            if(!pilhaVazia(p1.topo)) {
                desempilhar(&p1,&e);
                printf("E = %s\n", e);
            }else printf("[!] - Pilha 1 está vazia!\n\n");
        }
        if(op == 4){
            if(!pilhaVazia(p2.topo)) {
                desempilhar(&p2,&e);
                printf("E = %s\n", e);
            }else printf("[!] - Pilha 2 está vazia!\n\n");
        }

        if(op == 5){
            stackOfVowel(&p1,&p2,&p3);
        }
        

    }while (op !=0 );

    return 0;
}

int menu(){
    int op;
    printf("[0] - Sair\n[1] - Empilhar P1\n[2] - Empilhar P2\n[3] - Desempilhar P1\n[4] - Desempilhar P2\n[5] - Str que inciam com consoantes\n");
    printf("OPÇÃO: ");
    scanf("%d", &op);
    return op;
}

int pilhaCheia(Pilha p){
    return p.topo == (p.t)-1 ? 1 : 0;
}

int pilhaVazia(int topo){
    return topo == -1 ? 1 : 0;
}

void empilhar(Pilha *p, char e[TAM][11]){
    if(!pilhaCheia(*p)){
        p->topo += 1;
        strcpy(p->v[p->topo],e);
    }
}

void setElement(Pilha *p){
    char e[21];
    printf("Str: ");
    setbuf(stdin, NULL);
    scanf("%[^\n]", e);
    setbuf(stdin, NULL);
    empilhar(p, e);
}

void desempilhar(Pilha *p, char *e){
    if(!pilhaVazia(p->topo)){
        strcpy(e, p->v[p->topo]);
        p->topo--;
    }
}

int isVowels(int c){
    return c == 97  || c == 101 || c == 105 || c == 111 || c == 117 ? 1 : 0;
}