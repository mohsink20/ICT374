#include "ex4.h"

int	main()
{

	int n1, n2, n3;

  // Get array sizes
	printf("Enter size for array 1: ");
	scanf("%d", &n1);

	printf("Enter size for array 2: ");
	scanf("%d", &n2);

	printf("Enter size for array 3: ");
	scanf("%d", &n3);

  // Allocate and populate arrays
	int* arr1 = getArray(n1);
	int* arr2 = getArray(n2);
	int* arr3 = getArray(n3);

  // Print arrays
	for(int i = 0; i < n1; i++)
	{
		printf("%d ", arr1[i]);
	}
	printf("\n");

	for(int i = 0; i < n2; i++)
	{
		printf("%d ", arr2[i]);
	}
	printf("\n");

	for(int i = 0; i < n3; i++)
	{
		printf("%d ", arr3[i]);
	}
	printf("\n");

  // Free memory
	free(arr1);
	free(arr2);
	free(arr3);

	return 0;
}
