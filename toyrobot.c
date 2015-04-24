#include "src/point.h"
#include "src/table.h"
#include "src/robot.h"

int main() {
  table table;
  robot robot;

  table = new_table(new_point(0,0), new_point(4,4));

  robot = new_robot(new_point(0,0), 0.0, table);
  robot = robot.report(robot);
  robot = robot.move(robot);
  robot = robot.report(robot);

}

