#include <stdio.h>
#include <math.h>
#include "../header/runge_kutti.h"


int main(int argc,
         char **argv)
{
    printf("одноточечный:\n");
    euler_method((double)(0.1), (double)0, (double)(0.5), (double)1, (double)(0.3), (double)2, (double)0);
    printf("\nчетырехточечный:\n");
    runge_kutti_method((double)(0.1), (double)0, (double)(0.5), (double)1, (double)(0.3), (double)2, (double)0);
    return 0;
}


