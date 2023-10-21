// main.c

#include <stdio.h>
#include <string.h>
#include "token.h"

int main() {
  char input[100];
  char *tokens[MAX_NUM_TOKENS];
  int n;

  while (1) {
    printf(">> ");
    fgets(input, 100, stdin);

    if (input[strlen(input)-1] == '\n') {
      input[strlen(input)-1] = '\0';
    }

    if (strcmp(input, "exit") == 0) {
      break;
    }

    n = tokenise(input, tokens);

    if (n < 0) {
      printf("Too many tokens!\n");
    } else {
      for (int i = 0; i < n; i++) {
        printf("%s ", tokens[i]);
      }
      printf("\n");
    }

  }

  return 0;
}
