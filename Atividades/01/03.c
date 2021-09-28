#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isVowel(char str);

int qtdUppercaseAndVowels(char str1[], char str2[], int *str1Upp, int *str2Upp);

int main(){

    char str1[100], str2[100];
    int qtdVowels, str1Upp=0, str2Upp=0;

    printf("Str 1: ");
    scanf(" %[^\n]s", str1);
    printf("Str 2: ");
    scanf(" %[^\n]s", str2);


    qtdVowels = qtdUppercaseAndVowels(str1, str2, &str1Upp, &str2Upp);

    printf("\nVogais = %d", qtdVowels);
    printf("\nQtd maiúscula str1 = %d", str1Upp);
    printf("\nQtd maiúscula str2 = %d\n", str2Upp);

    return 0;

}

int qtdUppercaseAndVowels(char str1[], char str2[], int *str1Upp, int *str2Upp){
    int qtdVowels = 0;

    for(int i=0; i<strlen(str1); i++){
        if(isupper(str1[i])) *str1Upp+=1;
        if(isVowel(str1[i])) qtdVowels+=1;
    }

    for(int i=0; i<strlen(str2); i++){
        if(isupper(str2[i])) *str2Upp+=1;
        if(isVowel(str2[i])) qtdVowels+=1;
    }

    return qtdVowels;
}

int isVowel(char str){
    str  = islower(str) ? str : tolower(str);
    if(str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u') return 1;
    return 0;
}