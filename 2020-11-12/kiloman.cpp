#include <cstdio>

const int maxn = 128;
int h[maxn];
char cmd[maxn];

int main() {
  int tests;
  scanf(" %d", &tests);
  for(int t=0; t<tests; ++t) {
    int n;
    scanf(" %d", &n);
    for(int i=0; i<n; ++i)
      scanf(" %d", &h[i]);
    scanf(" %s", cmd);
    int total = 0;
    for(int i=0; i<n; ++i) {
      if ((h[i]>2) == (cmd[i]=='J'))
	++total;
    }
    printf("%d\n", total);
  }
  return 0;
}
