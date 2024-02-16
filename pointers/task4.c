int compareacs(const void * a, const void * b )
{
    int p1 = *(const int *)a;
    int p2 = *(const int *)b;

    if(p1 > p2){
        return 1;
    }else if(p1 < p2){
        return -1;
    } else {
        return 0;
    }
}

int comparedesk(const void * a, const void * b)
{
    int p1 = *(const int *)a;
    int p2 = *(const int *)b;

    if (p1 > p2)
        return -1;
    else if (p1 < p2)
        return 1;
    else
        return 0;
}


#include <stdio.h>
int main(void)
{

int a = 15;
int b = 10;

printf("%d", compareacs(&a,&b));
printf("\n");
printf("%d", comparedesk(&a, &b));

return 0;
}