#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define TAM 5


typedef char tdado[TAM];

typedef struct no{
    tdado e;
    struct no *next;    
} tstack;

typedef struct{
    tstack *top;
    int qtd;
} Stack;

void init(Stack *p);
int push(Stack *p, tdado x);
void pop(Stack *p, tdado *x);
void show(Stack p);
int isEmpty(Stack *p);
int isParenthe(char str[]);
int isOperand(char str[]);
int isOperator(char str[]);
tdado *getTop(Stack *p);
void showReverse(Stack *p);
void infixToPostfix(Stack *p1, char exp[]);

int main(){
    Stack p1;
    tdado x, exp; // = "10 + ( 2 * 100 ) " 100+((1*2)/2) | 100 + ( ( 1 * 2 ) / 2 )
    int op = 0;
	 
    do{
        printf("[0] - Sair\n[1] - Transformar expressão\nOPÇÃO: ");
        scanf("%d", &op);
        
        if(op){
            printf("# INFIXA: ", exp);
            scanf(" %[^\n]", exp);
    
            init(&p1);	

            infixToPostfix(&p1,exp);
            
            printf("# PÓS-FIXA: ");
            showReverse(&p1);
            printf("\n\n");
        }

    }while(op != 0);

	return 0;
}

void init(Stack *p){
    p->top = NULL;
    p->qtd = 0;
}

int push(Stack *p, tdado x){
    tstack *new = (tstack *)malloc(sizeof(tstack)); // alocando memória

    if(new == NULL) return 0; // erro ao alocar memória

	strcpy(new->e, x);
    new->next = p->top;
    p->top = new;
    p->qtd++;

    return 1;
}

void pop(Stack *p, tdado *x){
    tstack *a = p->top;

    if(a != NULL){
        p->top = a->next;
        a->next = NULL;
        //x = a->e;
		strcpy(*x, a->e);
        free(a);
    }

}

void show(Stack p){
    while(p.top != NULL){
        printf("%s ", p.top->e);
        p.top = p.top->next;
    }

}

int isEmpty(Stack *p){
    return p->top == NULL;
}

int isParenthe(char str[]){
    int c = str[0];
    if(c == '(') return 1;
    else if(c == ')') return 2;
    
    return 0;

}

int isOperand(char str[]){
    if(str[0] == '0') return 1;
    return atoi(str) != 0;
}

int isOperator(char str[]){
    int c = str[0];
    switch(c){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;
	}
	return -1;
}   

tdado *getTop(Stack *p){
    return p->top->e;
}

void showReverse(Stack *p){
    Stack pAux;
    tdado x;

    init(&pAux);

    while (!isEmpty(p)){
        pop(p, &x);
        push(&pAux, x);
    }

    show(pAux);
}

/*
Stack p1;
    tdado x, exp;
    int op = 0;

    do{
        printf("[0] - Sair\n[1] - Transformar expressão\nOPÇÃO: ");
        scanf("%d", &op);

        if(op){
            printf("# INFIXA: ", exp);
            scanf(" %[^\n]", exp);
    
            init(&p1);	

            infixToPostfix(&p1,exp);
            
            printf("# PÓS-FIXA: ");
            show(p1);
            printf("\n\n");
        }

    }while(op != 0);

    return 0;
*/

void infixToPostfix(Stack *p1, char exp[]){
    Stack p2;
    tdado x;
    char *div;
    init(&p2);
    
    div = strtok(exp, " ");
	while(div != NULL){

        if(isOperand(div)) push(p1,div); //printf("%s ", div);
        else if(isParenthe(div) == 1) push(&p2, div);
        else if(isParenthe(div) == 2){
            while(!isEmpty(&p2) && isParenthe(getTop(&p2)) != 1 ){
                pop(&p2, &x);
                push(p1,x);
            }

            if(!isEmpty(&p2) && (isParenthe(getTop(&p2)) != 1) ) return -1;
            else pop(&p2, &x);
        }else{
            while( !isEmpty(&p1) && isOperator(div) <= isOperator(getTop(&p1)) ){
                pop(&p2, &x);
                push(p1, x);
            }
            push(&p2, div);
        }

		div = strtok(NULL, " ");
	}
    
	while (!isEmpty(&p2)) { // tira todos os operadores da pilha
        pop(&p2,x);
        push(p1,x);
    }
    
}