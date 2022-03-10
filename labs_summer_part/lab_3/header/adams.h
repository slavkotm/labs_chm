#ifndef EULER_METHOD
#define EULER_METHOD
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

struct node 
{
    double data;
    struct node *next;
};

void delete_list(struct node *);

void print_list(struct node *);

double get_value_by_index_from_list(struct node *, int );

struct node *create_list(double );

struct node *add_item_to_list(struct node *, double );

double adams_extrapolation_method_3f(double y,
                                     double h,
                                     double dh,
                                     double d2h,
                                     double d3h);

double adams_interpolation_method_3f(double y,
                                     double h,
                                     double dh,
                                     double d2h,
                                     double d3h);

double f(double x,
         double y);

void adams_method(double h,
                  double x0,
                  double y0,
                  double b);

#endif
