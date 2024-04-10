#include <stdio.h>
#include <stdlib.h>
#define MAX_LENGTH 15

void printLegend()
{
    printf("\n1 - Add student");
    printf("\n2 - Print Diary");
    printf("\n3 - exit");
}

typedef struct student{
    char  name[MAX_LENGTH + 1];
    int studentNum;
    double avgGrade;
}Student;


int addStudent(Student *students, int count)
{
    printf("Enter the Student's Name: ");
    scanf("%s", &students[count].name);
    printf("Enter the Student's Number: ");
    scanf("%d" ,&students[count].studentNum);
    printf("Enter the Student's Grade: ");
    scanf("%lf" ,&students[count].avgGrade);
}

void printDiary(const Student *students, const int count){
    if(count == 0){
        printf("\nNo students");
    }else{
    printf("\nDiary:");
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
                    printf("\nHandle the zero pouinter");
                    }
                addStudent(student, count);
                count++;
                break;
            case 2:
                printDiary(student, count);
                break;
            case 3:
                free(student);
                exit(0);
        }
    }

}
