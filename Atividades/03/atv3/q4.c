#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
    char nome[20];
    int mat;
    int per;
    char cur[10];
}dados;
//usei a mesma função da questão anterior para ordenar

void ordenar(dados aluno[],int i,int j, int inicio, int fim);
void buscarmat (dados aluno[],int chave, int *posi,int inicio,int fim);
void buscarqntalunos (dados aluno[],char curso[], int *qnt,int inicio,int fim);
void vetorNomes(dados aluno[], int tam, char vetor2[][20], int i, int periodo, int *k);

int main(){
    int i,chave, periodo, posi = -1, k = 0,qnt = 0, tam = 3;
//iniciei posi com "-1" pq é minha variável que determina 
//a posição na qual se encontra a matrícula pesquisada e pode ser 0 tb
//k=0 para saber qnts posições tem a matriz com os nomes dos alunos do periodo pesquisado 
//qnt = 0 é o inicio para a contagem de alunos do curso pesquisado

    dados aluno[tam];
    char curso[10];
    char vetor2[tam][20];
    
    for (i = 0; i < tam; i++)//dados pelo usuário
    {
        printf("Digite o número da sua matrícula: ");
        scanf("%d", &aluno[i].mat);
        printf("Digite o seu nome: ");
        scanf("%s", aluno[i].nome);
        printf("Digite o nome do seu curso: ");
        scanf("%s", aluno[i].cur);
        printf("Digite o período: ");
        scanf("%d", &aluno[i].per);
    }

    ordenar(aluno,0,1,0,tam-1);//ordeno pela inserção
    
    for (i = 0; i < tam; i++)//imprimo ordenado
  {
    printf("matrícula: %d\n",aluno[i].mat);
    printf("nome: %s\n",aluno[i].nome);
    printf("curso: %s\n",aluno[i].cur);
    printf("período: %d\n",aluno[i].per);
    
  }

    printf("Deseja a relacao de alunos de qual periodo? ");
    scanf("%d", &periodo);

    vetorNomes(aluno, tam, vetor2, 0, periodo, &k);//pequiso o periodo e recebo 
//uma matriz de alunos dele
    
    for (i = 0; i < k;i++){
        printf("%s",vetor2[i]);
    } 

    printf("Digite a matricula que deseja buscar: ");
    scanf("%d",&chave);
    buscarmat(aluno,chave,&posi,0,tam-1);
    
    if(posi >= 0){// posição do vetor
        printf("matrícula: %d\n",aluno[posi].mat);
        printf("nome: %s\n",aluno[posi].nome);
        printf("curso: %s\n",aluno[posi].cur);
        printf("período: %d\n",aluno[posi].per);
    }else{
        printf("matricula nao encontrada\n");
    }
    
    printf("Digite o curso que deseja buscar a qnt de alunos: ");
    scanf("%s",curso);
    buscarqntalunos(aluno,curso,&qnt,0,tam-1);
    
    printf("qnt de alunos neste curso: %d ", qnt);

return 0;
}

void ordenar(dados aluno[],int i,int j, int inicio, int fim){
//Juliana, quando só tinha essa função e a de buscar, estava tudo 
//funcionando muito bem, por algum motivo após adicionarmos as outras  funções 
//a função ordenar parou de funcionar e acabou atrapalhando as demais
// a gente acha que foi alguma variável que a gente mexeu e acabou desmantelando 
//ordenar, e aí acaba que causa prob nas outras...
// a gente tava fazendo as funções separadas, talvez seja pq Wendel usou um nome e eu outro. 
//mas acredito que é besteira, só que a gente não consegue resolver até 0h :(


    char n1[20];
    int m1;
    int p1;
    char c1[10];
    if(j <= fim){
        if(aluno[i].mat > aluno[j].mat){ // condição de troca
            //matricula
            m1 = aluno[i].mat;
            aluno[i].mat = aluno[j].mat;
            aluno[j].mat= m1;
            //nome
            strcpy(n1,aluno[i].nome); 
            strcpy(aluno[i].nome,aluno[j].nome);
            strcpy(aluno[j].nome,n1);
            //periodo
            p1 = aluno[i].per;
            aluno[i].per = aluno[j].per;
            aluno[j].per= p1;            
            //curso
            strcpy(c1,aluno[i].cur);
            strcpy(aluno[i].cur,aluno[j].cur);
            strcpy(aluno[j].cur,n1);            
            
            if (i > inicio){
                ordenar(aluno,i-1,i,inicio,fim);
            }else{
                ordenar(aluno,j,j+1,inicio,fim);
            }
        }ordenar(aluno,j,j+1,inicio,fim);
    }
}
void vetorNomes(dados aluno[], int tam, char vetor2[][20], int i, int periodo, int *k)
{
  if ((i < tam) && (periodo == aluno[i].per))
  {
    strcpy(vetor2[*k],aluno[i].nome);
    (*k) += 1;
    vetorNomes(aluno, tam, vetor2, i + 1, periodo, k);
  }
  else if (i < tam)
  {
    vetorNomes(aluno, tam, vetor2, i + 1, periodo, k);
  }
}
//busca binária encontrei na net com pendência e tetei fazer sem pendÊncia
void buscarmat (dados aluno[],int chave, int *posi,int inicio,int fim){
    int meio;
    if((inicio <= fim)&&((*posi) < 0)){
        meio = (inicio + fim)/2;
        if(chave == aluno[meio].mat){
            *posi = meio;
        }else{
            if(chave < aluno[meio].mat){
                buscarmat(aluno,chave,posi,inicio,meio-1);
            }else{
                buscarmat(aluno,chave,posi,meio+1,fim);
            }
        }
    }
}
void buscarqntalunos (dados aluno[],char curso[], int *qnt,int inicio,int fim){
    
    if(inicio <= fim){
        if(strcmp(curso,aluno[inicio].cur)==0){
            (*qnt) += 1;
            buscarqntalunos(aluno,curso,qnt,inicio+1,fim);
        }else{
            buscarqntalunos(aluno,curso,qnt,inicio+1,fim);
        }    
    }
}