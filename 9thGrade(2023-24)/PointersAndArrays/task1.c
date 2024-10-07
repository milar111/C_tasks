// Направете функция, която да намира дължината на символен низ, използвайки адресна аритметика за обхождане на масива.

#include <stdio.h>
int findLength(const char* str) {
    int length = 0;

    while (*str != '\0') {
        str++;
        length++; 
    }

    return length;
}

int main() {
    const char* str = "Test";
    int length = findLength(str);
    printf("Length: %d\n", length); 
    return 0;
}
