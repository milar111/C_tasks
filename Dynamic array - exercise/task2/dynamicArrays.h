#ifndef DYNAMIC_ARRAYS_H
#define DYNAMIC_ARRAYS_H

#include <stdio.h>

#define EGN_LENGTH 11

typedef struct {
    char** data;
    int size;
    int capacity;
} DynamicArray;

void initArray(DynamicArray* arr);
void expandArray(DynamicArray* arr);
void addEGN(DynamicArray* arr, char* egn);
void removeEGN(DynamicArray* arr, char* egn);
void printEGNs(DynamicArray* arr);
void freeArray(DynamicArray* arr);

#endif
