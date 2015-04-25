#include <stdio.h>
#include "src/robotrunner.h"

int usage() {
  fprintf(stderr, "usage: toyrobot [file] | [< file]\n");
  return EXIT_FAILURE;
}

int failure() {
  fprintf(stderr, "Problem opening file for reading.\n");
  return EXIT_FAILURE;
}

int main(int argc, char *argv[]) {
  switch(argc) {
    case 1: exit(robot_runner(stdin));
    case 2: {
      FILE *file = fopen(argv[1], "r");
      file != NULL ? exit(robot_runner(file)) : exit(failure());
    }
    default: exit(usage());
  }
}

