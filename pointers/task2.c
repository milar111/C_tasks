#include <stdio.h>
#include <string.h>
#define MAX 200
int main(void)
{

char str[MAX];
char * p1;
printf("Str : ");
fgets(str, MAX, stdin);

strchr(str,'\n'); 



if (p1 != NULL) {

    *p1 = '\0';
  } else {
    printf("Handle the null pointer\n");
  }

printf( "Str:  %s\n" , str );
return 0;
}
