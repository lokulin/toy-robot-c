#include "point.h"

#ifndef TABLE_T
#define TABLE_T

typedef struct Table Table;

struct Table {
  Point llc;
  Point urc;
  int (*contains)(Table, Point);
};

#endif

Table new_table(Point llc, Point urc);

