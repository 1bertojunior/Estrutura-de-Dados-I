#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

typedef char tdado[MAX];

typedef struct tlist{
    tdado x;
    struct tlist *next; 
} tlist;

typedef struct{
    tlist *s;
    int tam;
} List;

int menu();
void init(List *l);
void insert(List *l, tdado x);
void insert2(List *l, tdado x);
void show(List *l);
int isVowel(char c);
void newLists(List *l1, List *l2, List *l3, List *l4);
tlist *search(List *l, tdado x);
int getStrsneighboring(List *l, tlist *x, tdado *str1, tdado *str2);

int main(){
    
    List l1, l2,l3, l4;
    tlist *aux;
    tdado x, x2;
    int op, r;

    init(&l1);

    do{
        op = menu();

        switch (op){
        case 1:
            printf("STR: ");
            setbuf(stdin, NULL);
            scanf(" %[^\n]", x);
            setbuf(stdin, NULL);
            
            insert(&l1, x);
            break;
        case 2:
            printf("# ORIGINAL\n");
            show(&l1);
            break;
        case 3:
            init(&l2);
            init(&l3);
            init(&l4);

            newLists(&l1, &l2, &l3, &l4);
            printf("# INICIAM COM VOGAL\n");
            show(&l2);
            printf("# INICIAM COM CONSOANTE\n");
            show(&l3);
            printf("# ORDENADAS PELO O TAMANHO\n");
            show(&l4);
            break;
        case 4:
            printf("# STRS VIZINHAS DE\n");
            printf("STR: ");
            setbuf(stdin, NULL);
            scanf(" %[^\n]", x);
            setbuf(stdin, NULL);
            aux = search(&l1, x);

            if(aux != NULL) {
                r = getStrsneighboring(&l1, aux, &x, &x2);
                if(r==0) printf("Anterior = %s\n", x);
                else if(r == 1) printf("Proximo = %s\n", x2);
                else printf("Anterior = %s | Proximo %s\n", x, x2);
            }else printf("[!] - Não encontrou!\n");

            break;
        default:
            break;
        }

    }while(op != 0);

    return 0;
}


int menu(){
    int op;
    printf("[0] - Exit\n[1] - Inserir\n[2] - Mostrar\n[3] - Strs que iniciam com vogais e outra com consoantes\n[4] - Strings vizinhas\nOPÇÃO: ");
    scanf("%d", &op);
    return op;
}

void init(List *l){
    l->s = NULL;
    l->tam = 0;
}

void insert(List *l, tdado x){
    tlist *s, *new, *new2, *prev;

    new = (tlist *)malloc(sizeof(tlist));
    s = l->s;
    prev = NULL;

    strcpy(new->x,x);
    new->next = NULL;


    if(s == NULL){
        l->s = new;
        new->next = NULL;
    }else{
        while(s != NULL &&  strcmp(s->x, x) < 0){
            prev = s;
            s = s->next;
        }
        new->next = s;
        
        if(prev == NULL) l->s = new;
        else prev->next = new;
    }
    l->tam++;
}

void insert2(List *l, tdado x){
    tlist *s, *new, *new2, *prev;
    new = (tlist *)malloc(sizeof(tlist));
    s = l->s;
    prev = NULL;

    strcpy(new->x,x);
    new->next = NULL;

    if(s == NULL){
        l->s = new;
        new->next = NULL;
    }else{
        while(s != NULL && strlen(s->x) < strlen(x)){
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
        printf("%s\n", s->x);
        s = s->next;
    }
}

int isVowel(char c){
    c = tolower(c);
    return c == 'a' || c == 'e' | c == 'i' || c == 'o' || c == 'u'; 
}

void newLists(List *l1, List *l2, List *l3, List *l4){
    tlist *s = l1->s;

    while(s != NULL){
        if(isVowel(s->x[0])) insert(l2, s->x);
        else insert(l3, s->x);
        
        insert2(l4, s->x);

        s = s->next;
    }
}

tlist *search(List *l, tdado x){
    tlist *s = l->s;
    tlist *r = NULL;

    while(s != NULL) {
        if(strcmp(s->x, x) == 0) r = s;
        s = s->next;
    }

    return r;
}

int getStrsneighboring(List *l, tlist *x, tdado *str1, tdado *str2){
    tlist *s = l->s;
    tdado prev = {};
    
    while(s != NULL){
        if(s == x){
            if(strlen(prev) == 0) {
                strcpy(str2, s->next->x);
                return 1;
            }else if(s->next == NULL){
                strcpy(str1, prev);
                return 0;
            }else{
                strcpy(str1, prev);
                strcpy(str2, s->next->x);
                return 2;
            } 
        }
        strcpy(prev, s->x);
        s = s->next;
    }    

}
