#include "sort.h"

/**
 * swap - swaps two elements of an array
 * @a: element one
 * @b: element two
 */
void swap(int *a, int *b)
{
	int t = *a;

	*a = *b;
	*b = t;
}
/**
 * partition - quicksort helper
 * @arr: the array given
 * @low: low number
 * @high: high number
 * @size: size of array
 * Return: a pivot
 */
int partition(int arr[], int low, int high, size_t size)
{
	int pivot = arr[high];
	int i = (low - 1), j, tmpi, tmpj, tmp;

	for (j = low; j <= high - 1; j++)
	{
		if (arr[j] <= pivot)
		{
			i++;
			tmpi = arr[i];
			tmpj = arr[j];
			swap(&arr[i], &arr[j]);
			if (tmpi != arr[i] && tmpj != arr[j])
				print_array(arr, size);
		}
	}
	tmp = arr[i + 1];
	swap(&arr[i + 1], &arr[high]);
	if (arr[i + 1] != tmp)
		print_array(arr, size);
	return (i + 1);
}
/**
 * quickSort - quicksorts
 * @arr: the array
 * @low: low number
 * @high: high number
 * @size: size of array
 */
void quickSort(int arr[], int low, int high, size_t size)
{
	int pi;

	if (low < high)
	{
		pi = partition(arr, low, high, size);
		quickSort(arr, low, pi - 1, size);
		quickSort(arr, pi + 1, high, size);
	}
}

/**
 * quick_sort - quick sort algorithm
 * @array: array given to us
 * @size: size of the array
 */

void quick_sort(int *array, size_t size)
{
	quickSort(array, 0, size - 1, size);
}
