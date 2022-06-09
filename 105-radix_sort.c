#include "sort.h"

/**
 *set_array - setting array contents
 *@array: int array pointer
 *@dest: destination array
 *@size:  size of array
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
 *LSD_counting - sorting array of ints using LSD Radix sort algo
 *@array: int array
 *@sorted: int array
 *@size: size of array
 *@exp: exponetial
 */
void LSD_counting(int *array, int *sorted, size_t size, size_t exp)
{
	int site = 0;
	int *bucket = malloc(sizeof(int) * 10);
    size_t x;

	for (site = 0; site < 10; site++)
		bucket[site] = 0;

	for (site = 0; site < (int) size; site++)
	{
		x = (array[site] / exp) % 10;
		bucket[x] += 1;
	}
	for (site = 1; site < (int) size; site++)
		bucket[site] += bucket[site - 1];
	for (site = size - 1; site >= 0; site--)
	{
		x = (array[site] / exp) % 10;
		bucket[x] -= 1;
		sorted[bucket[x]] = array[site];
	}
	free(bucket);
}

/**
 *radix_sort - sort int array performing LSD Radix sorting algorithm
 *@array: the integer array
 *@size: the array size
 */

void radix_sort(int *array, size_t size)
{
	int *sorted;
    int min = 0;
    int max = 0;
	size_t site = 0;
    size_t exp = 1;

	if (size < 2)
		return;
	sorted = malloc(sizeof(int) * size);
	set_array(array, sorted, size);
	min = array[0];
	max = array[0];
	for (site = 1; site < size; site++)
	{
		if (array[site] < min)
			min = array[site];
		else if (array[site] > max)
			max = array[site];
	}
	exp = 1;
	while ((max - min) / exp >= 1)
	{
		LSD_counting(array, sorted, size, exp);
		print_array(sorted, size);
		exp *= 10;
		set_array(sorted, array, size);
	}
	free(sorted);
}
