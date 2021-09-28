#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

typedef struct No{
	int valor;
	struct No *proximo;
}No;

typedef struct{
	No *inicio;
  No *fim;
	int tam;
}Lista;

void ordena(Lista *lista){
	assert(lista != NULL);
	if(lista->inicio != NULL){
		for(No *i = lista->inicio; i->proximo != NULL; i = i->proximo){
			No *menor = i;
			for(No *j = i->proximo; j != NULL; j = j->proximo){
				if(j->valor < menor->valor){
					menor = j;
				}
			}
		int aux = i->valor;
		i->valor = menor->valor;
		menor->valor = aux;
		}
	}
}

//inserir elementos sempre no inicio da lista
void inserirInicio(Lista *lista, int num){
  No *novo = (No *)malloc(sizeof(No));
	novo->valor = num;
  novo->proximo = NULL;
  
  if(lista->inicio == NULL) {
    lista->inicio = novo;
    novo->proximo = lista->inicio;
  }else{
    novo->proximo = lista->inicio;
    lista->inicio = novo;
    lista->fim->proximo = lista->inicio;

  }



}

void inserirFinal(Lista *lista, int valor){
	No *no,*novo = (No*)malloc(sizeof(No));
	novo->valor = valor;

	if(lista->inicio == NULL){
		lista->inicio = novo;
    lista->fim = novo;
    lista->fim->proximo = lista->inicio;
		//lista->tam++;
	}
	else{
		lista->fim->proximo = novo;
    lista->fim = novo;
    //lista->fim->proximo = lista->inicio;
    novo->proximo = lista->inicio;
	}
	lista->tam++;
}

void inserirOrdenado(Lista *lista,int num){
	No *aux,*novo = malloc(sizeof(No));
  if(novo){
    novo->valor = num;
    if(lista->inicio == NULL){
      printf("aqui\n");
      inserirInicio(lista,num);
    }
    else if(novo->valor < lista->inicio->valor){
      inserirInicio(lista,num);
    }
    else{
      aux = lista->inicio;
      while(aux->proximo != lista->inicio && novo->valor > aux->proximo->valor){
        aux = aux->proximo;
      }
      if(aux->proximo == lista->inicio){
        inserirFinal(lista,num);
      }
      else{
        novo->proximo = aux->proximo;
        aux->proximo = novo;
        lista->tam++;
      }
    }
  }
  else{
    printf("Erro na alocação\n");
  }
}

No *remover(Lista *lista, int num){
  No *aux, *remover = NULL;
  if(lista->inicio){
    if(lista->inicio == lista->fim && lista->inicio->valor == num){
      remover = lista->inicio;
      lista->inicio = NULL;
      lista->fim = NULL;
      lista->tam--;
    }
    else if(lista->inicio->valor == num){
      remover = lista->inicio;
      lista->inicio = remover->proximo;
      lista->fim->proximo = lista->inicio;
      lista->tam--;
    }
    else{
      aux = lista->inicio;
      while(aux->proximo != lista->inicio && aux->proximo->valor != num){
        aux = aux->proximo;
      }
      if(aux->proximo->valor == num){
        if(lista->fim == aux->proximo){
          remover = aux->proximo;
          aux->proximo = remover->proximo;
          lista->fim = aux;
        }
        else{
          remover = aux->proximo;
          aux->proximo = remover->proximo;
        }
        lista->tam--;
      }
    }
  }
  return remover;
}

No *buscar(Lista *lista, int num){
  No *aux = lista->inicio;
  if(aux){
    do{
      if(aux->valor == num){
        return aux;
      }
      aux = aux->proximo;
    }while (aux != lista->inicio);
  }
  return NULL;
}

// imprimir elementos na lista
void imprimir(Lista lista){
	No *no;
  no = lista.inicio;
	printf("Tamanho da lista: %d\n",lista.tam);
  printf("NO= %d", no->valor);
	if(no != NULL){
    printf("aqui\n");
    do{
      printf("%d ",no->valor);
      no = no->proximo;
    }while(no != lista.inicio);
  }
	printf("\n\n");
}

void criar_lista(Lista *lista){
  lista->inicio = NULL;
  lista->fim = NULL;
  lista->tam = 0;
}

int main(int argc, char *argv[]){
	Lista lista;
	//criar_lista(&lista);
  lista.inicio = NULL;
  lista.fim = NULL;
	lista.tam = 0;
	int op,valor;
	do{
		printf("0 - Sair\n1 - Inserir\n2 - Imprimir\n");
		scanf("%d",&op);
		switch(op){
			case 1:
				printf("Valor: ");
				scanf("%d",&valor);
				inserirInicio(&lista,valor);
        printf("# S = %d\n", lista.inicio->valor);
				break;
			case 2:
				imprimir(lista);
				break;
      default:
        break;
		}
	}while(op != 0);

	return 0;
}
