/*
  ID: pufepro1
  LANG: C++
  TASK: milk2
*/
#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

struct event_t {
  int t;
  bool finish;
};
bool operator<(event_t a, event_t b) {
  if (a.t != b.t)
    return a.t < b.t;
  return !a.finish && b.finish;
}
const int maxn = 10100;
event_t event[maxn];

int main() {
  FILE *fin  = fopen("milk2.in", "r");
  FILE *fout = fopen("milk2.out", "w");
  int n;
  fscanf(fin, " %d", &n);
  for(int i=0; i<n; ++i) {
    fscanf(fin, " %d %d", &event[2*i].t, &event[2*i+1].t);
    event[2*i].finish = false;
    event[2*i+1].finish = true;
  }
  sort(event, event+2*n);
  int num_workers = 1;
  int greatest_work = 0;
  int greatest_idle = 0;
  int start = event[0].t;
  for(int i=1; i<2*n; ++i) {
    if (event[i].finish) {
      --num_workers;
      if (num_workers == 0) {
	// work -> start, event[i].t
	greatest_work = max(greatest_work, event[i].t - start);
	start = event[i].t;
      }
    }
    else {
      if (num_workers == 0) {
	// idle -> start, event[i].t
	greatest_idle = max(greatest_idle, event[i].t - start);
	start = event[i].t;
      }
      ++num_workers;
    }
  }
  fprintf(fout, "%d %d\n", greatest_work, greatest_idle);
  return 0;
}
