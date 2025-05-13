#include <stdio.h>
#include <string.h>

void column_cipher(char *text, int k) {
    int len = strlen(text);
    int rows = (len + k - 1) / k;

    char matrix[rows][k];
    int index = 0;

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < k; j++) {
            if (index < len) {
                matrix[i][j] = text[index];
                index++;
            } else {
                matrix[i][j] = '_'; 
            }
        }
    }

    index = 0;
    for (int j = 0; j < k; j++) {
        for (int i = 0; i < rows; i++) {
            text[index] = matrix[i][j];
            index++;
        }
    }

    text[index] = '\0';
}

void column_decode(char *text, int k) {
    int len = strlen(text);
    int rows = (len + k - 1) / k;

    char matrix[rows][k];
    int index = 0;

    for (int j = 0; j < k; j++) {
        for (int i = 0; i < rows; i++) {
            if (index < len) {
                matrix[i][j] = text[index];
                index++;
            }
        }
    }

    index = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < k; j++) {
            text[index] = matrix[i][j];
            index++;
        }
    }

    text[index] = '\0';
}

int main() {
    char text[1000];
    int k = 3; 

    printf("Enter text: ");
    fgets(text, sizeof(text), stdin); 

    text[strcspn(text, "\n")] = '\0';
    column_cipher(text, k);
    printf("Encoded: %s\n", text);

    column_decode(text, k);
    printf("Decoded: %s\n", text);

    return 0;
}
