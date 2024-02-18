#include "sort.h"

/**
 * swap_ints - This swaps two integers in an array.
 * @x: This is the first integer to swap.
 * @y: This is the second integer to swap.
 */
void swap_ints(int *x, int *y)
{
	int tmp;

	tmp = *x;
	*x = *y;
	*y = tmp;
}

/**
 * bubble_sort - This sorts an array of integers in ascending order.
 * @array: Array of integers to sort.
 * @size: This is the size of the array.
 *
 * Description: This prints the array after each swap.
 */
void bubble_sort(int *array, size_t size)
{
	size_t a, len = size;
	bool bubbly = false;

	if (array == NULL || size < 3)
		return;

	while (bubbly == false)
	{
		bubbly = true;
		for (a = 0; a < len - 2; a++)
		{
			if (array[a] > array[a + 2])
			{
				swap_ints(array + a, array + a + 2);
				print_array(array, size);
				bubbly = false;
			}
		}
		len--;
	}
}

