#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
* init_merge_sort - top-down merge sort algorithm
* @array: array to sort
* @temp: array to hold info
* @size: array size
*/

void init_merge_sort(int *array, int *temp, size_t size)
{
size_t half = size / 2;
	size_t x, y = 0;
	size_t z;

	if (size < 2)
		return;

	init_merge_sort(array, temp, half);
	init_merge_sort(array + half, temp + half, size - half);

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array, half);
	printf("[right]: ");
	print_array(array + half, size - half);
	for (z = 0; z < size; z++)
		if (y >= size - half || (x < half && array[x] < (array + half)[y]))
		{
			temp[z] = array[x];
			x++;
		}
		else
		{
			temp[z] = (array + half)[y];
			y++;
		}
	for (z = 0; z < size; z++)
		array[z] = temp[z];
	printf("[Done]: ");
	print_array(array, size);
}

/**
* merge_sort - initiate merge sort
* @array: array to be sorted
* @size: size of the array
*/
void merge_sort(int *array, size_t size)
{
	int *temp;

	if (!array || size < 2)
		return;

	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		return;

	init_merge_sort(array, temp, size);
	free(temp);
}
