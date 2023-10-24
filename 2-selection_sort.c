#include "sort.h"

/**
 * selection_sort - a function that sorts an array of integers in
 * ascending order using selection sort algorithim
 *
 * @array: the array to sort
 * @size: the size of the array
 */

void selection_sort(int *array, size_t size)
{
	size_t i, j, k;
	int min;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = array[i];
		j = i + 1;
		k = i;
		while (j < size)
		{
			if (min > array[j])
			{
				min = array[j];
				k = j;
			}
			j++;
		}
		if (i != k)
		{
			array[k] = array[i];
			array[i] = min;
		}
		print_array(array, size);
	}
}
