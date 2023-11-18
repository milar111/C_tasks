#include <stdio.h>
#define ARRAY_SIZE 9

void main(){
    #ifdef ARRAY_SIZE
    int arr[ARRAY_SIZE];
    int i = 1;
    if(ARRAY_SIZE >= 1 && ARRAY_SIZE <= 10)
    {
        for(int j = 0; j < ARRAY_SIZE; j++)
        {
            arr[j] = i;
            i = i * 2;
            printf("\n%d", arr[j]);
        }
    }else{
        printf("wrong size");
    }
    #endif
    #ifndef ARRAY_SIZE
    printf("macro not defined");
    #endif
}