#include <stdlib.h>
#include <math.h>
#include <stdio.h>

#include "golden_section_search.h"


void golden_section_search(double *minimum, double (*function)(double x), List* lst, double accuracy, int quantity) {
	//	golden section search
	double end = get_end(lst);
	double start = get_start(lst);
	// printf("start = %lf, end = %lf\n", get_start(lst), get_end(lst));

	double VALUE = (end - start) / PHI;

	double x1 = end - VALUE;
	double x2 = start + VALUE;
	double fx1 = function(x1);
	double fx2 = function(x2);


	for (int i = 0; i < quantity; i++) {
		while (fabs(end - start) > accuracy) {
			if (fx1 >= fx2) {
				start = x1;
			}
			else {
				end = x2;
			}

			VALUE = (end - start) / PHI;

			x1 = end - VALUE;
			x2 = start + VALUE;
			fx1 = function(x1);
			fx2 = function(x2);
		}
		(*minimum) = (end + start) / 2;	//	write in cell of array
		minimum = minimum + 1; //pointer go to next element in array
		get_next(&lst);
		// printf("start = %lf, end = %lf\n", get_start(lst), get_end(lst));
		end = get_end(lst);
		start = get_start(lst);
	}

//	return (end + start) / 2;

}

double get_step(int adapt, double fx_cur, double fx_nxt, double cur_step, double max_function_speed) {
	if (!adapt) {
		return cur_step;
	}

	double delta = fabs(fx_nxt - fx_cur);
	double min_function_speed = max_function_speed * 0.1;

	if (delta >= max_function_speed) {
		return cur_step * 0.9;
	}

	if (delta < min_function_speed) {
		return cur_step * 1.1;
	}

}

List* localization( double (*function)(double x), double max_iteration, double step, int adapt, double max_function_speed) {
	List* lst = init_list();
	double x_prv = 0;
	double x_cur = 0;
	double x_nxt = x_cur + step;
	double fx_cur = function(x_cur);
	double fx_nxt = function(x_nxt);
	int flag = 0;		//	флаг, который фиксирует рост функции. у нас функция убывающая, но так удобнее тестировать я думаю
						//	теперь программа должна реагировать не первое fx_nxt >= fx_cur а остальные пропускать, пока функция еще раз
						//	не изменит свой знак 0 - еще не росла 1 - уже росла
	step = get_step(0, fx_cur, fx_nxt, step, max_function_speed);

	int iteration = 1;
	
	if (fx_nxt >= fx_cur) {
		add_in_list(&lst, x_cur, x_nxt);
		flag = 1;	//	function increase or stable
		//remember segment{x_nxt, x_cur}
	}
	while (iteration <= max_iteration) {
		x_prv = x_cur;
		x_cur = x_nxt;
		x_nxt = x_cur + step;
		fx_cur = fx_nxt;
		fx_nxt = function(x_nxt);
		if ((fx_nxt >= fx_cur) && (flag == 0)) {
			add_in_list(&lst, x_prv, x_nxt);
			flag = 1;	//	function increase or stable
			//remember segment {x_prv, x_nxt}
		}
		else {
			if (fx_nxt < fx_cur) {
				flag = 0;	//	function decrease
			}
		}
		step = get_step(adapt, fx_cur, fx_nxt, step, max_function_speed);
		iteration++;
	}
	return lst;
}