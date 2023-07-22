#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using
 * the shell sort algorithm (knuth sequence)
 * @array: array to sort
 * @size: size of the array
 */

void shell_sort(int *array, size_t size)
{
	size_t gap = 1, i, j;
	int temp;

	if (!array || size <= 1)
		return;
	while (gap < size / 3)
		gap = gap * 3 + 1;
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; j >= gap && array[j - gap] > temp;
					j = j - gap)
			{
				array[j] = array[j - gap];
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = gap / 3;
	}
}