// Направете програма, която да предоставя на потребителя меню с три опции - добавяне на ученик, извеждане на списък със всички ученици и изход. При въвеждането на ученик трябва да се въведе ученик с име, което може да е до 15 символа, неговият номер в клас и средния му успех (променлива от тип double). За извеждането на ученици трябва да се принтира информация за всеки ученик от класа - неговото име, номер в клас и среден успех. За целта използвайте структура, която да пази информацията на масива и заделяне на динамична памет за масива от ученици.

#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 15

void printLegend()
{
    printf("1 - Add student");
    printf("\n2 - Print Diary");
    printf("\n3 - exit");
}

typedef struct student{
    char  name[MAX_LENGTH + 1];
    int studentNum;
    double avgGrade;
}Student;

//Don't know why it works ->
void addStudent(Student *students, int count)
{
    printf("\nEnter the Student's Name: ");
    scanf("%s", &students[count].name);
    printf("\nEnter the Student's Number: ");
    scanf("%d" ,&students[count].studentNum);
    printf("\nEnter the Student's Grade: ");
    scanf("%lf" ,&students[count].avgGrade);
    count++;
}

void printDiary(const Student *students, const int count){
    if(count == 0){
        printf("No students");
    }else{
    printf("Diary:");
    for(int i  = 0 ; i < count ; i++){
        printf("\nName : %s \nNumber:%d\nGrade:%lf\n",students[i].name,students[i].studentNum,students[i].avgGrade);
    }
    }
}

int main(void){
    int choice;
    int count = 0;
    Student *student = NULL;
    while (1)
    {
        printLegend();
        int command;
        printf("\nEnter the number of a command:");
        scanf("%d", &command);

        switch(command){
            case 1:
                student = realloc(student,(count+1)*sizeof(Student));
                if (student == NULL){
                    printf("Handle the zero pouinter");
                    }
                addStudent(student, count + 1);
                break;
            case 2:
                printDiary(student, count);
                break;
            case 3:
                exit(0);
        }
    }

}