#include <stdio.h>

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int anchor(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1; 
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[right]);
    return i + 1;
}

void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int num = anchor(arr, low, high);
        quick_sort(arr, low, num - 1);
        quick_sort(arr, num + 1, high);
    }
}

int main() {
    int numbers[8] = {6, 8, 3, 7, 2, 4, 5, 1};

    quick_sort(numbers, 0, 7);
    for (int i = 0; i < 8; i++) {
        printf("%d ", numbers[i]);
    }

    return 0;
}
