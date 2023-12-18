#include <stdio.h>

int strcmp(char* str1, char* str2) {
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

int main(int argc, char *argv[]) {
    if(argc != 3) {
        printf("Error\n");
        return 1;
    }
    int result = strcmp(argv[1], argv[2]);
    printf("%d\n", result);
    return 0;
}
