#include "../header/method_constant_variation.h"

void first_diff_sys_equations(double a,
                              double b,
                              double h,
                              double fisrt_start_value,
                              double second_start_value)
{
    double t = fisrt_start_value;
    double s = second_start_value;

    /*double a0 = 1, b0 = -1, y0 = -1;
    double a1 = 1, b1 = 0, y1 = 4;*/
    double a0 = 1, b0 = -1, y0 = 2;
    double a1 = 1, b1 = 1.5, y1 = 0;

    double z_a = 0, dz_a = 0;
    double z1_a = 0, dz1_a = 1;
    double z2_a = 1, dz2_a = 0;
    
    double z_b, dz_b;
    double z1_b, dz1_b;
    double z2_b, dz2_b;

    double arr1[(int)(b * 10) + 1], arr2[(int)(b * 10) + 1], arr3[(int)(b * 10) + 1];
    double arr1_s[(int)(b * 10) + 1], arr2_s[(int)(b * 10) + 1], arr3_s[(int)(b * 10) + 1];
    int i = 0;
    for(double x = a; x <= b; x += h)
    {
        //printf("k = %.1lf   t = %.4lf   s = %.4lf\n", x, t, s);
        arr1[i] = t;
        arr1_s[i] = s;
        t = t + h * f2(s);
        s = s + h * f1(x, s, t);
        i++;
    }
    i--;
    z_b = arr1[i];
    dz_b = arr1_s[i];
    i = 0;
    //printf("\n");
    
    printf("%.4lf, %.4lf\n",z_b, dz_b);


    t = fisrt_start_value;
    s = second_start_value + (double)1;

    for(double x = a; x <= b; x += h)
    {
        //printf("k = %.1lf   t = %.4lf   s = %.4lf\n", x, t, s);
        arr2[i] = t;
        arr2_s[i] = s;
        t = t + h * f2(s);
        s = s + h * f3(x, s, t);
        i++;
    }
    i--;
    z1_b = arr2[i];
    dz1_b = arr2_s[i];
    i = 0;

    printf("%.4lf, %.4lf\n",z1_b, dz1_b);
    //printf("\n");

    t = fisrt_start_value + (double)1;
    s = second_start_value;

    for(double x = a; x <= b; x += h)
    {
        //printf("k = %.1lf   t = %.4lf   s = %.4lf\n", x, t, s);
        arr3[i] = t;
        arr3_s[i] = s;
        t = t + h * f2(s);
        s = s + h * f3(x, s, t);
        i++;
    }
    i--;
    z2_b = arr3[i];
    dz2_b = arr3_s[i];
    i = 0;

    printf("%.4lf, %.4lf\n",z2_b, dz2_b);

    double *tmp_arr = count_constants(a0, b0, y0, a1, b1, y1, z_a, z_b, z1_a, z1_b, z2_a, z2_b, dz_a, dz_b, dz1_a, dz1_b, dz2_a, dz2_b);

    double y = 0;

    //printf("\n");

    //for(int x = (int)a; x < (int)(b * 10) + 1; x++)
    //{
        //printf("t = %.4lf    t1 = %.4lf   t2 = %.4lf\n", arr1[x], arr2[x], arr3[x]);
    //}
    //printf("\n");

    for(double x = a; x <= b; x += h)
    {
        y = tmp_arr[0] * arr2[i] + tmp_arr[1] * arr3[i] + arr1[i];
        //printf("%d   k = %.1lf   y = %.4lf\n", i, x, y);
        i++;
    }
    printf("y = %.4lf\n", y);

    printf("------------------------------------------------------------------------------\n");
    printf("| k | x_k | z(x_k) | s(x_k) | z1(x_k) | s1(x_k) | z2(x_k) | s2(x_k) | y(x_k) |\n");
    for(int x = (int)a; x < (int)(b * 10) + 1; x++)
    {
        printf("------------------------------------------------------------------------------\n");
        printf("| %d | %.1lf | %.4lf | %.4lf | %.4lf  | %.4lf  | %.4lf  | %.4lf  | %.4lf |\n", x, (double)((double)x / 10), 
                arr1[x], arr1_s[x], arr2[x], arr2_s[x], arr3[x], arr3_s[x], tmp_arr[0] * arr2[x] + tmp_arr[1] * arr3[x] + arr1[x]);
    }
    printf("------------------------------------------------------------------------------\n");
}

double f3(double x,
          double s,
          double t)
{
    return pow(x + 1, 2) * s + ((double)2 / (pow(x + 1, 2))) * t;
    //return -(x + 1) * s + (double)2 * t;
}

double f1(double x,
          double s,
          double t)
{
    return pow(x + 1, 2) * s + ((double)2 / (pow(x + 1, 2))) * t + (double)1;
    //return -(x + 1) * s + (double)2 * t + (double)2;
}

double yyx0()
{
    return ((double)(0.8994) - (double)(0.9994))/ (double)(0.1);
}
double yyxn()
{
    return ((double)(0.6413) - (double)(0.6909))/ (double)(0.1);
}


double f2(double s)
{
    return s;
}

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
                        double dz2_b)
{
    double *constants = malloc(2 * sizeof(double));

    constants[1] =  ( (y1 - a1 * z_b - b1 * dz_b) - (y0 - a0 * z_a - b0 * dz_a) * ( (a1 * z1_b + b1 * dz1_b) / (a0 * z1_a + b0 * dz1_a) ) )
                    /
                    ( (a1 * z2_b + b1 * dz2_b) - (a0 * z2_a + b0 * dz2_a) * ( (a1 * z1_b + b1 * dz1_b) / (a0 * z1_a + b0 * dz1_a) ) );

    constants[0] = ((y0 - a0 * z_a - b0 * dz_a) - constants[1] * (a0 * z2_a + b0 * dz2_a)) / (a0 * z1_a + b0 * dz1_a); 

    printf("c1 = %.4lf, c2 = %.4lf\n", constants[0], constants[1]);

    return constants;



}
