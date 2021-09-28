#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define tamanho 5

typedef struct {
    char chassi[18];
    char placa[8];
    char modelo[10];
    char marca[10];
    char cor[10];
    int anoF;
}Carro;

typedef struct{
    Carro c[tamanho];
    int inicio;
    int fim;
    int qtd;
}Fila;
// ṕra fazer sentido fiz uma fila com n posições e dentro dessa fila tem um vetor tipo carro

int menu();
int menuzinho();
Carro desenfileirar(Fila *f);
Carro preenchecar();
int estacheia(Fila f);
int estavazia(Fila f);
void mostrarFila(Fila f);
void inicializarFila(Fila *f);
int consultaplaca(Fila *f, char placa[8], Fila *reserva, char chassi[18]);
void separarPeI(Fila *f,Fila *par,Fila *impar);
void imprimirUmCarro(Carro car);


// os casos que precisam de variáveis específicas estão sendo declaradas neles, como a senhora orientou
int main(){
    Fila f, par, impar;
    int op;
    inicializarFila(&f);
    inicializarFila(&par);
    inicializarFila(&impar);
    do{
        op = menu();
        switch (op){
            case 1:
                if(estacheia(f) == 1){
                    printf("Fila cheia\n");
                }else{
                    Carro car;
                    car = preenchecar();
                    enfileirar(&f,car);
                }    
            break;
            case 2:{
                int op;
                op = menuzinho();
                if(op == 1 && (estavazia(f)!=1)){
                    mostrarFila(f);
                }else if(op == 2 && (estavazia(par)!=1)){
                    mostrarFila(par); 
                }else if(op==3 && (estavazia(impar)!=1)){
                    mostrarFila(impar);   
                } else printf("Fila vazia\n");            
            }break;
            case 3:{
                Fila reserva;
                char placa[8], chassi[18];
                inicializarFila(&reserva);
                printf("Placa: ");
                scanf("%s",placa);
                if(consultaplaca(&f,placa,&reserva,chassi)==1){
                    printf("Chassi = %s\n", chassi);
                }else{
                    printf("Carro nao encontrado\n");
                } 
            }
            break;
            case 4:{
                Carro car;
                car = desenfileirar(&f);  
                imprimirUmCarro(car);
            }
            break;
            case 5:
                if(estavazia(f)==1){
                    printf("Fila vazia\n");
                }else{
                    separarPeI(&f,&par,&impar);
                }
            break;        
        }
    }while(op != 6);
    return 0;
}
int menuzinho(){
    int op;
    do{
        printf("[1] - Fila Original\n[2] - Fila Par\n[3] - Fila Impar\n");
        scanf("%d", &op);
    }while((op < 1)||(op > 3));
    return op;
}

int menu(){
    int op;
    do{
        printf("[1] - Inserir\n[2] - Imprimir\n[3] - Consultar Chassi\n[4] - Remover\n[5] - Separar (pares e impares)\n[6]Sair\n");
        scanf("%d", &op);
    }while((op < 1)||(op > 6));
    return op;
}



//ao começar inicializo todas as filas, e reinicializo a fila f quando depois de vazia eu vou preencher novamente 
void inicializarFila(Fila *f){
    f -> inicio = 0;
    f -> fim = -1;
    f -> qtd = 0;
}

void enfileirar(Fila *f, Carro car){
    
    if (f -> qtd < tamanho){
        f -> fim ++;
        f -> c[f->fim] = car;
        f -> qtd++;
        
    }
}

int consultaplaca(Fila *f, char placa[8], Fila *reserva, char chassi[18]){
    int encontrou = 0;
    Carro x;
    while ((*f).inicio <= (*f).fim){
        x = desenfileirar(f);
       
        if(strcmp(x.placa,placa) == 0){
            strcpy(chassi,x.chassi); // retirado da fila
            encontrou = 1;
        }else{
            enfileirar(reserva,x); // quando não era a que eu procurava eu enfileiro em uma fila auxiliar
        }
    }
    
    inicializarFila(f);// reinicializo pois minha fila é linear e não circular
    while ((*reserva).inicio <= (*reserva).fim){
        x = desenfileirar(reserva); // desenfileiro a fila auxiliar
        enfileirar(f,x); // e enfileiro cada elemento de volta da fila original
    }
    
    return encontrou; // se não encontrou eu imprimo isso no main
}
// imprime qualquer fila
void mostrarFila(Fila f){
    while(f.inicio <= f.fim){
        printf("Chassi: %s\n", f.c[f.inicio].chassi);
        printf("Placa: %s\n", f.c[f.inicio].placa);
        printf("Modelo: %s\n", f.c[f.inicio].modelo);
        printf("Marca: %s\n", f.c[f.inicio].marca);
        printf("Cor: %s\n",f.c[f.inicio].cor);
        printf("ano de fabricação: %d\n",f.c[f.inicio].anoF);
        f.inicio++;
    }
    printf("\n");
}
//imprime um carro adicionei para verificar o código

void imprimirUmCarro(Carro car){
    printf("Chassi: %s\n", car.chassi);
    printf("Placa: %s\n", car.placa);
    printf("Modelo: %s\n", car.modelo);
    printf("Marca: %s\n", car.marca);
    printf("Cor: %s\n",car.cor);
    printf("ano de fabricação: %d\n",car.anoF);
}

int estavazia(Fila f){
    if(f.qtd == 0){
        return 1;
    }else{
        return 0;
    }
}

// poderia ser apenas uma função (cheia ou vazia), não sei se tornaria o código mais eficiente
// mas poderia retornar a quantidade ou mesmo verificar lá no menu
// depois vejo c a senhora

int estacheia(Fila f){
    if(f.qtd == tamanho){
        return 1;
    }else{
        return 0;
    }
}
// retorna um tipo carro preenchido para ser enfileirado
// tinha retornado por parâmetro, mas deu problema na hora de ler o inteiro ano de fabricação com asterísco do ponteiro
// aí assim resolvi meu estresse

Carro preenchecar(){
    Carro car;
    printf("Chassi: ");
    scanf("%s",car.chassi);
    printf("Placa: ");
    scanf("%s",car.placa);
    printf("Modelo: ");
    scanf("%s",car.modelo);
    printf("Marca: ");
    scanf("%s",car.marca);
    printf("Cor: ");
    scanf("%s",car.cor);
    printf("ano de fabricação: ");
    scanf("%d",&car.anoF);
    return car;
}
// retorno o carro retirado da fila para ser impresso lá no main
Carro desenfileirar(Fila *f){
    Carro retorno = f -> c[f-> inicio];
    f -> inicio++;
    f -> qtd--;
    return retorno;    
}

// vou desenfileirando e colocado o dado nas novas filas 
// comparo a posição do último número da placa, usando char como inteiro 
// inspirada na questão do binário
void separarPeI(Fila *f,Fila *par,Fila *impar){
    Carro car;
    while ((*f).inicio <= (*f).fim){
        car = desenfileirar(f);
        if((car.placa[6]-48)%2  == 0){
            enfileirar(par,car);
        }else{
            enfileirar(impar,car);
        }
    }
}

