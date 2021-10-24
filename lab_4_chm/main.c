#include <stdio.h>
#include <math.h>
#include <stdlib.h>

//рекурсивная функция, которая находит приближенное решение СЛАУ 3 переменных
//методом простых итераций.
void find_xs(double* x, double* arr, double* tmp_arr, double e, int j) {

	j++;
	x[0] = (-0.5) * arr[1] + (-0.05) * arr[2] + (-1.45);
    	x[1] = (-0.02) * arr[0] + (-0.144) * arr[2] + (-0.14);
	x[2] = (0.179856) * arr[0] + (-0.719424) * arr[1] + (-7.884892);

	for(int i = 0; i < 3; i++) {
		if((x[i] - arr[i]) < (double)0) 
			tmp_arr[i] = -(x[i] - arr[i]);
		else
			tmp_arr[i] = x[i] - arr[i];
	}

	double max = tmp_arr[0];

	for (int i = 0; i < 3; i++)
		if (tmp_arr[i] > max) 
			max = tmp_arr[i];


	printf("%d, %.6lf, %.6lf, %.6lf, %.6lf\n", j, x[0], x[1], x[2], max);

	tmp_arr[0] = tmp_arr[1] = tmp_arr[2] = (double)0;
	arr[0] = arr[1] = arr[2] = (double)0;

	if(max > e)
		find_xs(arr, x, tmp_arr, e, j);
	else 
		return;

}

int main() {

	double* x = malloc(3 * sizeof(double));
	double* arr = malloc(3 * sizeof(double));
	double* tmp_arr = malloc(3 * sizeof(double));
	double e = 0.0000056;

	arr[0] = -1.45;
	arr[1] = -0.14;
	arr[2] = -7.88;

	find_xs(x, arr, tmp_arr, e, 0);

	free(tmp_arr);
	free(arr);
	free(x);


	return 0;
}
