#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;
    float *avg = (float *)malloc(sizeof(float));
    *avg = 0;
    printf("Number of grades:");
    scanf("%d", &count);
    if (count < 1) exit(1);
    float *grades = (float *)calloc(count, sizeof(float));

    if (grades == NULL) {
        printf("Error\n");
        return 1;
    }

    for (int i = 0; i < count; i++) {
        printf("Grade %d:", i + 1);
        scanf("%f", &grades[i]);
    }

    while (1) {
        printf("1.AVG\n");
        printf("2.Add grade\n");
        printf("3.Remove grade\n");
        printf("4.Exit\n");

        int choice;
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                float sum = 0;
                for (int i = 0; i < count; i++) {
                    sum += grades[i];
                }
                *avg = sum / count;
                printf("AVG: %f\n", *avg);
                break;
            }
            case 2: {
                count += 1;
                float *temp = (float *)realloc(grades, count * sizeof(float));
                if (temp != NULL) {
                    grades = temp;
                    printf("New grade : \n");
                    scanf("%f", &grades[count - 1]);
                } else {
                    printf("Error\n");
                    return 1;
                }
                break;
            }
            case 3: {
                if (count > 0) {
                    count -= 1;
                    float *temp = (float *)realloc(grades, count * sizeof(float));
                    if (temp != NULL) {
                        grades = temp;
                    } else {
                        printf("Error\n");
                        return 1;
                    }
                } else {
                    printf("No grades\n");
                }
                break;
            }
            case 4:
                free(grades);
                free(avg);
                return 0;
            default:
                break;
        }
    }
    return 0;
}
