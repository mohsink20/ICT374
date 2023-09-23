#include <stdio.h>

int	main()
{
	int	date;
	char	month[10];
	int	year;

	printf("Enter date in format DD-MMM-YYYY: ");
	scanf("%d-%3s-%d", &date, month, &year);

	printf("Date: %d\n", date);
	printf("Month: %s\n", month);
	printf("Year: %d\n", year);

	return 0;
}
