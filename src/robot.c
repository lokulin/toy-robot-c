#include "robot.h"

robot robot_move(robot self) {
  printf("Move!\n");
  return self.place(self
                    , new_point(self.loc.x + sin(self.facing*M_PI)
                               , self.loc.y + cos(self.facing*M_PI))
                    , self.facing, self.table);
}

robot robot_left(robot self) {
  return self.place(self, self.loc, mod(self.facing - 0.5, 2.0), self.table);
}

robot robot_right(robot self) {
  return self.place(self, self.loc, mod(self.facing + 0.5, 2.0), self.table);
}

robot robot_report(robot self) {
  printf("%.0f,%.0f,%.1f\n", self.loc.x, self.loc.y, self.facing);
  return self;
}

robot robot_place(robot self, point loc, float facing, table table) {
  // table contains loc
    return new_robot(loc, facing, table);
  // else
  // return self
}

robot new_robot(point loc, float facing, table table) {
  robot robot;

  robot.loc = loc;
  robot.facing = facing;
  robot.table = table;

  robot.move = robot_move;
  robot.left = robot_left;
  robot.right = robot_right;
  robot.report = robot_report;
  robot.place = robot_place;

  return robot;
}

float mod(float x, float y) {
  return x - y * floor(x/y);
}

