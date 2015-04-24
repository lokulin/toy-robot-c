#include "table.h"

int table_contains(table self, point point) {
  return (self.llc.x <= point.x && self.llc.y <= point.y
      && self.urc.x >= point.x && self.urc.y >= point.y);
}

table new_table(point llc, point urc) {
  table table;

  table.llc = llc;
  table.urc = urc;

  table.contains = table_contains;

  return table;
}

