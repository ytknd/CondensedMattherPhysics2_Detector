#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "MT.h"
#define ATTEMPTS 100000

int main (void) {

	int i;
	double theta, fai, x[ATTEMPTS], y[ATTEMPTS], z[ATTEMPTS], x2, y2, r = 1.0, height = 16.0, detector_radius = 1.0;
	FILE *fp;

	init_genrand((unsigned) time (NULL));

	int count = 0;
	for (i = 0; i < ATTEMPTS; i++) {

		theta = acos(1 - 2 * genrand_real1());
		fai =  2 * M_PI * genrand_real1();

		x[i] = r * sin(theta) * cos(fai);
		y[i] = r * sin(theta) * sin(fai);
		z[i] = r * cos(theta);

		x2 = x[i] * height / z[i];
		y2 = y[i] * height / z[i];

		if (z[i] > 0 && (x2 * x2 + y2 * y2) < (detector_radius * detector_radius)) { //後方に散乱している粒子も捕捉しているのでカットする
			count++;
		}
	}

	printf ("%d\n.", count);

	return 0;
}