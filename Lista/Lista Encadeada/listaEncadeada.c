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

void init(List *l);
void insert(List *l, tdado x);
void insert1(List *l, tdado x);
void insert2(List *l, tdado x);

void show(List *l);
int menu();
tdado set();

int main(){
    
    List l1;
    tdado x;
    int op;

    init(&l1);

    do{
        op = menu();

        switch(op){
        case 1:
            x = set();      
           // insert1(&l1, x);
            break;
        case 2:
            x = set();      
            //insert2(&l1, x);
            break;
        case 3:
            x = set();      
            insert(&l1, x);
            break;
        case 4:
            show(&l1);
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
    printf("[0] - Exit\n[1] - Inserir inicio\n[2] - Inserir fim\n[3] - Inserir ordenado\n[4] - Mostrar\nOPÇÃO: ");
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