#include "ex2.h"

void	fillArray(int *array, int arraySize)
{
	for(int i = 0; i < arraySize; i++)
	{
		printf("Enter number %d: ", i+1);
		scanf("%d", &array[i]);
	}
}
