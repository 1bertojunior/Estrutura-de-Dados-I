/*
Dois Vetores estão definidos na função main.
Os testes também foram realizados nos exemplos abaixo.
vetor1[6] = {1,2,9,8,7,5};
vetor2[5] = {1,4,6,7,8};

vetor1[5] = {3,5,9,7,3};
vetor2[5] = {1,3,4,5,8};

OBS: Não esqueça de mudar o tamanho dos vetores nas chamadas das função!
Evite dores de cabeça kkk
*/


#include<stdio.h>
#include<stdlib.h>

void insercaoRecursiv(int v[],int n){
  int x,i;
  if(n > 1){
    insercaoRecursiv(v,n-1);
    i = n-1;
    while(i > 0 && v[i-1] > v[i]){
      x = v[i-1];
      v[i-1] = v[i];
      v[i] = x;
      i--;
    }
  }
}

int pertence(int v[],int tamanho_v,int procurado){
  int r = 0;
  for(int k = 0; k < tamanho_v; k++){
    if(v[k] == procurado){
      return r; // 0 se exitir
    }
  }
  return r+1; // 1 se não exitir
}

void unir(int v1[], int v2[], int v3[], int t1, int t2,int t3, int i, int j,int *t){
  if (i  <  t1){
    v3[i] =  v1[i];
    (*t)++;
    unir(v1, v2, v3, t1, t2,t3, i + 1, j,t);
  }
  else
  if (j  <  t2){ /*Verifico se o numero não pertence ainda ao vetor3*/
    //int p = pertence(v3,t2,v2[j]);
    //printf("p = %d\n",p);
    if(pertence(v3,t2,v2[j])){
      v3[i] = v2[j];
      //*t += 1;
      (*t)++;
      i+=1;
    }
    unir(v1,v2,v3,t1,t2,t3,i,j + 1,t);
  }
}

int main(int argc, char *argv[]){

  int vetor1[5] = {9,4,8,3,6};
  int vetor2[5] = {4,3,2,1,0};
  int vetor3[12];
  int i = 0, j = 0, t = 0; // t é o tamanho de vetor 3
  insercaoRecursiv(vetor1,5);
  insercaoRecursiv(vetor2,5);
  unir(vetor1,vetor2,vetor3,5,5,12,0,0,&t);
  printf("Vetor3 = ");
  insercaoRecursiv(vetor3,t);
  for(int i = 0; i < t; i++){
    printf("%d",vetor3[i]);
  }
  printf("\n");
  return 0;
}
/*

 if(i<t){
        if(v1[i]==v2[j]){
            v3[*t3] = v1[i];
            *t3 = *t3 +1;
            join(v1,v2,v3,i+1,j+1,t,t3);
        }else if(v1[i]<v2[j]){
            v3[*t3] = v1[i];
            *t3 = *t3 +1;
            join(v1,v2,v3,i+1,j,t,t3);
        }else if()
    }else if(j<t){

    }

    */