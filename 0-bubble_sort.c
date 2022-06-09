#include "sort.h"
/*s*/
/**
 * bubble_sort - Prints an array of integers in ascending order
 *
 * @array: The array to be printed
 * @size: size of array
 */

void bubble_sort(int *array, size_t size)
{
	size_t tmp;
	size_t flip;
	size_t x;
	int y;

	flip = 1;
	tmp = size;

	if (array == NULL || size == 0)
	{
		return;
	}
	while (flip)
	{
		flip = 0;
		for (x = 0 ; x < tmp - 1 ; x++)
		{
			if (array[x] > array[x + 1])
			{
				y = array[x];
				array[x] = array[x + 1];
				array[x + 1] = y;
				flip = 1;
				print_array(array, size);
			}
		}
		tmp = x;
	}
}
