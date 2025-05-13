#include <stdio.h>

void caesar(char *text, int shift, char direction) {
    if (direction == 'L' || direction == 'l') {
        shift = -shift;
    }

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' + shift + 26) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            text[i] = ((c - 'a' + shift + 26) % 26) + 'a';
        }
    }
}

void caesar_decode(char *text, int shift, char direction) {
    if (direction == 'L' || direction == 'l') {
        shift = -shift;
    }
    shift = -shift;

    for (int i = 0; text[i] != '\0'; i++) {
        char c = text[i];

        if (c >= 'A' && c <= 'Z') {
            text[i] = ((c - 'A' + shift + 26) % 26) + 'A';
        } else if (c >= 'a' && c <= 'z') {
            text[i] = ((c - 'a' + shift + 26) % 26) + 'a';
        }
    }
}

int main() {
    char text[1000];

    printf("Enter text: ");
    scanf("%s", text);
    caesar(text, 5, 'R');
    printf("Encrypted text: %s\n", text);
    caesar_decode(text, 5, 'R');
    printf("Decrypted text: %s\n", text);

    return 0;
}
