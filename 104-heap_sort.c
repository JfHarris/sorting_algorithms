#include <stdlib.h>
#include <stdio.h>
#include "sort.h"

/**
 * switch_e - switches list elements
 * @array: array of elements
 * @x: location
 * @y: var
 * @size: size
 */

void switch_e(int *array, int x, int y, int size)
{
    int new = 0;

    new = array[x];
    array[x] = array[y];
    array[y] = new;
    print_array(array, size);
}

/**
  * heap_find - Selection sort
  * @array: array
  * @find: find
  * @switc: switch
  * @size: size
  */

void heap_find(int *array, int find, int switc, int size)
{
    int x = switc;
    int l = (switc * 2) + 1;
    int r = (switc * 2) + 2;

    if (l < find && array[l] > array[x])
        x = l;

    if (r < find && array[r] > array[x])
        x = r;

    if (x != switc)
    {
        switch_e(array, switc, x, size);
        heap_find(array, find, x, size);
    }
}

/**
  * heap_sort - heap sort
  * @array: array
  * @size: size
  */

void heap_sort(int *array, size_t size)
{
    int x = 0;
    int sz = size;

    for (x = (size / 2) - 1; x >= 0; x--)
        heap_find(array, sz, x, size);

    for (x = size - 1; x >= 0; x--)
    {
        if (x != 0)
            switch_e(array, x, 0, size);
        heap_find(array, x, 0, size);
    }
}
