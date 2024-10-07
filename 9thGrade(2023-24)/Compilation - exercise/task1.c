// Write a program in which you define a macro function that takes two arguments (A and B) and finds the result of (A + B) ^ 2. Demonstrate the use of this macro in the main function. Run the preprocessing step for this program and upload its output in a separate file to the job.

#include <stdio.h>
#define SUM_SQUARE(A, B) ((A + B) * (A + B))

int main(void)
{
    int n1= 8;
    int n2 = 2;

    printf("%d", SUM_SQUARE(n1, n2));

    return 0;
}