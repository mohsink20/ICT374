#include "ex4.h"

int	*getArray(int arraySize)
{
	int*	array = malloc(arraySize * sizeof(int));

	if(array == NULL)
	{
		printf("Error allocating memory\n");
		exit(1);
	}
	// Moved fillArray logic into getArray
	for(int i = 0; i < arraySize; i++)
	{
		printf("Enter number %d: ", i+1);
		scanf("%d", &array[i]);
	}
	return array;
}
