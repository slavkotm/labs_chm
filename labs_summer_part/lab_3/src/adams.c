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

double adams_extrapolation_method_4f(double y,
                                     double h,
                                     double dh,
                                     double d2h,
                                     double d3h,
                                     double d4h)
{
    return y + h + (double)((double)1 / (double)2) * dh +
           (double)((double)5 / (double)12) * d2h       +
           (double)((double)3 / (double)8) * d3h        +
           (double)((double)251 / (double)720) * d4h;
}

double adams_interpolation_method_4f(double y,
                                     double h,
                                     double dh,
                                     double d2h,
                                     double d3h,
                                     double d4h)
{
    return y + h - (double)((double)1 / (double)2) * dh -
           (double)((double)1 / (double)12) * d2h       -
           (double)((double)1 / (double)24) * d3h       -
           (double)((double)19 / (double)720) * d4h;
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
                *list_d3hs = NULL,
                *list_d4hs = NULL;

    for(double step = x0; step <= x0 + b * h; step += h)
    {
        k1 = h * f(step, y); 

        if(step <= (h * (double)4))
            list_hs = add_item_to_list(list_hs, k1);

        k2 = h * f(step + h / 2, y + k1 / 2); 

        k3 = h * f(step + h / 2, y + k2 / 2); 

        k4 = h * f(step + h, y + k3); 

        printf("y(%.1lf) = %.9lf\n", step, y); 
        
        if(step <= (h * (double)4))
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

    struct node *tmp_list_d3hs = list_d3hs;

    while(tmp_list_d3hs->next != NULL)
    {
        list_d4hs = add_item_to_list(list_d4hs, 
                               tmp_list_d3hs->next->data - tmp_list_d3hs->data);

        tmp_list_d3hs = tmp_list_d3hs->next;
    }

    int j = 0;

    for(double step = 0.5; step <= 0.7; step += h)
    {
        list_ys = add_item_to_list(list_ys, 
                               adams_extrapolation_method_4f(get_value_by_index_from_list(list_ys,  4 + j),
                                                             get_value_by_index_from_list(list_hs,  4 + j),
                                                             get_value_by_index_from_list(list_dhs,  3 + j),
                                                             get_value_by_index_from_list(list_d2hs, 2 + j),
                                                             get_value_by_index_from_list(list_d3hs, 1 + j),
                                                             get_value_by_index_from_list(list_d4hs, 0 + j)));

        list_hs = add_item_to_list(list_hs, 
                               h * f(step, get_value_by_index_from_list(list_ys,   5 + j)));
        list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs,   5 + j) - get_value_by_index_from_list(list_hs, 4 + j));
        list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs, 4 + j) - get_value_by_index_from_list(list_dhs, 3 + j));
        list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 3+j) - get_value_by_index_from_list(list_d2hs, 2 + j));
        list_d4hs = add_item_to_list(list_d4hs, get_value_by_index_from_list(list_d3hs,  2+j) - get_value_by_index_from_list(list_d3hs, 1 + j));



        list_ys = add_item_to_list(list_ys, 
                               adams_interpolation_method_4f(get_value_by_index_from_list(list_ys, 4 + j),
                                                             get_value_by_index_from_list(list_hs,  5 + j),
                                                             get_value_by_index_from_list(list_dhs,  4 + j),
                                                             get_value_by_index_from_list(list_d2hs,  3 + j),
                                                             get_value_by_index_from_list(list_d3hs,  2 + j),
                                                             get_value_by_index_from_list(list_d4hs,  1 + j)));
        list_hs = add_item_to_list(list_hs, 
                               h * f(step, get_value_by_index_from_list(list_ys, 6 + j)));
        list_dhs = add_item_to_list(list_dhs, get_value_by_index_from_list(list_hs, 6 + j) - get_value_by_index_from_list(list_hs, 4 + j));
        list_d2hs = add_item_to_list(list_d2hs, get_value_by_index_from_list(list_dhs,  5 + j) - get_value_by_index_from_list(list_dhs, 3 + j));
        list_d3hs = add_item_to_list(list_d3hs, get_value_by_index_from_list(list_d2hs, 4 + j) - get_value_by_index_from_list(list_d2hs, 2 + j));
        list_d4hs = add_item_to_list(list_d4hs, get_value_by_index_from_list(list_d3hs, 3 + j) - get_value_by_index_from_list(list_d3hs,  1 + j));

        j += 2;
    }

    double xs = (double)0;
    struct node *tmp_list_ys = list_ys;
    int flag = 0;
    printf("----------------------------------------------------------------------------------------\n");
    printf("|   x   |      y     |      h     |      dh     |     d2h     |    d3h     |    d4h    |\n");
    printf("----------------------------------------------------------------------------------------\n");
    while(tmp_list_ys != NULL)
    {
        printf("|  %.1lf  |  %.6lf  |  %.6lf  |  %.6lf  |  %.6lf  |  %.6lf  |  %.6lf |\n", xs, tmp_list_ys->data, list_hs->data, list_dhs->data, 
                list_d2hs->data, list_d3hs->data, list_d4hs->data);
        printf("----------------------------------------------------------------------------------------\n");
        if(xs == 0.5 && flag == 0)
        {
            flag++;
            xs -= h;
        }
        if(xs == 0.6 && flag == 1)
        {
            flag++;
            xs -= h;
        }
        if(xs == 0.7 && flag == 2)
        {
            flag++;
            xs -= h;
        }
        xs += h;
        tmp_list_ys = tmp_list_ys->next;
        list_hs = list_hs->next;
        if(list_dhs->next != NULL)
            list_dhs = list_dhs->next;
        if(list_d2hs->next != NULL)
            list_d2hs = list_d2hs->next;
        if(list_d3hs->next != NULL)
            list_d3hs = list_d3hs->next;
        if(list_d4hs->next != NULL)
            list_d4hs = list_d4hs->next;
    }

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
