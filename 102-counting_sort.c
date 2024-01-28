#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * counting_sort - sorts an array of integers in ascending order
 *		using the Counting sort algorithm
 * @array: The array to be sorted
 * @size: Number of elements in @array
 */
void counting_sort(int *array, size_t size)
{
	size_t k;
	int j, i, max;
	int *count_array, *output_array;

	if (!array || size < 2)
		return;

	max = array[0];
	for (k = 1; k < size; k++)
	{
		if (array[k] > max)
			max = array[k];
	}
	count_array = malloc(sizeof(int) * (max + 1));
	output_array = malloc(sizeof(array));

	for (i = 0; i <= max; i++)
		count_array[i] = 0;

	for (k = 0; k < size; k++)
	{
		j = array[k];
		count_array[j]++;
	}
	for (i = 1; i <= max; i++)
		count_array[i] = count_array[i - 1] + count_array[i];

	print_array(count_array, max + 1);

	for (i = size - 1; i >= 0; i--)
	{
		j = array[i];
		--count_array[j];
		output_array[count_array[j]] = j;
	}
	for (k = 0; k < size; k++)
		array[k] = output_array[k];
	free(count_array);
	free(output_array);
}

