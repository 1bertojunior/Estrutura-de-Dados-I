#include <stdio.h>
#include <stdlib.h>

typedef int tdado;

typedef struct tlist{
    tdado x;
    struct tlist *prev, *next; 
    
} tlist;

typedef struct{
    tlist *s, *e;
    int tam;
} List;

void init(List *l);
int insert(List *l, tdado x);

int delete(List *l, tdado x){
    tlist *aux;
    int result = 0;

    aux = l->s;

    while(aux != NULL && result != 1){
        if(x == aux->x){
            if(aux->prev == NULL){
                aux->next->prev = NULL;
                l->s = aux->next;
                free(aux);
            }else if(aux->next == NULL){
                aux->prev->next = NULL;
                l->e = aux->prev;
                free(aux);
            }else{
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                
            }
            free(aux);
            result = 1;
        }
        aux = aux->next; 
    }
    

    return result;
}

void show(List *l);
void showReserve(List *l);
int menu();
tdado set();

int getQtdOfNeighbors(List *l, tdado x){
    tlist *aux = l->s;
    int result = 0;

    while(aux != NULL){
        if(x == aux->x){
            if(aux->prev != NULL) result++;
            if(aux->next != NULL) result++;
        }
        aux = aux->next;
    }

    return result;
}

int productOfNeighboring(List *l, tdado x){
    int result = 0, qtdNeighboring = 0;

    qtdNeighboring = getQtdOfNeighbors(l,x) ;

    tlist *aux = l->s;

    while(aux != NULL){
        if(x == aux->x) {
            if(qtdNeighboring == 2) result = aux->prev->x * aux->next->x;
            else if(qtdNeighboring == 1){
                if(aux->prev != NULL) result = aux->prev->x;
                else if(aux->next != NULL) result = aux->next->x;
            }
        }
        aux = aux->next;
    }

    return result;
}


int main(){
    
    List l1;
    tdado x;
    int op, aux;

    init(&l1);

    do{
        op = menu();

        switch(op){
        case 1:
            x = set();      
            if(insert(&l1, x)) printf("# SUCCESS!\n");
            else printf("[!] - ERRO!\n");
            break;
        case 2:
            printf("# REMOVER\nX: ");
            scanf("%d", &x);
            aux = delete(&l1, x);
            if(aux) printf("# SUCCESS!\n");
            else printf("[!] - ERRO!\n");
            break;
        case 3:
            printf("# LISTA\n");
            show(&l1);
            break;

        case 4:
            printf("# LISTA INVERSA\n");
            showReserve(&l1);
            break;
        case 5:
            printf("# QUANTIDADE DE VIZINHOS\nX: ");
            scanf("%d", &x);

            aux = getQtdOfNeighbors(&l1, x);

            printf("# RESULT: %d\n", aux);
            break;

        case 6:
            printf("# PRODUTO DOS VIZINHOS\nX: ");
            scanf("%d", &x);

            aux = productOfNeighboring(&l1, x);

            printf("# RESULT: %d\n", aux);
            break;

        default:
            break;
        }
    

    }while(op != 0);

    return 0;
}

//FUNCTIONS
int menu(){
    int op;
    printf("[0] - Exit\n[1] - Inserir\n[2] - Mostrar\n[3] - Invertida\n[4] - Vizinhos\n[5] - Produto dos vizinhos\n\nOPÇÃO: ");
    scanf("%d", &op);
    return op;
}

tdado set(){
    tdado x;
    printf("X: ");
    setbuf(stdin, NULL);
    scanf("%d", &x);  
    setbuf(stdin, NULL);
    return x;
}

void init(List *l){
    l->s = l->e = NULL;
    l->tam = 0;
}

int insert(List *l, tdado x){
    tlist *new, *aux;
    
	new = (tlist *) malloc(sizeof(tlist));
    if(new == NULL) return 0;
    new->x = x;
    new->prev = new->next = NULL;

    aux = l->s;

    if(aux == NULL) l->s = l->e = new;
	else{
        if(x < l->s->x){
            new->next = l->s;
            l->s->prev = new;
            l->s = new;

        } else if(x > l->e->x){
            l->e->next = new;
            new->prev = l->e;
            l->e = new;
        }else{
            while(aux != NULL && aux->x < x) aux = aux->next;            
            new->prev = aux->prev;
            aux->prev->next = new;
            new->next = aux;
            new->next->prev = new; 
        }
    }
    
    l->tam++;
    return 1;
}

void show(List *l){
    tlist *aux = l->s;

    while(aux != NULL){
        printf("%d ", aux->x);
        aux = aux->next;
    }
    printf("\n");

}

void showReserve(List *l){
    tlist *aux = l->e;

    while(aux != NULL){
        printf("%d ", aux->x);
        aux = aux->prev;
    }
    printf("\n");
}