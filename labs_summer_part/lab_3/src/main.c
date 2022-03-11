#include <stdio.h>
#include <math.h>
#include "../header/adams.h"


int main(int argc,
         char **argv)
{
    adams_method((double)(0.1), (double)0, (double)0, (double)7);
    return 0;
}


