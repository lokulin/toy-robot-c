#include "table.h"

static int table_contains(Table self, Point point) {
  return (self.llc.x <= point.x && self.llc.y <= point.y
      && self.urc.x >= point.x && self.urc.y >= point.y);
}

Table new_table(Point llc, Point urc) {
  Table table;

  table.llc = llc;
  table.urc = urc;

  table.contains = table_contains;

  return table;
}

