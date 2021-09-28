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

int verifica_parenteses(char str[MAX]);
int is_num(char mini_str);
int is_operator(char mini_str);
void invert_str(char str[MAX]);
int verifica_inicio_fim(char str[MAX]);
int checkExp(char str[MAX]);

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

            if(checkExp(exp) != 0){
                init(&p1);	

                infixToPostfix(&p1,exp);
                
                printf("# PÓS-FIXA: ");
                showReverse(&p1);
                printf("\n\n");
            }else printf("[!] Expresão inválida!\n");
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

int verifica_parenteses(char str[MAX]){
    int i, count = 0;

    for(i = 0; str[i]; i++){
        if(str[i] == '(')  count++;
        if(str[i] == ')') count--;
    }

    return count == 0;
}

int is_num(char mini_str){
    return (mini_str >= '0' && mini_str <= '9');
}

int is_operator(char mini_str){
    if(mini_str == '+' || mini_str == '-' || mini_str == '*' || mini_str == '/') return 1;
    return 0;
}

void invert_str(char str[MAX]){
    char c;
    int i, tam = strlen(str);

    for(i = 0; i < tam/2; i++){
        c = str[i];
        str[i] = str[tam - 1 - i];
        str[tam - 1 - i] = c;
    }
}

int verifica_inicio_fim(char str[MAX]){
    int r = 0;
    char *aux, copia_str[MAX], copia_strb[MAX];

    strcpy(copia_str, str);
    strcpy(copia_strb, str);
    // Verifica Inicio da STRING -> Deve ser diferente de um operador
    aux = strtok(copia_str, " ");
    if(is_operator(aux) == 0) r++;
    invert_str(copia_strb);
    aux = strtok(copia_strb, " ");
    // Verifica Fim da STRING -> Deve ser diferente de um operador
    if(is_operator(aux) == 0)  r++;
    if(r != 0 && r % 2 == 0) return 1;
    return 0;
}

int checkExp(char str[MAX]){
    int i = 0, op = 0, r = 0;
    char *aux;

    if((verifica_inicio_fim(str) == 1) && (verifica_parenteses(str) == 1)){
        while(str[i] != '\0'){
            if(is_operator(str[i]) == 1){
                op++;
                if((is_num(str[i+2]) == 1 && is_num(str[i-2]) == 1) || str[i+2] == '(' || str[i-2] == ')'){
                    r++;
                }
            }
            if(str[i] == ' ' && is_num(str[i-1]) == 1 && is_num(str[i+1]) == 1){
                r--;
            }
            i++;
        }
    }

    return op != 0 && r == op;
}