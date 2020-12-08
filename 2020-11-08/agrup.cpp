#include <cstdio>
#include <cmath> // floor, sqrt

const int maxn = 128;

struct point_t {
  double x, y;
};

struct cluster_t {
  int n;
  double sx, sy;
  point_t c;
};

point_t point[maxn];
cluster_t cluster[maxn];
int num_clusters=0;

double dist(point_t a, point_t b) {
  double dx = a.x - b.x;
  double dy = a.y - b.y;
  return sqrt(dx*dx + dy*dy);
}
void create_cluster(point_t p) {
  cluster[num_clusters].c = p;
  cluster[num_clusters].n = 1;
  cluster[num_clusters].sx = p.x;
  cluster[num_clusters].sy = p.y;
  ++num_clusters;
}
void add_to_cluster(point_t p, cluster_t &c) {
  c.n++;
  c.sx += p.x;
  c.sy += p.y;
  c.c = point_t{c.sx/c.n, c.sy/c.n};
}
void find_cluster(point_t p, double r) {
  int best_cluster = -1;
  for(int i=num_clusters-1; i>=0; --i) {
    double d = dist(p, cluster[i].c);
    if (d <= r) {
      best_cluster = i;
      r = d;
    }
  }
  if (best_cluster == -1) {
    create_cluster(p);
  } else {
    add_to_cluster(p, cluster[best_cluster]);
  }
}

int main() {
  int n;

  double radius;

  scanf(" %d %lf", &n, &radius);
  for(int i=0; i<n; ++i) {
    scanf(" %lf %lf", &point[i].x, &point[i].y);
  }
  for(int i=0; i<n; ++i) {
    find_cluster(point[i], radius);
  }
  printf("%d\n", num_clusters);
  for(int i=0; i<num_clusters; ++i) {
    printf("%d %d\n", 
	   int(floor(cluster[i].c.x)),
	   int(floor(cluster[i].c.y)));
  }
  return 0;
}
