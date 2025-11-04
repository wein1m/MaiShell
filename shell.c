#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINEBUF 1024

struct Command {
  char *name;
  void (*func)(void);
};

void cmd_exit() {
  printf("baii baii~🐇\n");
  exit(0);
}

void cmd_clear() { system("cls"); }

void cmd_hello() {
  printf("HEHEEE~ HELLOOWWW THEREEE MY LITTE BUNNBUNNNN🐰\n");
}

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

void handleCommand(char *cmd, struct Command *commands, size_t len) {
  if (!cmd) {
    return;
  } else if (strcmp(cmd, "") == 0) {
    return;
  }

  int found = 0;
  for (struct Command *p = commands; p < commands + len; p++) {
    if (strcmp(cmd, p->name) == 0) {
      p->func();
      found = 1;
      break;
    }
  }

  if (!found)
    printf("heh~ that '%s' isn't inside my dict, bunny. try to use '/help'\n",
           cmd);
}

int main() {
  char line[LINEBUF];
  struct Command commands[] = {
      {"exit", cmd_exit},
      {"clear", cmd_clear},
      {"hello", cmd_hello},
  };

  while (1) {
    printf("MaiShell ~> ");

    if (fgets(line, sizeof(line), stdin)) {
      trim(line);
      // printf("hehe~ '%s'??🐰\n", line);
      handleCommand(line, commands, (sizeof(commands) / sizeof(commands[0])));
    }
  }
}
