#include "../header/euler.h"

double found_function_y(double t) 
{ 
    return exp((double)4 * t) * 
           ( 
               (pow(t, 2) / ( (double)4 * exp((double)4 * t) ) )   + 

               ( t / ( (double)8 * exp((double)4 * t) ) )          + 

               ( (double)1 / ( (double)32 * exp((double)4 * t) ) ) + 

               ( (double)( (double)31 / (double)32 ) ) 
           ); 
}

double found_function_z(double t)
{
    return exp((double)(-1) * t) * 
           (
               ((double)4 * exp(t) * t) - 
               ((double)4 * exp(t))     +
               (found_function_y((double)0.5) * exp((double)0.5) + exp((double)0.5) * (double)2)
           );
}

double start_function_y(double t,
                        double y)
{
    return (double)4 * y - pow(t, 2);
}

double start_function_z(double t,
                        double z)
{
    return ((double)(-1) * z) + (double)4 * t;
}

double euler_method_for_function_y(double h, 
                                   double step_count,
                                   double call_function_for_start_value)
{
    double approximate_solution = call_function_for_start_value;

    for(double t = (double)0; t <= h * step_count; t += h)
    {
        printf("%.2lf, %.6lf, %.6lf, %.6lf\n", t, approximate_solution, start_function_y(t, approximate_solution), found_function_y(t));
        if(t >= h * step_count)
            break;
        approximate_solution = approximate_solution + h * start_function_y(t, approximate_solution);
    }

    return approximate_solution;
}

double euler_method_for_function_z(double h, 
                                   double step_count,
                                   double call_function_for_start_value)
{
    double approximate_solution = call_function_for_start_value;

    for(double t = h * step_count; t >= (double)0; t -= h)
    {
        printf("%.2lf, %.6lf, %.6lf, %.6lf\n", t, approximate_solution, start_function_z(t, approximate_solution), found_function_z(t));
        if(t <= (double)h)
            break;
        approximate_solution = approximate_solution - h * start_function_z(t, approximate_solution);
    }

    return approximate_solution;
}

