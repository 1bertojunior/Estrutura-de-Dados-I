#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

#define L 4
#define C 3

void setMatriz(char m[L][C][100], int c, int l, int *cl);
void showMatriz(char m[L][C][100], int c, int l);
void quickSort(char m[L][C][100], int s, int e, int c);
int partition(char m[L][C][100], int s, int e, int c);
void swap(char m[L][C][100], int i, int j, int c);
void copyM(char m1[L][C][100], char m2[L][C][100]);
int qtdDigitsAndCapitalLetters(char m[], int *d, int * cl);
int isVowels(int c);
int qtdStartingWithConsonant(char m[L][C][100], int c);

int main(){
    char m[L][C][100], mo[L][C][100];
    int op, c=0, o=0;
    
    if(0){
        strcpy(m[0][0], "string");
        strcpy(m[1][0], "int");
        strcpy(m[2][0], "char");
        strcpy(m[3][0], "bool");
    
        strcpy(m[0][1], "vscode");
        strcpy(m[1][1], "sublime");
        strcpy(m[2][1], "androidstu");
        strcpy(m[3][1], "xcode");

        strcpy(m[0][2], "humberto");
        strcpy(m[1][2], "junior");
        strcpy(m[2][2], "jose");
        strcpy(m[3][2], "silva");
        c=1;
        copyM(m,mo);
    }
    
    do{ 
        printf("[0] - Encerrar\n[1] - Ler matriz\n[2] - Ordenar\n[3] - Matriz original e ordenada\n[4] - Número de dígitos e de letras maiúsculas\n[5] - Qtd de str que iniciam com consoante\n");
        printf("OPÇÃO: ");
        scanf("%d", &op);

        if(op == 1) {
            if(c == 0){
                printf("# LER\n");
                setMatriz(m,C,L, &c);
                copyM(m,mo);
            }else printf("# Matriz já prenchida!\n");
        }
        if(op == 2) {
            if(c>0){
                for(int i=0; i<3; i++) quickSort(m,0,L-1,i); 
                o=1;
            }else printf("[!] Nenhum dado cadastrado!\n");
        }            
        if(op == 3) {
            if(c>0){
                if(o){
                    printf("# ORDENADA\n");
                    showMatriz(m,C,L);
                }else printf("[!] A matriz ainda não foi ordenada!\n");
                printf("\n# ORIGINAL\n");
                showMatriz(mo,C,L);
            } else printf("[!] Nenhum dado cadastrado!\n");
        }
        if(op == 4){
            if(o){
                int ca,la, d=0, ma=0;
                printf("COLUNA: ");
                scanf("%d",&ca);
                printf("LINHA: ");
                scanf("%d", &la);
                if(strlen(m[la][ca]) >0){
                    printf("STRING: %s\n", m[la][ca]);
                    qtdDigitsAndCapitalLetters(m[la][ca],&d,&ma);
                    printf("Digitos: %d\n",d);
                    printf("Maiúsculas: %d\n", ma);
                }else printf("[!] POSIÇÃO INVÁLIDA!\n");
            }else printf("[!] A matriz ainda não foi ordenada!\n");
        }
        if(op == 5){
            if(c>0){
                int n,qtd;
                printf("COLUNA: ");
                scanf("%d",&n);
                if(n<C){
                    qtd = qtdStartingWithConsonant(m,n);
                    printf("Consoantes: %d\n", qtd);
                }else printf("[!] Coluna inválida\n");
            }else printf("[!] Nenhum dado cadastrado!\n");
        }
    }while(op != 0);
   

    return 0;
}

void setMatriz(char m[L][C][100], int c, int l, int *cl){
    for(int i=0; i<c; i++){
        printf("# COLUNA %d\n", i+1);
        for(int j=0; j<l; j++){
            printf("M[%d][%d]:", j,i);
            scanf("%s", m[j][i]);
            (*cl)+=1;
        }
        printf("\n");
    }
}

void showMatriz(char m[L][C][100], int c, int l){
    for(int i=0; i<l; i++){
        for(int j=0; j<c; j++){
            printf("%s ", m[i][j]);
        }
        printf("\n");
    }
}


void quickSort(char m[L][C][100], int s, int e, int c){
    int p;
    if(s<e){
        p = partition(m,s,e,c);
        quickSort(m,s,p-1,c);
        quickSort(m,p+1,e,c);
    }
}

int partition(char m[L][C][100], int s, int e, int c){
    int p = e;
    int i = s;

    for(int j=i; j<e; j++){
        if(strcmp(m[j][c], m[p][c]) <= 0){
            swap(m,i,j,c);
            i++;
        }
    }
    swap(m,i,e,c);

    return i;
}

void swap(char m[L][C][100], int i, int j, int c){
    char a[100];
    strcpy(a,m[i][c]);
    strcpy(m[i][c],m[j][c]);
    strcpy(m[j][c], a);
}

void copyM(char m1[L][C][100], char m2[L][C][100]){
    for (int i=0; i<L; i++ ) for(int j=0; j<C; j++) strcpy(m2[i][j],m1[i][j]);
}

int qtdDigitsAndCapitalLetters(char m[], int *d, int * cl){
    for(int i=0; i<strlen(m); i++){
        if(isdigit(m[i])) *d+=1;
        else if(isupper(m[i])) *cl+=1;
    }
} /// int sem return

int isVowels(int c){
    return c == 97  || c == 101 || c == 105 || c == 111 || c == 117 ? 1 : 0;
}

int qtdStartingWithConsonant(char m[L][C][100], int c){
    int r=0;
    for(int i=0; i<L; i++)  if(!isVowels(m[i][c][0])) r++;
    return r;
}
