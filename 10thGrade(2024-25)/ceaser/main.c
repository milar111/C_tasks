#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX_LEN 1000

void caesarEncrypt(char *text, int key) {
    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];
        if (isalpha(c)) {
            char base = isupper(c) ? 'A' : 'a';
            text[i] = (c - base + key) % 26 + base;
        }
    }
}

void caesarDecrypt(char *text, int key) {
    caesarEncrypt(text, 26 - (key % 26));
}

int main() {
    char text[MAX_LEN] = "test"; 
    int key = 3;               
    printf("Original:   %s\n", text);

    caesarEncrypt(text, key);
    printf("Encrypted:  %s\n", text);

    caesarDecrypt(text, key);
    printf("Decrypted:  %s\n", text);

    return 0;
}
