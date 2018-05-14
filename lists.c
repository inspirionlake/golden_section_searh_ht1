#include <stdio.h>
#include <stdlib.h>

#include "lists.h"

typedef struct node {
	double start;
	double end;
	struct node* next;
} List;

List* init_list(void) {
	List* tmp = (List*)malloc(sizeof(List));
	tmp -> next = NULL;
	return tmp;
}

void add_in_list(List **head, double start, double end) {
	List* tmp;
	tmp = (List*)malloc(sizeof(List));
	tmp -> start = start;
	tmp -> end = end;
	tmp -> next = (*head);
	(*head) = tmp;
}

void print_list(List* head) {
	List* pl = head;
	while (head -> next != NULL) {
		printf("start = %lf, end = %lf\n", head -> start, head -> end);
		head = head -> next;
	}
	head = pl;
	//printf("start = %lf, end = %lf\n", head -> start, head -> end);
}

void delete_list(List* head) {
	while (head -> next != NULL) {
		List* tmp = head;
		head = head -> next;
		free(tmp);
	}
	free(head);
}

int count_of_nodes(List* head) {
	List* pl = head;
	int counter = 0;
	while (head -> next != NULL) {
		head = head -> next;
		counter++;
	}
	head = pl;
	return counter;
}

double get_start(List* head) {
	return head -> start;
}

double get_end(List* head) {
	return head -> end;
}

void get_next(List** head) {
	if ((*head) == NULL) return;
	(*head) = (*head) -> next;
}

// int main() {
// 	printf("Program running...\n");
// 	List* head = init_list(1.0,1.0);
// 	add_in_list(&head, 23.5, 12.7);
// 	add_in_list(&head, 42.7, 55.98);

// 	print_list(head);
// 	delete_list(head);

// 	printf("Program end.\n");
// 	return 0;
// }