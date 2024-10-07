#ifndef QUADRATICROOTS_H
#define QUADRATICROOTS_H

typedef struct {
    double x1;
    double x2;
    int norealroots;
} QuadraticRootsResult;

QuadraticRootsResult findroots(double a, double b, double c);

#endif
