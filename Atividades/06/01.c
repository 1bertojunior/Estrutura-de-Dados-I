#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int id;
    char title[21];
    char artist[21];
    int year;
}tdado;

typedef struct no{
    tdado e;
    struct no *next;    
} tstack;

typedef struct{
    tstack *top;
    int qtd;
} Stack;

int menu();
void init(Stack *p);
int isEmpty(Stack p);
int push(Stack *p, tdado x);
tdado pop(Stack *p);
tdado set();
void showAll(Stack *p);
void showOne(tdado x);
void searchByYear(Stack *p, Stack *sy, int y);

int main(){

    Stack p1, spop, srock, ssertanejo, sforro, saxe, syear; //pop, rock, sertanejo, forro, axe;
    tdado x;
    int op, genre, y;

    init(&p1);
    init(&spop);
    init(&srock);
    init(&ssertanejo);
    init(&sforro);
    init(&saxe);
    init(&syear);

    do{
        op = menu(); 

        switch (op){
            case 1:
                printf("# PUSH NORMAL\n");
                x = set();                
                if(push(&p1, x)) printf("# SUCCESS!\n");
                else printf("[!] = ERRO!\n");

                break;
            case 2:
                if(!isEmpty(p1)){
                    printf("# POP NORMAL\n");
                    x = pop(&p1);
                    showOne(x);
                }else printf("[!] Vazia!\n");
                break;
            case 3:
                if(!isEmpty(p1)){
                    printf("#SHOW NORMAL\n");
                    showAll(&p1);
                }else printf("[!] Vazia!\n");
                break;
            case 4:
                printf("# PUSH POR GÊNERO\n");
                x = set();

                printf("[1] - Pop | [2] - Rock | [3] - Sertanejo | [4] - Forro | [5] - Axe\nGênero: ");
                scanf("%d", &genre);
                
                switch(genre){
                    case 1:
                        if(push(&spop, x)) printf("# SUCCESS!\n");
                        else printf("[!] = ERRO!\n");
                        break;
                    case 2:
                        if(push(&srock, x)) printf("# SUCCESS!\n");
                        else printf("[!] = ERRO!\n");
                        break;
                    case 3:
                        if(push(&ssertanejo, x)) printf("# SUCCESS!\n");
                        else printf("[!] = ERRO!\n");
                        break;
                    case 4:
                        if(push(&sforro, x)) printf("# SUCCESS!\n");
                        else printf("[!] = ERRO!\n");
                        break;
                    case 5:
                        if(push(&saxe, x)) printf("# SUCCESS!\n");
                        else printf("[!] = ERRO!\n");
                        break;
                    default:
                        break;
                }                
                break;
            case 5:
                printf("\n#SHOW POR GÊNERO\n");
                printf("# POP\n");
                showAll(&spop);
                printf("\n# ROCK\n");
                showAll(&srock);
                printf("\n# SERTANEJO\n");
                showAll(&ssertanejo);
                printf("\n# FORRO\n");
                showAll(&sforro);
                printf("\n# AXE\n");
                showAll(&saxe);
                break;

            case 6:
                printf( "#  SHOW POR GÊNERO\n");
                printf("[1] - Pop | [2] - Rock | [3] - Sertanejo | [4] - Forro | [5] - Axe\nGênero: ");
                scanf("%d", &genre);
                
                switch(genre){
                    case 1:
                        showAll(&spop);
                        break;
                    case 2:
                        showAll(&srock);
                        break;
                    case 3:
                        showAll(&ssertanejo);
                        break;
                    case 4:
                        showAll(&sforro);
                        break;
                    case 5:
                        showAll(&saxe);
                        break;
                    default:
                        break;
                }

                break;

            case 7:
                printf("# CDS POR ANO\nANO: ");
                scanf("%d", &y);

                searchByYear(&spop, &syear, y);  // POP
                searchByYear(&srock, &syear, y);  // POP
                searchByYear(&ssertanejo, &syear, y);  // POP
                searchByYear(&sforro, &syear, y);  // POP
                searchByYear(&saxe, &syear, y);  // POP

                printf("# CDS PELO ANO %d\n", y);

                showAll(&syear);

                break;

            default:
                printf("[!] - OPÇÃO INVÁLIDA!\n");
                break;
        }

    }while(op != 0);

    return 0;
}

int menu(){
    int op;
    printf("[0] - Exit\n[1] - Push normal\n[2] - Pop normal\n[3] - Show normal\n[4] - Push gênero\n[5] - Show all gênero\n[6] -  Show por gênero\n[7] - Show por ano\n");
    printf("OPÇÃO: ");
    scanf("%d", &op);

    return op;
}

void init(Stack *p){
    p->top = NULL;
    p->qtd = 0;
}

int isEmpty(Stack p){
    return p.top == NULL;
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

tdado set(){
    tdado x;

    printf("ID: ");
    scanf("%d", &x.id);
    printf("Título: ");
    scanf(" %[^\n]", x.title);
    printf("Artista: ");
    scanf(" %[^\n]", x.artist);
    printf("Ano: ");
    scanf("%d", &x.year);
    
    return x;
}

void showAll(Stack *p){
    Stack sa;
    tdado tda;

    init(&sa);

    while(p->top != NULL){
        tda = pop(p);
        push(&sa, tda);

        showOne(tda);
    }

    while(sa.top != NULL){
        tda = pop(&sa);
        push(p,tda);
    }
   
}

void showOne(tdado x){
    printf("ID = %d\n", x.id);
    printf("TITULO = %s\n", x.title);
    printf("ARTISTA = %s\n", x.artist);
    printf("ANO = %d\n", x.year);
}

void searchByYear(Stack *p, Stack *sy, int y){
    Stack sa;
    tdado tda;

    init(&sa);

    int t = 0;
    
    while(p->top != NULL){
        tda = pop(p); // remove 

        if(tda.year == y) {
            push(sy, tda); // empilhar nas de ano
            push(&sa, tda); // empilhar na secundaria
            t++;
        }else {
            t++;
            push(&sa, tda); // empilhar na secundaria
        }

    }

    for(int i=0; i<t; i++, t--){
        tda = pop(&sa);
        push(p,tda);
    }

}