#include <stdio.h>
#include <unistd.h>

int	main()
{
	printf("Original parent PID: %d\n", getpid());
	fork();
	printf("After 1st fork PID: %d, PPID: %d\n", getpid(), getppid());

	fork();
	printf("After 2nd fork PID: %d, PPID: %d\n", getpid(), getppid());

	sleep(1000);
  	return 0;
}
