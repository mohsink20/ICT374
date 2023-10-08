#include "ex2.h"

int	main()
{

	int	arr1[5];
	int	arr2[10];
	int	arr3[15];

	printf("Filling array 1:\n");
	fillArray(arr1, 5);

	printf("Filling array 2:\n");
	fillArray(arr2, 10);

	printf("Filling array 3:\n");
	fillArray(arr3, 15);

	printf("Displaying arrays:\n");
	for(int i = 0; i < 5; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");

	for(int i = 0; i < 10; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	for(int i = 0; i < 15; i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");

	return 0;
}
