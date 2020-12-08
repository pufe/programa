#include <cstdio>
#include <cmath>

struct point_t {
  double x, y;
  point_t operator-(point_t a) {
    return point_t{x-a.x, y-a.y};
  }
  double length() {
    return sqrt(x*x + y*y);
  }
  double distance(point_t b) {
    return (*this-b).length();
  }
};

struct node_t {
  point_t coord;
  bool visited;
  double distance;
};
const int maxn = 512;
node_t person[maxn];

int find_minimum_distance(int n) {
  int index = -1;
  double best = 1e9;
  for(int i=0; i<n; ++i) {
    if (!person[i].visited)
      if (person[i].distance < best) {
	best = person[i].distance;
	index = i;
      }
  }
  return index;
}

double mst(int start, int n) {
  double total = 0;
  person[start].distance = 0;
  for(int i=0; i<n; ++i) {
    int x = find_minimum_distance(n);
    person[x].visited = true;
    total += person[x].distance;
    for(int j=0; j<n; ++j) {
      double d = person[x].coord.distance(person[j].coord);
      if (person[j].distance > d)
	person[j].distance = d;
    }
  }
  return total;
}

int main() {
  int num_tests;
  scanf(" %d", &num_tests);
  for(int t=0; t<num_tests; ++t) {
    int n;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      scanf(" %lf %lf", &person[i].coord.x, &person[i].coord.y);
      person[i].visited = false;
      person[i].distance = 1e9;
    }
    printf("%.2lf\n", mst(0, n)/100.0);
  }
}
