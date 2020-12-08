#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1000100;
const int inf = 0x3fff3fff;

struct point_t {
  int left_r, right_r;
  int left_f, right_f;
};

char av[maxn];
point_t p[maxn];

int go_f(int r) {
  int best_dist = inf;
  int f;
  if (r>=0 && r<inf) {
    f = p[r].left_f;
    best_dist = min(best_dist, r - f);
    f = p[r].right_f;
    best_dist = min(best_dist, f - r);
  }
  return best_dist;
}

int go_r(int f) {
  int best_dist = inf;
  int r;
  if (f>=0 && f<inf) {
    r = p[f].left_r;
    best_dist = min(best_dist, f - r);
    r = p[f].right_r;
    best_dist = min(best_dist, r - f);
  }
  return best_dist;
}
int calculate(int x) {
  int best_dist = inf;
  int r, f;
  r = p[x].left_r;
  best_dist = min(best_dist, x-r+go_f(r));
  r = p[x].right_r;
  best_dist = min(best_dist, r-x+go_f(r));
  f = p[x].left_f;
  best_dist = min(best_dist, x-f+go_r(f));
  f = p[x].right_f;
  best_dist = min(best_dist, f-x+go_r(f));
  return best_dist;
}

int main() {
  int tests;
  scanf(" %d", &tests);
  for(int t=0; t<tests; ++t) {
    scanf(" %s", av);
    int n = strlen(av);
    int last_r = -inf;
    int last_f = -inf;
    for(int i=0; i<n; ++i) {
      if (av[i] == 'C')
	last_r = i;
      else if (av[i] == 'F')
	last_f = i;
      p[i].left_r = last_r;
      p[i].left_f = last_f;
    }
    last_r = inf;
    last_f = inf;
    for(int i=n-1; i>=0; --i) {
      if (av[i] == 'C')
	last_r = i;
      else if (av[i] == 'F')
	last_f = i;
      p[i].right_r = last_r;
      p[i].right_f = last_f;
    }
    int best_dist = inf;
    for(int i=0; i<n; ++i) {
      if (av[i] == 'R')
	best_dist = min(best_dist, calculate(i));
    }
    printf("%d\n", best_dist);
  }
  return 0;
}
