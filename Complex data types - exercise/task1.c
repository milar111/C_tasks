#include <stdio.h>

typedef unsigned long long ULL;

ULL add(ULL a, ULL b) {
    return a + b;
}

typedef ULL (*func_ptr)(ULL, ULL);

ULL reduce(ULL* array, ULL size, func_ptr f, ULL initial_value) {
    ULL result = initial_value;
    for (ULL i = 0; i < size; ++i) {
        result = f(result, array[i]);
    }
    return result;
}

int main() {
    ULL arr[] = {1, 2, 3};
    ULL initial_value = 0;
    ULL final_result = reduce(arr, 3, add, initial_value);
    printf("%llu\n", final_result);

    return 0;
}
