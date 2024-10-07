#include <stdio.h>

typedef unsigned long long ull;

ull add(ull a, ull b) {
    return a + b;
}

typedef ull (*func_ptr)(ull, ull);

ull reduce(ull* array, ull size, func_ptr f, ull value) {
    ull result = value;
    for (int i = 0; i < size; i++) {
        result = f(result, array[i]);
    }
    return result;
}

int main() {
    ull arr[] = {1, 2, 3};
    ull value = 0;
    ull final_result = reduce(arr, 3, add, value);
    printf("%llu\n", final_result);

    return 0;
}
