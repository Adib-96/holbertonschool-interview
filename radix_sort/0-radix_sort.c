#include "sort.h"
#include <stdlib.h>

/**
 * get_max - Finds the maximum value in an array
 * @array: The array to search
 * @size: Number of elements in the array
 * Return: The maximum integer in the array
 */
int get_max(int *array, size_t size)
{
int max = array[0];
for (size_t i = 1; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
return (max);
}

/**
 * counting_sort - Performs a counting sort on the array based on a digit
 * @array: The array to sort
 * @size: Number of elements in the array
 * @exp: Exponent representing the digit to sort by
 */
void counting_sort(int *array, size_t size, int exp)
{
int *output = malloc(size * sizeof(int));
int count[10] = {0};
if (!output)
return;
for (size_t i = 0; i < size; i++)
count[(array[i] / exp) % 10]++;
for (int i = 1; i < 10; i++)
count[i] += count[i - 1];
for (int i = size - 1; i >= 0; i--)
{
output[count[(array[i] / exp) % 10] - 1] = array[i];
count[(array[i] / exp) % 10]--;
}
for (size_t i = 0; i < size; i++)
array[i] = output[i];
free(output);
print_array(array, size);
}

/**
 * radix_sort - Sorts an array of integers in ascending order using the LSD
 * @array: The array to sort
 * @size: Number of elements in the array
 */
void radix_sort(int *array, size_t size)
{
if (size < 2)
return;
int max = get_max(array, size);
for (int exp = 1; max / exp > 0; exp *= 10)
counting_sort(array, size, exp);
}
