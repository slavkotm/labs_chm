#ifndef EULER_METHOD
#define EULER_METHOD
#include <stdio.h>
#include <math.h>

double f1(double x,
          double y,
          double z,
          double n);

double f2(double x,
          double y,
          double z,
          double k);

void euler_method(double h,
                  double x0,
                  double y0,
                  double z0,
                  double b,
                  double n,
                  double k);

void runge_kutti_method(double h,
                        double x0,
                        double y0,
                        double z0,
                        double b,
                        double n, 
                        double k);

#endif
