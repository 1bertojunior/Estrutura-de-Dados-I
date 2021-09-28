// Programa C para converter expressão infixa em postfix
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Tipo de pilha
struct Stack{
	int top;
	unsigned capacity;
	int* array;
};

// Operações de pilha
struct Stack* createStack( unsigned capacity ){
	struct Stack* stack = (struct Stack*) malloc(sizeof(struct Stack));

	if (!stack) return NULL;

	stack->top = -1;
	stack->capacity = capacity;

	stack->array = (int*) malloc(stack->capacity * sizeof(int));

	return stack;
}
int isEmpty(struct Stack* stack){
	return stack->top == -1 ;
}
char peek(struct Stack* stack){
	return stack->array[stack->top];
}
char pop(struct Stack* stack){
	if (!isEmpty(stack))
		return stack->array[stack->top--] ;
	return '$';
}
void push(struct Stack* stack, char op){
	stack->array[++stack->top] = op;
}

// Uma função de utilidade para verificar se
// o caractere fornecido é operando
int isOperand(char ch){
	return (ch >= '0' && ch <= '9'); 
}

// Uma função de utilidade para retornar precedência de um determinado operador
// Maior valor retornado significa  maior precedência
int Prec(char ch){
	switch (ch){
        case '+':
        case '-':
            return 1;

        case '*':
        case '/':
            return 2;

        case '^':
            return 3;
	}
	return -1;
}


// A função principal que
// converte dada expressão infixa
// para corrigir a expressão.
int infixToPostfix(char* exp){
	int i, k;

	// Crie uma pilha de capacidade
    // igual ao tamanho da expressão
	struct Stack* stack = createStack(strlen(exp));
	if(!stack) return -1; // Veja se a pilha foi criada com sucesso

	for (i = 0, k = -1; exp[i]; ++i){
		
		// Se o caractere escaneado for
        // um operando, adiciona-o à saída.
		if (isOperand(exp[i])) exp[++k] = exp[i];
		
		// Se o caractere escaneado for um
        // ‘(‘, empurre-o para a pilha.
		else if (exp[i] == '(') push(stack, exp[i]);
		
		// Se o caractere escaneado for um ‘)’,
        // pop e saída da pilha
        // até que um ‘(‘ seja encontrado.
		else if (exp[i] == ')'){
			while (!isEmpty(stack) && peek(stack) != '(') exp[++k] = pop(stack);
			if (!isEmpty(stack) && peek(stack) != '(') return -1; // expressão inválida		
			else pop(stack);
		}else{ // um operador é encontrado
			while (!isEmpty(stack) &&
				Prec(exp[i]) <= Prec(peek(stack)))
				exp[++k] = pop(stack);
			push(stack, exp[i]);
		}

	}

	// tira todos os operadores da pilha
	while (!isEmpty(stack)) exp[++k] = pop(stack );

	exp[++k] = '\0';
	printf( "%s", exp );
}

// Programa de driver para testar as funções acima
int main(){
	char exp[] = "1+2*100"; //10 + ( 2 * 100 )
	infixToPostfix(exp);
	return 0;
}
