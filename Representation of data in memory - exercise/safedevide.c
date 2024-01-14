#include <stdio.h>
#include "safeint.h"
#include "util.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        ERROR_MSG;
        return 1;
    }

    struct SafeResult result = safedivide(atoi(argv[1]), atoi(argv[2]));

    if (result.errorflag) {
        if (atoi(argv[2]) == 0) {
            ERROR_MSG;
        } else {
            ERROR_OVERFLOW();
        }
        return 1;
    }

    printf("%d\n", result.value);

    return 0;
}
