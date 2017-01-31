#include <stdlib.h>
#include <stdio.h>
#include </home/fas/cpsc424/ahs3/utils/timing/timing.h>
#include <math.h>

double N = 1000000000;

int main(int argc, const char * argv[]) {
	double dx = 1/N;
	double point_x = 0.0;
	double volume = 0.0;

	double wcStartTime;
	double wcFinishTime;
	double cpuTime;
	timing(&wcStartTime, &cpuTime);
	for (double i = 0; i < N; i++) {
		double point_sq = 1 + point_x * point_x;
		double y = 1.0 / point_sq; 
		volume += dx * y;
		point_x += dx;
	}
	timing(&wcFinishTime, &cpuTime);
	double durration = wcFinishTime - wcStartTime;

	double quarterPi = volume; // volume = pi * r^2, since r = 1; volume in pi 
	double check = tan(quarterPi); //Calculate tan(pi / 4) to make sure it is close to 1
	printf("Volume: %f, Pi check: %f\n", volume, check);

	point_x = 0.0;
	volume = 0.0;
	timing(&wcStartTime, &cpuTime);
	//The divide is not in this loop
	for (double i = 0; i < N; i++) {
		double point_sq = 1 + point_x * point_x;
		// double y = point_sq;  /// point_sq; //List all oporations
		volume += dx * point_sq;
		point_x += dx;
	}

	timing(&wcFinishTime, &cpuTime);
	printf("Volume: %f\n", volume);

	double durrationNoDivide = wcFinishTime - wcStartTime;
	printf("Duration With Divide: %f\n", durration);
	printf("Duration Without Divide: %f\n", durrationNoDivide);
	printf("Duration Diff: %f\n\n", durration - durrationNoDivide);
}
