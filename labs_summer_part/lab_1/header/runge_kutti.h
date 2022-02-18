#ifndef RUNGE_KUTTI_METHOD
#define RUNGE_KUTTI_METHOD
#include <stdio.h>
#include <math.h>

double start_fun_z(double t,
                   double z);

double found_fun_z(double t);

double start_fun_y(double t,
                   double y);

double found_fun_y(double t);

double runge_kutti_method_for_fun_y(double h,
                                    double step_count,
                                    double call_function);

double runge_kutti_method_for_fun_z(double h,
                                    double step_count,
                                    double call_function);

#endif
