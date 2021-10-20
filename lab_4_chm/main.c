#include <stdio.h>
#include <math.h>

void find_xs(double** A, double* f, double* x, double* arr, int j, double e) {
	
	for(int i = 0; i < 3; i++) 
		arr[i] = abs(x[j + 3] - x[j]);
	double max = arr[0];
	for(int i = 0; i < 3; i++) 
		if(arr[i] > max)
			max = arr[i];

	if(max > e) {
		int k = j + 6;
		double* mass = malloc((j + 6) * sizeof(double));
		x[j
		free(mass);
	}
	else
		return;

	
}

int main() {




	return 0;
}
