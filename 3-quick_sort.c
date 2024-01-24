#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * quick_sort - sorts an array of integers in ascending order
 *		using the Quick sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void quick_sort(int *array, size_t size)
{
	size_t j;
	int i = 0, temp, piv;

	if (size <= 1)
		return;

	piv = array[size - 1];
	for (j = 0; j < size - 1; j++)
	{
		if (piv <= array[j])
			continue;
		else
		{
			temp = array[i];
			array[i] = array[j];
			array[j] = temp;
			i++;
			print_array(array, size);
		}
	}

	temp = array[i];
	array[i] = array[size - 1];
	array[size - 1] = temp;
	print_array(array, size);

	quick_sort(array, i);
	quick_sort(&array[i + 1], size - i - 1);
}
