#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * selection_sort - sorts an array of integers in ascending order
 *		using the Selection sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, k, ind = 0;
	int j, min, x;

	if (!array || size < 2)
		return;

	for (i = 0; i < size - 1; i++)
	{
		x = 0;
		min = array[i];

		for (k = i + 1; k < size; k++)
			if (min > array[k])
			{
				min = array[k];
				ind = k;
				x++;
				continue;
			}
		if (x > 0)
		{
			j = array[i];
			array[i] = array[ind];
			array[ind] = j;
			print_array(array, size);
		}
	}
}
