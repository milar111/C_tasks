typedef union{
    long odd;
    short even;
}Number;

#include<stdio.h>
int main(void){
    Number number[10] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
    
    for (int i = 0; i < 10; i++)
    {
        if(i % 2 == 0)
        {
            number[i].even = i;
        }else{
            number[i].odd = i;
        } 
    }
    printf("Odd:\n");
    for(int i = 0; i < 10; i++)
    {
        if(i % 2 != 0)
        {
            printf("%hd\n", number[i].odd);
        }
    }
    printf("Even:\n");
    for (int i = 0; i < 10; i++)
    {
        if (i % 2 == 0)
        {
            printf("%ld\n", number[i].even);
        }
    }
    
}