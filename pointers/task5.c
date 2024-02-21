#include <stdio.h>

void swap_elements(void *a, void *b) {
    int temp = *(int*)a;
    *(int*)a = *(int*)b;
    *(int*)b = temp;
}

void bubblesort(void *array, int count, int (*compare)(const void *, const void *), void (*swap_elements)(void *, void *)) {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (compare(array + j, array + j + 1) > 0) {
                swap_elements(array + j, array + j + 1);
            }
        }
    }
}

int ascending_compare(const void *a, const void *b) {
    int num1 = *(int*)a; 
    int num2 = *(int*)b;  
    if (num1 < num2)     
        return -1;   
    if (num1 > num2)     
        return 1;    
    return 0;        
}

int descending_compare(const void *a, const void *b) {
    int num1 = *(int*)a; 
    int num2 = *(int*)b; 
    if (num1 > num2)    
        return -1;        
    if (num1 < num2)    
        return 1;       
    return 0;             
}



int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    printf("Ascending order: ");
    bubblesort(arr, n, ascending_compare, swap_elements);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    printf("Descending order: ");
    bubblesort(arr, n, descending_compare, swap_elements);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
