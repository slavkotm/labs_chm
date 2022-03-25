#include <stdio.h>
#include <math.h>
#include "../header/method_constant_variation.h"


int main(int argc,
         char **argv)
{
    //first_diff_sys_equations((double)0, (double)(1), (double)(0.1), (double)0, (double)0);
    first_diff_sys_equations((double)0, (double)(0.5), (double)(0.1), (double)0, (double)0);
    printf("y'(x0) = %.4lf\n", yyx0());
    printf("y'(xn) = %.4lf\n", yyxn());

    printf("y(0.5) + 1.5 * y'(0.5) = %.5lf\n", (0.6413 + (1.5) * yyxn()));
    printf("y(0) - y'(0) = %.5lf\n", (0.9994 + 1));

    return 0;
}


