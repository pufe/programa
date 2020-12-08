#include <cstdio>

struct point_t {
  double x, y;
  point_t operator+(point_t o) {
    return point_t{x+o.x, y+o.y};
  }
  point_t operator-(point_t o) {
    return point_t{x-o.x, y-o.y};
  }
  point_t operator*(double v) {
    return point_t{x*v, y*v};
  }
  point_t operator/(double v) {
    return point_t{x/v, y/v};
  }
  point_t rotate() {
    return point_t{-y, x};
  }
  double dot(point_t o) {
    return x*o.x + y*o.y;
  }
  void print() {
    printf("~ %lf %lf\n", x, y);
  }
};

int main() {
  int tests;
  point_t p[4];
  scanf(" %d", &tests);
  for(int t=1; t<=tests; ++t) {
    for(int i=0; i<4; ++i)
      scanf(" %lf %lf", &p[i].x, &p[i].y);
    point_t am = (p[0]+p[2])/2;
    point_t ap = (p[0]-p[2]).rotate();
    point_t bm = (p[1]+p[3])/2;
    point_t bp = (p[1]-p[3]).rotate();
    point_t x = bm + bp*((am-bm).dot(bp)/bp.dot(bp));
    point_t r = am + ap*((x-am).dot(x-am)/ap.dot(x-am));
    printf("Case #%d: %.2lf %.2lf\n", t, r.x, r.y);
  }
  return 0;
}
