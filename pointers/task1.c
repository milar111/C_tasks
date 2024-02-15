#include <stdio.h>

int main(void)
{
double x1, x2;
double *p1, *p2;

printf("X1 = ");
scanf("%lf", &x1);

printf("X2 = ");
scanf("%lf", &x2);

p1 = &x1;
p2 = &x2;

printf("X1 = %lf, The  adress of X1 = %p",x1, p1);
printf("\n");
printf("X1 - %lf, The adress of X2 = %p",x2, p2);

return 0;

}


