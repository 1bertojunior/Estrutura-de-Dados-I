#include <stdio.h>
#include <stdlib.h>

#define T 5

void ler(int v[],int t){
    for(int i=0; i<t;i++){
        printf("V[%d]: ",i);
        scanf("%d", &v[i]);
    }
}

void show(int v[], int i, int t){
    if(i<t){
        printf("%d ", v[i]);
        show(v,i+1,t);
    }
}

int partition(int v[], int s, int e){
    int left, right, pivot, aux;
    left = s; //start
    right = e; //rigth
    pivot = v[s]; // primeira psoicção
    while(left < right){
        while(v[left] <= pivot) left++;
        while(v[right] > pivot) right--;
        if(left < right){
            aux = v[left];
            v[left] = v[right];
            v[right] = aux;
        }
    }
    v[s] = v[right];
    v[right] = pivot;
    return right;

}

void quickSort(int v[], int s, int e){
    if(s<e){
        int pivot = partition(v,s,e);

        quickSort(v,s,pivot-1);
        quickSort(v,pivot+1,e);
    }
}

void interSection(int v1[], int v2[], int v3[], int t, int *t3, int i, int j){
    if(j<t){
        if(v1[i] == v2[j]) v3[(*t3)++] = v1[i];
        interSection(v1,v2,v3,t,t3,i,j+1);   
    }
    if(i !=t-1 && j== t-1) interSection(v1,v2,v3,t,t3,i+1,j=0);
}

int main(){

    int v1[5], v2[5],v3[T*2], i=0, t3=0;

    printf("Informe %d elementos para o V1: \n", T);
    ler(v1,T);
    printf("Informe %d elementos para o V2: \n", T);
    ler(v2,T);
    printf("Vetores informados:\n");
    show(v1,i,T); printf("\n");
    show(v2,i,T); printf("\n");

    quickSort(v1,i,T);
    quickSort(v2,i,T);

    printf("Vetores ordenados: \n");
    show(v1,i,T);
    printf("\n");
    show(v2,i,T);
    printf("\n");

    interSection(v1,v2,v3,T,&t3,0,0);
    printf("intersecção dos dois vetores: \n");
    if(t3!=0) show(v3,i,t3);
    else printf("OS vetetores não tem elemento em comum!");
    printf("\n");

    return 0;
}