// main.c
#include "quadraticroots.h"
#include <stdio.h>

int main() {
    QuadraticRootsResult result1 = findroots(1, -3, 2);
    QuadraticRootsResult result2 = findroots(1.0f, -3.0f, 2.0f);
    QuadraticRootsResult result3 = findroots(1.0, -3.0, 2.0); 

    printf("Result 1: x1 = %lf, x2 = %lf, norealroots = %d\n", result1.x1, result1.x2, result1.norealroots);
    printf("Result 2: x1 = %lf, x2 = %lf, norealroots = %d\n", result2.x1, result2.x2, result2.norealroots);
    printf("Result 3: x1 = %lf, x2 = %lf, norealroots = %d\n", result3.x1, result3.x2, result3.norealroots);

    return 0;
}
