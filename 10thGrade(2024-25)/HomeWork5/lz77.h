#ifndef LZ77_H
#define LZ77_H

unsigned char* lz77_compress(unsigned char* data, unsigned short window_size, unsigned short lookahead_size);
unsigned char* lz77_decompress(unsigned char* data);

#endif 