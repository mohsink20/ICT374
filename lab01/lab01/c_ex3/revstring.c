#include <stdio.h>
#include <string.h>

size_t	my_strlen(const char *str)
{
	int	i = 0;
	while (str[i])
		++i;
	return (i);
}
int	main()
{
	char 	line[100];
	fgets(line, sizeof(line), stdin);

	int length = my_strlen(line);
	for(int i = length - 1; i >= 0; i--)
	{
		printf("%c", line[i]);
	}
	printf("\n");
	return 0;
}
