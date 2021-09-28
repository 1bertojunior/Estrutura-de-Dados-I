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

int menu();
tdado set();
void init(List *l);

int insert(List *l, tdado x);
void showAll(List l);
void showOne(tdado x);

int delete(List *l, tdado x){
    tlist *aux = l->s;
    int result = 1;

    if(aux != NULL){
        if(l->s->x == x){
            if(l->s->next == l->s){
                l->s = l->e =NULL;
            }else{
                l->s = l->s->next;
                l->s->prev = l->e;
                l->e->next = l->s;
            }
        }else if(l->e->x == x){
            l->e->prev->next = l->s;
            l->e = l->e->prev;
            l->e->next = l->s;
        }else{

            while(aux != l->s && aux->x != x){
                aux = aux->next;
            }

            if(aux->x == x){
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
            }

            // while(aux->next != l->s && aux->x != x && result != 0){
            //     aux = aux->next; 
            //     if(x < aux->x) result = 0;
            // } 
            // if(result){
            //     aux->prev->next = aux->next;
            //     aux->next->prev = aux->prev;
            // }
            
        }
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
                if(delete(&l1, x)) printf("# SUCCESS!\n");
                else printf("[!] - ERRO!\n");
                break;
            case 3:
                printf("# MOSTRAR TODOS\n");
                showAll(l1);
                break;

            default:
                break;
        }
    }while(op != 0);



    return 0;
}

int menu(){
    int op;
    printf("[0] - Exit\n[1] - Inserir\n[2] - Remover\n[3] - Todos\nOPÇÃO: ");
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
            if(x < l->s->x){
                new->prev = l->e; // xxx
                new->next = l->s; // xx
                l->s = new;     
                l->e->next = l->s;
            }else if(x > l->e->x){
                new->prev = l->e; // xx
                new->next = l->s; // xx
                l->e = new;
                l->e->prev->next = l->e;
                l->s->prev = l->e;
            }else{
                while(x > aux->x) aux =aux->next;

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
void showAll(List l){
    tlist *aux = l.s;

    if(l.s != NULL){
        do{
            printf("%d ", aux->x);
            aux = aux->next;
        }while(aux != l.s);
    }
    printf("\n");

}



