#include "sort.h"
/**
 * bubble_sort - This sorts array lements from min to max value
 * @array: Represents an array
 * @size: Represents an array size
 */
void bubble_sort(int *array, size_t size)
{

	size_t a, index, tmp = 0;

	if (size < 2)
		return;
	for (a = 0; a < size; a++)
		for (index = 0; index < size; index++)
		{
			if (array[index] > array[index + 1] && array[index + 1])
			{
			tmp = array[index];
			array[index] = array[index + 1];
			array[index + 1] = tmp;
			print_array(array, size);
			}
		}
}
