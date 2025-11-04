#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEBUF 1024

void trim(char *s) {
  // change '\n' into '\0' in the end of line so it's easier to handle
  for (int i = 0; i < strlen(s); i++) {
    if (s[i] == '\n') {
      s[i] = '\0';
      break;
    }
  }

  // Trim leading spaces on the left ('  hello' -> 'hello')
  char *start = s;
  while (isspace(*start))
    start++;
  if (start != s)
    memmove(s, start, strlen(start) + 1);

  // Trim leading spaces on the rigth ('hello  ' -> 'hello')
  size_t len = strlen(s);
  while (len > 0 && isspace(s[len - 1])) {
    s[len - 1] = '\0';
    len--;
  }
}

void handleCommand(char *cmd) {
  if (!cmd) {
    return;
  } else if (strcmp(cmd, "") == 0) {
    return;
  }

  if (strcmp(cmd, "exit") == 0) {
    printf("baii baii~🐇");
    exit(0);
  } else if (strcmp(cmd, "clear") == 0) {
    system("cls");
  } else if (strcmp(cmd, "hello") == 0) {
    printf("HEHEEE~ HELLOOWWW THEREEE MY LITTE BUNNBUNNNN🐰\n");
  } else {
    printf("heh~ that '%s' isn't inside my dict, bunny. try to use '/help'\n",
           cmd);
  }
}

int main() {
  char line[LINEBUF];

  while (1) {
    printf("MaiShell ~> ");

    if (fgets(line, sizeof(line), stdin)) {
      trim(line);
      // printf("hehe~ '%s'??🐰\n", line);
      handleCommand(line);
    }
  }
}
