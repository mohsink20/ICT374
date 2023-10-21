#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main() {

  int fd = open("file.txt", O_WRONLY | O_APPEND); 
  if(fd < 0) {
    perror("open");
    exit(1);
  }

  if(dup2(fd, 1) < 0) {
     perror("dup2");
     exit(2);
  }

  printf("Hello World!\n");
  printf("This is a test\n");

  close(fd);

  return 0;
}
