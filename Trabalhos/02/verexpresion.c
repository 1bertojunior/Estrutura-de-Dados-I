#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100
//aux = strtok(NULL, " ");

int verifica_parenteses(char str[MAX]){
    int i, contpa = 0;
    for(i = 0; str[i]; i++){
        if(str[i] == '(')
            contpa++;
        if(str[i] == ')')
            contpa--;
    }
    if(contpa == 0)
        return 1;
    return 0;
}

int is_num(char mini_str[MAX]){

    return strtol(mini_str, NULL, 10) != 0;
    if(strtol(mini_str, NULL, 10) != 0)
        return 1;
    return 0;
}

int is_operator(char *mini_str){
    if(*mini_str == '+' || *mini_str == '-' || *mini_str == '*' || *mini_str == '/')
        return 1;
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
    if(is_operator(aux) == 0)
        r++;
    invert_str(copia_strb);
    aux = strtok(copia_strb, " ");
    // Verifica Fim da STRING -> Deve ser diferente de um operador
    if(is_operator(aux) == 0)
        r++;
    if(r != 0 && r % 2 == 0)
        return 1;
    return 0;
}

void clsbuf(void){
    char a;
    while((a = getchar()) != '\n' && a != EOF);
}

int verifica_exp(char str[MAX]){
    char copia_str[MAX];
    char *aux;

    strcpy(copia_str, str);
    
    if((verifica_inicio_fim(copia_str) == 1) && (verifica_parenteses(copia_str) == 1)){
        aux = strtok(copia_str, " ");
        while(aux != NULL){
            //printf("%s\n", aux);

            printf("COND = %d\n", is_num(aux) == 1 || *aux == '(' || *aux == ')');
           
            if(is_num(aux) == 1 || *aux == '(' || *aux == ')'){
                
                aux = strtok(NULL, " ");
                
                if(aux != NULL){
                    printf("%c ? %d\n", *aux, is_operator(aux));
                    if(!is_operator(aux) || !is_num(aux))
                        return -3;     
                }
                
            }else{
                return -2;
            }
    
            aux = strtok(NULL, " ");
           
        }
    }else{
        return -1;
    }

    return 1;
}

int main(){
    char exp[MAX] = "( 1 + 2 )"; // ( 1 + 2 * ( 3 / 1 ) * 8 )
    printf("%s\n", exp);
    //char *aexp;

    //printf("Digite uma expressao valida: ");
    //scanf("%[^\n]", exp);
    //clsbuf();

    printf("A expressao esta correta?: %d", verifica_exp(exp));
    
    return 0;
}

/*
char *aux_str, *b_str;
    int num;
    aux_str = strtok(str, " "); //Quebra a string ao encontrar o carectere do segundo parametro -> (" ")

    aux_str = strtok(str, " ");
    if(aux_str[0] == ")" || aux_str[0] == "+" || aux_str == "-" || aux_str == "*" || aux_str == "/"){
        return 0;
    }else{
        num = strtol(aux_str, NULL, 10);
    }

    while(aux_str){
        
        
}

// testes:
printf("Parenteses OK? : %d\n", verifica_parenteses(exp));
aexp = strtok(exp, " ");
printf("Eh um operador? : %d\n", is_operator(aexp));
aexp = strtok(exp, " ");
printf("Tem numero no inicio? : %d\n", is_num(aexp));
printf("Inicio e fim tudo certo? %d", verifica_inicio_fim(exp));


if(is_num(aux) == 1 || aux == "(" || aux == ")"){
    aux = strtok(NULL, " ");
    if(is_operator(aux) == 0)
        return 0;                    
}else{
    return 0;
}
aux = strtok(NULL, " ");

*/