#include <stdio.h> 
#include <stdlib.h>
#include <math.h>

double find_first_root(double epsi, double x0) {
    double difference = epsi;
    int i = 0;
    double root = x0;
    while(difference >= epsi) {
        double tmp_root = root;
        root = (pow(tmp_root, 3) + sin(tmp_root) + (double)1) / ((double)12);
        difference = tmp_root - root;
        if(difference < (double)0)
            difference = -difference;
        printf("%d %.6lf %.6lf\n", i, tmp_root, root);
        i++;
    }
    printf("%.6lf\n", difference);
    return root;
}

double find_second_root(double epsi, double x0) {
    double difference = epsi;
    double root = x0;
    int i = 0;
    while(difference >= epsi) {
        double tmp_root = root;
        root = sqrt((12 * tmp_root - sin(tmp_root) - 1) / tmp_root);
        difference = tmp_root - root;
        if(difference < (double)0)
            difference = -difference;
        printf("%d %.6lf %.6lf\n", i,  tmp_root, root);
        i++;
    }
    printf("%.6lf\n", difference);
    return root;
}

double find_third_root(double epsi, double x0) {
    double difference = epsi;
    double root = x0;
    int i = 0;
    while(difference >= epsi) {
        double tmp_root = root;
        root = -sqrt((12 * tmp_root - sin(tmp_root) - 1) / tmp_root);
        difference = tmp_root - root;
        if(difference < (double)0)
            difference = -difference;
        printf("%d %.6lf %.6lf\n", i, tmp_root, root);
        i++;
    }
    printf("%.6lf\n", difference);
    return root;
}

int main() {
    double e = 0.00005;
    printf("%.6lf\n", find_first_root(e, 0.0));
    printf("%.6lf\n", find_second_root(e, 3.5));
    printf("%.6lf\n", find_third_root(e, -3.5));
    return 0;
}

