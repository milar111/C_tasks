#include <stdio.h>
#include <stdbool.h> // bool библиотека за 

//Сложност: O(n)

//heapify - сортира heap-a
//shiftUp - сменя стойностите в heap-a
//heapSort - сортира heap-a

//сменя стойности
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;    
    *b = temp;
}


void heapify(int *arr, unsigned int count){
    // for (int i = count / 2; i >= 0; i--) {
    //     int root = i;

    //     shiftUp(arr, root);
    // }

    // if(i!= 0){
    //     int temp = arr[0];
    //     arr[0] = arr[i];
    //     arr[i] = temp;
    // }


    // int i = 0;
    // int check1 = 2 * i + 1;
    // int check2 = 2 * i + 2;

    // if(check1 < i && arr[check1] < arr[i]){
    //     i = check1;
    // }
    // if(check2 < i && arr[check2] < arr[i]){
    //     i = check2;
    // }


    // Започваме от последния възел, който има деца, и минаваме нагоре до корена
    for (int i = (count / 2) - 1; i >= 0; i--) {
        int big = i; // Вземаме текущия възел като най-голям
        int check1 = 2 * i + 1; // проверки
        int check2 = 2 * i + 2; 

        // Проверяваме дали лявото е по-голямо
        if (check1 < count && arr[check1] > arr[big]) {
            big = check1;
        }

        // Проверяваме дали дясното по-голямо 
        if (check2 < count && arr[check2] > arr[big]) {
            big = check2;
        }

        //разменяме ако текущия не е най-голям
        if (big != i) {
            swap(&arr[i], &arr[big]);
        }
        break;
    }
    

    
}


void siftUp(int* arr, unsigned int ind) {
    int temp = arr[0]; // сменя стойности
    arr[0] = arr[ind]; // Премества елемента към 0
    arr[ind] = temp; // Връща елемента на позиция index

    int check = 0;
    while (1) {
        // позиции за сравнение
        int check1 = 2 * check + 1;
        int check2 = 2 * check + 2;
        int largest = check;

        if (check1 < ind && arr[check1] > arr[largest]) {
            largest = check1;
        }
        if (check2 < ind && arr[check2] > arr[largest]) {
            largest = check2;
        }
        if (largest != check) {
            temp = arr[check]; // размяна
            arr[check] = arr[largest];
            arr[largest] = temp;
            temp = largest; // преминаваме надолу по heap-a
        } else {
            break;
        }
    }
}



void heapSort(int *arr, unsigned int count){
    heapify(arr, count);

    for(int i = count; i > 0; i--){     //обхожда елементите от края към началото
        shiftUp(arr, i);
    }

    
}


int main(void){
    int arr[] = {4, 10, 3, 5, 1};
    unsigned int count = sizeof(arr) / sizeof(arr[0]);

    heapSort(arr, count);

    for(int i = 0; i < count; i++){
        printf("%d ", arr[i]);
    }


    return 0;
}