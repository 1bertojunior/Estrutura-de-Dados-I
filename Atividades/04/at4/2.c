#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int myatoi(char *s,int n){
	//int r;
	// gambiarra
	//if(s[0] == '-') sinal = -1;
	//
	if(n == 1) return *s - '0';
	//r = 10 * myatoi(s,n-1,sinal) + s[n-1] - '0';
	return (10 * myatoi(s,n-1) + s[n-1] - '0');
}
int main(){
	char string[30];
	printf("digite uma string de números de até 30 caracteres\n");
	scanf("%s",string);
	int i = strlen(string);
	int my = myatoi(string,i);
	printf("String = %s\n",string);
	printf("Função myatoi = %d\n",my);
}
