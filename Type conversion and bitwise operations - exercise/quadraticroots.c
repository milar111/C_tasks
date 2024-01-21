#include "quadraticroots.h"
#include <math.h>

QuadraticRootsResult findroots(double a, double b, double c) {
    QuadraticRootsResult result;

    double discriminant = b * b - 4 * a * c;

    if (discriminant > 0) {
        result.x1 = (-b + sqrtl(discriminant)) / (2 * a);
        result.x2 = (-b - sqrtl(discriminant)) / (2 * a);
        result.norealroots = 0;
    } else if (discriminant == 0) {
        result.x1 = result.x2 = -b / (2 * a);
        result.norealroots = 0;
    } else {
        result.norealroots = 1;
    }

    return result;
}
