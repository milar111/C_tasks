#include <stdio.h>
#include <math.h>
#define SIZE 5

void stepen4(long arr[]) {
    for (int i = 0; i < SIZE; i++) {
        arr[i] = pow(arr[i], 4);
    }
}

int main() {

    long arr[] = {1, 2, 3, 4, 5};

    stepen4(arr);

    for (int i = 0; i < SIZE; i++) {
        printf("%ld ", arr[i]);
    }

    return 0;
}
