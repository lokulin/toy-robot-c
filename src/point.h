#ifndef POINT_T
#define POINT_T

struct pointT;

typedef struct pointT {
  float x;
  float y;
} point;

#endif

point new_point(float x, float y);

