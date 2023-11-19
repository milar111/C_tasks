#include <stdio.h>

int main(void)
{
    #ifdef _WIN32
        int arr[5] = {5, 4, 3, 2, 1};
        int size = 5;
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
        printf("Sorted via bubble sort: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    #elif __linux__
        int arr[5] = {5, 4, 3, 2, 1};
        int size = 5;
        int k;
        int temp;
        for (int i = 0; i < size - 1; i++) {
            k = i;
            for (int j = i + 1; j < size; j++) {
                if (arr[j] < arr[k]) {
                    k = j;
                }
            }
            temp = arr[i];
            arr[i] = arr[k];
            arr[k] = temp;
        }
        printf("Sorted via straight selection: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    #elif __APPLE__
        int arr[5] = {5, 4, 3, 2, 1};
        int size = 5;
        int key;
        int j;
        for(int i = 1; i < size; i++)
        {
            key = arr[i];
            j = i - 1;
            while(j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j = j - 1;
            }
            arr[j + 1] = key;
        }
        printf("Sorted via insertion sort: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    #else
        int arr[5] = {5, 4, 3, 2, 1};
        int size = 5;
        int temp;
        for (int i = 0; i < size / 2; i++) {
            temp = arr[i];
            arr[i] = arr[size - i - 1];
            arr[size - i - 1] = temp;
        }
        printf("Array reversed: ");
        for (int i = 0; i < size; i++) {
            printf("%d ", arr[i]);
        }
    #endif

    return 0;
}
