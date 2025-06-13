#include <stdio.h>
#include <string.h>

int main() {
    float grade, sum = 0;
    int count = 0;
    char input[10];

    printf("Grade Calculator (Scale: 2-6)\n");
    printf("----------------------------\n");
    printf("Enter grades (type 'stop' to finish):\n");

    while (1) {
        printf("Enter grade: ");
        if (scanf("%s", input) == 1) {
            if (strcmp(input, "stop") == 0) {
                break;
            }
            
            if (sscanf(input, "%f", &grade) == 1) {
                if (grade >= 2 && grade <= 6) {
                    sum += grade;
                    count++;
                    printf("Grade %.2f added. Current average: %.2f\n", grade, sum/count);
                } else {
                    printf("Invalid grade! Please enter a number between 2 and 6.\n");
                }
            } else {
                printf("Invalid input! Please enter a number between 2 and 6 or 'stop'.\n");
            }
        }
    }

    if (count > 0) {
        printf("\nFinal Results:\n");
        printf("Total grades entered: %d\n", count);
        printf("Average grade: %.2f\n", sum/count);
    } else {
        printf("\nNo grades were entered.\n");
    }

    return 0;
}
