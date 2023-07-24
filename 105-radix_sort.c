#include "sort.h"

/**
 * radix_sort - sorts an array of integers in ascending order
 * Using the LSD radix sort algorithm
 * @array: array to sort
 * @size: number of elements in an array
 */

void radix_sort(int *array, size_t size)
{
	int i, j;
	int container[10] = {0};
	int *temp;
	int max = 0;
	int exp = 1;

	if (!array || size <= 1)
		return;

	temp = malloc(sizeof(int) * size);
	if (!temp)
		return;

	for (i = 0; i < (int)size; i++)
		max = array[i] > max ? array[i] : max;

	while (max / exp > 0)
	{
		for  (i = 0; i < 10; i++)
			container[i] = 0;

		for (i = 0; i < (int)size; i++)
			container[(array[i] / exp) % 10]++;

		for (i = 1; i < 10; i++)
			container[i] += container[i - 1];

		for (j = size - 1; j >= 0; j--)
			temp[--container[(array[j] / exp) % 10]] = array[j];

		for (i = 0; i < (int)size; i++)
			array[i] = temp[i];

		exp *= 10;
		print_array(array, size);

		free(temp);
	}
}
