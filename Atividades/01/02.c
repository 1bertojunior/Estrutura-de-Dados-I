#include<stdio.h>
#include<string.h>
#include<ctype.h>

int isVowel(char str);
void countVowels(char str[], int *result);
int countVowels2(char str[]);

int main(){
    char str[100];
    int result = 0;
    
    printf("Uma string (de até 100 caracteres): ");
    scanf("%[^\n]s", str);

    countVowels(str, &result);
    printf("\nVogais = %d", result);
    result = countVowels2(str);
    printf("\nVogais 2 = %d\n", result);



    return 0;
}

void countVowels(char str[], int *result){
    for(int i=0; i<strlen(str); i++) if(isVowel(str[i])) *result+=1;
}

int countVowels2(char str[]){
    int result;
    for(int i=0; i<strlen(str); i++) if(isVowel(str[i])) result+=1;
    return result;

}

int isVowel(char str){
    str  = islower(str) ? str : tolower(str);
    if(str == 'a' || str == 'e' || str == 'i' || str == 'o' || str == 'u') return 1;
    return 0;
}