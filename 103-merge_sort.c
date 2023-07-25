#include "sort.h"
/**
 * merge - merges two sorted subarrays into one
 * @array: The origional array containing subarrays
 * @left: starting index of the left subarray
 * @mid: ending index of the left subarray
 * @right: the ending index of the rignt subarray
 */
void merge(int *array, size_t left, size_t mid, size_t right)
{
	int *left_subarray;
	int *right_subarray;
	size_t left_size;
	size_t right_size;
	size_t i, j, k;

	left_size = mid - left + 1;
	right_size = right - mid;
	left_subarray = malloc(left_size * sizeof(int));
	right_subarray = malloc(right_size * sizeof(int));
	if (!left_subarray || !right_subarray)
	{
		free(left_subarray);
		free(right_subarray);
		return;
	}

	for (i = 0; i < left_size; i++)
		left_subarray[i] = array[left + i];
	for (i = 0; i < right_size; i++)
		right_subarray[i] = array[mid + 1 + i];

	i = 0;
	j = 0;
	k = left;
	printf("[left]: ");
	print_array(left_subarray, left_size);
	printf("[right]: ");
	print_array(right_subarray, right_size);

	while (i < left_size && j < right_size)
	{
		if (left_subarray[i] <= right_subarray[j])
			array[k++] = left_subarray[i++];
		else
			array[k++] = right_subarray[j++];
	}

	while (i < left_size)
		array[k++] = left_subarray[i++];
	while (j < right_size)
		array[k++] = right_subarray[j++];

	free(left_subarray);
	free(right_subarray);
	printf("[Done]: ");
	print_array(array + left, right - left + 1);
}
/**
 * merge_sort_helper - helper function for the merge sort algorithm
 * @array: The array to be sorted
 * @left: starting index of the subarray to be sorted
 * @right: ending index of the subarray to be sorted
 */
void merge_sort_helper(int *array, size_t left, size_t right)
{
	size_t mid;

	if (left >= right)
		return;
	mid = left + (right - left) / 2;
	merge_sort_helper(array, left, mid);
	merge_sort_helper(array, mid + 1, right);
	merge(array, left, mid, right);
}
/**
 * merge_sort - sorts an array of integers using merge sort algorithm
 * @array: array to be sorted
 * @size: number of elements in the array
 */
void merge_sort(int *array, size_t size)
{
	if (!array || size == 0)
		return;
	printf("Merging...\n");
	merge_sort_helper(array, 0, size - 1);
}
