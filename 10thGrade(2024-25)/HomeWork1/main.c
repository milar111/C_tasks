#include <stdio.h>
#include <stdlib.h>

void printArray(int* arr, unsigned int count);
int getNumber(int num, int pos);
void radixSort(int* arr, unsigned int count);
int count_digits(int num);

int main(void) {
    // int arr[] = {1, 0, 31, 512, 3, 53, 23, 132, 432, 41, -5, -32, -100, -7};
    int arr[] = {61, 102, 13, 5, -6, -3};
    // int arr[] = {1, 1, 1, 1, 1, 1}; 
    // int arr[] = {-100, -32, -5, -7}; 
    // int arr[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}; 
    // int arr[] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}; 
    // int arr[] = {};
    // int arr[] = {100000, 50001, 100000, 2000000000, 3003, 4123};

    int count = sizeof(arr) / sizeof(int);

    printf("Original array: ");
    printArray(arr, count);
    printf("\n");
    radixSort(arr, count);
    printf("Sorted array: ");
    printArray(arr, count);

    return 0;
}

void printArray(int* arr, unsigned int count) {
    for (int i = 0; i < count; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int getNumber(int num, int pos) { //dqsno na lqwo
    for (int i = 1; i < pos; i++) {
        num /= 10;
    }
    return num % 10; 
}


int count_digits(int num) {
    int count = 0;
    if (num == 0) {
        return 1;
    }
    while (num != 0) {
        num /= 10;
        count++;
    }
    return count;
}


// Като започваме с най-малките цифри(от LSB към MSB) постепенно се изгражда правилния ред. Така числата с по-малък брой цифри се подреждат правилно още в началото. А ако накрая в начлото има числа с повече цифри(пр. 501, 202) те се добавят към края(когато дойде техният ред(в случая - редът на стотиците)) постепенно(202, 501), което подреджа масива.

void radixSort(int* arr, unsigned int count) {
    static int pos = 1; 
    int max_pos = 1;

    for(int i = 0; i < count; i++){
        if (count_digits(arr[i]) > max_pos) {
            max_pos = count_digits(arr[i]);
        }
    }

    if (pos > max_pos) {  
        return;
    }

    int* buckets[19];     
    int bucketCount[19] = {0}; 

    for (int i = 0; i < 19; i++) {
        buckets[i] = malloc(count * sizeof(int));
    }

    printf("Sorting by: %d\n", pos);

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
