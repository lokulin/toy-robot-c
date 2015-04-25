#include "robot.h"

static Robot robot_move(Robot self) {
  return self.place(self
                    , new_point(self.loc.x + sin(self.facing * acos(-1))
                                , self.loc.y + cos(self.facing * acos(-1)))
                    , self.facing, self.table);
}

static Robot robot_left(Robot self) {
  return self.place(self, self.loc, mod(self.facing - 0.5, 2.0), self.table);
}

static Robot robot_right(Robot self) {
  return self.place(self, self.loc, mod(self.facing + 0.5, 2.0), self.table);
}

static Robot robot_report(Robot self, const char **directions) {
  if (self.table.contains(self.table, self.loc) == 1) {
    printf("%.0f,%.0f,%s\n", self.loc.x, self.loc.y
                           , directions[(long)((self.facing*2.0)+0.5)]);
  }
  return self;
}

static Robot robot_place(Robot self, Point loc, float facing, Table table) {
  if (table.contains(table, loc) == 1) {
    return new_robot(loc, facing, table);
  } else {
    return self;
  }
}

Robot new_robot(Point loc, float facing, Table table) {
  Robot robot;

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

