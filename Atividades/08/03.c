#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TMAX 100 //   Numero maximo de elementos na lista

typedef struct No{
    int valor;
    struct No *proximo;
    struct No *anterior;
}No;

typedef struct{
    No *inicio;
    No *fim;
}Lista;

void inicia_lista(Lista *l);
void inserir_inicio(Lista *l, int num);
void inserir_fim(Lista *l, int num);
void inserir_ordenado(Lista *lista, int num);
void imprimirLista(Lista lista);
void remover_list(Lista *lista, int num);
No *buscar(Lista *lista, int num);

int rept_num(Lista *lista, int num); // Conta quantas vezes um numero se repete na lista
void numeros_proximos(Lista *lista, int num, int *numx, int *numy);

int main(){
    Lista L1;
    int n, tam = 0;

    inicia_lista(&L1);  //Iniciando lista com Null e Zero (0)

    srand((unsigned)time(NULL));
    // Preenchendo Lista
    while(++tam <= TMAX){
        n = rand() % 500 + 1;
        inserir_ordenado(&L1, n);
        //printf("Elemento inserido!  --  %d\n", n);
    }
    printf("%d num aleatorios foram add a LISTA.\n", TMAX);

    // Imprimindo a lista para conferir o resultado
    /*printf("\n\tLISTA: \n");
    imprimirLista(L1);*/
    printf("\n\n");

    printf("Valor inteiro: ");
    scanf("%d", &n);

    if(buscar(&L1, n)){
        printf("encontrou!\n");
        printf("O num %d se repete %d vezes", n, rept_num(&L1, n));
    }else{
        printf("NAO encontrou!\n");
        //procurar dois numeros mais proximos do valor informado (n)
        int nx, ny; // Para armazenar os dois numeros mais proximos de n
        numeros_proximos(&L1, n, &nx, &ny);
        printf("O 1 numero mais proximo de %d eh %d\n", n, nx);
        printf("O 2 numero mais proximo de %d eh %d\n", n, ny);
    }
    
    return 0;
}

void inicia_lista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
}

void inserir_inicio(Lista *l, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->proximo = l->inicio;
        l->inicio = novo;
        if(l->fim == NULL)
            l->fim = novo;
        l->fim->proximo = l->inicio;
    }
}

void inserir_fim(Lista *l, int num){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;

        // Verifica se eh o primeiro
        if(l->inicio == NULL){
            l->inicio = novo;
            l->fim = novo;
            l->fim->proximo = l->inicio;
        }else{
            l->fim->proximo = novo;
            l->fim = novo;
            novo->proximo = l->inicio;
        }
    }else
        printf("Erro ao alocar memoria\n");
}

void inserir_ordenado(Lista *lista, int num){
    No *aux, *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        // Verifica se esta vazia
        if(lista->inicio == NULL){
            inserir_inicio(lista, num);
        }else if(novo->valor < lista->inicio->valor){ //verifica se o valor eh menor
            inserir_inicio(lista, num);
        }else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && novo->valor > aux->proximo->valor)
                aux = aux->proximo;
            if(aux->proximo == lista->inicio)
                inserir_fim(lista, num);
            else{
                novo->proximo = aux->proximo;
                aux->proximo = novo;
            }
        }
    }else
        printf("Erro ao alocar memoria\n");
}

void imprimirLista(Lista lista){
    int cont = 0;
    No *no = lista.inicio;
    if(no){
        do{
            printf("%4d ", no->valor);
            if(++cont % 20 == 0)
                printf("\n");
            no = no->proximo;
        }while(no != lista.inicio);
        printf("\n");
    }else
        printf("Lista vazia!\n");
}

void remover_list(Lista *lista, int num){

    No *aux, *remover = NULL;

    if(lista->inicio){
        if(lista->inicio == lista->fim && lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = NULL;
            lista->fim = NULL;
        }else if(lista->inicio->valor == num){
            remover = lista->inicio;
            lista->inicio = remover->proximo;
            lista->fim->proximo = lista->inicio;
        }else{
            aux = lista->inicio;
            while(aux->proximo != lista->inicio && aux->proximo->valor != num)
                aux = aux->proximo;
            if(aux->proximo->valor == num){
                if(lista->fim == aux->proximo){
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                    lista->fim = aux;
                }else{
                    remover = aux->proximo;
                    aux->proximo = remover->proximo;
                }
            }
        }
    }

    if(remover){
        free(remover);
        printf("Elemento removido!");
    }else{
        printf("Elemento nao encontrado na lista!\n");
    }
}

No *buscar(Lista *lista, int num){
    No *aux = lista->inicio;

    if(aux){
        do{
            if(aux->valor == num)
                return aux;
            aux = aux->proximo;
        }while(aux != lista->inicio && aux->valor <= num);
    }
    
    return NULL;
}

int rept_num(Lista *lista, int num){
    int qnt = 0;
    No *aux = lista->inicio;

    if(aux){
        do{
            if(aux->valor == num)
                qnt++;
            aux = aux->proximo;
        }while(aux != lista->inicio && aux->valor <= num);
    }
    
    return qnt;

}

void numeros_proximos(Lista *lista, int num, int *numx, int *numy){
    int dif1, dif2;
    No *aux = lista->inicio;

    *numx = aux->valor;         // valor mais proximo "inicialmente"
    *numy = aux->proximo->valor; // segundo valor mais proximo "inicialmente"

    do{
        dif1 = abs(aux->valor - num);
        dif2 = abs(aux->valor - *numx);

        if(dif1 < dif2){
            *numx = aux->valor;
            *numy = aux->proximo->valor;
        }

        aux = aux->proximo;
    }while(aux != lista->inicio);
}
