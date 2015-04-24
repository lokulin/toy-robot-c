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

robot new_robot(point loc, float facing, table table);


