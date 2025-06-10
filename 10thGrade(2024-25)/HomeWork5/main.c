#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a compressed token
typedef struct {
    unsigned short offset;  // Distance back
    unsigned short length;  // Length of match
    unsigned char literal;  // Literal character (if offset and length are 0)
} Token;

// Function to compress data using LZ77 algorithm
unsigned char* lz77_compress(unsigned char* data, unsigned short window_size, unsigned short lookahead_size) {
    if (!data || window_size == 0 || lookahead_size == 0) return NULL;
    
    size_t data_len = strlen((char*)data);
    if (data_len == 0) return NULL;
    
    // Allocate buffer for compressed data (worst case: 3 bytes per input byte)
    unsigned char* compressed = (unsigned char*)malloc(data_len * 3);
    if (!compressed) return NULL;
    
    size_t comp_pos = 0;
    size_t pos = 0;
    
    while (pos < data_len) {
        unsigned short best_offset = 0;
        unsigned short best_length = 0;
        
        // Search for the longest match in the window
        for (unsigned short offset = 1; offset <= window_size && offset <= pos; offset++) {
            unsigned short length = 0;
            unsigned short max_length = lookahead_size;
            if (pos + max_length > data_len) {
                max_length = data_len - pos;
            }
            
            // Find match length
            while (length < max_length && data[pos - offset + length] == data[pos + length]) {
                length++;
            }
            
            // Check for repeating pattern
            if (length > 0) {
                unsigned char last_char = data[pos - offset + length - 1];
                unsigned short extra_length = 0;
                
                // Check how many times the last character can be repeated
                while (length + extra_length < max_length && data[pos + length + extra_length] == last_char) {
                    extra_length++;
                }
                
                length += extra_length;
            }
            
            if (length > best_length) {
                best_length = length;
                best_offset = offset;
            }
        }
        
        // Write token to compressed data
        if (best_length > 0) {
            // Write offset and length
            compressed[comp_pos++] = (best_offset >> 8) & 0xFF;
            compressed[comp_pos++] = best_offset & 0xFF;
            compressed[comp_pos++] = best_length & 0xFF;
            pos += best_length;
        } else {
            // Write literal
            compressed[comp_pos++] = 0;  // offset = 0
            compressed[comp_pos++] = 0;  // length = 0
            compressed[comp_pos++] = data[pos++];
        }
    }
    
    // Resize buffer to actual size
    compressed = (unsigned char*)realloc(compressed, comp_pos);
    return compressed;
}

// Function to decompress data using LZ77 algorithm
unsigned char* lz77_decompress(unsigned char* data) {
    if (!data) return NULL;
    
    size_t data_len = strlen((char*)data);
    if (data_len == 0) return NULL;
    
    // Allocate buffer for decompressed data (worst case: same size as input)
    unsigned char* decompressed = (unsigned char*)malloc(data_len);
    if (!decompressed) return NULL;
    
    size_t decomp_pos = 0;
    size_t pos = 0;
    
    while (pos < data_len) {
        unsigned short offset = (data[pos] << 8) | data[pos + 1];
        unsigned short length = data[pos + 2];
        pos += 3;
        
        if (offset == 0 && length == 0) {
            // Literal
            decompressed[decomp_pos++] = data[pos++];
        } else {
            // Copy from previous position
            for (unsigned short i = 0; i < length; i++) {
                decompressed[decomp_pos] = decompressed[decomp_pos - offset];
                decomp_pos++;
            }
        }
    }
    
    // Resize buffer to actual size
    decompressed = (unsigned char*)realloc(decompressed, decomp_pos);
    return decompressed;
}

int main(int argc, char* argv[]) {
    if (argc < 4) {
        printf("Usage:\n");
        printf("Compress: %s compress input.txt output.txt window_size lookahead_size\n", argv[0]);
        printf("Decompress: %s decompress input.txt output.txt\n", argv[0]);
        return 1;
    }
    
    FILE* input = fopen(argv[2], "rb");
    if (!input) {
        printf("Error: Cannot open input file\n");
        return 1;
    }
    
    FILE* output = fopen(argv[3], "wb");
    if (!output) {
        printf("Error: Cannot open output file\n");
        fclose(input);
        return 1;
    }
    
    if (strcmp(argv[1], "compress") == 0) {
        if (argc != 6) {
            printf("Error: Compress mode requires window_size and lookahead_size\n");
            fclose(input);
            fclose(output);
            return 1;
        }
        
        unsigned short window_size = atoi(argv[4]);
        unsigned short lookahead_size = atoi(argv[5]);
        
        // Read input file
        fseek(input, 0, SEEK_END);
        long file_size = ftell(input);
        fseek(input, 0, SEEK_SET);
        
        unsigned char* data = (unsigned char*)malloc(file_size + 1);
        if (!data) {
            printf("Error: Memory allocation failed\n");
            fclose(input);
            fclose(output);
            return 1;
        }
        
        fread(data, 1, file_size, input);
        data[file_size] = '\0';
        
        // Compress data
        unsigned char* compressed = lz77_compress(data, window_size, lookahead_size);
        if (!compressed) {
            printf("Error: Compression failed\n");
            free(data);
            fclose(input);
            fclose(output);
            return 1;
        }
        
        // Write compressed data
        fwrite(compressed, 1, strlen((char*)compressed), output);
        
        free(data);
        free(compressed);
    } else if (strcmp(argv[1], "decompress") == 0) {
        // Read input file
        fseek(input, 0, SEEK_END);
        long file_size = ftell(input);
        fseek(input, 0, SEEK_SET);
        
        unsigned char* data = (unsigned char*)malloc(file_size + 1);
        if (!data) {
            printf("Error: Memory allocation failed\n");
            fclose(input);
            fclose(output);
            return 1;
        }
        
        fread(data, 1, file_size, input);
        data[file_size] = '\0';
        
        // Decompress data
        unsigned char* decompressed = lz77_decompress(data);
        if (!decompressed) {
            printf("Error: Decompression failed\n");
            free(data);
            fclose(input);
            fclose(output);
            return 1;
        }
        
        // Write decompressed data
        fwrite(decompressed, 1, strlen((char*)decompressed), output);
        
        free(data);
        free(decompressed);
    } else {
        printf("Error: Invalid mode. Use 'compress' or 'decompress'\n");
    }
    
    fclose(input);
    fclose(output);
    return 0;
}

