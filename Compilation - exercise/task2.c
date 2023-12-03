// Write a program to find the least common multiple of two numbers. Example: a=12, b=18, least common multiple = 36. Complete the first two steps of the compilation process for this program and upload the assembly code along with the assignment to the assignment.
#include <stdio.h>
int main(void)
{
    int n1 = 18;
    int n2 = 12;
    int nok;
    
    if(n1 > n2)
    {
        nok = n1;
        while(nok % n2 != 0)
        {
            nok += n1;
        }
    }else
    {
        nok = n2;
        while (nok % n1 != 0)
        {
            nok += n2;
        }
        
    }

    printf("%d", nok);

    return 0;
}