#include "sort.h"

/**
 * partition - short description
 *
 * @array: argument_1 description
 * @low: argument_2 description
 * @high: argument_2 description
 * @size: argument_2 description
 *
 * Return: return description
 */
size_t partition(int **array, size_t low, size_t high, size_t size)
{
	size_t i, j;
	int tmp, pivot;

	pivot = (*array)[high];
	i = low - 1;
	for (j = low; j < high; j++)
	{
		if ((*array)[j] <= pivot)
		{
			i++;
			tmp = (*array)[i];
			(*array)[i] = (*array)[j];
			(*array)[j] = tmp;
			if ((*array)[i] != (*array)[j])
				print_array(*array, size);
		}
	}

	tmp = (*array)[i + 1];
	(*array)[i + 1] = (*array)[high];
	(*array)[high] = tmp;
	if ((*array)[i + 1] != (*array)[high])
		print_array(*array, size);
	return (i + 1);
}


/**
 * qS - short description
 *
 * Description: long description
 * 
 * @array: argument_1 description
 * @low: argument_2 descrip
 * @high: argument_2 description
 * @size: argument_2 description
 * Return: return description
 */
void qS(int **array, size_t low, size_t high, size_t size)
{
	size_t pi;

	if (low < high)
	{
		pi = partition(array, low, high, size);

		if (pi != 0)
			qS(array, low, (pi - 1), size);
		if (pi < size - 1)
			qS(array, (pi + 1), high, size);
	}
}


/**
 * quick_sort - short description
 * 
 * Description: long description
 * 
 * @array: argument_1 description
 * @size: argument_2 description
 * 
 * Return: return description
 */
void quick_sort(int *array, size_t size)
{
	if (size > 1)
		qS(&array, 0, (size - 1), size);
}
