#ifndef __GOLDEN_SECTION_SEARCH_H__
#define __GOLDEN_SECTION_SEARCH_H__

#define PHI 1.618033988

#include "lists.h"

/*	Function golden_section_search()
	*minimum - linear array where store finded minimums on intervals from localization()
	*function - pointer on investigated function
	*lst - pointer on singly linked list which struct described in lists.c here store start and end of finded 
	intervals with localization()*/
void golden_section_search(double *minimum, double (*function)(double x), List* lst, double accuracy, int quantity);

/*	Function get_step():
	adapt - 1=on 0=off adaptive step, fx_cur - current value of function f(x_i), fx_nxt - next value of function f(x_i+1),
	cur_step - current step in localization algorithm*, max_function_speed - maximum value of derivative of investigated function*/
double get_step(int adapt, double fx_cur, double fx_nxt, double cur_step, double max_function_speed);

/*	Function localization():
	fp - investigated function, x_min - point of start interval, x_ max - point of end, step - step of localization algorithm
	daptive step 0 - off, 1 - on, speed - maximum "speed" of function */
List* localization( double (*function)(double x), double max_iteration, double step, int adapt, double max_function_speed);


#endif