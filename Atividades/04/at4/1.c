#include<stdio.h>
#include<stdlib.h>
/*
* Rastreamento do código!
*
* A função binario recebe um número, um ponteiro como contador e um vetor
* de char com 8 para armazenar o binario do número.
* Usaremos o número 12 para realizar o rastreamento.
* Como 12 é menor que 256, então, a função parte para a próxima condição(o 
* if mais interno).
*
* Dividimos 12 por 2 e analizamos o resultado. Se o resultado é maior que 0
* entramos na condição e chamamos a função binario novamente só que
* passando 6 (nro/2). O código repete-se até nro/2 > 0 seja falso, fazendo-o
* entrar na condição else. Logo, que a condição else é executada o vetor de 
* char bin, na posição *i, recebe o resto de (nro % 2), que deve ser 0 ou 1
* e é somado com 48.
*
* Depois há um print do valor atribuido a bin[*i] e o ponteiro i é incremen
* tado. E função volta recursivamente resolvendo as pendencias deixadas pelo
* segundo if (if(nro/2 > 0)), alocando em bin os restos das divisões +48 nas 
* posições *i.
* Precisa-se somar 48 nas atibuições para que bin, um vetor de char, receba
* 0 ou 1 como caracteres, e não como inteiros.
*/
	
int binario(int nro, int *i,char bin[8]){
if (nro < 256){
	if(nro / 2 > 0){
		binario(nro/2,i,bin);
		bin[*i] = (nro % 2) + 48;
		printf("1bin[%d] = %c\n",*i,bin[*i]);
		(*i)++;
	}
	else {
		bin[*i] = (nro % 2) + 48;
		printf("bin[%d] = %c\n",*i,bin[*i]);
		(*i)++;
		}
	}
	int p = *i;
	return p;
}

int main(){
	int n, i = 0;
	char bin[9];
	printf("n: ");
	scanf("%d",&n);
if(n < 256){
	
	int b = binario(n,&i,bin);
	printf("Valor de i(retornado pela função) %d\n",b);
	bin[b+1] = '\0';
	printf("O número binario e: %s\n",bin);
}
else printf("O maior número possível com 8 dígitos é 255.\n");
return(0);
}
