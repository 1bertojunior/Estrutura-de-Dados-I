#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100
#define TAM 5

typedef char tdado[TAM];

typedef struct {
    tdado v[11];
    int top;
} Stack;

void init(Stack *p);
int isFull(int top);
int isEmpty(Stack *p);
int isParenthe(char str[]);
int isOperator(char str[]);
int isOperand(char str[]);
tdado *getTop(Stack *p);
void show(Stack p);
void showReverse(Stack *p);
void infixToPostfix(Stack *p1, char exp[]);

int main(){

    Stack p1;
    tdado x;
    char exp[MAX];
    int op;

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
    p->top = -1;
} 
int isEmpty(Stack *p){
    return p->top == -1;
}
int push(Stack *p, tdado e){
    if(p->top == MAX-1) return 0;
    
    p->top++;
    strcpy(p->v[p->top],e);

    return 1; 
}
void pop(Stack *p, char *e){
    if(p->top != -1){
        strcpy(e, p->v[p->top]);
        p->top--;
    }
    
}
int isParenthe(char str[]){
    int c = str[0];
    if(c == '(') return 1;
    else if(c == ')') return 2;
    
    return 0;

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
int isOperand(char str[]){
    return atoi(str) != 0;
}
tdado *getTop(Stack *p){
    return p->v[p->top];
}
void show(Stack p){
    while (p.top != -1){
        printf("%s ", p.v[p.top]);
        p.top--;
    }
    
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


