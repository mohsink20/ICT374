#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int	main(int argc, char* argv[])
{
	int n = 5; // number of child processes to create 

	for (int i=1; i<=n; i++)
	{
		pid_t pid = fork();

		if (pid == 0)
		{ // child process
			printf("Child %d: PID: %d, PPID: %d\n", i, getpid(), getppid());
			sleep(i*60);
			exit(0);
		}
	}
	// parent waits for all children
	int	status;
	while (wait(&status) > 0);
	return 0;
}
