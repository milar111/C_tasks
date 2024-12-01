#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, unsigned int count);
int getNumber(int num, int pos);
void radixSort(int* arr, unsigned int count);
void sortByDigit(int* arr, int count, int pos);

int main(void) {
    int arr[] = {1, 0, 31, 512, 3, 53, 23, 132, 432, 41, -5, -32, -100, -7};
    // int arr[] = {1, 1, 1, 1, 1, 1}; // Повтарящи се стойности
    // int arr[] = {-100, -32, -5, -7}; // Отрицателни стойности
    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; // Сортиран възходящо
    // int arr[] = {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; // Сортиран низходящо
    // int arr[] = {};
    // int arr[] = {100000, 500000, 1000000, 2000000, 3000000};
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

int getNumber(int num, int pos) {
    switch(pos){
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

void sortByDigit(int* arr, int count, int pos) {
    int* temp = malloc(count * sizeof(int));
    int index = 0;

    for (int digit = 0; digit < 10; digit++) {
        for (int j = 0; j < count; j++) {
            if (getNumber(arr[j], pos) == digit) {
                temp[index++] = arr[j];
            }
        }
    }

    for (int i = 0; i < count; i++) {
        arr[i] = temp[i];
    }
    free(temp);
}

void radixSort(int* arr, unsigned int count) {
    int* negArr = malloc(count * sizeof(int)); 
    int* posArr = malloc(count * sizeof(int)); 
    
    int negCount = 0;
    int posCount = 0;

    for (int i = 0; i < count; i++) {
        if (arr[i] < 0) {
            negArr[negCount++] = -arr[i]; 
        } else {
            posArr[posCount++] = arr[i];
        }
    }

    static int pos = 1;  
    while (pos <= 3) {  
        sortByDigit(posArr, posCount, pos);
        sortByDigit(negArr, negCount, pos);
        pos++;
    }

    for (int i = 0; i < negCount; i++) {
        arr[i] = -negArr[negCount - i - 1]; //obrystane i wrystane na znak
    }
    for (int i = 0; i < posCount; i++) {
        arr[negCount + i] = posArr[i];
    }

    free(negArr);
    free(posArr);
}
