#ifndef POINT_T
#define POINT_T

typedef struct point point;

struct point {
  float x;
  float y;
};

#endif

point new_point(float x, float y);

