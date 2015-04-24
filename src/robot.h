#include <stdio.h>
#include <math.h>
#include "point.h"
#include "table.h"

#ifndef ROBOT_T
#define ROBOT_T

typedef struct robot robot;

struct robot {
  point loc;
  float facing;
  table table;
  robot (*move)(robot);
  robot (*left)(robot);
  robot (*right)(robot);
  robot (*report)(robot);
  robot (*place)(robot, point, float, table);
};

#endif

robot robot_move(robot self);
robot robot_left(robot self);
robot robot_right(robot self);
robot robot_report(robot self);
robot robot_place(robot self, point loc, float facing, table table);
robot new_robot(point loc, float facing, table table);

float mod(float x, float y);

