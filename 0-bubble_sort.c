#include "sort.h"

/**
 * bubble_sort - sorts the given array in ascending order
 * @array: array of integers
 * @size: array size/number of elements in the given array
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	size_t temp;
	int sorted = 0;

	if (size <= 1)
	{
		return;
	}

	for (i = 0; i < size - 1 && !sorted; ++i)
	{
		sorted = 1;
		for (j = 0; j < size - 1 - i; ++j)
		{
			if (array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
				sorted = 0;
				print_array(array, size);
			}
		}
	}
}
