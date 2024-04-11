#include <stdio.h>

typedef unsigned long long ull;

ull add(ull a, ull b) {
    return a + b;
}

typedef ull (*func_ptr)(ull, ull);

ull reduce(ull* array, ull size, func_ptr f, ull initial_value) {
    ull result = initial_value;
    for (ull i = 0; i < size; ++i) {
        result = f(result, array[i]);
    }
    return result;
}

int main() {
    ull arr[] = {1, 2, 3};
    ull initial_value = 0;
    ull final_result = reduce(arr, 3, add, initial_value);
    printf("%llu\n", final_result);

    return 0;
}
