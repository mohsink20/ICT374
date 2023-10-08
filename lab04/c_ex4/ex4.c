#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int	main()
{
	pid_t	pid = fork();

	if (pid == 0)
	{
		printf("Child process PID: %d\n", getpid());
		printf("Child PPID: %d\n", getppid());
		sleep(100);
	}
	else
	{
		printf("Parent process PID: %d\n", getpid());
		printf("Parent waiting for child...\n");
		wait(NULL);
		printf("The child has terminated\n");
	}
	return 0;
}
