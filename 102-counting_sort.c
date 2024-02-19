#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Get the maximum value in an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Return: The maximum integer in the array.
 */
int get_max(int *array, int size)
{
	int max = array[0];
	int a;

	max = array[0];
	for (a = 1; a < size; a++)
	{
	if (array[a] > max)
		max = array[a];
	}

	return (max);
}

/**
 * counting_sort - Sort an array of integers in ascending order
 *                 using the counting sort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Prints the counting array after setting it up.
 */
void counting_sort(int *array, size_t size)
{
	int max;
	int *count;
	int *sorted;
	int a;

	if (array == NULL || size < 2)
		return;

	max = get_max(array, size);

	count = malloc(sizeof(int) * (max + 1));
	if (count == NULL)
		return;

	sorted = malloc(sizeof(int) * size);
	if (sorted == NULL)
	{
		free(count);
		return;
	}


	for (a = 0; a < (max + 1); a++)
		count[a] = 0;
	for (a = 0; a < (int)size; a++)
		count[array[a]] += 1;
	for (a = 1; a < (max + 1); a++)
		count[a] += count[a - 1];
	print_array(count, max + 1);

	for (a = size - 1; a >= 0; a--)
	{
		sorted[count[array[a]] - 1] = array[a];
		count[array[a]] -= 1;
	}

	for (a = 0; a < (int)size; a++)
		array[a] = sorted[a];

	free(sorted);
	free(count);
}
