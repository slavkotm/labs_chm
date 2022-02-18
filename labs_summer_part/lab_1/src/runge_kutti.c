#include "../header/runge_kutti.h"

double start_fun_z(double t,
                   double z)
{
    return ((double)(-1) * z) + (double)4 * t;
}

double found_fun_z(double t)
{
    return exp((double)(-1) * t) * 
           (
               ((double)4 * exp(t) * t) - 
               ((double)4 * exp(t))     +
               (found_fun_y((double)0.5) * exp((double)0.5) + exp((double)0.5) * (double)2)
           );
}

double start_fun_y(double t,
                   double y)
{
    return (double)4 * y - pow(t, 2);
}

double found_fun_y(double t)
{
    return exp((double)4 * t) * 
           ( 
               (pow(t, 2) / ( (double)4 * exp((double)4 * t) ) )   + 

               ( t / ( (double)8 * exp((double)4 * t) ) )          + 

               ( (double)1 / ( (double)32 * exp((double)4 * t) ) ) + 

               ( (double)( (double)31 / (double)32 ) ) 
           ); 
}

double runge_kutti_method_for_fun_y(double h,
                                    double step_count,
                                    double call_function_for_start_value)
{
    double approximate_solution = call_function_for_start_value;
    double k1, k2, k3, k4, dy;

    for(double t = (double)0; t < h * step_count; t += h)
    {
        k1 = h * start_fun_y(t, approximate_solution);

        k2 = h * start_fun_y(t + (h / (double)2), 
                             approximate_solution + (k1 / (double)2));

        k3 = h * start_fun_y(t + (h / (double)2),
                             approximate_solution + (k2 / (double)2));

        k4 = h * start_fun_y(t + h, approximate_solution + k3);

        dy = ((double)1 / (double)6) * (k1 + ((double)2 * k2) + ((double)2 * k3) + k4);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t, 
                                                approximate_solution, 
                                                start_fun_y(t ,approximate_solution),
                                                k1, 
                                                k1);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t + (h / (double)2), 
                                             approximate_solution + (k1 / (double)2),
                                             start_fun_y(t + (h / (double)2), 
                                             approximate_solution + (k1 / (double)2)), 
                                              k2, 
                                              k2 * (double)2);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t + (h / (double)2), 
                                              approximate_solution + (k2 / (double)2),
                                            start_fun_y(t + (h / (double)2),
                                            approximate_solution + (k2 / (double)2)), 
                                              k3, 
                                              k3 * (double)2);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t + h, 
                                              approximate_solution + k3, 
                                              start_fun_y(t + h, 
                                                  approximate_solution + k3),
                                              k4, 
                                              k4);

        printf("                                    %.6lf\n", dy); 

        approximate_solution = approximate_solution + dy;
    }

    printf("%.2lf, %.6lf, %.6lf\n", h * step_count, 
                                    approximate_solution, found_fun_y((double)(0.5))); 

    return approximate_solution;
}

double runge_kutti_method_for_fun_z(double h,
                                    double step_count,
                                    double call_function_for_start_value)
{
    double approximate_solution = call_function_for_start_value;
    double k1, k2, k3, k4, dz;

    for(double t = (double)(-1) * h * step_count; t > (double)(-1) * h; t += h)
    {
        k1 = h * start_fun_z(t, approximate_solution);

        k2 = h * start_fun_z(t + (h / (double)2), 
                             approximate_solution + (k1 / (double)2));

        k3 = h * start_fun_z(t + (h / (double)2),
                             approximate_solution + (k2 / (double)2));

        k4 = h * start_fun_z(t + h, approximate_solution + k3);

        dz = ((double)1 / (double)6) * (k1 + ((double)2 * k2) + ((double)2 * k3) + k4);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t, 
                                                approximate_solution, 
                                                start_fun_z(t ,approximate_solution),
                                                k1, 
                                                k1);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t + (h / (double)2), 
                                             approximate_solution + (k1 / (double)2),
                                             start_fun_z(t + (h / (double)2), 
                                             approximate_solution + (k1 / (double)2)), 
                                              k2, 
                                              k2 * (double)2);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t + (h / (double)2), 
                                              approximate_solution + (k2 / (double)2),
                                            start_fun_z(t + (h / (double)2),
                                            approximate_solution + (k2 / (double)2)), 
                                              k3, 
                                              k3 * (double)2);

        printf("%.2lf, %.6lf, %.6lf, %.6lf, %.6lf\n", t + h, 
                                              approximate_solution + k3, 
                                              start_fun_z(t + h, 
                                                  approximate_solution + k3),
                                              k4, 
                                              k4);

        printf("                                    %.6lf\n", dz); 

        approximate_solution = approximate_solution + dz;
    }

    printf("%.2lf, %.6lf, %.6lf\n", (double)0, 
                                    approximate_solution, found_fun_z((double)(0))); 

    return approximate_solution;
}
