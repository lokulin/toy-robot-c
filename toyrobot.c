#define _GNU_SOURCE
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "src/point.h"
#include "src/table.h"
#include "src/robot.h"

typedef enum { MOVE, LEFT, RIGHT, REPORT, PLACE } commands;
static char *str_commands[] = {"MOVE","LEFT","RIGHT","REPORT","PLACE"};
static int num_commands = sizeof(str_commands)/sizeof(str_commands[0]);

typedef enum { NORTH, EAST, SOUTH, WEST } directions;
static char *str_directions[] = {"NORTH","EAST","SOUTH","WEST"};
static int num_directions = sizeof(str_directions)/sizeof(str_directions[0]);


int main() {
  char *buffer = NULL;
  size_t n = 0;
  table table = new_table(new_point(0,0), new_point(-1,-1));
  robot robot = new_robot(new_point(1,2), 0.5, table);

  while(getline(&buffer, &n, stdin) != -1) {
    int cmd = -1;
    int i = 0;
    int len = strlen (buffer);

    if (buffer[len - 1] == '\n') {
        buffer[len - 1] = 0;
    }

    /*TODO split buffer in to command and arguments */

    for(i = 0; i < num_commands; i++) {
      if (strcmp(buffer, str_commands[i]) == 0) {
        cmd = i;
      }
    }

    switch( cmd ) {
      case MOVE  : robot = robot.move(robot); break;
      case LEFT  : robot = robot.left(robot); break;
      case RIGHT : robot = robot.right(robot); break;
      case REPORT: robot.report(robot); break;
      case PLACE : printf("Place Robot facing in one of %d directions\n", num_directions); break;
    }

  }

  free(buffer);
  return 0;
}

