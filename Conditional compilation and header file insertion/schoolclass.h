#include "person.h"
#ifndef SCHOOLCLASS_H
#define SCHOOLCLASS_H
struct schoolclass
{
    struct person studrnt[26];
    struct person teacher[26];
    char paralelka[5];
    int numInClass[26];
};
#endif