#include <stdio.h>

int	square(int n)
{
	return n * n;
}

int	main()
{
  // Declare function pointer
	int (*fp)(int);

  // Print address of square function
	printf("Address of square function: %p\n", square);

  // Assign square function to fp
	fp = square;

  // Call square directly
	int	num1 = square(10);
	printf("Direct call: %d\n", num1);

  // Call square indirectly via fp
	int num2 = fp(10);
	printf("Indirect call: %d\n", num2);

	return 0;
}
