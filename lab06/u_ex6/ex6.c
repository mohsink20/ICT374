#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {

  int flags;

  sleep(5);

  // Set stdin to non-blocking
  flags = fcntl(STDIN_FILENO, F_GETFL, 0);
  fcntl(STDIN_FILENO, F_SETFL, flags | O_NONBLOCK);

  char input[100];
  int n = read(STDIN_FILENO, input, 100);
  
  if (n > 0) {
    // Got input
    printf("Input: %s\n", input); 
  } else {
    printf("No input!\n");
  }

  return 0;
}
