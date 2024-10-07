#include <stdio.h>

void strlen(char* str) {
    int length = 0;
    while(str[length] != '\0') {
        length++;
    }
    printf("%d\n", length);
}

int main(int argc, char *argv[]) {
    if(argc != 2) {
        printf("Error\n");
        return 1;
    }
    strlen(argv[1]);
    return 0;
}
