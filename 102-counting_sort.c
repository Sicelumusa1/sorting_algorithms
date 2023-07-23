#include "sort.h"

/**
 * counting_sort - sort an array of integers in ascending order
 * using the counting sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */

void counting_sort(int *array, size_t size)
{
	size_t i;
	size_t sorted_index;
	int  max_value = array[0];
	int *counting_array;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max_value)
			max_value = array[i];
	}

	counting_array = malloc((max_value + 1) * sizeof(int));
	if (counting_array == NULL)
		return;

	for (i = 0; i <= (size_t)max_value; i++)
		counting_array[i] = 0;

	for (i = 0; i < size; i++)
		counting_array[array[i]]++;

	print_array(array, size);

	sorted_index = 0;
	for (i = 0; i <= (size_t)max_value; i++)
	{
		while (counting_array[i] > 0)
		{
			array[sorted_index] = i;
			sorted_index++;
			counting_array[i]--;
		}
	}

	free(counting_array);
}
