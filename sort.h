#ifndef SORT_H
#define SORT_H

#include <stdio.h>
#include <stdlib.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer sorted in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */

typedef struct listint_s
{
	const int n;
	struct listint_s *prev;
	struct listint_s *next;
} listint_t;

void print_array(const int *array, size_t size);
void print_list(const listint_t *list);
void bubble_sort(int *array, size_t size);
void insertion_sort_list(listint_t **list);
void selection_sort(int *array, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void heap_sort(int *array, size_t size);
void shift_down(int *array, int size, int start);
void radix_sort(int *array, size_t size);
void merge_sort_helper(int *array, size_t left, size_t right);
void merge(int *array, size_t left, size_t mid, size_t right);
void merge_sort(int *array, size_t size);


void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);

void swap(int *x, int *y);
size_t lomuto_partition(int *array, size_t l, size_t r);
void quick_sort_helper(int *array, size_t l, size_t r);

#endif  /*SORT_H*/
