// Направете функция, която да сортира масив, използвайки адресна аритметика. Създайте функция, която се казва swap, и която да разменя две променливи. Използвайте я в алгоритъма за сортиране.

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void sortArray(int arr[], int size) {
    int i, j;

    for (i = 0; i < size - 1; i++) {
        for (j = 0; j < size - i - 1; j++) {
            if (*(arr + j) > *(arr + j + 1)) {
                swap(arr + j, arr + j + 1);
            }
        }
    }
}

#include <stdio.h>
#define MAX 5
int main(void)
{
    
int arr[MAX] = {1, 5, 3, 2, 6};
sortArray(arr, MAX);
   for (int i = 0; i < MAX; i++) {
        printf("%d ", arr[i]);
    }


return 0;
}