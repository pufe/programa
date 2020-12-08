#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

struct point_t {
  int x, y;
  point_t operator-(point_t o) {
    return point_t{x-o.x, y-o.y};
  }
  int dot(point_t o) {
    return x*o.x + y*o.y;
  }
  int cross(point_t o) {
    return x*o.y - y*o.x;
  }
  int length2() {
    return dot(*this);
  }
  double length() {
    return sqrt((double)length2());
  }
};
const int maxn = 2048;
point_t computer[maxn];

bool cmp_coord(point_t a, point_t b) {
  if (a.y != b.y)
    return a.y < b.y;
  return a.x < b.x;
}
bool cmp_angle(point_t a, point_t b) {
  int c = a.cross(b);
  if (c!=0)
    return c > 0;
  return a.length2() < b.length2();
}

bool generates_concavity(vector<point_t>& poly, point_t p) {
  point_t last = poly[poly.size()-1];
  point_t prev = poly[poly.size()-2];
  point_t a = last-prev;
  point_t b = p-last;
  return a.cross(b) < 0;
}

double convex_hull(int n) {
  vector<point_t> poly;
  double length = 0;
  poly.push_back(point_t{0,0});
  for(int i=1; i<n; ++i) {
    while(poly.size() > 2
	  && generates_concavity(poly, computer[i])) {
      poly.pop_back();
    }
    poly.push_back(computer[i]);
  }
  for(int i=0; i<(int)poly.size(); ++i) {
    length += (poly[(i+1)%poly.size()]-poly[i]).length();
  }
  return length;
}

int main() {
  int n;
  while(true) {
    scanf(" %d", &n);
    if (n==0)
      break;
    for(int i=0; i<n; ++i) {
      scanf(" %d %d", &computer[i].x, &computer[i].y);
    }
    sort(computer, computer+n, cmp_coord);
    for(int i=1; i<n; ++i) {
      computer[i] = computer[i]-computer[0];
    }
    sort(computer+1, computer+n, cmp_angle);
    printf("Tera que comprar uma fita de tamanho %.2lf.\n",
	   convex_hull(n));
  }
  return 0;
}
