#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lz77.h"

unsigned char* lz77_compress(unsigned char* data, unsigned short window_size, unsigned short lookahead_size) {
    unsigned int data_len = strlen((char*)data);
    unsigned int output_size = 0;
    unsigned char* output = malloc(data_len * 10); 
    
    unsigned int i = 0;
    while (i < data_len) {
        unsigned short best_pos = 0;
        unsigned short best_len = 0;
        
        for (unsigned short pos = 1; pos <= window_size && pos <= i; pos++) {
            unsigned short len = 0;
            while (len < lookahead_size && i + len < data_len && data[i - pos + len] == data[i + len]) len++;
            if (len > 0) {
                unsigned char last_char = data[i - pos + len - 1];
                while (len < lookahead_size && i + len < data_len && data[i + len] == last_char) len++;
            }
            if (len > best_len) {
                best_len = len;
                best_pos = pos;
            }
        }
        
        if (best_len > 0) {
            output[output_size++] = '(';
            sprintf( (char*)&output[output_size], "%hu,%hu", best_pos, best_len);
            output_size += strlen((char*)&output[output_size]);
            output[output_size++] = ')';
            i += best_len;
        } else {
            output[output_size++] = '(';
            sprintf((char*)&output[output_size], "0,0");
            output_size += strlen((char*)&output[output_size]);
            output[output_size++] = ')';
            output[output_size++] = data[i++];
        }
    }
    output[output_size] = '\0';
    return output;
}



unsigned char* lz77_decompress(unsigned char* data) {
    unsigned int data_len = strlen((char*)data);
    unsigned int output_size = 0;
    unsigned char* output = malloc(data_len * 10); 
    unsigned int i = 0;
    while (i < data_len) {
        if (data[i] != '(') {
            i++;
            continue;}
        
        unsigned short pos, len;
        i++; 
        sscanf((char*)&data[i], "%hu,%hu", &pos, &len);
        
        while (data[i] != ')') i++;
        i++; 
        
        if (pos == 0 && len == 0) { output[output_size++] = data[i++];
        } else {
            for (unsigned short j = 0; j < len; j++) {
                if (j < pos) { 
                    output[output_size] = output[output_size - pos];
                } else { 
                    output[output_size] = output[output_size - 1];
                    }
                output_size++;
            }
        }
    }
    
    output[output_size] = '\0';
    return output;
} 