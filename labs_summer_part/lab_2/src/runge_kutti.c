#include "../header/runge_kutti.h"

double f1(double x,
          double y,
          double z,
          double n)
{
    double alpha = (double)2 + (double)(0.5) * n;
    return exp((double)(-1) * (pow(y, 2) + pow(z, 2))) + alpha * x;
}

double f2(double x,
          double y,
          double z,
          double k)
{
    double beta = (double)2 + (double)(0.5) * k;
    return beta * pow(y, 2) + z;
}

void euler_method(double h,
                  double x0,
                  double y0,
                  double z0,
                  double b,
                  double n,
                  double k)
{
    double y = y0;
    double z = z0;
    for(double step = x0; step < b + h; step += h)
    {
        printf("y(%.1lf) = %.5lf\nz(%.1lf) = %.5lf\n\n", step, y, step, z);
        y = y + h * f1(step, y, z, n);
        z = z + h * f2(step, y, z, k);
    }
}

void runge_kutti_method(double h,
                        double x0,
                        double y0,
                        double z0,
                        double b,
                        double n, 
                        double k)
{
    double k11 = h * f1(x0, y0, z0, n); 
    double k12 = h * f2(x0, y0, z0, k);

    double k21 = h * f1(x0 + h / 2, y0 + k11 / 2, z0 + k12 / 2, n); 
    double k22 = h * f2(x0 + h / 2, y0 + k11 / 2, z0 + k12 / 2, k); 

    double k31 = h * f1(x0 + h / 2, y0 + k21 / 2, z0 + k22 / 2, n); 
    double k32 = h * f2(x0 + h / 2, y0 + k21 / 2, z0 + k22 / 2, k); 

    double k41 = h * f1(x0 + h, y0 + k31, z0 + k32, n); 
    double k42 = h * f2(x0 + h, y0 + k31, z0 + k32, k);

    double y = y0;
    double z = z0;

    for(double step = x0; step < b + h; step += h)
    {
        printf("y(%.1lf) = %.5lf\nz(%.1lf) = %.5lf\n\n", step, y, step, z);

        k11 = h * f1(step, y, z, n); 
        k12 = h * f2(step, y, z, k);

        k21 = h * f1(step + h / 2, y + k11 / 2, z + k12 / 2, n); 
        k22 = h * f2(step + h / 2, y + k11 / 2, z + k12 / 2, k); 

        k31 = h * f1(step + h / 2, y + k21 / 2, z + k22 / 2, n); 
        k32 = h * f2(step + h / 2, y + k21 / 2, z + k22 / 2, k); 

        k41 = h * f1(step + h, y + k31, z + k32, n); 
        k42 = h * f2(step + h, y + k31, z + k32, k);

        y = y + (((double)1)/((double)6))*(k11+(double)2*k21+(double)2*k31+k41);
        z = z + (((double)1)/((double)6))*(k12+(double)2*k22+(double)2*k32+k42);
    }




















}
