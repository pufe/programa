#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

typedef long long int num;

const double pi = 4*atan(1);

struct point_t {
  int x, y;
};

point_t operator-(point_t a, point_t b) {
  return point_t{a.x-b.x, a.y-b.y};
}
int dot(point_t a, point_t b) {
  return a.x*b.x + a.y*b.y;
}
int cross(point_t a, point_t b) {
  return a.x*b.y - a.y*b.x;
}
struct segment_t {
  point_t a, b;
  num sq_dist(point_t p) {
    point_t ap = p-a;
    point_t ab = b-a;
    point_t ba = a-b;
    point_t bp = p-b;
    if (dot(ap, ab)<0 || dot(bp, ba)<0 || dot(ab, ab)==0)
      return min(dot(ap, ap), dot(bp, bp));
    num x = cross(ap, ab);
    return x*x/dot(ab, ab);
  }
};

struct rect_t {
  point_t p;
  int h, w;
  bool contains(point_t a) {
    int dx = a.x - p.x;
    int dy = a.y - p.y;
    if (dx >= 0 && dx <= w && dy >=0 && dy <= h)
      return true;
    return false;
  }
  point_t corner(int i) {
    return point_t{p.x+w*(i%2), p.y+h*(i/2)};
  }
  segment_t segment(int i) {
    int v[] = {0, 1, 3, 2, 0};
    return segment_t{corner(v[i]), corner(v[i+1])};
  }
};

struct circle_t {
  point_t c;
  int r;
  bool contains(point_t a) {
    int dx = a.x - c.x;
    int dy = a.y - c.y;
    if (dx*dx + dy*dy <= r*r)
      return true;
    return false;
  }
};

int table[4][4] = {{200, 20, 30, 50},
		   {300, 10, 25, 40},
		   {400, 25, 55, 70},
		   {100, 18, 38, 60}};

bool intersect(rect_t a, circle_t b) {
  if (a.contains(b.c))
    return true;
  for(int i=0; i<4; ++i) {
    if (a.segment(i).sq_dist(b.c) <= b.r*b.r)
      return true;
  }
  return false;
}

int main() {
  int t;
  int level;
  int i;
  char name[32];
  rect_t enemy;
  circle_t magic;
  int damage;

  for(scanf(" %d", &t); t>0; --t) {
    scanf(" %d %d %d %d", 
	  &enemy.w, &enemy.h,
	  &enemy.p.x, &enemy.p.y);
    scanf(" %s %d %d %d",
	  name, &level,
	  &magic.c.x, &magic.c.y);
    if (name[0]=='f')
      i=0;
    else if (name[0]=='w')
      i=1;
    else if (name[0]=='e')
      i=2;
    else
      i=3;
    magic.r = table[i][level];
    damage = table[i][0];
    if (intersect(enemy, magic))
      printf("%d\n", damage);
    else
      printf("0\n");
  }
  return 0;
}
