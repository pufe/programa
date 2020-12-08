#include <cstdio>
#include <algorithm>
using namespace std;

const int maxn = 1024;
int original[maxn];
int sorted[maxn];

int main() {
  int tests;
  int n, c;
  scanf(" %d", &tests);
  for(int t=0; t<tests; ++t) {
    scanf(" %d", &n);
    for(int i=0; i<n; ++i) {
      scanf(" %d", &original[i]);
      sorted[i] = -original[i];
    }
    sort(sorted, sorted+n);
    c=0;
    for(int i=0; i<n; ++i) {
      if (original[i] == -sorted[i])
	++c;
    }
    printf("%d\n", c);
  }
  return 0;
}
