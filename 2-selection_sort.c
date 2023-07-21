#include "sort.h"

/**
 * selection_sort - sorts tho given array in ascending order
 * using selection sort
 * @array: array to sort
 * @size: array size/ number of elements in an array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j;
	int temp, idx_of_min;
	int swap_occurred;

	if (size <= 1)
		return;

	for (i = 0; i < size - 1; ++i)
	{
		idx_of_min = i;
		swap_occurred = 0;

		for (j = i + 1; j < size; ++j)
		{
			if (array[j] < array[idx_of_min])
			{
				idx_of_min = j;
				swap_occurred = 1;
			}
		}
		if (swap_occurred)
		{
			temp = array[idx_of_min];
			array[idx_of_min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
