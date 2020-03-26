#include "cfunction.h"
#include <math.h>
#include <stdlib.h>

void mycfunc(double *x, int *y, double constant1, int constant2, double *output) {
    output[0] = x[0];
    output[1] = y[0] * 1.0;
    output[2] = constant1;
    output[3] = constant2 * 1.0;
}
