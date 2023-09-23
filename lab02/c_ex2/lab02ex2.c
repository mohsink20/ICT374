#include <stdio.h>

int	main()
{
	char	*fname = "foo2";
	FILE *fstr;

	fstr = fopen(fname, "w+");
	if (fstr == NULL) {
	fprintf(stderr, "Cannot open file %s, terminate program\n", fname);
	return 1;
}
	int day = 8;
	char *month = "August";
	int year = 2020;

	fprintf(fstr, "Today is %04d %s %d.\n", day, month, year);

	fclose(fstr);
	return 0;
}
