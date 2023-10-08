#include <stdio.h>

int	main()
{

	int	ai[10];
	int	*pi;
	int	i;

	for (i=0; i<10; ++i)
	ai[i] = i + 100;    // initialise each array element

	pi = ai;       // let pi point to the array
                       // alternatively, pi = &ai[0];

	for (i=0; i<10; ++i)
	{
		printf("Notation 1: a[%d]=%d\n", i, ai[i]); // array notation
		printf("Notation 2: a[%d]=%d\n", i, pi[i]); // pointer notation

		printf("Notation 3: a[%d]=%d\n", i, *(ai + i)); // array + offset
		printf("Notation 4: a[%d]=%d\n", i, *(pi + i)); // pointer + offset

		pi = pi + i; // increment pointer
		printf("Notation 5: a[%d]=%d\n", i, *pi); // dereference updated pointer

		pi = ai + i; // reset pointer to array + offset
		printf("Notation 6: a[%d]=%d\n", i, *pi); // dereference pointer
	}
	return 0;
}
