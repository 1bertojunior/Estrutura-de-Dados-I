#include <stdio.h>
#include <stdlib.h>

typedef int tdado;

typedef struct tlist{
    tdado x;
    struct tlist *next; 
    
} tlist;

typedef struct{
    tlist *s, *e;
    int tam;
} List;

int menu();
tdado set();
void init(List *l);
int insert(List *l, tdado x);
void showOne(tdado x);
void showAll(List l);


int delete(List *l, tdado x){
    tlist *aux;
    int result = 0;

    aux = l->s;

    if(aux != NULL){
        do{
            if(aux->x == x){
                
                    //printf("# ACHOU\n");
                if(l->s == l->e) l->s = l->e = NULL;
                else if(aux == l->s){
                    l->s = aux->next;
                    l->e->next = l->s;
                }else{
                    if(aux->next == l->e){
                        aux->next = aux->next->next;
                        l->e = aux;
                    }else{
                        aux->next = aux->next->next;
                    }
                }


                //result = 1;
            }

            aux = aux->next;

        }while(aux != l->s && result != 1);
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
        new->x = x;
        new->next = NULL;

        if(aux == NULL){
            l->s = l->e = new;
            new->next = l->s;
        }else{
            if(x < l->s->x){
                new->next = l->s;
                l->s = l->e->next = new;
            }else if(x > l->e->x){
                l->e->next = new;
                new->next = l->s;
                l->e = new;
            }else{
                while(aux->next != l->s && aux->next->x < x) aux = aux->next; 
                new->next = aux->next;
                aux->next = new;
            }
        }
        l->tam++;
        result = 1;
    }

    return result;
}

void showAll(List l){
    tlist *aux = l.s;

    if(aux != NULL){
        do{
            printf("%d ", aux->x);
            aux = aux->next;
        }while(aux != l.s);
    }
    
    printf("\n");
}

void showOne(tdado x){
    printf("X: %d ", x);
}




















