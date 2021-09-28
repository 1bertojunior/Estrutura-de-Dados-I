#include<stdio.h>
#include <string.h>

typedef struct{
    int registration;
    char name[20];
    int age;
    float height;
} Student;


void tallestStudent(Student a[], int qtdStudents, float *studentHeight);
int ageOfShortestStudent(Student a[],int qtdStudents);
float averageStudentHeight(Student a[], int qtdStudents, char names[100][20]);

int main(){

    int i, qtdStudents, lowestStudentAge;
    float studentHeight = 0;
    char namesAverageStudentHeight[100][20];

    printf("Quantidade de alunos que vai adiconar: ");
    scanf("%d", &qtdStudents);

    Student alunos[qtdStudents];

    for(i=0; i <qtdStudents; i++){
        printf("Matricula: ");
        scanf("%d", &alunos[i].registration);
        printf("Nome: ");
        scanf(" %[^\n]s", &alunos[i].name);
        printf("Idade: ");
        scanf("%d", &alunos[i].age);
        printf("Altura: ");
        scanf("%f", &alunos[i].height);
    }

    //aluno mais alto
    tallestStudent(alunos, qtdStudents, &studentHeight);
    printf("Altura do aluno mais alto = %d\n", studentHeight);
    lowestStudentAge = ageOfShortestStudent(alunos, qtdStudents);
    printf("Idade do aluno mais baixo = %d\n", lowestStudentAge);
    printf("M = %.2f\n", averageStudentHeight(alunos, qtdStudents,namesAverageStudentHeight));
    printf("Nome dos alunos que tem a altura mediana:\n");

    for(i=0; strcmp(namesAverageStudentHeight[i], "") != 0; i++) printf("%s\n",namesAverageStudentHeight[i]);
    
    return 0;
}
//AS FUNÇÕES IMPLEMENTADAS ABAIXO RECEBEM UM ARRAY DE ALUNOS E QUANTIDADE DE ALUNOS

// FUNÇÃO QUE DEVOLVER POR PARÂMETRO A ALTURA DO ALUNO MAIS ALTO.  
// RECEBE COMO TERCEIO PARÂMETRO UM ENDEREÇO DE MEMÓRIA NO QUAL SERÁ RETORNADO A ALTURA
void tallestStudent(Student a[], int qtdStudents, float *studentHeight){
    for(int i=0; i<qtdStudents; i++) *studentHeight = a[i].height > *studentHeight ? a[i].height : *studentHeight;
}
//FUNÇÃO QUE DEVOLVE PELA FUNÇÃO (RETURN) A IDADE DO ALUNO MAIS BAIXO
int ageOfShortestStudent(Student a[],int qtdStudents){
    int shortestStudent = a[0].height, age = a[0].age;
    for(int i=1; i<qtdStudents; i++) {
        if(a[i].height < shortestStudent){
            shortestStudent = a[i].height;
            age = a[i].age;
        }
    }
    return age;
}
// FUNÇÃO QUE DEVOLVER A MÉDIA DA ALTURA DOS ALUNOS PELA FUNÇÃO E OS NOMES DOS ALUNOS QUE TEM A ALTURA MEDIA POR PARÂMETRO
// A FUNÇÃO RECEBE COMO TERCEIRO PARÂMETRO O ARRAY DE NOMES NO QUAL SERÁ RETORNAMO OS NOMES 
float averageStudentHeight(Student a[], int qtdStudents, char names[100][20]){
    int i, j=0;
    float  m =0;
    for(i=0; i<qtdStudents; i++) m+= a[i].height;
    m = m/qtdStudents;

    for(i=0; i<qtdStudents; i++) {
        if(a[i].height == m) {
            strcpy(names[j], a[i].name);
            j++;
        }
    }
 
    return m;
}