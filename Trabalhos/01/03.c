#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define T 6

typedef struct {
    int id;
    char name[200];
    int qtdPeriods;
    int workLoad;
    char shift[200];
} Course;

typedef struct{
    int id;
    int fkCourse;
    char name[100];
    int period; 
    int workLoad;
} Discipline;

void menu(Course c[], Discipline d[], int *cc, int *dc, int t);
void setCourse(Course c[], int *cc, int t);
void getCourse(Course c[], int i);
void showAllCourse(Course c[], int t);
int getCourseById(Course c[], int s, int e, int n);
void getCourseByShift(Course c[], int s, int e, int i, char str[]);
void removeCourseById(Course c[], int s, int e, int *cc);
void swapCourse(Course c[], int i, int j);
void quickSortCourse(Course c[], int s, int e);
int partitionCourse(Course c[], int s, int e);
void setDiscipline(Discipline d[], Course c[], int *dc, int *cc, int t);
void getDiscipline(Discipline d[], int i);
void showAllDiscipline(Discipline d[], int t);
void getDisciplineByCourse(Discipline d[], int s, int e, int i, int n);
void getDisciplineByPeriod(Discipline d[], int s, int e, int i, int n);
void removeDisciplineById(Discipline d[], int s, int e, int *dc);
void swapDiscipline(Discipline d[], int i, int j);
void quickSortDiscipline(Discipline d[], int s, int e);
int partitionDiscipline(Discipline d[], int s, int e);
int getDisciplineById(Discipline d[], int s, int e, int n);
int getQtdDisciplineByCourse(Course c[], Discipline d[], int s, int e, int n);
int checkMulti15(int n);

int main(){

    Course c[T];
    Discipline d[T];
    int op=0, cc=0, dc=0;

    menu(c, d, &cc, &dc, T);

    return 0;
}

void menu(Course c[], Discipline d[], int *cc, int *dc, int t){
    int op;
   
    do{
        printf("\n");
        printf("[0] - Exit\n[1] - Cadastrar curso\n[2] - Cadastrar disciplina\n[3] - Mostrar um curso\n[4] - Mostrar uma disciplina\n[5] - Cursos por turno\n[6] - Disciplinas de um Curso\n[7] - Disciplina por período\n[8] - Remover uma disciplina\n[9] - Remover curso\n[10] - All cursos\n[11] - ALl disciplinas\n");
        printf("OPÇÃO: ");
        scanf("%d", &op);

        if(op == 1) {
            setCourse(c,cc,t);
            quickSortCourse(c,0,*cc-1);
        }
        if(op == 2) {
            setDiscipline(d,c, dc, cc, t);
            quickSortDiscipline(d,0,*dc-1); 
        }
        if(op == 3) {
            if(*cc>0){
                int id;
                printf("Codigo do curso: ");
                scanf("%d", &id);
                id = getCourseById(c,0,*cc,id);
                if( id == -1) printf("Curso não encontrado! :(\n");
                else getCourse(c,id);
            }else printf("[!] Nenhum curso cadastrado!\n");
        }
        if(op == 4){
            if(*dc){
                int id;
                printf("Codigo da disciplina: ");
                scanf("%d", &id);
                id = getDisciplineById(d,0,*dc, id);
                if( id == -1) printf("Disiciplina não encontrada! :(\n");
                else getDiscipline(d,id);
            }else printf("[!] Nenhuma disciplina cadastrada!\n");
        }
        if(op == 5) {
            if(*cc>0){
                char str[100];
                printf("Turno: ");
                scanf(" %[^\n]", str);
                getCourseByShift(c,0,*cc,0,str);
            }else printf("[!] Nenhum curso cadastrado!\n");
        }
        if(op == 6){
            if(*dc>0){
                int n;
                printf("Código do curso: ");
                scanf("%d", &n);
                getDisciplineByCourse(d,0,*dc, 0,n);
            }else printf("[!] Nenhum disciplina cadastrada!\n");
        }
        if(op == 7){
            if(*dc>0){
                int n;
                printf("Período: ");
                scanf("%d", &n);
                getDisciplineByPeriod(d,0,*dc, 0,n);
            }else printf("[!] Nenhum disciplina cadastrada!\n");

        }
        if(op == 8){
            if(*dc>0){
                int n;
                printf("Código da disciplina: ");
                scanf("%d", &n);
                n = getDisciplineById(d,0,*dc,n);
                if(n != -1){
                    removeDisciplineById(d,n,*dc,dc);
                    *dc -= 1;
                    printf("Sucess!\n");
                }else printf("Disciplina não encontrada!\n");  
            }else printf("[!] Nenhum disciplina cadastrada!\n"); 
        }
        if(op == 9){
            if(*cc>0){
                int n, id;
                printf("Código do curso: ");
                scanf("%d", &n);
                id = getCourseById(c,0,*cc,n);
                if(id != -1){
                    if(getQtdDisciplineByCourse(c,d,0,*cc,n) == 0) {
                        removeCourseById(c,id,*cc,cc);
                        printf("Sucess!\n");
                        *cc-=1;
                    }else printf("[!] ERRO! O curso possuí disciplinas cadastradas!\n");               
                }else printf("Curso não encontrado!\n");
            }else printf("[!] Nenhum curso cadastrado!\n");
        }
        
        if(op == 10) showAllCourse(c,*cc);
        if(op == 11) showAllDiscipline(d,*dc);

    }while(op!=0);
}

void setCourse(Course c[], int *cc, int t){
    if(*cc < t){
        int id;
        printf("# Curso %d!\n", *cc+1);
        printf("Código: ");
        scanf("%d", &id);
        if(getCourseById(c,0,*cc,id) == -1){
            c[*cc].id = id;
            printf("Nome: ");
            scanf(" %[^\n]", c[*cc].name);
            printf("Qtd de periodos: ");
            scanf("%d", &c[*cc].qtdPeriods);
            printf("Carga horária: ");
            scanf("%d", &c[*cc].workLoad);
            printf("Turno: ");
            scanf(" %[^\n]", c[*cc].shift);
            *cc +=1;
        }else{
            printf("Código já cadastrado! Tente outro.\n");
            setCourse(c,cc,t);
        }
       
    }else printf("# %d de %d cursos já foram cadastrados!\n", *cc, t);
    
}

void getCourse(Course c[], int i){
    printf("# CURSO\n");
    printf("Código = %d\n", c[i].id);
    printf("Nome = %s\n", c[i].name);
    printf("Qtd de periodos = %d\n", c[i].qtdPeriods);
    printf("Carga horária = %d\n", c[i].workLoad);
    printf("Turno = %s\n\n", c[i].shift);
}

void showAllCourse(Course c[], int t){
    for(int i=0; i< t; i++) getCourse(c,i);
}

int getCourseById(Course c[], int s, int e, int n){
    if(s > e) return -1;
    else{
        int i = (s+e)/2;
        if(c[i].id == n) return i;
        else{
            if(n < c[i].id) return getCourseById(c,s,i-1,n);
            else return getCourseById(c,i+1,e,n);
        }
    }
}

void getCourseByShift(Course c[], int s, int e, int i, char str[]){
    if(s<e){
        if(strcmp(c[s].shift, str) == 0) {
            getCourse(c,s);
            i=1;
        }
        getCourseByShift(c,s+1,e,i,str);
    }else if(!i) printf("# Nenhum curso encontrado!");
}

void removeCourseById(Course c[], int s, int e, int *cc){
    if(s<e-1){
        swapCourse(c,s,s+1);
        removeCourseById(c,s+1,e,cc);
    }
}

void swapCourse(Course c[], int i, int j){
    Course a;

    a.id = c[i].id;
    strcpy(a.name, c[i].name);
    a.qtdPeriods = c[i].qtdPeriods;
    a.workLoad = c[i].workLoad;
    strcpy(a.shift, c[i].shift);

    c[i].id = c[j].id;
    strcpy(c[i].name, c[j].name);
    c[i].qtdPeriods = c[j].qtdPeriods;
    c[i].workLoad = c[j].workLoad;
    strcpy(c[i].shift, c[j].shift);

    c[j].id = a.id;
    strcpy(c[j].name, a.name);
    c[j].qtdPeriods = a.qtdPeriods;
    c[j].workLoad = a.workLoad;
    strcpy(c[j].shift, a.shift);
}

void quickSortCourse(Course c[], int s, int e){
    int p;
    if(s<e){
        p = partitionCourse(c,s,e);
        quickSortCourse(c,s, p-1); // sub lista com os elementos da esquerda
        quickSortCourse(c,p+1,e); // sub lista com os elementos da direita
    }
}

int partitionCourse(Course c[], int s, int e){
    int p = c[e].id; // pivô - ultimo elemnto
    int i = s; // barra amerela, vai inciar com o inicio "s"

    // barra roxa, vai comecar com o inicio, mas vai terminar logo antes do fim "e"
    for(int j=i; j<e; j++){ // pq o último é o pivô
        if(c[j].id <= p){ // comparação do elemento j com o pivô
            swapCourse(c,i,j); // troca entre o j e a area dos elemntos menores
            i++;
        }
    }

    // 8 10 5
    // 
    
    swapCourse(c,i,e); // por último, jogar o pivo no meio entre os menores e os maiores

    return i; // retornar a psoição do pivo
}

void setDiscipline(Discipline d[], Course c[], int *dc, int *cc, int t){
     if(*dc < t){
        Discipline a;
        int id;
        printf("# Disciplina %d!\n", *dc+1);
        printf("Codigo: ");
        scanf("%d", &a.id);
        if(getDisciplineById(d,0,*dc,a.id) == -1){
            d[*dc].id = a.id;
            do{
                printf("Codigo do curso: ");
                scanf("%d", &a.fkCourse);
                id = getCourseById(c,0,*cc,a.fkCourse);
            }while(id == -1);
            d[*dc].fkCourse = a.fkCourse;
            printf("Nome: ");
            scanf(" %[^\n]", d[*dc].name);
            do{
                printf("Periodo: ");
                scanf("%d", &a.period);
            }while(a.period > c[id].qtdPeriods);
            d[*dc].period = a.period;
            do{
                printf("Carga horária (Multi de 15): ");
                scanf("%d", &a.workLoad);
            }while( a.workLoad <= 0 || !checkMulti15(a.workLoad));
            d[*dc].workLoad = a.workLoad;
            printf("Success!");


            *dc += 1;

        }else{
            printf("Codigo já cadastrado! Tente outro.\n");
            setDiscipline(d,c, dc, cc,t);
        }
     }
}

void getDiscipline(Discipline d[], int i){
    printf("# DISCIPLINAS\n");
    printf("Código = %d\n", d[i].id);
    printf("Curso = %d\n", d[i].fkCourse);
    printf("Nome = %s\n", d[i].name);
    printf("Periodo = %d\n", d[i].period);
    printf("Carg horária = %d\n", d[i].workLoad);
}

void showAllDiscipline(Discipline d[], int t){
    for(int i=0; i<t; i++) getDiscipline(d, i); 
}

void getDisciplineByCourse(Discipline d[], int s, int e, int i, int n){
    if(s<e){
        if(d[s].fkCourse == n) {
            getDiscipline(d,s);
            i=1;
        }
        getDisciplineByCourse(d,s+1,e,i,n);
    }else if(!i) printf("# Nenhuma disciplina encontrada!");
}

void getDisciplineByPeriod(Discipline d[], int s, int e, int i, int n){
    if(s<e){
        if(d[s].period == n) {
            getDiscipline(d,s);
            i=1;
        }
        getDisciplineByPeriod(d,s+1,e,i,n);
    }else if(!i) printf("# Nenhuma disciplina encontrada!");
}

void removeDisciplineById(Discipline d[], int s, int e, int *dc){
    if(s<e-1){
        swapDiscipline(d,s,s+1);
        removeDisciplineById(d,s+1,e,dc);
    }

}

void swapDiscipline(Discipline d[], int i, int j){
    Discipline a;

    a.id = d[i].id;
    a.fkCourse = d[i].fkCourse;
    strcpy(a.name, d[i].name);
    a.period = d[i].period;
    a.workLoad = d[i].workLoad;

    d[i].id = d[j].id;
    d[i].fkCourse = d[j].fkCourse;
    strcpy(d[i].name, d[j].name);
    d[i].period = d[j].period;
    d[i].workLoad = d[j].workLoad;

    d[j].id = a.id;
    d[j].fkCourse = a.fkCourse;
    strcpy(d[j].name, a.name);
    d[j].period = a.period;
    d[j].workLoad = a.workLoad;
}

void quickSortDiscipline(Discipline d[], int s, int e){
    int p;
    if(s<e){
        p = partitionDiscipline(d,s,e);
        quickSortDiscipline(d,s,p-1);
        quickSortDiscipline(d, p+1, e);
    }
}

int partitionDiscipline(Discipline d[], int s, int e){
    int p = d[e].id;
    int i = s;

    for(int j=s; j<e; j++){
        if(d[j].id < p){
            swapDiscipline(d,i,j);
            i++;
        }
    }

    swapDiscipline(d,i,e);

    return i;
}

int getDisciplineById(Discipline d[], int s, int e, int n){
    if(s > e) return -1;
    else{
        int i = (s+e)/2;
        if(d[i].id == n) return i;
        else{
            if(n < d[i].id) return getDisciplineById(d,s,i-1,n);
            else return getDisciplineById(d,i+1,e,n);
        }
    }
}

int getQtdDisciplineByCourse(Course c[], Discipline d[], int s, int e, int n){
    int r = 0;
    if(s<e){
        if(d[s].fkCourse == n) r = getQtdDisciplineByCourse(c,d,s+1,e,n)  + 1;
        else r = getQtdDisciplineByCourse(c,d,s+1,e,n);
    }
    return r;
}

int checkMulti15(int n){
    return n%15 == 0 ? 1 : 0;
}