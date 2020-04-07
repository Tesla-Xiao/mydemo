#include "cfunction.h"
#include <math.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define PI 3.1415926535

void mycfunc(double *array_d, int *array_i, double d, int i, char *array_c, double *output) 
{
	if (strcmp(array_c, "cos") == 0)
	{
		output[0] = cos(array_d[0] + array_i[0] * PI);
		output[1] = cos(d + i * PI);
	} else if (strcmp(array_c, "sin") == 0) {
		output[0] = sin(array_d[0] + array_i[0] * PI);
		output[1] = sin(d + i * PI);
	}
}
