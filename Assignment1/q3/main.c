#include "myshell.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		fprintf(stderr, "Usage: %s <command1> <command2> ... <commandN>\n", argv[0]);
		return 1;
	}
	executeCommandsConcurrently(argc, argv);
	printf("All done, bye-bye!\n");

	return 0;
}
