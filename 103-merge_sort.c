#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 *init_merge_sort - merge sort algorithm
 *@array: int array pointer
 *@first: size of array
 *@middle: size of array
 *@last: size of array
 *@dest: int array pointer
 */
void init_merge_sort(int *array, size_t first, size_t middle, size_t last, int *dest)
{
	size_t x = first;
	size_t y = middle;
	size_t z;

	for (z = first; z < last; z++)
	{
		if (x < middle && (y >= last || array[x] <= array[y]))
		{
			dest[z] = array[x];
			x = x + 1;
		}
		else
		{
			dest[z] = array[y];
			y = y + 1;
		}
	}
}

/**
 *split - output format
 *@dest: int array pointer
 *@first: size of array
 *@last: size of array
 *@array: int array pointer
 */

void split(int *dest, size_t first, size_t last, int *array)
{
	size_t middle;
	size_t x;

	if (last - first < 2)
		return;
	middle = (last + first) / 2;
	split(array, first, middle, dest);
	split(array, middle, last, dest);
	init_merge_sort(dest, first, middle, last, array);

	printf("Merging...\n");
	printf("[left]: ");
	for (x = first; x < middle; x++)
	{
		printf("%d", dest[x]);
		if (x < middle - 1)
			printf(", ");
	}
	printf("\n[right]: ");
	for (x = middle; x < last; x++)
	{
		printf("%d", dest[x]);
		if (x < last - 1)
			printf(", ");
	}
	printf("\n[Done]: ");
	for (x = first; x < last; x++)
	{
		printf("%d", array[x]);
		if (x < last - 1)
			printf(", ");
		else
			printf("\n");
	}
}

/**
 *set_array - setting array contents
 *@array: int array pointer
 *@dest: destination array
 *@size: size of array
 */

void set_array(int *array, int *dest, size_t size)
{
	size_t site = 0;

	for (site = 0; site < size; site++)
	{
		dest[site] = array[site];
	}
}

/**
 *merge_sort - sorts array of ints in ascending order using Merge sort algo
 *@array: int array pointer
 *@size: size of array
 */

void merge_sort(int *array, size_t size)
{
	int *dest = malloc(sizeof(int) * size);

	set_array(array, dest, size);
	split(dest, 0, size, array);
	free(dest);
}
