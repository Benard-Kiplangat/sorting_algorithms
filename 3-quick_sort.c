#include "sort.h"

/**
  * quick_sort - a function that implements the quicksort algorithm and
  * prints the array for every swap
  *
  * @array: the array to be sort
  * @size: size of array
  *
  * Return: nothing
  */

void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quickSort(array, 0, size - 1, size);
}

/**
  * sort_array - a recursive function to sort a partition of the array
  *
  * @arr: the array to sort
  * @low: starting index of every array's partition
  * @high: the last index of the partition
  * @size: the size of the whole array
  */

void quickSort(int *array, int beg, int end, size_t size)
{
	int pivot = (int) size;

	if (beg < end)
	{
		pivot = partition(array, beg, end, size);
		quickSort(array, beg, pivot - 1, size);
		quickSort(array, pivot + 1, end, size);
	}
}
/**
  * partition - a function that determines the pivot of an array using lumoto's
  *
  * @array: the array to partition
  * @low: the starting index of an array to partition
  * @high: the last index of the array to partition
  * @size: the size of the full array
  *
  * Return: the index of the pivot
  */
int partition(int *array, int beg, int end, size_t size)
{
	int i = beg, j = 0, pivot = array[end], tmp = 0;

	for (j = beg; j < end; j++)
	{
		if (array[j] < pivot)
		{
			if (i != j)
			{
				tmp = array[j];
				array[j] = array[i];
				array[i] = tmp;
				print_array(array, size);
			}
			i++;
		}
	}
	if (array[i] != array[end])
	{
		tmp = array[i];
		array[i] = array[end];
		array[end] = tmp;
		print_array(array, size);
	}
	return (i);
}
