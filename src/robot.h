#include <stdio.h>
#include <math.h>
#include "point.h"
#include "table.h"
#include "util.h"

#ifndef ROBOT_T
#define ROBOT_T

typedef struct Robot Robot;

struct Robot {
  Point loc;
  float facing;
  Table table;
  Robot (*move)(Robot);
  Robot (*left)(Robot);
  Robot (*right)(Robot);
  Robot (*report)(Robot, const char **);
  Robot (*place)(Robot, Point, float, Table);
};

#endif

Robot new_robot(Point loc, float facing, Table table);

