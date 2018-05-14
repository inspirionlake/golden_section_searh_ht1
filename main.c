#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "lists.h"
#include "golden_section_search.h"

double investigated_function(double x) {		// investigated function set here in return
	//return x * x - 4 * x + 10;
	//return 1 / exp(x * M_PI / 180) * 40 * sin(0.5 * x * x) + 5;
	return sin(4 * x) - cos(2 * x);
}

double (*fp)(double) = investigated_function;

int main() {
	printf("Run...\n");

	List* intervals;

	int adapt = 0;								//	adaptive step 0 - off, 1 - on
	double speed = 0.5;							//	maximum "speed" of function

	double step = 0.005;							//	step of localization algorithm
	double x_min = 0.0;							//	point of start interval
	double x_max = 10;							//	point of end
	double accuracy = 0.1;						//	required accuracy 

	intervals = localization(fp, x_min, x_max, step, adapt, speed);	//	fp - investigated function, x_min - point of start interval
																	//	x_ max - point of end, step - step of localization algorithm
																	//	daptive step 0 - off, 1 - on, speed - maximum "speed" of function

	print_list(intervals);

	int count = count_of_nodes(intervals);

	double minimums[count];

	golden_section_search(minimums, fp, intervals, accuracy, count);

	for (int i = 0; i < count; i++) {
		printf("minimum #%d = %lf\n", i, minimums[i]);
	}

	delete_list(intervals);

	return 0;
}