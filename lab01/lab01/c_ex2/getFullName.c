/*  file:	getFullName.c
 *  author:	Mohsin Ali Khan (34072315)
 *  date:	23/09/23
 *  revised:	23/09/23
 */

#include <stdio.h>
#include <stdlib.h>

# define BUFSIZE 128

int	main(void)
{
	char name[BUFSIZE];

	printf("Type your full name: ");
	fgets(name, BUFSIZE, stdin);

	printf("Your name is %s\n", name);

	exit(0);
}
