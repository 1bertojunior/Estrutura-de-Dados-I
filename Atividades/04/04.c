#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define T 2

typedef struct {
    int id;
    char name[11];
    int qtdPeriods;
} Course;

typedef struct {
    int id;
    int fk_course;
    char name[21];
    int period;
    int workLoad;
} Discipline;

int partition(Course v[], int s, int e){
    int left, right, pivot;
    left = s; //start
    right = e; //rigth
    pivot = v[s].id; // primeira psoicção
    while(left < right){
        while(v[left].id <= pivot) left++;
        while(v[right].id > pivot) right--;
        if(left < right){
            Course aux;

            aux.id = v[left].id;
            strcpy(aux.name,v[left].name);
            aux.qtdPeriods = v[left].name;
            printf("%s\n",aux.name);

            v[left].id = v[right].id;
            strcpy(v[left].name, v[right].name);
            v[left].qtdPeriods = v[right].qtdPeriods;
            printf("%s\n",v[left].name);

            v[right].id = aux.id;
            strcpy(v[right].name, aux.name);
            v[right].qtdPeriods = aux.qtdPeriods;
            printf("%s\n",v[right].name);

            



        }
    }
    v[s].id = v[right].id;
    v[right].id = pivot;
    return right;

}

void quickSort(Course *v[], int s, int e){
    if(s<e){
        int pivot = partition(v,s,e);

        quickSort(v,s,pivot-1);
        quickSort(v,pivot+1,e);
    }
}

void menu(Course c[], Discipline d[], int t, int *ic, int *id){    
    int op;
    printf("[0] - Sair\n[1] - Add Curso\n[2] - Add Disciplina\n[3] - Menu2\n");
    printf("Opção: ");
    scanf("%d", &op);
    if(op ==10);
    
    if(op == 0) exit;
    if(op == 1) ler1(c,t, ic);
    if(op == 2) ler2(c, d,t, ic, id);
    if(op == 3) menu2(c,d, t, ic,id);
    if(op == 4) show1(c,0,t);
    if(op == 5) show2(d,0,t);

    printf("\n\n#não ordenado\n");
    show1(c,0,t);
    printf("\n\n#ordenado\n");
    quickSort(c,0,T);
    show1(c,0,t);

    //menu(c,d,t,ic,id);

}

void menu2(Course c[], Discipline d[], int t, int *ic, int *id){
    int op;
    printf("[0] - Voltar\n[1] - Curso com maior qtd de periodos\n[2] - Qtd disciplinas de um periodo\n[3] - Qtd discipplina de um periodo de um curso");
    printf("Opção: ");
    scanf("%d", &op);
    if(op ==0) menu(c,d,t, ic,id);
}

void ler1(Course v[],int t, int *ic){
    if(*ic <t){
        printf("Entre com os dados de %d cursos:\n", t);
        for(int i=0; i<t;i++){
            printf("# Dados do curso %d:\n", i+1);
            printf("Codigo: ");
            scanf("%d", &v[i].id);
            printf("Nome: ");
            scanf("%s", v[i].name);
            printf("Qtd de periodo: ");
            scanf("%d", &v[i].qtdPeriods);
            (*ic)++;
            printf("\nqtd cursos %d\n", *ic);
        }
    }else printf("# %d de %d cursos já cadastrados\n", *ic, t);
}

void ler2(Course c[], Discipline v[], int t, int *ic, int *id){
    if(*ic !=0 ){
        if(*id < t){
            for(int i=0; i<t;i++){
                int id_course;
                printf("# Dados da disciplina %d:\n", i+1);
                printf("Código do curso: ");
                scanf("%d", &id_course);
                if(checkCourse(c,0,t/2,id_course)){
                    v[i].fk_course = id_course;
                    printf("Codigo: ");
                    scanf("%d", &v[i].id);
                    printf("Nome: ");
                    scanf("%s", v[i].name);
                    printf("Período: ");
                    scanf("%d", &v[i].period);
                    printf("Carga horária: ");
                    scanf("%d", &v[i].workLoad);
                    
                    (*id)++;
                    printf("\nqtd dicisplina %d\n", *id);
                }else {
                    printf("Codigo de curso invalido, tente novamente!\n");
                    --i;
                }
            }
        }else printf("# %d de %d dicisplinas já cadastradss\n", *id, t);
    }else printf("Nenhum curso cadastrado!\n");

}

void show1(Course c[], int i, int t){
    if(i<t){
        printf("# Curso %d\n", i+1);
        printf("Codigo: %d\n", c[i].id);
        printf("Nome: %s\n", c[i].name);
        printf("Qtd de periodos: %d\n", c[i].qtdPeriods);
        show1(c,i+1,t);
    }
}

void show2(Discipline v[], int i, int t){
    if(i<t){
        printf("# Disciplina %d\n", i+1);
        printf("Nome: %s\n", v[i].name);
        printf("Codigo da disciplina: %d\n", v[i].id);
        printf("Codigo do curso: %d\n", v[i].fk_course);
        printf("Período: %d\n", v[i].period);
        printf("Carha horária: %d\n", v[i].workLoad);
        show2(v,i+1,t);
    }

}

int checkCourse(Course v[], int s, int e, int n){
    if(s > e) return 0;
    else{
        int i = (s+e)/2;
        if(v[i].id == n) return 1;
        else{
            if(n < v[i].id) return checkCourse(v,s,i-1,n);
            else return checkCourse(v,i+1,e,n);
        }
    }
}



void main(){

    Course c[T];
    Discipline d[T];
    int ic=0, id=0;
    
    menu(c,d,T, &ic, &id);
    
}