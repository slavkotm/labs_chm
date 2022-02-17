#ifndef EULER_KOSHI_METHOD
#define EULER_KOSHI_METHOD
#include <stdio.h>
#include <math.h>

double found_function_zed(double t);

double start_function_zed(double t,
                        double z);

double start_function_yai(double t,
                        double y);

double found_function_yai(double t);

double function_dy(double h,
                   double start_function_y,
                   double function_value_next_step);

double euler_koshi_method_for_function_y(double h,
                                         double step_count,
                                         double call_function_for_start_value);

double euler_koshi_method_for_function_z(double h,
                                         double step_count,
                                         double call_function_for_start_value);

#endif
