#include "dynamicArrays.h"
#include <stdlib.h>

void initArray(DynamicArray* arr) {
    arr->size = 0;
    arr->capacity = 2;
    arr->data = (char**)malloc(arr->capacity * sizeof(char*));
    if (arr->data == NULL) {
        printf("Error\n");
        exit(1);
    }
}

void expandArray(DynamicArray* arr) {
    arr->capacity *= 2;
    char** newData = (char**)realloc(arr->data, arr->capacity * sizeof(char*));
    if (newData == NULL) {
        printf("Error\n");
        exit(1);
    }
    arr->data = newData;
}

void addEGN(DynamicArray* arr, char* egn) {
    if (arr->size == arr->capacity) {
        expandArray(arr);
    }
    arr->data[arr->size] = (char*)malloc(EGN_LENGTH);
    for (int i = 0; i < EGN_LENGTH; i++) {
        arr->data[arr->size][i] = egn[i];
    }
    arr->data[arr->size][EGN_LENGTH] = '\0';
    arr->size++;
}

void removeEGN(DynamicArray* arr, char* egn) {
    for (int i = 0; i < arr->size; i++) {
        int match = 1;
        for (int j = 0; j < EGN_LENGTH; j++) {
            if (arr->data[i][j] != egn[j]) {
                match = 0;
                break;
            }
        }
        if (match) {
            free(arr->data[i]);
            for (int k = i; k < arr->size - 1; k++) {
                arr->data[k] = arr->data[k + 1];
            }
            arr->size--;
            break;
        }
    }
}

void printEGNs(DynamicArray* arr) {
    printf("EGN:\n");
    for (int i = 0; i < arr->size; i++) {
        printf("%s\n", arr->data[i]);
    }
}

void freeArray(DynamicArray* arr) {
    for (int i = 0; i < arr->size; i++) {
        free(arr->data[i]);
    }
    free(arr->data);
}
