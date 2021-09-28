/*
    A função misterio1 trata de receber uma string e devolver todos os números (inteiros)  presentes na mesma
    Ela recebe quatro parâmetros, o primeiro é a string, na qual será verificada a existência de números,
    o segundo, é um inteiro contendo o tamanho da string, o terceiro é um inteiro que representa a valor que será
    multiplicado o número para ser realizado a soma para chegar nos digitos da string, e por último, o quarto parâmetro
    é um endereço de memória de uma variável que será atribuído ao conteúdo da mesma o resultado.
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void misterio1(char str[], int i, int uni, int *valor){
    int n;
    if(i >=0){
        if(isdigit(str[i])){
            n = str[i] - 48;
            *(valor) += (n * uni);
            misterio1(str,i -1, uni * 10, valor);
        }else misterio1(str,i -1, uni, valor);
    }
}
//algoritmo sem recursão
void misterio2(char str[], int i, int uni, int *valor){
    int n;
    for( ;i>=0; --i){
        if(isdigit(str[i])){
            n = str[i] - 48;
            *(valor) += (n * uni);
            uni *= 10;
        }
    }

}

int main(){

    int valor=0, valor2=0;
    char str[21];

    printf("str: ");
    scanf(" %[^\n]",  str);

    misterio1(str, strlen(str)-1, 1, &valor);
    misterio2(str, strlen(str)-1, 1, &valor2);

    printf("QTD NUM = %d\n", valor);
    printf("QTD NUM = %d\n", valor2);

    return 0;
}