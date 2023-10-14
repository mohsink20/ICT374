#ifndef Q3_H
# define Q3_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Function to execute a command in a child process
int executeCommand(const char *command);

// Function to execute multiple commands concurrently
void executeCommandsConcurrently(int argc, char *argv[]);

#endif
