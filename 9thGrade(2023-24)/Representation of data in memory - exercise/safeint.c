#include <limits.h>
#include "safeint.h"

struct SafeResult safeadd(int a, int b) {
    struct SafeResult result;
    result.value = a + b;
    result.errorflag = (b > 0 && a > INT_MAX - b) || (b < 0 && a < INT_MIN - b);
    return result;
}

struct SafeResult safesubtract(int a, int b) {
    struct SafeResult result;
    result.value = a - b;
    result.errorflag = (b > 0 && a < INT_MIN + b) || (b < 0 && a > INT_MAX + b);
    return result;
}

struct SafeResult safemultiply(int a, int b) {
    struct SafeResult result;
    result.value = a * b;
    result.errorflag = (a > 0 && b > 0 && result.value < 0) || (a < 0 && b < 0 && result.value < 0);
    return result;
}

struct SafeResult safedivide(int a, int b) {
    struct SafeResult result;
    result.value = a / b;
    result.errorflag = (b == 0) || (a == INT_MIN && b == -1);
    return result;
}

struct SafeResult safestrtoint(char* str) {
    struct SafeResult result;
    result.value = atoi(str);
    result.errorflag = safeadd(result.value, 0).errorflag || safemultiply(result.value, 0).errorflag;
    return result;
}
