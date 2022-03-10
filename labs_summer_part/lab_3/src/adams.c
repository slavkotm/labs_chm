#include "../header/adams.h"

struct node *create_list(double value)
{
    struct node *list = (struct node *)malloc(sizeof(struct node));
    list->data = value;
    list->next = NULL;
    return list;
}

void delete_list(struct node *list)
{
    while(list != NULL)
    {
        struct node *item = list;
        list = list->next;
        free(item);
    }
}

struct node *add_item_to_list(struct node *list, double value)
{
    struct node *tmp = list;
    if(list == NULL)
    {
        list = (struct node *)malloc(sizeof(struct node));
        list->data = value;
        list->next = NULL;
    }
    else 
    {
        while(tmp->next != NULL)
        {
            tmp = tmp->next;
        }
        struct node *item = (struct node *)malloc(sizeof(struct node));
        item->data = value;
        item->next = NULL;
        tmp->next = item;
    }
    return list;
}

void print_list(struct node *list)
{
    while(list != NULL)
    {
        printf("%.9lf\n", list->data);
        list = list->next;
    }
}

double adams_extrapolation_method_3f(double y,
                                     double h,
                                     double dh,
                                     double d2h,
                                     double d3h)
{
    return y + h + (double)((double)1 / (double)2) * dh +
           (double)((double)5 / (double)12) * d2h       +
           (double)((double)3 / (double)8) * d3h;
}

double adams_interpolation_method_3f(double y,
                                     double h,
                                     double dh,
                                     double d2h,
                                     double d3h)
{
    return y + h - (double)((double)1 / (double)2) * dh -
           (double)((double)1 / (double)12) * d2h       -
           (double)((double)1 / (double)24) * d3h;
}

double f(double x,
         double y)
{
    return ((double)3) / (pow(x, 2) + pow(y, 2) + (double)3);
}

void adams_method(double h,
                  double x0,
                  double y0,
                  double b)
{
    double y = (double)0;
    double k1, k2, k3, k4;
    
    struct node *list_ys = NULL, 
                *list_hs = NULL, 
                *list_dhs = NULL, 
                *list_d2hs = NULL, 
                *list_d3hs = NULL;

    for(double step = x0; step <= x0 + b * h; step += h)
    {
        k1 = h * f(step, y); 

        if(step <= (x0 + b * h) / 2)
            list_hs = add_item_to_list(list_hs, k1);

        k2 = h * f(step + h / 2, y + k1 / 2); 

        k3 = h * f(step + h / 2, y + k2 / 2); 

        k4 = h * f(step + h, y + k3); 

        printf("y(%.1lf) = %.9lf\n", step, y); 
        
        if(step <= (x0 + b * h) / 2)
            list_ys = add_item_to_list(list_ys, y);

        double dy = (((double)1)/((double)6))*(k1+(double)2*k2+(double)2*k3+k4);

        y = y + dy;
    }

    struct node *tmp_list_hs = list_hs;

    while(tmp_list_hs->next != NULL)
    {
        list_dhs = add_item_to_list(list_dhs, 
                                    tmp_list_hs->next->data - tmp_list_hs->data);
        tmp_list_hs = tmp_list_hs->next;
    }

    struct node *tmp_list_dhs = list_dhs;

    while(tmp_list_dhs->next != NULL)
    {
        list_d2hs = add_item_to_list(list_d2hs, 
                               tmp_list_dhs->next->data - tmp_list_dhs->data);

        tmp_list_dhs = tmp_list_dhs->next;
    }

    struct node *tmp_list_d2hs = list_d2hs;

    while(tmp_list_d2hs->next != NULL)
    {
        list_d3hs = add_item_to_list(list_d3hs, 
                               tmp_list_d2hs->next->data - tmp_list_d2hs->data);

        tmp_list_d2hs = tmp_list_d2hs->next;
    }

    list_ys = add_item_to_list(list_ys, 
                               adams_extrapolation_method_3f(get_value_by_index_from_list(list_ys, 3),
                                                             get_value_by_index_from_list(list_hs, 3),
                                                             get_value_by_index_from_list(list_dhs, 2),
                                                             get_value_by_index_from_list(list_d2hs, 1),
                                                             get_value_by_index_from_list(list_d3hs, 0)));

    list_hs = add_item_to_list(list_hs, 
                               h * f(0.4, get_value_by_index_from_list(list_ys, 4)));

    list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs, 4) - get_value_by_index_from_list(list_hs, 3));
    list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs, 3) - get_value_by_index_from_list(list_dhs, 2));
    list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 2) - get_value_by_index_from_list(list_d2hs, 1));

    list_ys = add_item_to_list(list_ys, 
                               adams_interpolation_method_3f(get_value_by_index_from_list(list_ys, 3),
                                                             get_value_by_index_from_list(list_hs, 4),
                                                             get_value_by_index_from_list(list_dhs, 3),
                                                             get_value_by_index_from_list(list_d2hs, 2),
                                                             get_value_by_index_from_list(list_d3hs, 1)));

    
    list_hs = add_item_to_list(list_hs, 
                               h * f(0.4, get_value_by_index_from_list(list_ys, 5)));
    list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs, 5) - get_value_by_index_from_list(list_hs, 3));
    list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs, 4) - get_value_by_index_from_list(list_dhs, 2));
    list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 3) - get_value_by_index_from_list(list_d2hs, 1));

    list_ys = add_item_to_list(list_ys, 
                               adams_extrapolation_method_3f(get_value_by_index_from_list(list_ys, 5),
                                                             get_value_by_index_from_list(list_hs, 5),
                                                             get_value_by_index_from_list(list_dhs, 4),
                                                             get_value_by_index_from_list(list_d2hs, 3),
                                                             get_value_by_index_from_list(list_d3hs, 2)));

    list_hs = add_item_to_list(list_hs, 
                               h * f(0.5, get_value_by_index_from_list(list_ys, 6)));
    list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs, 6) - get_value_by_index_from_list(list_hs, 5));
    list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs, 5) - get_value_by_index_from_list(list_dhs, 4));
    list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 4) - get_value_by_index_from_list(list_d2hs, 3));

    list_ys = add_item_to_list(list_ys, 
                               adams_interpolation_method_3f(get_value_by_index_from_list(list_ys, 5),
                                                             get_value_by_index_from_list(list_hs, 6),
                                                             get_value_by_index_from_list(list_dhs, 5),
                                                             get_value_by_index_from_list(list_d2hs, 4),
                                                             get_value_by_index_from_list(list_d3hs, 3)));

    list_hs = add_item_to_list(list_hs, 
                               h * f(0.5, get_value_by_index_from_list(list_ys, 7)));
    list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs, 7) - get_value_by_index_from_list(list_hs, 5));
    list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs, 6) - get_value_by_index_from_list(list_dhs, 4));
    list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 5) - get_value_by_index_from_list(list_d2hs, 3));


    list_ys = add_item_to_list(list_ys, 
                               adams_extrapolation_method_3f(get_value_by_index_from_list(list_ys, 7),
                                                             get_value_by_index_from_list(list_hs, 7),
                                                             get_value_by_index_from_list(list_dhs, 6),
                                                             get_value_by_index_from_list(list_d2hs, 5),
                                                             get_value_by_index_from_list(list_d3hs, 4)));

    list_hs = add_item_to_list(list_hs, 
                               h * f(0.6, get_value_by_index_from_list(list_ys, 8)));
    list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs, 8) - get_value_by_index_from_list(list_hs, 7));
    list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs, 7) - get_value_by_index_from_list(list_dhs, 6));
    list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 6) - get_value_by_index_from_list(list_d2hs, 5));

    list_ys = add_item_to_list(list_ys, 
                               adams_interpolation_method_3f(get_value_by_index_from_list(list_ys, 7),
                                                             get_value_by_index_from_list(list_hs, 8),
                                                             get_value_by_index_from_list(list_dhs, 7),
                                                             get_value_by_index_from_list(list_d2hs, 6),
                                                             get_value_by_index_from_list(list_d3hs, 5)));
    list_hs = add_item_to_list(list_hs, 
                               h * f(0.6, get_value_by_index_from_list(list_ys, 9)));
    list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs, 9) - get_value_by_index_from_list(list_hs, 7));
    list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs, 8) - get_value_by_index_from_list(list_dhs, 6));
    list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 7) - get_value_by_index_from_list(list_d2hs, 5));

    printf("\n\ny:\n");
    print_list(list_ys);
    printf("\nh:\n");
    print_list(list_hs);
    printf("\ndh:\n");
    print_list(list_dhs);
    printf("\nd2h:\n");
    print_list(list_d2hs);
    printf("\nd3h:\n");
    print_list(list_d3hs);

    delete_list(list_ys);
    delete_list(list_hs);
    delete_list(list_dhs);
    delete_list(list_d2hs);
    delete_list(list_d3hs);
}

double get_value_by_index_from_list(struct node *list, int index)
{
    int i = 0;
    while(i < index && list->next != NULL)
    {
        list = list->next;
        i++;
    }
    return list->data;
}
