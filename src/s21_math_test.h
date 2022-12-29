#include "s21_math.h"
#include <check.h>
#include <stdlib.h>

#define DOUBLES 9
#define SCIENTS 9
#define RADIANS 9

long double scients[SCIENTS] = {1e0, -1, 0, 0e1, 0e0, 1e6, 1e-6, 1e-6, 5e5};

long double doubles[DOUBLES] = {0.99999,     -1,    0,    10,        0.1,
                                100.100, 00.01, 0.10, 151.000313};

long double radians[RADIANS] = {0.5,       -1,    0,    3.14,        0.1,
                                100.100, 00.01, 0.10, 151.000313};
