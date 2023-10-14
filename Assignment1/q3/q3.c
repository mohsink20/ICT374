#include "q3.h"

int	executeCommand(const char *command)
{
	pid_t pid = fork();

	if (pid < 0)
	{
		perror("fork");
		return -1;
	}
	else if (pid == 0)
	{
        // Child process
		char *args[] = {(char *)command, NULL}; // Cast to non-const
		execv(command, args); // Use execv for PATH-based command execution
		perror("execv"); // Executing command failed
		exit(1); // Terminate child with an error code
	}
	else {
        // Parent process
		int	status;

		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			return WEXITSTATUS(status); // Return the exit status of the child
		}
		return -1; // Child did not exit normally
    	}
}

void	executeCommandsConcurrently(int argc, char *argv[])
{
	int	num_commands = argc - 1;

	printf("Executing %d commands concurrently:\n", num_commands);

	for (int i = 1; i <= num_commands; i++)
	{
		const char *command = argv[i];
		int exit_status = executeCommand(command);

		if (exit_status == 0)
		{
			printf("Command '%s' has completed successfully\n", command);
		}
		else if (exit_status == -1)
		{
			printf("Command '%s' failed to execute\n", command);
		}
		else
		{
			printf("Command '%s' has not completed successfully (Exit Status: %d)\n", command, exit_status);
		}
	}
}
