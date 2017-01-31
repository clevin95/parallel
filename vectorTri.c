#include <stdlib.h>
#include <stdio.h>
#include </home/fas/cpsc424/ahs3/utils/timing/timing.h>
#include <dummy.h>
#include <math.h>

int main(int argc, const char * argv[]) {
	int k;
	for (k = 1; k <= 28; k++) { 
		double power = pow(2.1, k);
		double N = floor(power);

		double *a = malloc(sizeof(double) * N);
		double *b = malloc(sizeof(double) * N);
		double *c = malloc(sizeof(double) * N);
		double *d = malloc(sizeof(double) * N);

		int y;
		for (y = 0; y < N; y++) {
			//Initialize arrays with random values
			b[y] = (double) rand();
			c[y] = (double) rand();
			d[y] = (double) rand();
		}
		double wcStartTime = 0;
		double cpuTime = 0;
		double wcFinishTime = 0;
		double runtime = 0;
		int repeat = 1;
		//Run each loop until the number of repetitions 
		//results in an runtime greater than 1 second
		for(; runtime<1.0; repeat*=2) {
			timing(&wcStartTime, &cpuTime);
			int j;
			for (j = 0; j < repeat; j++) {
				int i;
				for (i = 0; i < N; i++) {
					a[i] = b[i] + c[i] * d[i]; // 3 loads, 1 store, 2 double precision flops
				}
				if (a[0] < 0) {
					dummy(a, b, c, d);
				}
			}
			timing(&wcFinishTime, &cpuTime);
			runtime = wcFinishTime - wcStartTime;
		}

		double denom = runtime * 1000000.0; // Convert from Flops to MFlops
		double MFLOPS = (repeat * N * 2.0) / denom; // Number of interations times Flops per iteration over time gives MFlops/s
		printf("%f, %f\n", log(N), MFLOPS); 
		free(a);
		free(b);
		free(c);
		free(d);
	}
}
