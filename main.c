#include <math.h>
#include "PlotFunc.h"

// typedef double (*MathFunc_t)(double x);

int main()
{
    MathFunc_t funcArray[6] = {sin, asin, cos, acos, tan, sqrt};
    MathFunc_t func = funcArray[0];
    Plot(func, 50);
    return 0;
}









