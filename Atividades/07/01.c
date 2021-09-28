#include <stdio.h>
#include <stdlib.h>

typedef int tdado;

typedef struct tlist{
    tdado x;
    struct tlist *next; 
} tlist;

typedef struct{
    tlist *s;
    int tam;
} List;

int menu();
tdado set();
void init(List *l);
void insert(List *l, tdado x);
void show(List *l);
void showRecursive(tlist *tp);
int sumEveNumbers1(List *l);
int sumEveNumbers2(tlist *tp);
int checkMulti3(int n);
int productOfMultiplesOf3LessThan60_1(List *l);
int productOfMultiplesOf3LessThan60_2(tlist *tp);
int checkProduct(int n);
int toRemove(List *l, tdado x);
tlist *search(List *l, tdado x);

int main(){
    
    List l1;
    tlist *aux;
    tdado x;
    int op, xr=0;

    init(&l1);

    do{
        op = menu();

        switch(op){
        case 1:
            x = set();      
            insert(&l1, x);
            break;
        case 2:
            show(&l1);
            break;
        case 3:
            showRecursive(l1.s);
            break;
        case 4:
            xr = sumEveNumbers1(&l1);
            printf("# Soma numeros pares: %d\n", xr);
            break;
        case 5:
            xr = sumEveNumbers2(l1.s);
            printf("# Soma numeros pares: %d\n", xr);
            break;
        case 6:
            xr = productOfMultiplesOf3LessThan60_1(&l1);
            printf("# Produto dos multiplos de 3 menores que 60 = %d\n", checkProduct(xr));
            break;
        case 7:
            xr = productOfMultiplesOf3LessThan60_2(l1.s);
            printf("# Produto dos multiplos de 3 menores que 60 = %d\n", checkProduct(xr));
            break;
        case 8:
            x = set();
            toRemove(&l1, x);
            break;
        case 9:
            x = set();
            aux = search(&l1, x);
            if(aux != NULL) {
                toRemove(&l1, x);
                x = set();                
                insert(&l1, x);                   
            } else printf("[!] - Não encontrou!\n");
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
    printf("[0] - Exit\n[1] - Inserir\n[2] - Mostrar\n[3] - Mostar invertido\n[4] - Soma pares interativa\n[5] - Soma pares recursiva\n[6] - Produto dos múltiplos de 3 menores do que 60 interativo\n[7] - Produto dos múltiplos de 3 menores do que 60 recursivo\n[8] - Remover\n[9] - Alterar\nOPÇÃO: ");
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
    l->s = NULL;
    l->tam = 0;
}

void insert(List *l, tdado x){
    
    tlist *s, *new, *prev;
    
	new = (tlist *) malloc(sizeof(tlist));
    s = l->s;
	prev = NULL;

    new->x = x;
	new->next = NULL;

	if(s == NULL){
		l->s = new;
        new->next = NULL;
	}else{
		while(s != NULL && s->x < x){
			prev = s;
			s = s->next;
		}
		new->next = s;

		if(prev == NULL) l->s = new;
		else prev->next = new;
	}
  l->tam++;
    
}

void show(List *l){
    tlist *s = l->s;

    while(s != NULL){
        printf("%d\n", s->x);
        s = s->next;
    }

}

void showRecursive(tlist *tp){
    if(tp != NULL){
        showRecursive(tp->next);
        printf("%d\n", tp->x);
    }
}

/*

void show(pilha *p){
    pilha *aux;
    if(p->topo != -1){
        aux->topo--;
        show(aux);
        printf("%c ", p->Pilha[p.topo]);
    }
}
*/

int sumEveNumbers1(List *l){
    tlist *s = l->s;
    int r = 0;
    
    while(s != NULL) {
        if(s->x %2 == 0) r += s->x;
        s = s->next;
    }

    return r;
}

int sumEveNumbers2(tlist *tp){
    if(tp != NULL) return sumEveNumbers2(tp->next) + (tp->x % 2 == 0? tp->x : 0);
}

int checkMulti3(int n){
    return n%3 == 0 ? 1 : 0;
}

int productOfMultiplesOf3LessThan60_1(List *l){
    int r=1;
    tlist *s = l->s;

    while(s != NULL){
        if(checkMulti3(s->x) && s->x <=60) r *= s->x;
        s = s->next;
    }

     return r;
}
int productOfMultiplesOf3LessThan60_2(tlist *tp){
    int r = 1;
    if(tp != NULL) r = (checkMulti3(tp->x) ? tp->x : 1) * productOfMultiplesOf3LessThan60_2(tp->next);
    return r;
} 

int checkProduct(int n){
    return n == 1 ? 0 : n;
}

int toRemove(List *l, tdado x){
    tlist *ptr, *prev;
    int r =0;

    if(l->s != NULL){
        ptr = prev = l->s;

        while(ptr != NULL){
            if(ptr->x == x){
                if(ptr == l->s){
                    l->s = l->s->next;
                    free(ptr);
                }else{
                    prev->next = ptr->next;
                    free(ptr);
                }

                r = 1;
            }else{
                prev = ptr;
                ptr = ptr->next;
            }
        }
        
    }
    
  return r;
}

tlist *search(List *l, tdado x){
    tlist *s = l->s;
    tlist *r = NULL;

    while(s != NULL) {
        if(s->x == x) r = s;
        s = s->next;
    }

    return r;
}






