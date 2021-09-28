#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
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

void insertionSort(int v[],int i,int j, int a, int s, int e){
    if(j<=e){
        if(v[i] > v[j]){
            a = v[i];
            v[i] = v[j];
            v[j] = a;

            if(i > s) insertionSort(v,i-1,i,a,s,e);
            else insertionSort(v, j, j+1, a,s,e);
        }
        insertionSort(v,j,j+1,a,s,e);
    }
}

int binarySearch(int v[], int s, int e, int n){
  if(s > e) return 0;
  else{
    int i = (s+e)/2;
    if(v[i] == n) return 1;
    else{
      if(n < v[i]) return binarySearch(v,s,i-1,n);
      else return binarySearch(v,i+1,e,n);
    }
  }
}

void join(int v1[], int v2[], int v3[], int i, int j, int t, int *t3){
    if(i<t){
        v3[*t3] = v1[i];
        (*t3)++;
        join(v1,v2,v3,i+1,j,t,t3);
    }else if(j<t){
        if(!binarySearch(v3,0,*t3,v2[j])){
            v3[i] = v2[j];
            (*t3)++;
            i+=1;
        }
        join(v1,v2,v3,i++,j+1,t, t3);
    }
}

int main(){

  int t = 5, t3=0;
  int v1[T];
  int v2[T];
  int v3[T*2];

  printf("Informe %d elementos para o V1: \n", t);
  ler(v1,T);
  printf("Informe %d elementos para o V2: \n", t);
  ler(v2,T);

  printf("Vetores informados:\n");
  show(v1,0,T); printf("\n");
  show(v2,0,T); printf("\n");

  insertionSort(v1,0,1,0,0,t);
  insertionSort(v2,0,1,0,0,t);

  printf("Vetores ordenados: \n");
  show(v1,0,T); printf("\n");
  show(v2,0,T); printf("\n");

  join(v1,v2,v3,0,0,T,&t3);
  insertionSort(v3,0,1,0,0,t3-1);

  printf("União dos dois vetores: \n");
  show(v3,0,t3); printf("\n");

  return 0;
}