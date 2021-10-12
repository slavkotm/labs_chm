#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int SIZE_A = 9;
int SIZE_f = 3;
int SIZE_L = 6;
int SIZE_xs_ys_r = 3;

void start_data(double *arr_one, double *arr_two);
void trans_matr(double *arr, int SIZE, double* arr_data);
void positive_defin(double *arr);
void find_L(double* arr, double* any_arr, double* sec_arr);
void find_ys(double* any_arr, double* arr_f, double* arr_ys); 
void find_xs(double* sec_arr, double* arr_f, double* arr_ys, double* arr_xs);
void find_r_inf_1_2(double* arr_matr, double* arr_xs, double* arr_f);

int main()
{

	double* arr_matr = malloc(SIZE_A * sizeof(double));
	double* arr_f = malloc(SIZE_f * sizeof(double));
	double* arr_L = malloc(SIZE_L * sizeof(double));
	double* arr_LT = malloc(SIZE_L * sizeof(double));
	double* arr_xs = malloc(SIZE_xs_ys_r * sizeof(double));
	double* arr_ys = malloc(SIZE_xs_ys_r * sizeof(double));

	start_data(arr_matr, arr_f);

	for(int i = 0; i < SIZE_A; i++)
		printf("%lf ", arr_matr[i]);

	printf("\n");
	for(int i = 0; i < SIZE_f; i++)
		printf("%lf ", arr_f[i]);
	printf("\n");

	trans_matr(arr_matr, SIZE_A, arr_matr);

	for(int i = 0; i < SIZE_A; i++)
		printf("%lf ", arr_matr[i]);

	printf("\n");

	positive_defin(arr_matr);
	
	printf("\n");

	find_L(arr_matr, arr_L, arr_LT);
	find_ys(arr_L, arr_f, arr_ys);
	find_xs(arr_LT, arr_f, arr_ys, arr_xs);

	printf("\n");
	for(int i = 0; i < SIZE_L; i++)
		printf("%lf ", arr_L[i]);
	printf("\n");


	printf("\n");
	for(int i = 0; i < SIZE_L; i++)
		printf("%lf ", arr_LT[i]);
	printf("\n");

	
	printf("\n");
	for(int i = 0; i < SIZE_xs_ys_r; i++)
		printf("%lf ", arr_xs[i]);
	printf("\n");


	printf("\n");
	for(int i = 0; i < SIZE_xs_ys_r; i++)
		printf("%lf ", arr_ys[i]);
	printf("\n");


	free(arr_LT);
	free(arr_L);
	free(arr_f);
	free(arr_matr);

	return 0;
}

void start_data(double *arr_one, double *arr_two) {
	
	arr_one[0] = 3.1; 
	arr_one[1] = (double)1; 
	arr_one[2] = 2.1;
	arr_one[3] = (double)1;
	arr_one[4] = 3.6;
	arr_one[5] = 2.1;
	arr_one[6] = 2.1;
	arr_one[7] = 2.1;
	arr_one[8] = 4.1;

	arr_two[0] = 2.1;
	arr_two[1] = (double)1;
	arr_two[2] = 1.1;
}


void trans_matr(double* arr, int SIZE, double* arr_data) {

	int value = 0;
	
	double temp = arr[1];

	arr[1] = arr[3];
	arr[3] = temp;

	temp = arr[2];
	arr[2] = arr[2];
	arr[6] = temp;

	temp = arr[5];
	arr[5] = arr[7];
	arr[7] = temp;

	for(int i = 0; i < SIZE; i++) {
		if(arr[i] != arr_data[i]) {
			value = 1;
			break;
		}
	}

	if(value)
		printf("matrix is no transpos\n");
	else
		printf("matrix is transpos\n");
}

void positive_defin(double *arr) {
	
	int value = 0;
	if(arr[0] > (double)0)
		if((arr[0] * arr[4] - arr[1] * arr[3]) > (double)0)
			if((arr[0] * arr[4] * arr[8] + arr[1] * arr[5] * arr[6] + arr[2] * arr[3] * arr[7] - arr[2] * arr[4] * arr[6] - arr[0] * arr[5] * arr[7] - arr[1] * arr[3] * arr[8]) > (double)0)
				value = 1;
	if(value)
		printf("matrix is positive definit\n");
	else
		printf("matrix is not positive definit\n");
}


void find_L(double* arr, double* any_arr, double* sec_arr) {

	any_arr[0] = sqrt(arr[0]);
	sec_arr[0] = sqrt(arr[0]);

	sec_arr[1] = arr[1] / any_arr[0];
	sec_arr[2] = arr[2] / any_arr[0];

	any_arr[1] = arr[3] / any_arr[0];
	any_arr[2] = sqrt(arr[4] - any_arr[1] * sec_arr[1]);

	any_arr[3] = arr[6] / any_arr[0];
	any_arr[4] = (arr[7] - any_arr[3] * sec_arr[1]) / any_arr[2];

	sec_arr[3] = any_arr[2];
	sec_arr[4] = (arr[5] - any_arr[1] * sec_arr[2]) / sec_arr[3];

	any_arr[5] = sec_arr[5] = sqrt(arr[8] - any_arr[3] * sec_arr[2] - any_arr[4] * sec_arr[4]);
}


void find_ys(double* any_arr, double* arr_f, double* arr_ys) { 

	arr_ys[0] = arr_f[0] / any_arr[0];
	arr_ys[1] = (arr_f[1] - any_arr[1] * arr_ys[0]) / any_arr[2];
	arr_ys[2] = (arr_f[2] - any_arr[3] * arr_ys[0] - arr_ys[1] * any_arr[4]) / any_arr[5];	
}


void find_xs(double* sec_arr, double* arr_f, double* arr_ys, double* arr_xs) {

	arr_xs[2] = arr_ys[2] / sec_arr[5];
	arr_xs[1] = (arr_ys[1] - sec_arr[4] * arr_xs[2]) / sec_arr[3];
	arr_xs[0] = (arr_ys[0] - sec_arr[2] * arr_xs[2] - arr_xs[1] * sec_arr[1]) / sec_arr[0];
}
















