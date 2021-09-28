#include <stdio.h>
#define max 50

void lervetor(int vetor[],int *Tam); //retorna o tamanho do vetor
//lervetor só para qnd o usuário digitar "-1" ou chegar ao fim do vetor

void ordenar (int v[],int i,int j, int inicio, int fim);

void uniao (int v1[],int v2[],int v3[], int i, int j,int *k, int fim1, int fim2);
//o k está contando qnts posições v3 está sendo preenchida

int main(){
    int i,k=0, Tamv1, Tamv2;
    int v1[max];
    int v2[max];
    int v3[max+max];
    
    printf("Digite o primeiro vetor ou (-1) para finalizar o preenchimento\n");
    lervetor(v1,&Tamv1);
    printf("Digite o segundo vetor ou (-1) para finalizar o preenchimento\n");
    lervetor(v2,&Tamv2);
    
// mando tamanho - 1 e lá na função uso "<="
    ordenar (v1, 0, 1,0,Tamv1-1);
    ordenar (v2, 0, 1,0,Tamv2-1);
   
    uniao (v1,v2,v3,0,0,&k,Tamv1-1,Tamv2-1);

    for(i=0; i < k; i++){
        printf(" %d -",v3[i]);
    }
    return 0;
}
void lervetor(int vetor[],int *Tam){
    int x, i=0;
    *Tam=0;
    do{
        printf("Num:  ");
        scanf("%d",&x);
        if(x > 0){
            vetor[i]=x;
            i++;
            (*Tam)+=1;
                
        } 
    }while((x!=-1)&&(i<max));
    
}

void ordenar (int v[],int i,int j, int inicio, int fim){
    int aux;// auxiliar para as trocas
    if(j <= fim){
        if(v[i] > v[j]){
            aux = v[i];
            v[i] = v[j];
            v[j]= aux;
            if (i > inicio){
                ordenar(v,i-1,i,inicio,fim);
            }else{
                ordenar(v,j,j+1,inicio,fim);
            }
        }ordenar(v,j,j+1,inicio,fim);
    }
}

// Na união basicamente preencho o v3 e armazeno seu tamanho em ordem crescente
// Não sei muito o que comentar pq a senhora já conhece o código ;p

void uniao (int v1[],int v2[],int v3[], int i, int j,int *k, int fim1,int fim2){
        if((i<=fim1)&&(j<=fim2)){//verifico se tenho dado a ser lido nos dois vetores
            if(v1[i] == v2[j]){
                v3[*k] = v1[i];
                (*k)+=1;
                uniao(v1,v2,v3,i+1,j+1,k,fim1,fim2);
            }else if (v1[i] < v2[j]){
                v3[*k] = v1[i];
                (*k)+=1;
                uniao(v1,v2,v3,i+1,j,k,fim1,fim2);
            }else{
                v3[*k] = v2[j];
                (*k)+=1;
                uniao(v1,v2,v3,i,j+1,k,fim1,fim2);
            }
        }else if (i <= fim1){
            v3[*k] = v1[i];
            (*k)+=1;
            uniao(v1,v2,v3,i+1,j,k,fim1,fim2);
        }else if (j <= fim2){
            v3[*k] = v2[j];
            (*k)+=1;
            uniao(v1,v2,v3,i,j+1,k,fim1,fim2);
        }
}  