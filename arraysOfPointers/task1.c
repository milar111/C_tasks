#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SUBJECTS 10
#define MAX_NAME_LENGTH 15

void remove_newline(char *str) {
    char *newline = strchr(str, '\n');
    if (newline != NULL) {
    *newline = '\0';
}
}

int main() {
    int num_subjects, num_students = 0;
    char **subjects = malloc(MAX_SUBJECTS * sizeof(char*));
    for (int i = 0; i < MAX_SUBJECTS; i++) {
        subjects[i] = malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
    }

    printf("Enter the number of subjects: ");
    scanf("%d", &num_subjects);
    getchar();

    if (num_subjects <= 0) {
        printf("Error: Number of subjects must be a positive integer.\n");
        return 1;
    }

    printf("Enter the names of the subjects:\n");
    for (int i = 0; i < num_subjects; i++) {
        fgets(subjects[i], MAX_NAME_LENGTH + 1, stdin);
        remove_newline(subjects[i]);
    }

    char **students = NULL;
    int **grades = NULL;
    int *total_grades = NULL;

    int choice;
    do {
        printf("\nMenu:\n1. Enter a student\n2. Print diary\n3. Exit\nEnter your choice: ");
        scanf("%d", &choice);
        getchar();

        if (choice == 1) {
            students = realloc(students, (num_students + 1) * sizeof(char*));
            students[num_students] = malloc((MAX_NAME_LENGTH + 1) * sizeof(char));
            printf("Enter student's name: ");
            fgets(students[num_students], MAX_NAME_LENGTH + 1, stdin);
            remove_newline(students[num_students]);

            grades = realloc(grades, (num_students + 1) * sizeof(int*));
            grades[num_students] = malloc(num_subjects * sizeof(int));

            printf("Enter grades for each subject:\n");
            int sum_grades = 0;
            for (int i = 0; i < num_subjects; i++) {
                scanf("%d", &grades[num_students][i]);
                sum_grades += grades[num_students][i];
            }
            total_grades = realloc(total_grades, (num_students + 1) * sizeof(int));
            total_grades[num_students] = sum_grades;

            num_students++;
        } else if (choice == 2) {
            printf("%-15s", "");
            for (int i = 0; i < num_subjects; i++) {
                printf("%-15s", subjects[i]);
            }
            printf("%-15s\n", "AVG");

            for (int i = 0; i < num_students; i++) {
                printf("%-15s", students[i]);
                for (int j = 0; j < num_subjects; j++) {
                    printf("%-15d", grades[i][j]);
                }
                float avg_grade = (float)total_grades[i] / num_subjects;
                printf("%-15.2f\n", avg_grade);
            }
        } else if (choice == 3) {
            for (int i = 0; i < MAX_SUBJECTS; i++) {
                free(subjects[i]);
            }
            free(subjects);
            for (int i = 0; i < num_students; i++) {
                free(students[i]);
                free(grades[i]);
            }
            free(students);
            free(grades);
            free(total_grades);
        } else {
            printf("Invalid choice. Please enter a number between 1 and 3.\n");
        }
    } while (choice != 3);

    return 0;
}
