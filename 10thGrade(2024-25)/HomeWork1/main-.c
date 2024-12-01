#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, unsigned int count);
int getNumber(int num, int pos);
void radixSort(int* arr, unsigned int count);

int main(void) {
    // int arr[] = {1, 0, 31, 512, 3, 53, 23, 132, 432, 41, -5, -32, -100, -7};
    // int arr[] = {61, 102, 13, 5, -6, -3};
    // int arr[] = {1, 1, 1, 1, 1, 1}; 
    int arr[] = {-100, -32, -5, -7}; 
    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    // int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 
    // int arr[] = {};
    // int arr[] = {100000, 500000, 100000, 2000000, 3000};
    int count = sizeof(arr) / sizeof(int);

    printf("Original array: ");
    printArray(arr, count);
    printf("\n");

    radixSort(arr, count);

    printf("Sorted array: ");
    printArray(arr, count);
    printf("\n");

    return 0;
}

void printArray(int* arr, unsigned int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getNumber(int num, int pos) { //dqsno na lqwo
    switch (pos) {
        case 1:
            return num % 10;
        case 2:
            return (num / 10) % 10;
        case 3:
            return (num / 100) % 10;
        default:
            return -1;
    }
}


// Избрах да сортирам от LSB към MSB, понеже не иска да се знае максималната дължина на числата.

void radixSort(int* arr, unsigned int count) {
    static int pos = 1; 

    if (pos > 3) {  
        // pos = 1; 
        return;
    }

    int* buckets[19];     
    int bucketCount[19] = {0}; 

    for (int i = 0; i < 19; i++) {
        buckets[i] = malloc(count * sizeof(int));
    }

    printf("Sorting by digit position: %d\n", pos);

    for (int i = 0; i < count; i++) {
        int digit = getNumber(arr[i], pos);
        int bucketIndex = digit + 9; 
        int index = bucketCount[bucketIndex];
        buckets[bucketIndex][index] = arr[i];
        bucketCount[bucketIndex] += 1;
    }

    int index = 0;
    for (int i = 0; i < 19; i++) {
        for (int j = 0; j < bucketCount[i]; j++) {
            arr[index] = buckets[i][j];
            index++;
        }
    }

    for (int i = 0; i < 19; i++) {
        free(buckets[i]);
    }

    printArray(arr, count);

    pos++;  
    radixSort(arr, count);  
}
