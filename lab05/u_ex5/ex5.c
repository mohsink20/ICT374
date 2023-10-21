#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

  pid_t pid;

  // Fork off the parent process
  pid = fork();

  // An error occurred
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  // Success: Let the parent terminate
  if (pid > 0) {
    printf("Daemon PID: %d\n", pid);
    exit(EXIT_SUCCESS);
  }

  // On success: The child process becomes session leader
  if (setsid() < 0) {
    exit(EXIT_FAILURE);
  }

  // Ignore signal sent from child to parent process
  signal(SIGCHLD, SIG_IGN);

  // Fork off for the second time
  pid = fork();

  // An error occurred
  if (pid < 0) {
    exit(EXIT_FAILURE);
  }

  // Terminate the parent process
  if (pid > 0) {
    exit(EXIT_SUCCESS);
  }

  // Set new file permissions
  umask(0);

  // Change the working directory
  chdir("/");

  // Close all open file descriptors
  int x;
  for (x = sysconf(_SC_OPEN_MAX); x>=0; x--) {
    close (x);
  }

  // Open the log file
  int fd = open("daemon.log", O_WRONLY|O_CREAT|O_APPEND, 0644);

  // Write to the log file every 10 seconds
  while (1) {
    write(fd, "I have nothing to do\n", 22);
    sleep(10);
  }

}
