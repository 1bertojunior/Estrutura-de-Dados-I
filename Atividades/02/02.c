#include<stdio.h>
#include<stdlib.h>

void altera1(int *p, int *a){ // altera conteúdo
    *p = *a;
    *a = *a + 50;
}

void altera2(int **p, int *b){ //alterar endereço
    *p = b;
    *b = *b +300;
}

int main(){
   
    int *px; 
    int *py;
    px = (int *)malloc(sizeof(int));
    py = (int *)malloc(sizeof(int));
    *px = 500;
    *py = *px + 50;

    printf("End. px = %p, px = %p, py = %d\n", &px, px, *py );
    altera1(px, py);
    printf("End. px = %p, px = %p, py = %d\n", &px, px, *py );

    printf("End. py = %p, py = %p, px = %d\n", &py, py, *px );
    altera2(&py, px);
    printf("End. py = %p, py = %p, px = %d\n", &py, py, *px );

   
    return(0);
}