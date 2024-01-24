#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - sorts an array of integers in ascending order
 *		using the Shell sort algorithm and Knuth sequence
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, g = 1, s, k, i;
	int temp;

	if (!array || size < 2)
		return;

	s = size;
	while (g)
	{
		gap = g;
		g = g * 3 + 1;
		if (g > s)
			break;
	}
	while (gap > 0)
	{
		for (k = gap; k < size; k++)
		{
			i = k;
			while ((i >=  gap) && array[i] < array[i - gap])
			{
				temp = array[i];
				array[i] = array[i - gap];
				array[i - gap] = temp;
				i -= gap;
			}
		}
		gap = (gap - 1) / 3;
		print_array(array, size);
	}
}
