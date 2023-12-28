#include <stdio.h>
#include <limits.h>
int main()
{
    int myChar = sizeof(char);
    int myShort = sizeof(short);
    int myLong = sizeof(long);
    int myLongLong = sizeof(long long);
    int myInt = sizeof(int);

    printf("%-10s %-10s %-10d %-10d %-10d %-10d \n", "int", "%d", myInt, INT_MIN, INT_MAX, UINT_MAX);
    printf("%-10s %-10s %-10d %-10d %-10d %-10d \n", "char", "%c", myChar, SCHAR_MIN, SCHAR_MAX, UCHAR_MAX);
    printf("%-10s %-10s %-10d %-10d %-10d %-10d \n", "short", "%d", myShort, SHRT_MIN, SHRT_MAX, UINT_MAX);
    printf("%-10s %-10s %-10d %-10d %-10d %-10d \n", "long", "%ld", myLong, LONG_MIN, LONG_MAX, ULONG_MAX);
    printf("%-10s %-10s %-10d %-10d %-10d %-10d \n", "long long", "%lld", myLongLong, LLONG_MIN, LLONG_MAX, ULLONG_MAX);
    

    return 0;
}