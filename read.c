#include <string.h>
#include <stdio.h>

char *readStdIn(char *buffer)
{
    char *result = fgets(buffer, 1024, stdin);
    int len;

    if (result == NULL) {
        return NULL;
    }

    len = strlen (buffer);
    if (len == 0) {
        return NULL;
    }

    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = 0;
    }

    return buffer;
}

int main() {
  char buffer[1024];

  while(readStdIn(buffer)) {
    printf("%s\n",buffer);
    if (strcmp(buffer, "MOVE") == 0) {
      printf("MOVIN!\n");
    }
  }
}
