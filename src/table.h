#include "point.h"

#ifndef TABLE_T
#define TABLE_T

typedef struct table table;

struct table {
  point llc;
  point urc;
};

#endif

table new_table(point llc, point urc);

