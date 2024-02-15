void swap(void * a, void * b) 
{
  int temp = *(int *)a;
  *(int  *)a = *(int *)b;
  *(int *)b = temp;
}

#include <stdio.h>
int main(void)
{

int a = 3;
  int b = 4;
  swap(&a, &b);
  printf("A:%d\n", a);
  printf("B:%d\n", b);


}