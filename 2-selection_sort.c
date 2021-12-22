#include "sort.h"

/**
 * selection_sort - print array using selection sort algorithm
 *@array: array to print
 *@size: array size
 *
 * Return: void
 */

void selection_sort(int *array, size_t size)
{
	size_t x;
	size_t flip;
	size_t index_tmp;
	size_t index;
	int y;

	x = index_tmp = 0;
	while (x < size)
	{
		index = x;
		flip = 0;
		y = array[x];
		while (index < size)
		{
			if (y > array[index])
			{
				y = array[index];
				index_tmp = index;
				flip = 1;
			}
			index++;
		}
		if (flip == 1)
		{
			array[index_tmp] = array[x];
			array[x] = y;
			print_array(array, size);
		}
		x++;
	}
}
