#include "../header/euler_koshi.h"

double start_function_yai(double t, 
                        double y)
{
    return (double)4 * y - pow(t, 2);
}

double start_function_zed(double t,
                        double z)
{
    return ((double)(-1) * z) + (double)4 * t;
}

double found_function_zed(double t)
{
    return exp((double)(-1) * t) * 
           (
               ((double)4 * exp(t) * t) - 
               ((double)4 * exp(t))     +
               (found_function_yai((double)0.5) * exp((double)0.5) + 
                exp((double)0.5) * (double)2)
           );
}

double found_function_yai(double t)
{
    return exp((double)4 * t) * 
           ( 
               (pow(t, 2) / ( (double)4 * exp((double)4 * t) ) )   + 

               ( t / ( (double)8 * exp((double)4 * t) ) )          + 

               ( (double)1 / ( (double)32 * exp((double)4 * t) ) ) + 

               ( (double)( (double)31 / (double)32 ) ) 
           ); 
}

double function_dy(double h,
                   double start_function_y, 
                   double function_value_next_step)
{
    return (h / (double)2) * (start_function_y + function_value_next_step);
}

double euler_koshi_method_for_function_y(double h, 
                                         double step_count, 
                                         double call_function_for_start_value)
{
    double approximate_solution = call_function_for_start_value;

    for(double t = (double)(0); t <= h * step_count; t += h)
    {
        double f_next_step;

        double y_next_step = approximate_solution + 
                             h * start_function_yai(t, 
                                                    approximate_solution);

        for(double j = t + h; j <= h * step_count; j += h)
        {
            f_next_step = start_function_yai(j, y_next_step);
            break;
        };

        printf("%.1lf, %.6lf, %.6lf, %.6lf, %.6lf, %.6lf, %.6lf\n", 
                t, 
                approximate_solution,
                start_function_yai(t, approximate_solution),
                y_next_step,
                f_next_step,
                function_dy(h, 
                            start_function_yai(t, approximate_solution), 
                            f_next_step),
                found_function_yai(t)
              );


        approximate_solution = approximate_solution + 
                         function_dy(h, 
                                     start_function_yai(t, approximate_solution), 
                                     f_next_step);
    }

    return approximate_solution;
}

double euler_koshi_method_for_function_z(double h, 
                                         double step_count, 
                                         double call_function_for_start_value)
{
    double approximate_solution = call_function_for_start_value;

    for(double t = h * step_count; t >= (double)0; t -= h)
    {
        double f_next_step;

        double y_next_step = approximate_solution - 
                             h * start_function_zed(t, 
                                                    approximate_solution);

        for(double j = t - h; j >= (double)0; j -= h)
        {
            f_next_step = start_function_zed(j, y_next_step);
            break;
        };

        printf("%.1lf, %.6lf, %.6lf, %.6lf, %.6lf, %.6lf, %.6lf\n", 
                t, 
                approximate_solution,
                start_function_zed(t, approximate_solution),
                y_next_step,
                f_next_step,
                function_dy(h, 
                            start_function_zed(t, approximate_solution), 
                            f_next_step),
                found_function_zed(t)
              );


        approximate_solution = approximate_solution - 
                         function_dy(h, 
                                     start_function_zed(t, approximate_solution), 
                                     f_next_step);
    }

    return approximate_solution;
}
