#include "safeint.h"
#include <limits.h>
#include <stdlib.h>

struct SafeResult safeadd(int a, int b) {
    struct SafeResult result;
    result.value = a + b;
    result.errorflag = ((b > 0) && (a > INT_MAX - b)) || ((b < 0) && (a < INT_MIN - b));
    return result;
}

struct SafeResult safesubtract(int a, int b) {
    struct SafeResult result;
    result.value = a - b;
    result.errorflag = ((b > 0) && (a < INT_MIN + b)) || ((b < 0) && (a > INT_MAX + b));
    return result;
}

struct SafeResult safemultiply(int a, int b) {
    struct SafeResult result;
    result.value = a * b;
    result.errorflag = ((a > 0) && (b > 0) && (result.value / a != b)) || ((a < 0) && (b < 0) && (result.value / a != b));
    return result;
}

struct SafeResult safedivide(int a, int b) {
    struct SafeResult result;
    if (b == 0) {
        result.errorflag = 1;
    } else {
        result.value = a / b;
        result.errorflag = (a == INT_MIN && b == -1);
    }
    return result;
}

struct SafeResult safestrtoint(char* str) {
    struct SafeResult result;
    long long num = atoll(str);

    if (num > INT_MAX || num < INT_MIN) {
        result.errorflag = 1;
    } else {
        result.value = (int)num;
        result.errorflag = 0;
    }
    return result;
}