#include <stdio.h>
#define DEBUG 1

void sort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[5] = {1, 3, 2, 5, 4};
    int sum = 0;
    sort(arr, 5);
    for (int j = 3; j < 5; j += 3) {
        sum += arr[j];
    }
    printf("Sum : %d\n", sum);
#ifdef DEBUG
    printf("Sorted arr : ");
    for (int i = 0; i < 5; i++) {
        printf("%d", arr[i]);
    }
    printf("\n");
    printf("Elements divisible by 3 : ");
    for (int i = 0; i < 5; i++) {
        if (i % 3 == 0) {
            printf("%d", arr[i]);
        }
    }
#endif
}
