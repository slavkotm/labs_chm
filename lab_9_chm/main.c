#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double find_first_root(double epsi, double x0) {
    double difference = epsi;
    int i = 0;
    double root = x0;
    while(difference >= epsi) {
        double tmp_root = root;
        root = root - (pow(root, 4) - 2.9 * pow(root, 3) + 0.1 * pow(root, 2) + 5.8 * root - 4.2) / (4 * pow(root, 3) - 8.7 * pow(root, 2) + 0.2 * root + 5.8);
        difference = tmp_root - root;
        if(difference < (double)0)
            difference = -difference;
        printf("iteration:%d, temp_root:%.15lf, root:%.15lf, difference:%.15lf\n", i, tmp_root, root, difference);
        i++;
    }
    printf("%.15lf\n", root);
    return root;
}

double check_result(double found_x) {
    return pow(found_x, 4) - 2.9 * pow(found_x, 3) + 0.1 * pow(found_x, 2) + 5.8 * found_x - 4.2;
}

int main(int argc, char* argv[]) {
    double e = 0.000005;
    printf("%.15lf\n", check_result(find_first_root(e, 1.0))); 
    printf("%.15lf\n", check_result(find_first_root(e, 1.45))); 
    printf("%.15lf\n", check_result(find_first_root(e, 2.0))); 
    printf("%.15lf\n", check_result(find_first_root(e, -2.0))); 
    return 0;
}
