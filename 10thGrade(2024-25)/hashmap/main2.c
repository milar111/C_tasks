#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t ch;

typedef struct {
    ch symbol;           
    const char *code;  
} MAP;

void encode(ch *input, MAP *map, int m_size, ch *output_arr) {
    for (int i = 0; input[i] != '\0'; i++) {
        ch curr = input[i];
        for (int j = 0; j < m_size; j++) {
            if (map[j].symbol == curr) {
                strcat(output_arr, map[j].code);
                break;
            }
        }
    }
}

int main(void) {
    ch input[] = "banana";  
    ch output_arr[1000] = "";
    MAP map[] = {
        {'a', "0"},
        {'b', "10"},
        {'n', "11"},
    };

    int m_size = sizeof(map) / sizeof(map[0]);
    encode(input, map, m_size, output_arr);
    printf("%s\n", output_arr); 
    return 0;
}




