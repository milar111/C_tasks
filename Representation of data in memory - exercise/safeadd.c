#include <stdio.h>
#include "safeint.h"
#include "util.h"

int main(int argc, char* argv[]) {
    if (argc != 3) {
        ERROR_MSG
        return 1;
    }

    struct SafeResult result = safeadd(atoi(argv[1]), atoi(argv[2]));

    if (result.errorflag) {
        ERROR_OVERFLOW()
        return 1;
    }

    printf("%d\n", result.value);

    return 0;
}
