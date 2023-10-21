#include <stdio.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

  struct stat sb;

  if (argc != 2) {
    printf("Usage: %s <filename>\n", argv[0]);
    return 1;
  }

  if (stat(argv[1], &sb) == -1) {
    perror("stat");
    return 1;
  }

  printf("File type: ");

  switch (sb.st_mode & S_IFMT) {
    case S_IFBLK:  printf("block device\n");            break;
    case S_IFCHR:  printf("character device\n");        break;
    case S_IFDIR:  printf("directory\n");               break;
    case S_IFIFO:  printf("FIFO/pipe\n");               break;
    case S_IFLNK:  printf("symlink\n");                 break;
    case S_IFREG:  printf("regular file\n");            break;
    case S_IFSOCK: printf("socket\n");                  break;
    default:       printf("unknown?\n");                break;
  }

  printf("File permissions: ");
  printf( (sb.st_mode & S_IRUSR) ? "r" : "-");
  printf( (sb.st_mode & S_IWUSR) ? "w" : "-");
  printf( (sb.st_mode & S_IXUSR) ? "x" : "-");
  printf( (sb.st_mode & S_IRGRP) ? "r" : "-");
  printf( (sb.st_mode & S_IWGRP) ? "w" : "-");
  printf( (sb.st_mode & S_IXGRP) ? "x" : "-");
  printf( (sb.st_mode & S_IROTH) ? "r" : "-");
  printf( (sb.st_mode & S_IWOTH) ? "w" : "-");
  printf( (sb.st_mode & S_IXOTH) ? "x" : "-");
  printf("\n");

  printf("Inode number: %ld\n", (long) sb.st_ino);

  printf("File size: %lld bytes\n", (long long) sb.st_size);

  return 0;
}
