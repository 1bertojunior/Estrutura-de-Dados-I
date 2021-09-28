#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int TAM = 100;


typedef struct No{
    int ex, valor, potencia;
    struct No *proximo;
}No;

typedef struct{
    No *inicio;
    No *fim;
    int k;
}Lista;

void inicia_lista(Lista *l);
void inserir(Lista *l, int num, int p, int e);
void imprimirLista(Lista lista);
void ler_polinomio(Lista *l);
void imprimir_polinomios(Lista L[TAM], int t);
void somar_polinomios(Lista L[TAM], int id1, int id2);
void avaliar_polinomio(Lista l);
void derivada_parcial(Lista l, char var, int valor);
int check_var(char var);

int menu_principal();
int menu_existe();

int main(){
    int op, i = 0, id, id2, valor;
    char c;

    // CRIANDO VETOR DE LISTAS CIRCULARES
    Lista L[TAM];


    do{
        op = menu_principal();
        printf("\n");
        switch (op){
            case 1:
                // Cadastrar
                inicia_lista(&L[i]);
                ler_polinomio(&L[i]);
                i++;                
                break;
            case 2:
                // Somar
                printf("Digite o indice dos polinomios que deseja somar: ");
                scanf("%d%d", &id, &id2);
                printf("Soma entre os polinomio\n");
                somar_polinomios(L, id, id2);
                break;
            case 4:
                // Avaliar
                printf("Indice de um polinomio entre 0 e %d (inclusive): ", i-1);
                scanf("%d", &id);
                printf("Polinomio escolhido:\t");
                imprimirLista(L[id]);
                avaliar_polinomio(L[id]);
                break;
            case 5:
                // Imprimir um polinomio
                printf("Indice de um polinomio entre 0 e %d (inclusive): ", i-1);
                scanf("%d", &id);
                printf("Polinomio escolhido:\t");
                imprimirLista(L[id]);
                break;
            case 6:
                // Imprimir todos
                printf("Vetor com todos os polinomios\n");
                printf("Indice\t|\tPolinomio\n");
                imprimir_polinomios(L, i);
                break;
            case 7:
                // Derivada
                printf("Indice de um polinomio entre 0 e %d (inclusive): ", i-1);
                scanf("%d", &id);
                printf("Polinomio escolhido:\t");
                imprimirLista(L[id]);

                printf("Digite uma das variaveis (x, y ou z): ");
                scanf("%c", &c);
                
                printf("Digite um valor para a variavel %c: ", c);
                scanf("%d", &valor);
                derivada_parcial(L[id], c, valor);
                break;
        }
        printf("\n\n");
    }while(op != 0);

    return 0;
}

void inicia_lista(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
}

void inserir(Lista *l, int num, int p, int e){
    No *novo = malloc(sizeof(No));

    if(novo){
        novo->valor = num;
        novo->potencia = p;
        novo->ex = e;

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



void ler_polinomio(Lista *l){
    char var[3] = {"xyz"};
    int i = 0, v, p, k = 0;

    while (i < 3){
        printf("Existe %c?\n", var[i]);
        if(menu_existe()){
            printf("Valor: ");
            scanf("%d", &v);
            printf("Potencia: ");
            scanf("%d", &p);
            inserir(l, v, p, 1);
        }else
            inserir(l, 0, 0, 0);
        i++;
    }
    printf("Constante (0 se n existe): ");
    scanf("%d", &k);
    l->k = k;
}

int menu_existe(){
    int op;
    printf("[1] - Sim | [0] - Nao\n");
    printf("opcao: ");
    scanf("%d", &op);
    return op;
}

int menu_principal(){
    int op;
    do{
        printf("[1] - Cadastrar polinomio\n");
        printf("[2] - Somar polinomios\n");
        printf("[3] - Multiplicar polinomios\n");
        printf("[4] - Avaliar polinomio\n");
        printf("[5] - Imprimir um polinomio\n");
        printf("[6] - Imprimir todos os polinomios\n");
        printf("[7] - Derivada parcial\n");
        printf("[0] - Sair\n");
        scanf("%d", &op);
    }while(op < 0 || op > 7);
    return op;
}
void imprimirLista(Lista lista){
    char var[3] = {"xyz"};
    int i = 0;
    No *no = lista.inicio;
    if(no){
        do{
            if(no->ex){
                printf("%d%c^", no->valor, var[i]);
                if(no->potencia > 0)
                    printf("%d", no->potencia);
                if(i < 3)
                    printf(" + ");
            }
            no = no->proximo;
            i++;
        }while(no != lista.inicio);
        if(lista.k)
            printf("%d", lista.k);
        printf("\n");
    }else
        printf("Lista vazia!\n");
}

void imprimir_polinomios(Lista L[TAM], int t){
    int j = 0;
    while(j < t){
        printf("%3d\t  ", j+1);
        imprimirLista(L[j]);
        j++;
    }
}

void somar_polinomios(Lista L[TAM], int id1, int id2){
    int i = 0;

    Lista aux;
    inicia_lista(&aux);

    No *noA = L[id1].inicio;
    No *noB = L[id2].inicio;

    while (i < 3){
        if(noA->ex && noB->ex){
            if(noA->potencia == noB->potencia){
                inserir(&aux, noA->valor+noB->valor, noA->potencia, 1);
                aux.k =  L[id1].k + L[id2].k;
            }else{
                inserir(&aux, noA->valor, noA->potencia, 1);
                inserir(&aux, noB->valor, noB->potencia, 1);
                aux.k =  L[id1].k + L[id2].k;
            }
        }else{
            if(noA){
                inserir(&aux, noA->valor, noA->potencia, 1);
                aux.k =  L[id1].k + L[id2].k;
            }else if(noB){
                inserir(&aux, noA->valor, noA->potencia, 1);
                aux.k =  L[id1].k + L[id2].k;
            }else
                inserir(&aux, 0, 0, 0);
                aux.k =  0;
        }
        noA = noA->proximo;
        noB = noB->proximo;
        i++;
    }

    imprimirLista(aux);
}

void avaliar_polinomio(Lista l){

    int v[3], i = 0, rp = 0;
    char var[3] = {"xyz"};

    No *no = l.inicio;
    if(no){
        do{
            if(no->ex){
                printf("Digite um valor para %c: ", var[i]);
                scanf("%d", &v[i]);
            }else{
                v[i] = -1;
            }
            no = no->proximo;
            i++;
        }while(no != l.inicio);

        printf("Resultdo do polinomio com os valores informados: ");
        No *no = l.inicio;
        for(i=0; i<3; i++){
            if(v[i] != -1){
                rp += pow(v[i], no->potencia)*no->valor;                
            }
            no = no->proximo;
        }
        printf("\nResult: %d \n", rp+l.k);
    }else
        printf("Lista vazia!\n");
}

int check_var(char var){
    var = tolower(var);
    int r = -1;
    if(var == 'x')
        r = 0;
    else if (var == 'y')
        r = 1;
    else if (var == 'z')
        r = 2;

    return r;
}

void derivada_parcial(Lista l, char var, int valor){

    char vaux[3] = {"xyz"};
    int i = 0;
    No *no = l.inicio;
    if(no){
        do{
            if(check_var(var) == i && no->ex){
                printf("(%.0lf)", pow(valor, no->potencia)*no->valor);
                if(i < 3)
                    printf(" + ");
            }else{
                if(no->ex){
                    printf("%d%c^", no->valor, vaux[i]);
                    if(no->potencia > 0)
                        printf("%d", no->potencia);
                    if(i < 3)
                        printf(" + ");
                }
            }
            
            no = no->proximo;
            i++;
        }while(no != l.inicio);
        if(l.k)
            printf("%d", l.k);
        printf("\n");
    }else
        printf("Lista vazia!\n");
}
