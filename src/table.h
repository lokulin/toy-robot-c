#include "point.h"

#ifndef TABLE_T
#define TABLE_T

struct tableT;

typedef struct tableT {
  point llc;
  point urc;
} table;

#endif

table new_table(point llc, point urc);

