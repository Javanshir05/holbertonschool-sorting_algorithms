#include "sort.h"

/**
 * lomuto_partition - Partitions the array using Lomuto scheme
 * @array: Array to partition
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 *
 * Return: Pivot index
 */
static int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1;
	int j;
	int tmp;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j)
			{
				tmp = array[i];
				array[i] = array[j];
				array[j] = tmp;
				print_array(array, size);
			}
		}
	}

	if (i + 1 != high && array[i + 1] != array[high])
	{
		tmp = array[i + 1];
		array[i + 1] = array[high];
		array[high] = tmp;
		print_array(array, size);
	}

	return (i + 1);
}

/**
 * quick_sort_recursive - Recursively sorts using quick sort
 * @array: Array to sort
 * @low: Starting index
 * @high: Ending index
 * @size: Size of the array
 */
static void quick_sort_recursive(int *array, int low, int high, size_t size)
{
	int p;

	if (low < high)
	{
		p = lomuto_partition(array, low, high, size);
		quick_sort_recursive(array, low, p - 1, size);
		quick_sort_recursive(array, p + 1, high, size);
	}
}

/**
 * quick_sort - Sorts an array using Quick sort (Lomuto)
 * @array: Array to sort
 * @size: Number of elements
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quick_sort_recursive(array, 0, size - 1, size);
}
