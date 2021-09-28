#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Tipo de dado usado para lista.
typedef struct{
    int cpf, age;
    char name[21];
} tdado;
// Tipo de lista (No) usado para a lista.
// Contém o dado e um ponteiro para o anterior e próximo.
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
int delete(List *l, tdado *x);
void showAll(List *l);
void showOne(tdado x);

void newListWithLaterPeople(List *l1,List *l2, tdado x){
    tlist *aux = l1->s;
    tdado xAux;
    int result = 0;

    while(aux != NULL && result != 1){
        if(aux->x.cpf == x.cpf) result = 1;
        
        if(result){
            l2->s = aux->next;
            l2->e = l1->e;
            l1->e = aux;
            aux->next = NULL;
        }

        aux = aux->next;
    }
}

void smallerPeopleOfAge(List *l1, List *l2, tdado x){
    tlist *aux = l1->s;

    while(aux != NULL){
        if(aux->x.age < x.age) insert(l2,aux->x);
        aux = aux->next;
    }
    
}

// printf("%d < %d = %d\n", aux->x.age, x.age, aux->x.age < x.age);
            // showOne(aux->x);


int getQtdOfNeighbors(List *l, tdado x){
    tlist *aux = l->s;
    int result = 0;

    while(aux != NULL){
        if(x.cpf == aux->x.cpf){
            if(aux->prev != NULL) result++;
            if(aux->next != NULL) result++;
        }
        aux = aux->next;
    }

    return result;
}

int ageOfNeighborMoreOlder(List *l, tdado *x){
    tlist *aux = l->s;
    tdado xAux;
    int result = 0;

    if(l->s == l->e) result = -1;
    else{
        printf("ENTROU\n");
        if(l->s->x.cpf == x->cpf) xAux = l->s->next->x;
        else if(l->e->x.cpf == x->cpf) xAux = l->e->prev->x;
        else{
            while(aux->x.cpf != x->cpf) aux = aux->next;
            if(aux->prev->x.age < aux->next->x.age) xAux = aux->next->x;
            else xAux = aux->prev->x;
        }
    }

    if(xAux.age > x->age) result = 1;
    *x = xAux;

    return result;  
}



int main(){
    
    List l1,l2,l3;
    tdado x;
    int op, aux;

    init(&l1);
    init(&l2);
    init(&l3);

    if(1){
        x.cpf = x.age = 1;
        strcpy(x.name,"1");
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n"); 
        x.cpf = x.age = 2;
        strcpy(x.name,"2");
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n"); 
        x.cpf = x.age = 3;
        strcpy(x.name,"3");
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n"); 
        x.cpf = x.age = 4;
        strcpy(x.name,"4");
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n"); 
        x.cpf = x.age = 5;
        strcpy(x.name,"5");
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n"); 
        x.cpf = x.age = 6;
        strcpy(x.name,"6");
        if(insert(&l1, x)) printf("# SUCCESS!\n");
        else printf("[!] - ERRO!\n"); 
    }

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
            scanf("%d", &x.cpf);
            aux = delete(&l1, &x);
            if(aux) {
                printf("# SUCCESS!\n");
                showOne(x);
            }
            else printf("[!] - ERRO!\n");
            break;
        case 3:
            printf("# LISTA\n");
            showAll(&l1);
            break;
        case 4:
            printf("# NOVA LISTA COM PESSOAS POSTERIORES\nX: ");
            scanf("%d", &x.cpf);
            newListWithLaterPeople(&l1, &l2,x);
            printf("\n# NOVA LISTA\n");
            showAll(&l2);
            break;

        case 5:
            printf("# PESSOAS COM IDADE MENOR\nX: ");
            scanf("%d", &x.age);
            smallerPeopleOfAge(&l1,&l3, x);
            
            printf("\n# NOVA LISTA PESSOAS COM IDADE MENOR\n");
            showAll(&l3);

            break;
        case 6:
            printf("# IDADE DO VIZINHO MAIS VELHO\nX: ");
            scanf("%d", &x.cpf);
            aux = ageOfNeighborMoreOlder(&l1,&x);
            showOne(x);
            printf("É MAIS VELHO? %s\n", aux == 1 ? "SIM" : "NÃO");
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
    printf("[0] - Exit\n[1] - Inserir\n[2] - Remover\n[3] - Mostrar\n[4] - Posteriores\n[5] - Idade menor\nOPÇÃO: ");
    scanf("%d", &op);
    return op;
}

tdado set(){
    tdado x;
    printf("CPF: ");
    setbuf(stdin, NULL);
    scanf("%d", &x.cpf);  
    setbuf(stdin, NULL);
    printf("NOME: ");
    setbuf(stdin, NULL);
    scanf(" %[^\n]", x.name);  
    setbuf(stdin, NULL);
    printf("IDADE: ");
    setbuf(stdin, NULL);
    scanf("%d", &x.age);  
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
        if(x.cpf < l->s->x.cpf){
            new->next = l->s;
            l->s->prev = new;
            l->s = new;

        } else if(x.cpf > l->e->x.cpf){
            l->e->next = new;
            new->prev = l->e;
            l->e = new;
        }else{
            while(aux != NULL && aux->x.cpf < x.cpf) aux = aux->next;            
            new->prev = aux->prev;
            aux->prev->next = new;
            new->next = aux;
            new->next->prev = new; 
        }
    }
    
    l->tam++;
    return 1;
}

int delete(List *l, tdado *x){
    tlist *aux;
    int result = 0;

    aux = l->s;

    while(aux != NULL && result != 1){
        if(x->cpf == aux->x.cpf){
            if(aux->prev == NULL){
                printf("INICIO\n");
                if(aux->next == NULL) l->s = l->e = NULL;
                else{
                    aux->next->prev = NULL;
                    l->s = aux->next;
                }
            }else if(aux->next == NULL){
                aux->prev->next = NULL;
                l->e = aux->prev;
                *x = aux->x;
            }else{
                aux->prev->next = aux->next;
                aux->next->prev = aux->prev;
                *x = aux->x;
            }
            free(aux);
            result = 1;
        }
        aux = aux->next; 
    }
    
    return result;
}

void showAll(List *l){
    tlist *aux = l->s;

    while(aux != NULL){
        showOne(aux->x);
        aux = aux->next;
    }
}

void showOne(tdado x){
    printf("###############\n");
    printf("CPF: ");
    printf("%d\n", x.cpf);
    printf("NOME: ");
    printf("%s\n", x.name);
    printf("IDADE: ");
    printf("%d\n", x.age);
}
