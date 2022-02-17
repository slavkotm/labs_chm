#ifndef EULER_METHOD
#define EULER_METHOD
#include <stdio.h>
#include <math.h>


double found_function_y(double t); 

double found_function_z(double t);

double start_function_y(double t,
                        double y);

double start_function_z(double t,
                        double z);

double euler_method_for_function_y(double h, 
                                   double step_count,
                                   double call_function_for_start_value);

double euler_method_for_function_z(double h, 
                                   double step_count,
                                   double call_function_for_start_value);

#endif
