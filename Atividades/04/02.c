#include<stdio.h>
#include<string.h>>


int toConvert(char str[], int i, int u){
    int r=0, n=0;
    if(i>=0){
        n = str[i] - 48;
        r = (n*u) + toConvert(str,i-1,u*10);
    }
    return r;
}

int main(){

    char str[5];

    printf("Informe um n de até 5 digitos: ");
    scanf("%s", str);

    printf("String for Binario = %d\n", toConvert(str,strlen(str)-1,1));

    return 0;
}