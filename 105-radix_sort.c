#include "sort.h"

#include "sort.h"

/**
* find_largest - finds largest val of array
* @array: array to search
* @size: array size
* Return: Largest value
*/

int find_largest(int *array, size_t size)
{
	int x;
	int max;

	max = 0;

	for (x = 0; x < (int)size; x++)
	{
		if (max < array[x])
			max = array[x];
	}
	return (max);
}

/**
* radix_sort - Sorts array using radix algorithm
* @array: Array to sort
* @size: size of array
* Return: void
*/

void radix_sort(int *array, size_t size)
{
	int x;
	int site;
	int *y;
	int *z;

	if (array == NULL || size < 2)
		return;
	x = find_largest(array, size);
	y = malloc(sizeof(int) * (int)size);
	z = malloc(sizeof(int) * (10));
	if (z == NULL || y == NULL)
		return;
	for (site = 1; x / site > 0; site *= 10)
		count_sort(array, size, site, y, z), print_array(array, size);
	free(y);
	free(z);
}

/**
* count_sort - sorts array by counting
* @array: rray to sort
* @size: size of array
* @site: value site
* @y: temporary 
* @z: array
* Return: void
*/

void count_sort(int *array, size_t size, int site, int *y, int *z)
{
	int x;

	if (array == NULL || size < 2)
		return;
	for (x = 0; x < 10; x++)
		z[x] = 0;
	for (x = 0; x < (int)size; x++)
		z[((array[x] / site) % 10)] += 1;
	for (x = 0; x < 10; x++)
		z[x] += z[x - 1];
	for (x = size - 1; x >= 0; x--)
	{
		y[z[((array[x] / site) % 10)] - 1] = array[x];
		z[((array[x] / site) % 10)] -= 1;
	}
	for (x = 0; x < (int)size; x++)
		array[x] = y[x];
}
