#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

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
void showStack(Pilha p);

int main(){

    Pilha p1,p2,p3;
    char e[TAM][10];
    int op, m, n;

    p1.topo = p2.topo = -1;

    printf("Quantidade de elemets para P1: ");
    scanf("%d", &p1.t);
    printf("Quantidade de elemets para P2: ");
    scanf("%d", &p2.t);


    do{
        op = menu();

        if(op == 1) {
            if(!pilhaCheia(p1)){
                setElement(&p1);
            }else printf("[!] - Pilha 1 cheia!\n\n");
        }
        if(op == 2) {
            if(!pilhaCheia(p2)){
                setElement(&p2);
            }else printf("[!] - Pilha 2 cheia!\n\n");
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
            printf("Imprimir pilha (1 ou 2): ");
            scanf("%d", &n);
            if(n == 1) showStack(p1);
            else if(n == 2) showStack(p2);
            else printf("[!] - Pilha invalida!\n");
            
        }
        if(op == 6){
            m = p1.t > p2.t ? p1.t : p2.t;
            printf("M %d\n", m);

            for(int i=0; i<m; i++){
                if(!pilhaVazia(p1.topo) && pilhaVazia(p2.topo)){
                    

                    if(!isVowels(tolower(p1.v[i][0]))) empilhar(&p3, p1.v[i]);
                    if(!isVowels(tolower(p2.v[i][0]))) empilhar(&p3, p2.v[i]);
                }else if(1){

                }
            }
           
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

int pilhaCheia(Pilha p){
    return p.topo == p.t-1 ? 1 : 0;
}

int pilhaVazia(int topo){
    return topo == -1 ? 1 : 0;
}

void empilhar(Pilha *p, char e[TAM][11]){
    if(!pilhaCheia(*p)){
        (p)->topo += 1;
        strcpy(p->v[p->topo],*e);
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

void showStack(Pilha p){
    for(int i=0; i<=p.topo; i++) printf("%s\n", p.v[i]);
}