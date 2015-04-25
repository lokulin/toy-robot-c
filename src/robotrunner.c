#include "robotrunner.h"

typedef enum { MOVE, LEFT, RIGHT, REPORT, PLACE } command_enum;
static const char *commands[] = {"MOVE","LEFT","RIGHT","REPORT","PLACE"};

typedef enum { NORTH, EAST, SOUTH, WEST } direction_enum;
static const char *directions[] = {"NORTH","EAST","SOUTH","WEST"};

static const char *cmd_delimiter = " ";
static const char *arg_delimiter = ",";

typedef struct Command { char *name, *args, *guard; } Command;

typedef struct PlaceArgs {
  float x,y, direction;
  char *guard;
} PlaceArgs;

static Command get_command(char *input) {
  Command command;
  command.name = strsep(&input, cmd_delimiter);
  command.args = strsep(&input, cmd_delimiter);
  command.guard = strsep(&input, cmd_delimiter);
  return command;
}

static PlaceArgs get_place_args(char *input) {
  PlaceArgs args;
  char *xend, *yend, *x, *y, *direction;

  x = strsep(&input, arg_delimiter);
  y = strsep(&input, arg_delimiter);
  direction = strsep(&input, arg_delimiter);

  args.guard = strsep(&input, arg_delimiter);
  args.x = strtof(x, &xend);
  args.y = strtof(y, &yend);
  args.direction = 0.5 * index_of(direction, directions
                                  , sizeof(directions)/sizeof(directions[0]));

  if(args.direction == -0.5 || (int)(xend-x) == 0 || (int)(yend-y) == 0 )
  {
    args.guard = "Invalid Arguments";
  }

  return args;
}

static Robot send_command(Robot robot, Command cmd) {
    if(cmd.name != NULL && cmd.guard == NULL && strcmp(cmd.name,"")) {
      int c = index_of(cmd.name, commands, sizeof(commands) / sizeof(commands[0]));

      switch(c) {
      case MOVE  : return cmd.args == NULL ? robot.move(robot) : robot; break;
      case LEFT  : return cmd.args == NULL ? robot.left(robot) : robot; break;
      case RIGHT : return cmd.args == NULL ? robot.right(robot) : robot; break;
      case REPORT: return cmd.args == NULL ? robot.report(robot, directions) : robot; break;
      case PLACE : {
        PlaceArgs args = get_place_args(cmd.args);
        Table table = new_table(new_point(0,0), new_point(4,4));
        return args.guard == NULL ? robot.place(robot, new_point(args.x,args.y)
                                                , args.direction, table) : robot;
        break;
      }
      }
    }
    return robot;
}

int robot_runner(FILE *file) {
  char *buffer = NULL;
  size_t n = 0;
  ssize_t r;

  /*Make a magical invalid table space that contains nothing*/
  Table table = new_table(new_point(0,0), new_point(-1,-1));
  Robot robot = new_robot(new_point(1,2), 0.5, table);

  while((r=getline(&buffer, &n, stdin)) != -1) {
    char *line=strdup(buffer);
    if (line[r - 1] == '\n') {
        line[r - 1] = 0;
    }
    robot = send_command(robot,get_command(line));
    free(line);
  }

  free(buffer);
  return EXIT_SUCCESS;
}

int robot_tester() {
  Table table = new_table(new_point(0,0), new_point(4,4));
  Robot robot = new_robot(new_point(0,0), 0.0, table);
  int i;
  for(i=0; i<1000000; i++) {
    robot = robot.move(robot);
    robot = robot.left(robot);
    robot = robot.left(robot);
    robot = robot.move(robot);
    robot = robot.right(robot);
    robot = robot.right(robot);
  }
  return EXIT_SUCCESS;
}

