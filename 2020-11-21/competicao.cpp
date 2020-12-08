#include <cstdio>

int main() {
  int n, x, t;
  t=0;
  scanf(" %d", &n);
  for(int i=0; i<n; ++i) {
    scanf(" %d", &x);
    t += x - (x%3);
  }
  printf("%d\n", t);
  return 0;
}
