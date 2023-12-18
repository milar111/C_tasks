#include <stdio.h>

int strlen(char* str) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    return length;
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

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Error\n");
        return 1;
    }
    if(strlen(argv[1]) > 50 || strlen(argv[2]) > 50) {
        printf("Error max = 50.\n");
        return 1;
    }
    strconcat(argv[1], argv[2]);
    return 0;
}
