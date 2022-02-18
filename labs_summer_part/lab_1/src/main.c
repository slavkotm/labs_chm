#include <stdio.h>
#include <math.h>
#include "../header/runge_kutti.h"
#include "../header/euler.h"
#include "../header/euler_koshi.h"

int main(int argc,
         char **argv)
{
    /*printf("y(%.20lf) = %.20lf\n", (double)0.5, found_function_y((double)0.5));
    printf("z(%.20lf) = %.20lf\n\n", (double)0.5, found_function_z((double)0.5));
    
    printf("%.6lf\n", euler_method_for_function_y((double)(0.1), 
                      (double)5, 
                      found_function_y((double)0))); 

    printf("%.6lf\n", euler_method_for_function_z((double)(0.1), 
                                                  (double)5, 
                                                  found_function_z((double)0.5)));*/
    /*euler_koshi_method_for_function_y((double)(0.1), (double)5, found_function_yai((double)0));
    printf("\n");
    euler_koshi_method_for_function_z((double)(0.1), (double)5, found_function_zed((double)0.5));*/
    
    runge_kutti_method_for_fun_y((double)(0.1), (double)5, found_fun_y((double)0));        
    printf("\n");
    runge_kutti_method_for_fun_z((double)(-0.1), (double)5, found_fun_z((double)0.5));        

    return 0;
}


