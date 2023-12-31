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
	unsigned long int i, j, k;
	int min;

	if (size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		k = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[k])
				k = j;
		}
		if (i != k)
		{
			min = array[i];
			array[i] = array[k];
			array[k] = min;
			print_array(array, size);
		}
	}
}
