#ifndef CONSTANT_VARIATION__METHOD
#define CONSTANT_VARIATION__METHOD
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void first_diff_sys_equations(double a,
                              double b,
                              double h,
                              double fisrt_start_value,
                              double second_start_value);

double f1(double x,
          double s,
          double t);

double f2(double s);

double f3(double x,
          double s,
          double t);

double *count_constants(double a0,
                        double b0,
                        double y0,
                        double a1,
                        double b1,
                        double y1,
                        double z_a,
                        double z_b,
                        double z1_a,
                        double z1_b,
                        double z2_a,
                        double z2_b,
                        double dz_a,
                        double dz_b,
                        double dz1_a,
                        double dz1_b,
                        double dz2_a,
                        double dz2_b);

#endif
