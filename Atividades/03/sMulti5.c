#include<stdio.h>


void sMulti5(int v[], int i, int t, int *s){
    if(i<t){
        if(v[i]%5 == 0) *s = *s + v[i];   

        sMulti5(v, ++i, t, s);
    }
}

int sMulti52(int v[], int i, int t){
    int s=0;
    if(i<t){
        if(v[i]%5 == 0) s = sMulti52(v,i+1,t) + v[i];
        else s = sMulti52(v, i+1, t);
    }

    return s;
}

int checkMulti15(int n){
    return n%15 == 0 ? 1 : 0;
}



int main(){

    int v[6] = {5,8,10,12,15,17}, t=6, s=0;

    sMulti5(v,0,t,&s);

    char n[10];
    printf("\n%d\n", sizeof(n));
    printf("%d", sizeof(v)/4);

    printf("S = %d\n", s);
    printf("S2 = %d\n", sMulti52(v,0,t));

    int num = 31;

    printf("# %d é multiplo de 15? = %d\n", num, checkMulti15(num));
    return 0;
}