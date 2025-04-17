// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>

// typedef struct {
//     char* key;
//     int value;
// } item;

// item* linear_search(item* items, size_t size, const char* key) {
//     for (size_t i=0; i<size; i++) {
//         if (strcmp(items[i].key, key) == 0) {
//             return &items[i];
//         }
//     }
//     return NULL;
// }

// int main(void) {
//     item items[] = {
//         {"foo", 10}, {"bar", 42}, {"bazz", 36}, {"buzz", 7},
//         {"bob", 11}, {"jane", 100}, {"x", 200}};
//     size_t num_items = sizeof(items) / sizeof(item);

//     item* found = linear_search(items, num_items, "bob");
//     if (!found) {
//         return 1;
//     }
//     printf("linear_search: value of 'bob' is %d\n", found->value);
//     return 0;
// }






// #include <stdio.h>
// #include <stdint.h>

// #define FNV_OFFSET 14695981039346656037UL
// #define FNV_PRIME 1099511628211UL

// static uint64_t hash_key(const char* key) {
//     uint64_t hash = FNV_OFFSET;
//     for (const char* p = key; *p; p++) {
//         hash ^= (uint64_t)(unsigned char)(*p);
//         hash *= FNV_PRIME;
//     }
//     return hash;
// }


// int main(void){
//     const char* key = "foo";
//     uint64_t hash = hash_key(key);
//     printf("Hash of '%s' is %llu\n", key, (unsigned long long)hash);
//     return 0;
// }



#include<stdio.h>


int main(void){

    int n = 5; //101  << 3 = 101000
    printf("Right by 1: %d", n << 3);

    return 0;
}