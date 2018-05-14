#ifndef _LISTS_H_
#define _LISTS_H_

typedef struct node List;


// Make a head of list
List* init_list(void);

/*	Add in list new interval in this program
	**head - current head of list
	start and end - data for according field of list*/
void add_in_list(List **head, double start, double end);

/*	Display content of list
	*head - current head of list
	*/
void print_list(List *head);

/*	Delete all list from memory
	*head - current head of list
	*/
void delete_list(List* head);

/*	This function return number of nodes which store in list
	*head - current head of list
	*/
int count_of_nodes(List* head);

/*	Function return field named start from head (node)
	*head - current head of list
	*/
double get_start(List* head);

/*	Function return field named end from head (node)
	*head - current head of list
	*/
double get_end(List* head);

/* Function assign pointer on next node to head. If head == NULL nothing will change
	**head - current head of list
	*/
void get_next(List** head);

#endif