#include "util.h"

int index_of(char *needle, const char **haystack, int length) {
  int i;
  int needle_pos = -1;
  if(needle != NULL) {
    for(i = 0; needle_pos == -1 && i < length; i++) {
      needle_pos = strcmp(needle, haystack[i]) == 0 ? i : -1;
    }
  }
  return needle_pos;
}

float mod(float x, float y) {
  return x - y * floor(x/y);
}

