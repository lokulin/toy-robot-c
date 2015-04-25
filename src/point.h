#ifndef POINT_T
#define POINT_T

typedef struct Point Point;

struct Point {
  float x;
  float y;
};

#endif

Point new_point(float x, float y);

