#include <stdio.h>
#include "mystrings.h"

void strlength(char* str) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    printf("%d\n", length);
}

void strconcat(char* str1, char* str2) {
    int i = 0, j = 0;
    while(str1[i] != '\0') {
        i++;
    }
    while(str2[j] != '\0') {
        str1[i+j] = str2[j];
        j++;
    }
    str1[i+j] = '\0';
    printf("%s\n", str1);
}

int strcompare(char* str1, char* str2) {
    int i = 0;
    while(str1[i] != '\0' && str2[i] != '\0') {
        if(str1[i] < str2[i]) {
            return -1;
        } else if(str1[i] > str2[i]) {
            return 1;
        }
        i++;
    }
    if(str1[i] < str2[i]) {
        return -1;
    } else if(str1[i] > str2[i]) {
        return 1;
    } else {
        return 0;
    }
}
