// file:		token.c for Week 7
// author:		Mohsin Ali Khan
// date:		2023.10.20
// last modified:	2023.10.20
// note:		not thoroughlt tested, therefore it may contain errors

#include <string.h>
#include "token.h"

int tokenise (char line[], char *token[])
{
      char *tk;
      int i=0;

      tk = strtok(line, tokenSeparators);
      token[i] = tk;

      while (tk != NULL) {

          ++i;
          if (i>=MAX_NUM_TOKENS) {
              i = -1;
              break;
          }

          tk = strtok(NULL, tokenSeparators);
          token[i] = tk;
      }
      return i;
}
