#include <cstdio>
#include <cmath>

const double pi = 4*atan(1);

struct point_t {
  int x, y;
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
  point_t key_point(int i) {
    return point_t{p.x+w*(i%2), p.y+h*(i/2)};
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
  int cycle(int x) {
    x %= 4;
    switch(x) {
    case 0: return 1;
    case 1: return 0;
    case 2: return -1;
    case 3: return 0;
    }
  }
  point_t key_point(int i) {
    if (i==0)
      return c;
    return point_t{c.x+r*cycle(i),c.y+r*cycle(i+1)};
  }
};

int table[4][4] = {{200, 20, 30, 50},
		   {300, 10, 25, 40},
		   {400, 25, 55, 70},
		   {100, 18, 38, 60}};

bool intersect(rect_t a, circle_t b) {
  for(int i=0; i<4; ++i)
    if (b.contains(a.key_point(i)))
      return true;
  for(int i=0; i<5; ++i)
    if (a.contains(b.key_point(i)))
      return true;
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
	  &enemy.p.x, &enemy.p.y, &enemy.w, &enemy.h);
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
