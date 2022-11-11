#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "MT.h"
#define ATTEMPTS 1000

int main (void) {

	int i;
	double theta, fai, x[ATTEMPTS], y[ATTEMPTS], z[ATTEMPTS], r = 1.0;
	FILE *fp;

	init_genrand((unsigned) time (NULL));

	for (i = 0; i < ATTEMPTS; i++) {

		theta = acos(1 - 2 * genrand_real1());
		fai =  2 * M_PI * genrand_real1();

		x[i] = r * sin(theta) * cos(fai);
		y[i] = r * sin(theta) * sin(fai);
		z[i] = r * cos(theta);
	}

	fp = fopen("radiation_3d.txt", "w");
	for (i = 0; i < ATTEMPTS; i++) {

		fprintf (fp, "%f %f %f\n", x[i], y[i], z[i]);
	}

	return 0;
}