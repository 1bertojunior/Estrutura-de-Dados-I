#include<stdio.h>
#include<stdlib.h>

void altera1(int **p, int *a){
    //printf("\n%d %d %d\n", **p, *p, p);
    **p = *a;
    //printf("\n%d %d %d\n", **p, *p, p);
    *a = *a +50;
}

void altera2(int **p, int *b){
    *p = b;
    *b = *b +300;
}
int main(){
    int x,y, *px, *py;
    x = 500;
    y = x + 200;
    px = &x;
    py = &y;
    printf("x = %d, End. x = %p, px = %p, End. px = %p, p = %d \n",x,&x, px,y);
    altera1(&px, &y);
    printf("x = %d, End. x = %p, px = %p, y = %d \n",x,&x, px,y);
    getchar();
    printf("y = %d, End. y = %p, py = %p, x = %d \n",y,&y, py,x);
    altera2(&py, &x);
    printf("y = %d, End. y = %p, py = %p, x = %d \n",y,&y, py,x);
    getchar();
    return(0);
}

/*

    A) X é a variável iniciada com o valor 500 e, PX é um ponteiro - variável que armazena o endereço de memória da variável X.
    B) PX é uma variável que armazena o endereço de memória da variável X e já PY armazena o endereço de memória da variável Y.
    C) X: X = 500, &X e PX: endereço de memória da variável X, Y: 700
    D) O conteúdo de X é incrementado em 200, ou seja, X = 700; e o conteúdo de Y é incrementado em mais 50, Y = 750.
    E) Y: Y = 750, &Y e PY: endereço de memória da variável Y, X: 700
    F) PY: PY passa a armazenar o endereço de memória da variável X; e X é incrementado em mais 300, ou seja, X = 1000.
    G) A função "atera1" trata de incrementar em 50 e 300, os conteúdos das variáveis X e Y, respectivamente. Já a "aLtera2"

*/