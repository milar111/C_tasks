#include <stdio.h>
#include "safeint.h"
#include "util.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        return 1;
    }

    struct SafeResult result;
    struct SafeResult num1 = safestrtoint(argv[1]);
    struct SafeResult num2 = safestrtoint(argv[2]);

    if (num1.errorflag || num2.errorflag) {
        return 1;
    }

    result = safemultiply(num1.value, num2.value);

    if (result.errorflag) {
        return 1;
    }

    printf("%d\n", result.value);

    return 0;
}
