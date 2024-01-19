#include "sort.h"

/**
 * swap -swaps two elements
 * @a: first element
 * @b: second element
 */
 void swap(int *a, int *b)
 {
	int temp = *a;
	*a = *b;
	*b = temp;
 }

/**
 * Lomuto_partition - Lomuto partition scheme
 * @array: array to be partitioned
 * @low: first element of the array
 * @high: last element of the array
 */
static int lomuto_partition(int *array, int low, int high)
{
	int pivot, i, j;
	pivot = array[high];
	i = (low - 1);

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			swap(&array[i], &array[j]);
		}
	}
	
	swap(&array[i + 1], &array[high]);
	return (i + 1);
}

/**
 * quick_sort_helper- sorts array using quick sort algorithm
 * @array: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of array
 */
static void quick_sort_helper(int *array, int low, int high)
{
	if (low < high)
	{
		int pivot = lomuto_partition(array, low, high);

		if (pivot > low)
			print_array(array, high + 1);

		quick_sort_helper(array, low, pivot - 1);
		quick_sort_helper(array, pivot + 1, high);
	}
}

/**
 * quick_sort - sotrs array using quick sort algorithm
 * @array: array to be sorted
 * @size: size of the array
*/

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_helper(array, 0, size - 1);
}