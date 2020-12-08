#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int n;
  int furthest_h=0;
  int furthest_i=0;
  int best_distance=0;
  int current_h;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &current_h);
    int current_distance = i-furthest_i + furthest_h + current_h;
    best_distance = max(best_distance, current_distance);
    if (current_h > i-furthest_i + furthest_h) {
      furthest_i = i;
      furthest_h = current_h;
    }
  }
  printf("%d\n", best_distance);
  return 0;
}
