#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

typedef struct {
    int id, qtd;
    char name[21];
} tdado;

typedef struct tlist{
    tdado x;
    struct tlist *prev, *next; 
} tlist;

typedef struct{
    tlist *s, *e;
    int tam;
} List;

int menu();
tdado set();
void init(List *l);
int insert(List *l, tdado x);
int delete(List *l, tdado x);
void showAll(List l);
void showOne(tdado x);
void raffle (List *l, int *f);

int main(){

    List l1;
    tdado x;
    int op,flag = 0, flag2 = 0;

    init(&l1);

    if(0){
        x.id = 1;
        strcpy(x.name, "Premio 1");
        x.qtd = 1;
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n");

        x.id = 2;
        strcpy(x.name, "Premio 2");
        x.qtd = 2;
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n");


        x.id = 3;
        strcpy(x.name, "Premio 3");
        x.qtd = 3;
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n");

        x.id = 4;
        strcpy(x.name, "Premio 4");
        x.qtd = 4;
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n");

        x.id = 5;
        strcpy(x.name, "Premio 5");
        x.qtd = 5;
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n");
   
        
    }
    

    do{ 
        op = menu();
        switch(op){
            case 1:
                if(!flag2){
                    x = set();      
                    if(insert(&l1, x)) printf("# SUCCESS!\n");
                    else printf("[!] - ERRO!\n");
                }
                break;
            case 2:
                printf("# MOSTRAR TODOS\n");
                showAll(l1);
                break;
            case 3:
                printf("# GIRAR A ROLETA\n");
                raffle (&l1, &flag);
                flag2 = 1; 
                break;

            default:
                break;
        }
    }while(op != 0);

    return 0;
}

int menu(){
    int op;
    printf("[0] - Exit\n[1] - Inserir\n[2] - Todos\n[3] - Sortear\nOPÇÃO: ");
    scanf("%d", &op);
    return op;
}

tdado set(){
    tdado x;
    printf("ID: ");
    setbuf(stdin, NULL);
    scanf("%d", &x.id);
    printf("PREMIO: ");
    setbuf(stdin, NULL);
    scanf( "%[^\n]", x.name);   
    setbuf(stdin, NULL);
    printf("QUANTIDADE: ");
    setbuf(stdin, NULL);
    scanf("%d", &x.qtd);
    return x;
}

void init(List *l){
    l->s = l->e = NULL;
    l->tam = 0;
}

int insert(List *l, tdado x){
    tlist *aux = l->s, *new = (tlist *)malloc(sizeof(tlist));
    int result = 0;

    if(new != NULL){
        new->prev = NULL;
        new->next = NULL;
        new->x = x;

        if(aux == NULL){
            l->s = new;
            l->s->next = l->s;
            l->s->prev = l->s;
            l->e = l->s;
        }else{
            if(x.id < l->s->x.id){
                new->prev = l->e; // xxx
                new->next = l->s; // xx
                l->s = new;     
                l->e->next = l->s;
            }else if(x.id > l->e->x.id){
                new->prev = l->e; // xx
                new->next = l->s; // xx
                l->e = new;
                l->e->prev->next = l->e;
                l->s->prev = l->e;
            }else{
                while(x.id > aux->x.id) aux =aux->next;

                new->prev = aux->prev;
                aux->prev->next = new;
                new->next = aux;
                new->next->prev = new; 
            }
        }
        result = 1;
    }
    return result;
}

int delete(List *l, tdado x){
    tlist *aux = l->s;
    int result = 1;

    if(aux != NULL){
        if(l->s->x.id == x.id){
            if(l->s->next == l->s){
                l->s = l->e =NULL;
            }else{
                l->s = l->s->next;
                l->s->prev = l->e;
                l->e->next = l->s;
            }
        }else if(l->e->x.id == x.id){
            l->e->prev->next = l->s;
            l->e = l->e->prev;
            l->e->next = l->s;
        }else{

            while(aux != l->s && aux->x.id != x.id) aux = aux->next;

            if(aux->x.id == x.id){
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }            
        }
    }    
    return result;
}

void showAll(List l){
    tlist *aux = l.s;

    if(l.s != NULL){
        do{
            showOne(aux->x);
            aux = aux->next;
        }while(aux != l.s);
    }
    printf("\n");
}

void showOne(tdado x){
    printf("#############\n");
    printf("ID = %d\n", x.id);
    printf("PREMIO = %s\n", x.name);
    printf("QTD = %d\n", x.qtd);
}

void raffle (List *l, int *f){
    tlist *aux = NULL,*sAux = NULL, *eAux = NULL; 
    int numRandom, count=0;

    srand((unsigned)time(NULL));
    numRandom = 1 + rand() % 100;

    printf("# RAND = %d | FLAG = %d | COUNT = %d\n", numRandom, *f, count);

    sAux = aux = l->s;

    if(sAux != NULL){
        do{
            printf("ID = %d | COUNT = %d\n", sAux->x.id, count);            
            
            l->s = sAux; // andar com o inicio :)
            l->e = sAux->prev; // andar com o fim :)    

            sAux = *f ? sAux->prev : sAux->next ; // TERMAIO PARA VERRICAR SENTIDO QUE SERÁ PERCORRIDO 
            
            count++;
        }while(count < numRandom && sAux != eAux);

        aux = *f ? sAux->next: sAux->prev; 
        // aparti do valor da flag, é atribuido a mesma o tlista para a mesma

        if(aux != NULL){
            printf("# VOCÊ GANHOU O PRÊMIO: %s\n", aux->x.name);
            aux->x.qtd--;
        }

        if(aux->x.qtd == 0){
            if(delete(l, aux->x)) printf("# PRÊMIO REMOVIDO!\n");
            else printf("[!] - ERRO AO REMOVER!\n");
        }
        printf("\n");
    
        *f = *f ? 0 : 1; // ternario para mudar estado da flag
    }
}