#include "sort.h"

/**
 * heap_sort - sorts an array in an ascending order using heap
 * sorting algorithm
 * @array: array to be sorted
 * @size: number of elements in an array
 */

void heap_sort(int *array, size_t size)
{
	int i, temp;
	int *temp_buffer;
	size_t j;

	if (!array || size < 2)
		return;

	for (i = (size / 2) - 1; i >= 0; i--)
		shift_down(array, size, i);

	for (i = size - 1; i > 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;

		temp_buffer = malloc(size * sizeof(int));
		if (!temp_buffer)
			return;

		for (j = 0; j < size; j++)
			temp_buffer[j] = array[j];
		print_array(temp_buffer, size);
		free(temp_buffer);

		shift_down(array, i, 0);
	}
}

/**
 * shift_down - maintains max heap property during the sorting process
 * @array: array being sorted
 * @end: the index of the last element in current heap
 * @start: index of the root element to start the shift down process
 */
void shift_down(int *array, int end, int start)
{
	int root = start;
	int child;
	int temp = array[start];

	while ((root * 2) + 1 < end)
	{
		child = (root * 2) + 1;
		if ((child + 1 < end) && (array[child] < array[child + 1]))
			child++;
		if (temp >= array[child])
			break;
		array[root] = array[child];
		root = child;
	}
	array[root] = temp;
}
