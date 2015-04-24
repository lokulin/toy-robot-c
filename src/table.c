#include "table.h"

table new_table(point llc, point urc) {
  table table;

  table.llc = llc;
  table.urc = urc;

  return table;
}

