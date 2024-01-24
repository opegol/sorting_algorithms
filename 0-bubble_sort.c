#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * bubble_sort - sorts an array of integers in ascending order
 *		using the Bubble sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, k;
	int j, x;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		x = 0;
		for (k = 0; k < size - i - 1; k++)
			if (array[k] > array[k + 1])
			{
				j = array[k + 1];
				array[k + 1] = array[k];
				array[k] = j;
				x++;
				print_array(array, size);
			}
		if (x == 0)
			break;
	}
}
