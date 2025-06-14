#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lz77.h"

int main(int argc, char* argv[]) {
    FILE* input = fopen(argv[2], "r");
    if (input == NULL) {
        printf("errorF1\n");
        exit(1);
    }
    
    fseek(input, 0, SEEK_END);
    long file_size = ftell(input); //cur pp
    fseek(input, 0, SEEK_SET);
    unsigned char* data = malloc(file_size + 1);
    unsigned char* result;
    fread(data, 1, file_size, input);
    data[file_size] = '\0';
    fclose(input);
    if (strcmp(argv[1], "compress") == 0) {
        unsigned short window_size = atoi(argv[4]);
        unsigned short lookahead_size = atoi(argv[5]);
        result = lz77_compress(data, window_size, lookahead_size);
    } else if (strcmp(argv[1], "decompress") == 0) {
        result = lz77_decompress(data);
    } else {
        free(data);
        exit(1);
    }

    
    FILE* output = fopen(argv[3], "w");
    if (output == NULL) {
        printf("errorF2\n");
        free(data);
        free(result);
        exit(1);
    }
    
    fwrite(result, 1, strlen((char*)result), output);
    fclose(output);
    free(data);
    free(result);
    return 0;
}
