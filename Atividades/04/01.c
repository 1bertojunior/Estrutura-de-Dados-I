#include <stdio.h>
#include <stdlib.h>

void binario(int nro, int *i,char bin[8]){
    if (nro < 256){
        if(nro / 2 > 0){
            binario(nro/2,i,bin);
            bin[*i] = (nro % 2) + 48;
            printf("bin[%d] = %c\n",*i,bin[*i]);
            (*i)++;
        }else{ 
            bin[*i] = (nro % 2) + 48;
            printf("bin[%d] = %c\n",*i,bin[*i]);
            (*i)++;
        }
    }
}

int binario2(int nro, int *i,char bin[8]){
    if (nro < 256){
        if(nro / 2 > 0){
            binario(nro/2,i,bin);
            bin[*i+1] = (nro % 2) + 48;
            printf("bin[%d] = %c\n",*i,bin[*i]);
            (*i)++;
        }else{ 
            bin[*i+1] = (nro % 2) + 48;
            printf("bin[%d] = %c\n",*i,bin[*i]);
            (*i)++;
        }
    }

    return *i;
}

int main(){
    int n,n2, i=0,i2=0;
    char bin[9], bin2[9];
    
    printf("n: ");
    scanf("%d",&n);
    n2 = n;
    
    if(n < 256){
        binario(n,&i,bin);
        bin[i] = '\0';
        printf("O número binario e: %s\n",bin);
        i2 = binario2(n2,&i2,bin2);
        bin2[i] = '\0';
        printf("O número binario2 e: %s\n",bin2);
    }else printf("O maior número possível com 8 dígitos é255.\n");


    return 0;
}