#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define T 3

typedef struct {
    int registration;
    char name[31];
    char course[21];
    int period;
} Student;

void ler(Student v[],int t){
    for(int i=0; i<t;i++){
        printf("# Dados do aluno %d:\n", i+1);
        printf("Matricula: ");
        scanf("%d", &v[i].registration);
        printf("Nome: ");
        scanf("%s", v[i].name);
        printf("Curso: ");
        scanf("%s", v[i].course);
        printf("Periodo: ");
        scanf("%d", &v[i].period);
    }
}

void show(Student v[], int i, int t){
    if(i<t){
        printf("# Aluno %d\n", i+1);
        printf("Matricula: %d\n", v[i].registration);
        printf("Nome: %s\n", v[i].name);
        printf("Curso: %s\n", v[i].course);
        printf("Periodo: %d\n", v[i].period);
        show(v,i+1,t);
    }
}

void show2(char n[][31], int i, int t){ 
    if(i<t){
        printf("%s\n", n[i]);
        show2(n,i+1,t);
    }
}

void insertionSort(Student v[], int i,int j, int s, int e){
    Student a;
    if(j< e){
        if(v[i].registration > v[j].registration){
            a.registration = v[i].registration;
            v[i].registration = v[j].registration;
            v[j].registration = a.registration;
    
            strcpy(a.name, v[i].name);
            strcpy(v[i].name, v[j].name);
            strcpy(v[j].name, a.name); 
            
            strcpy(a.course, v[i].course);
            strcpy(v[i].course, v[j].course);
            strcpy(v[j].course, a.course); 
            
            a.period = v[i].period;
            v[i].period = v[j].period;
            v[j].period = a.period;

            if(i > s) insertionSort(v,i-1,i,s,e);
            else insertionSort(v, j, j+1,s,e);
        }
        insertionSort(v,j,j+1,s,e);
    }
}

void getStudentsOfOnePeriod(Student v[], char v2[][31], int s, int e, int n, int *i){
    if(s<e){
        if(v[s].period == n) strcpy(v2[(*i)++], v[s].name);
        getStudentsOfOnePeriod(v,v2,s+1,e,n,i);
    }
}

void getQtdStudentsByCourse(Student v[], int s, int e, char c[], int *n){
    if(s<e){
        if(strcmp(v[s].course,c)==0) {
            printf("%s\n", v[s].name);
            (*n)+=1;
        }
        getQtdStudentsByCourse(v,s+1,e,c,n);
    }
}

int getStudentByRegistration(Student v[], int s, int e, int n){
    if(s > e) return 0;
    else{
        int i = (s+e)/2;
        if(v[i].registration == n) return i;
        else{
            if(n < v[i].registration) return getStudentByRegistration(v,s,i-1,n);
            else return getStudentByRegistration(v,i+1,e,n);
        }
    }
}


int main(){

    Student students[T];
    int i=0, n=0;
    char studentsOfOnePeriod[T][31], c[31];

    printf("Entre com os dados de %d alunos:\n", T);
    ler(students,T);
    printf("Alunos cadastrados:\n");
    show(students,0,T);
    printf("\n");

    insertionSort(students,0,1,0,T);
    printf("Alunos ordenados por matricula:\n");
    show(students,0,T);
    printf("\n");

    printf("# Nome dos alunos de um determinado período\nPeriodo: ");
    scanf("%d", &n);
    printf("# Alunos do período %d:\n", n);
    getStudentsOfOnePeriod(students,studentsOfOnePeriod, 0, T, n,&i);
    if(i>0)show2(studentsOfOnePeriod,0,T);
    i=0;
    n=0;
    printf("\n");

    printf("# Quantidade de alunos de um determinado curso\nCurso: ");
    scanf("%s", c);
    getQtdStudentsByCourse(students,0,T,c,&n);
    printf("# Qtd de alunos do curso %s: ", c);
    printf("%d\n", n);
    n=0;
    printf("\n");

    printf("# Dados de um aluno dado a matrícula\nMatricula: ");
    scanf("%d", &n);
    printf("# Dados de um aluno da matrícula %d\n",n);
    n = getStudentByRegistration(students,0,T,n);
    printf("Matricula: %d\n", students[n].registration);
    printf("Nome: %s\n", students[n].name);
    printf("Curso: %s\n", students[n].course);
    printf("Periodo: %d\n", students[n].period);

    return 0;
}